#include "threads.h"
//#include "Bonus.h"

#define NUM_OF_THREADS 10

int main()
{
	//Part 1
	call_I_Love_Threads();

	//Part 2 - section A  
	std::vector<int> primes1;
	getPrimes(58, 100, primes1);
	printVector(primes1);
	printVector(callGetPrimes(58, 100));

	//Part 2 - section B
	//callGetPrimes(0, 1000);
	//callGetPrimes(0, 1000000);
	//callGetPrimes(0, 100000000);

	//Part 3 - section C
	std::cout << NUM_OF_THREADS << " threads are running " << std::endl;
	callWritePrimesMultipleThreads(0, 1000, "primes2.txt", NUM_OF_THREADS);
	callWritePrimesMultipleThreads(0, 100000, "primes2.txt", NUM_OF_THREADS);
	callWritePrimesMultipleThreads(0, 1000000, "primes2.txt", NUM_OF_THREADS);

	std::cout << "\nOnly one thread are running " << std::endl;
	callWritePrimesMultipleThreads(0, 1000, "primes2.txt", 1);
	callWritePrimesMultipleThreads(0, 100000, "primes2.txt", 1);
	callWritePrimesMultipleThreads(0, 1000000, "primes2.txt", 1);

	 //Bonus
	 //callPrintColorMultipleThreads(); 
	 //findMaxUsingThreads(); 
	 //threadsRecursion(1); 


	system("pause");
	return 0;
}