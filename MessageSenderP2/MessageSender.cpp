#include "MessageSender.h"

/*function displays the menu
* output: none
* input: none
*/
void MessageSender::showMenu()
{
	int op;
	while (true)
	{
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
