#include "MessageSender.h"
#include <iostream>

int main()
{
    MessageSender messageSender;

    try
    {
        std::thread adminFileThread(&MessageSender::readAdminFile, &messageSender);
        adminFileThread.detach();


        messageSender.showMenu();

    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
