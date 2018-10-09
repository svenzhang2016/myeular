/**
 * The sum of the squares of the first ten natural numbers is,
 * 12 + 22 + ... + 102 = 385
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)2 = 552 = 3025
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 − 385 = 2640.
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <iostream>

int main()
{
//    int data = 100;
//    long squareSum = 0, sumSquare = 0;
//
//    for(int i = 1; i <= 100; ++i)
//    {
//        squareSum += i * i;
//    }
//    for(int i = 1; i <= 100; ++i)
//    {
//        sumSquare += i;
//    }
//
//    std::cout << sumSquare * sumSquare - squareSum;

    /**
     *  1*1 + 2*2 + ....n*n =  (2n*n + 1)(n+1)n/6;
     */

    long sum = 100 * (100 + 1)/2;
    long sum_sq = (2*100+1)*(100+1)*100/6;
    std::cout << sum*sum - sum_sq;

    return 0;
}