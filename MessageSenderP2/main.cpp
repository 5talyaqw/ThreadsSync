#include "MessageSender.h"

int main()
{
    // Create the MessageSender object
    MessageSender messageSender;

    try
    {
        std::thread t1(&MessageSender::readAdminFile, &messageSender);
        std::thread t2(&MessageSender::writeMessagesToUsersFile, &messageSender);

        messageSender.showMenu();

        t1.join();
        t2.join();

        
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
