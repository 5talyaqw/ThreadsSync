#include "threads.h"
#include <iostream>

int main()
{
    int begin = 1;
    int end = 100;
    std::string filePath = "C:\\Users\\Cyber_User\\Desktop\\EkronotExercises\\ThreadsSync\\primes.txt";
    int N = 4;

    // Open file for writing
    std::ofstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return 1;
    }

    writePrimesToFile(begin, end, file);
    //callWritePrimesMultipleThreads(begin, end, filePath, N);

    //std::cout << "Finished writing primes to file: " << filePath << std::endl;
    return 0;
}