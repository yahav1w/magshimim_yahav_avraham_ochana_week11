#include <thread>
#include <ctime>
#include "Threads.h"

void I_Love_Threads()
{
	std::cout << "I love threads" << std::endl;
}

void call_I_Love_Threads()
{
	std::thread t1(I_Love_Threads);

	t1.join();
}

void printVector(const std::vector<int> primes)
{
	for (int i = 0;i < primes.size();i++)
	{
		std::cout << primes[i] << ",";
	}
	std::cout << std::endl;
}

void getPrimes(const int begin, const int end, std::vector<int>& primes)
{
	bool isPrime = true;
	for (int i = begin; i < end;i++)
	{
		isPrime = true;
		for (int j = 2;j < i;j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			primes.push_back(i);
		}
	}
}

std::vector<int> callGetPrimes(int begin, int end)
{
	std::vector<int> primes;
	time_t start, ending;
	time(&start);
	std::thread t(getPrimes, begin, end, std::ref(primes));
	t.join();
	time(&ending);
	std::cout << "time took: " << difftime(ending, start) << std::endl;
	return primes;
}

void writePrimesToFile(int begin, int end, std::ofstream& file)
{
	std::vector<int> prime = callGetPrimes(begin, end);
	file << "[ ";
	for (int i = 0;i < prime.size();i++)
	{
		file << prime[i];
		if (i != prime.size() - 1)
		{
			file << " , ";
		}
	}
	file << " ]";
}

void callWritePrimesMultipleThreads(int begin, int end, std::string filePath, int N)
{
	int diff = (end - begin) / N, threadEnd = 0;
	std::vector<std::thread> threads;
	end = end - diff * N;
	std::ofstream file(filePath);
	time_t start,ending;
	time(&start);
	for (int i = 0;i < N;i++)
	{
		threads.push_back(std::thread(writePrimesToFile, begin, threadEnd, std::ref(file)));
		begin += diff;
		threadEnd = (i == N - 1) ? end : begin + diff;
	}
	for (int i = 0;i < N;i++)
	{
		threads[i].join();
	}
	time(&ending);
	std::cout << "time took: " << difftime(ending, start) << std::endl;
}
