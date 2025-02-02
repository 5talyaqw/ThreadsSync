#include "threads.h"
#include <iostream>

int main()
{
    int begin = 1;
    int end = 100;
    std::string filePath = "primes.txt";
    int N = 4;

    callWritePrimesMultipleThreads(begin, end, filePath, N);

    std::cout << "Finished writing primes to file: " << filePath << std::endl;
    return 0;
}