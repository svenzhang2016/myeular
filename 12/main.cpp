#include <iostream>

int calDevisors(long num)
{
	int count = 0;
	for (int i = 1; i < sqrt(num); i++)
	{
		if (num % i == 0)
		{
			count += 2;
		}
	}
	return count;
}

int main()
{
	int maxDivisors = 0;	// max devisors
	long triangleNum = 0;	// triangular number
	int i = 1;
	while (1)
	{
		triangleNum += i;
		maxDivisors = calDevisors(triangleNum);
		if (maxDivisors >= 500)
		{
			std::cout << triangleNum << std::endl;
			break;
		}
		i++;
	}


	return 0;
}