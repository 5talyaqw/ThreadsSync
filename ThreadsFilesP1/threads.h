#include <string>
#include <fstream>
#include <iostream>
#include<vector>
#include <thread>
#include <mutex>
#include <cmath>


//helpers
bool isPrime(int num);
void getPrimes(int begin, int end, std::vector<int>& primes);


//file functions
void writePrimesToFile(int begin, int end, std::ofstream& file);
void callWritePrimesMultipleThreads(int begin, int end, std::string filePath, int N);