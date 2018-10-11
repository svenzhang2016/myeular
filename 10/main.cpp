/**
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */
#include <iostream>
#include <cmath>
#include <vector>

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
    /**
     *  method 1
     */
//    long num = 2000000;
//    long long sum = 5;
//    long n = 5;
//    while(n <= num) {
//        if (isPrime(n)) {
//            sum += n;
//        }
//        n += 2;
//        if(n <= num && isPrime(n)) {
//            sum += n;
//        }
//        n += 4;
//    }
//    std::cout << sum;

    /**
     * method 2
     * sieve of Eratosthenes
     */
//    long num = 2000000;
//    long crossNum = (long)sqrt(num);
//    std::vector<bool> vec(num, false);
//    for(long i = 4; i < num; i+=2) {
//        vec[i] = true;
//    }
//    for(long i = 3; i < crossNum; i+=2) {
//        if (!vec[i]) {
//            for(long j = i * i; j < num; j += 2*i){
//                vec[j] = true;
//            }
//        }
//    }
//    long long sum = 0;
//    for(long i = 2; i < num; ++i){
//        if(!vec[i]){
//            sum += i;
//        }
//    }
//    std::cout << sum;
    /**
     * method 3
     */
    long num = 2000000;
    long newNum = (num - 1) / 2;
    long crossNum = (long)sqrt(num - 1) / 2;

    std::vector<bool> vec(newNum, false);
    for(long i = 1; i < crossNum; ++i)
    {
        if(!vec[i]){
            for(long j = 2*i*(i+1);j < newNum; j += 2*i+1){
                vec[j] = true;
            }
        }
    }
    long long sum = 2;
    for(long i = 1; i < newNum; ++i){
        if(!vec[i]){
            sum += 2*i+1;
        }
    }
    std::cout << sum;
    return 0;
}