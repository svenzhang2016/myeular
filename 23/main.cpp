/*
A perfect number is a number for which the sum of its proper divisors is
exactly equal to the number. For example, the sum of the proper divisors of 28
would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n
and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
number that can be written as the sum of two abundant numbers is 24. By
mathematical analysis, it can be shown that all integers greater than 28123 can
be written as the sum of two abundant numbers. However, this upper limit cannot
be reduced any further by analysis even though it is known that the greatest
number that cannot be expressed as the sum of two abundant numbers is less than
this limit.

Find the sum of all the positive integers which cannot be written as the sum of
two abundant numbers.
 */
#include <iostream>

bool abundantNum(int val) {
    int sum = 1;
    int mid = sqrt(val);
    for (int i = 2; i <= mid; i++) {
        if (val % i == 0) {
            sum = sum + i;
            int j = val / i;
            if (j != i) {
                sum += j;
            }
        }
    }
    return sum > val;
}

bool canSumByAbundantData(int val) {
    int b = 0;
    for (int a = 1; a <= (val + 1) / 2; a++) {
        b = val - a;
        if (abundantNum(a) && abundantNum(b)) {
            return true;
        }
    }
    return false;
}

int main() {

    unsigned long abundantSum = 0;
    for (int i = 1; i < 24; i++) {
        abundantSum += i;
    }
    for (int i = 25; i <= 28123; i++) {
        if (!canSumByAbundantData(i)) {
            abundantSum += i;
        }
    }
    std::cout << "sum: " << abundantSum;
}