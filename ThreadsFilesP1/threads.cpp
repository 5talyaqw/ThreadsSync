#include "threads.h"

std::mutex filemtx;

/*function checking if number is prime
* output: true if prime and false if not prime
* input: number - int
*/
bool isPrime(int num)
{
	if (num <= 1)
	{
		return false;
	}
	for (int i = 2; i <= std::sqrt(num); ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

/*
* function adding all the prime numbers into vector variable
* output:none
* input: beginning - int, end - int, primes - vector of int refrence 
*/
void getPrimes(int begin, int end, std::vector<int>& primes)
{
	//going on all the numbers
	for (int i = begin; i <= end; ++i)
	{
		if (isPrime(i)) //sending to check if prime or not
		{
			primes.push_back(i); //if it is prime adding to the vector
		}
	}
}

void writePrimesToFile(int begin, int end, std::ofstream& file)
{
	std::lock_guard<std::mutex> lock(filemtx);
	std::vector<int> primes;
	getPrimes(begin, end, primes);

	for (auto it = primes.begin(); it != primes.end(); it++)
	{
		file << *it << '\n';
	}
}

void callWritePrimesMultipleThreads(int begin, int end, std::string filePath, int N)
{
}
