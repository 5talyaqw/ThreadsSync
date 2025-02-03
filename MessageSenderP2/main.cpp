#include "MessageSender.h"

int main()
{
    // Create the MessageSender object
    MessageSender messageSender;

    try
    {
        messageSender.showMenu();
        messageSender.readAdminFile();
        messageSender.writeMessagesToUsersFile();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
