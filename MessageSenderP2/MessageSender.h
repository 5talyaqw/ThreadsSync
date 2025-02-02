#pragma once
#include <iostream>
#include <fstream>
#include <thread>
#include <exception>
#include <set>
#include <string>

class MessageSender
{
public:
    void showMenu();
    void signIn();
    void signOut();
    void showConnectedUsers();

private:
    std::set<std::string> connectedUsers; //queue to users
};