#include "MessageSender.h"
#include <iostream>

int main()
{
    MessageSender messageSender;

    try
    {
        messageSender.showMenu();

    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}