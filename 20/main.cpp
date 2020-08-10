/* n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
Find the sum of the digits in the number 100!n! means n × (n − 1) × ... × 3 × 2
× 1 For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800, and the sum of the
digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/
#include <iostream>

int main() {
    unsigned char arr[200] = {0}; // each data in 100 does not bigger than 2
                                  // size, so max length array is 200
    unsigned val = 0, f = 0;
    arr[0] = 1;
    for (unsigned char i = 2; i <= 100; i++) {
        unsigned char inc = 0;
        for (unsigned char j = 0; j < 200; j++) {
            val = arr[j] * i + inc;
            inc = 0;
            if (val >= 10) {
                f = val % 10;
                inc = val / 10;
            } else {
                f = val;
            }
            arr[j] = f;
        }
    }

    unsigned int sum = 0;
    for (int i = 0; i < 200; ++i) {
        sum += arr[i];
    }

    std::cout << "sum: " << sum;

    return 0;
}