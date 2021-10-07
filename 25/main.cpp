/* The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000
digits?
*/
#include <iostream>
#include <string>

using namespace std;

string add(string a, string b) {
    if (b.size() > a.size()) {
        for (int i = a.size(); i < b.size(); i++) {
            a = "0" + a;
        }
    }
    int remainder = 0, temp = 0;
    string sum = "";
    for (int i = b.size() - 1; i >= 0; i--) {
        temp = (a[i] - '0') + (b[i] - '0') + remainder;
        sum = to_string(temp % 10) + sum;
        remainder = temp / 10;
    }
    if (remainder > 0) sum = to_string(remainder) + sum;
    return sum;
}

int main() {
    int n = 3;
    string a = "1";
    string b = "1";
    string c = "2";
    while (c.size() < 1000) {
        n++;
        a = b;
        b = c;
        c = add(a, b);
    }
    cout << n << endl;
}