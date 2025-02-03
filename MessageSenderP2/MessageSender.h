#pragma once
#include <iostream>
#include <fstream>
#include <exception>
#include <set>
#include <queue>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>

class MessageSender
{
public:
    //part A methods
    void showMenu();
    void signIn();
    void signOut();
    void showConnectedUsers();

    //part B methods
    void readAdminFile();

    //part C methods
    void writeMessagesToUsersFile();

private:
    std::set<std::string> connectedUsers; //queue to users
    std::queue<std::string> messagesQueue;

    std::mutex connectedUsersMtx;
    std::mutex messagesQueueMtx;

    std::condition_variable messagesCV;

};
