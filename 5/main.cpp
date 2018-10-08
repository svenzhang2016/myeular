/**
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
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
    long multi = 1;
    for(int i = 2; i <= 20; ++i)
    {
        if(isPrime(i))
        {
            multi *= i;
        }
    }
    multi *= 24;

    std::cout << multi;

    return  0;
}
