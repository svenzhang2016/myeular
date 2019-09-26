#include <iostream>

int main()
{
	long long result = 1;
	int n = 20;
	for (int i = 1; i <= n; i++)
	{
		result = (result * ((long long)n + i)) / i;
	}
	std::cout << result << std::endl;

	return 0;
}