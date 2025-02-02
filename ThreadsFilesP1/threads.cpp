#include "threads.h"

//global variable for file mtx
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
	//opening file
	std::ofstream file(filePath);
	//making sure its open
	if (!file.is_open())
	{
		std::cerr << "Error opening file: " << filePath << std::endl;
		return;
	}

	//vector of threads
	std::vector<std::thread> threads;
	int range = (end - begin + 1) / N;
	int start = begin;

	//creating threads
	for (int i = 0; i < N; i++)
	{
		int stop = (i == N - 1) ? end : (start + range - 1);
		threads.push_back(std::thread(writePrimesToFile, start, stop, std::ref(file)));
		start = stop + 1;
	}

	//ensuring each thread completes execution b4 continue
	for (int i = 0; i < threads.size(); i++)
	{
		threads[i].join();
	}

	//closing file
	file.close();
}
