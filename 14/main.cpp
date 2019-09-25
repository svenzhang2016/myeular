/*
The following iterative sequence is defined for the set of positive integers:
n → n/2 (n is even)
n → 3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million.
*/
#include <iostream>

int countChain(int n)
{
	int count = 0;
	while (n != 1)
	{
		if (n & 1 == 0)
		{
			n = 3 * n + 1;
		}
		else
		{
			n = n / 2;
		}
		count++;
	}
	return count;
}

int main()
{
	int max = 0;
	int chains = 0, maxChains = 0;

	for (int n = 500000; n < 10e6; n++)
	{
		chains = countChain(n);
		if (maxChains < chains)
		{
			maxChains = chains;
			max = n;
		}
	}
	std::cout << max << std::endl;	
	
	return 0;
}