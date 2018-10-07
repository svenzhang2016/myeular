/**
 * The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
 */

#include <iostream>
#include <cmath>
#include <list>

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

long long largestPrime(long long value)
{
    std::list<long long> primes;
    long long line = sqrt(value);
    long long lineDown = 0;
    for(long long i = 2; i < line + 1; ++i)
    {
        if(value % i == 0)
        {
            long long lineUp = value / i;
            if(isPrime(lineUp))
            {
                return lineUp;
            }
            if(isPrime(i))
            {
                lineDown = i;
            }
        }
    }
    return  lineDown;
}

int main()
{
    long long value = 600851475143;
    std::cout << largestPrime(value);
    return 0;
}