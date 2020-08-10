
/**
 Let d(n) be defined as the sum of proper divisors of n (numbers less than n
 which divide evenly into n).
 If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and
 each of a and b are called amicable numbers.

 For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71
 and 142; so d(284) = 220.

 Evaluate the sum of all the amicable numbers under 10000.
*/

#include <iostream>

int d(int value) {
    int sum = 1;
    for (int i = 2; i * i <= value; ++i) {
        if (value % i == 0) {
            sum += i;
            if (i != value / i) {
                sum += value / i;
            }
        }
    }
    return sum;
}

bool isAmicable(int value) {
    int a = d(value);
    if (a != value && d(a) == value) {
        return true;
    }
    return false;
}

int main() {
    unsigned long sum = 0;
    for (int i = 0; i < 10000; ++i) {
        if (isAmicable(i)) {
            sum += i;
        }
    }
    std::cout << "sum: " << sum;
}