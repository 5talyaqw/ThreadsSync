#include "MessageSender.h"

/*function displays the menu
* output: none
* input: none
*/
void MessageSender::showMenu()
{
	int op;
	std::cout << "1. Sign In\n2. Sign Out\n3. Connected Users\n4. Exit\n";
	std::cout << "choose option 1-4: ";
	std::cin >> op;
		
	//switch case based on the op
	switch (op)
	{
	case 1:
		signIn();
		break;
	case 2:
		signOut();
		break;
	case 3:
		showConnectedUsers();
		break;
	case 4:
		std::cout << "Exiting...\n";
		return;
	default:
		throw std::invalid_argument("Not valid option!");
		break;
	}
}


/*method to sign in the username
* output: none
* input: none
*/
void MessageSender::signIn()
{
	std::string userName;
	std::cout << "Enter username to sign in: ";
	std::cin >> userName;
	if (userName.empty())
	{
		throw std::invalid_argument("Username cannnot be empty!");
	}

	//check if username already exists
	if (connectedUsers.find(userName) != connectedUsers.end())
	{
		throw std::invalid_argument("Error: Username already signed in.");
	}

	connectedUsers.insert(userName); // inserts the username to the set of connected users variable
	std::cout << "User " << userName << " signed in successfully.\n";
}

/*method to sign out the user
* output: none
* input: none
*/
void MessageSender::signOut()
{
	std::string userName;
	std::cout << "Enter username to sign out: ";
	std::cin >> userName;

	//trying to find the username in the set
	auto it = connectedUsers.find(userName);
	if (it == connectedUsers.end())
	{
		throw std::invalid_argument("Cannot find the asked username!");
	}

	//removing the user from the set
	connectedUsers.erase(it);
	std::cout << "User " << userName << " signed out successfully.\n";
}

/*function show connected users
* output: none
* input: none
*/
void MessageSender::showConnectedUsers()
{
	//checks if its empty
	if (connectedUsers.empty())
	{
		std::cout << "No users are currently connected.\n";
		return;
	}

	//going all over the connected users set with iterators to display them
	std::cout << "Connected users:\n";
	for (auto it = connectedUsers.begin(); it != connectedUsers.end(); ++it)
	{
		std::cout << *it << "\n";
	}
}

void MessageSender::readAdminFile()
{
	const std::string filePath = "C:\\Users\\Cyber_User\\Desktop\\EkronotExercises\\ThreadsSync\\data.txt";
	std::this_thread::sleep_for(std::chrono::seconds(60));  // Wait for 60 seconds
		
	//opening file
	std::ifstream file(filePath);
	if (file.is_open())
	{
		std::string line;

		//read the file line by line
		while (std::getline(file, line))
		{
			if (!line.empty()) // avoid pushing empty lines
			{
				messagesQueue.push(line);
			}
		}
		std::ofstream file;
		file.open(filePath, std::ofstream::out | std::ofstream::trunc);
		file.close();
		std::cout << "done copying each line.\n";
	}
	else
	{
		std::cerr << "Error: Unable to open file " << filePath << "\n";
	}
}

void MessageSender::writeMessagesToUsersFile()
{
	const std::string filePath = "C:\\Users\\Cyber_User\\Desktop\\EkronotExercises\\ThreadsSync\\output (1).txt";
	std::ofstream outputFile(filePath, std::ios::app); // Open file in append mode
	if (!outputFile)
	{
		std::cerr << "Error: Unable to open file " << filePath << "\n";
		return;
	}

	// Check if the queue has messages
	while (!messagesQueue.empty())
	{
		std::string message = messagesQueue.front(); // Get the next message
		messagesQueue.pop(); // Remove it from the queue

		// Iterate over the connected users and write the message for each
		for (auto it = connectedUsers.begin(); it != connectedUsers.end(); ++it)
		{
			// Write the username and the message to the file
			outputFile << *it << " : " << message << "\n";
		}
	}

	// Close the file after writing
	outputFile.close();
	std::cout << "Messages have been written to " << filePath << "\n";
}
