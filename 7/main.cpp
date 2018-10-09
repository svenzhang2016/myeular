/**
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * What is the 10 001st prime number?
 */

#include <iostream>
#include <cmath>

bool isPrime(long long num)
{
    if (num == 2 || num == 3)
    {
        return true;
    }
    if(num % 6 != 1 && num % 6 != 5)
        return false;
    for(long long i = 5; i < sqrt(num) + 1; ++i)
    {
        if(num % i == 0 || num % (i + 2) == 0)
            return  false;
    }
    return true;
}
int main()
{
    int index = 2;
    long long i = 3;
    while(index < 10001)
    {
        i += 2;
        if(isPrime(i))
        {
            index++;
        }
    }
    std::cout << i;

    return  0;
}