/**
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a2 + b2 = c2
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <iostream>
#include <cmath>

typedef long long dllong;

dllong gcd(dllong a, dllong b)
{
    while(b != 0)
    {
        dllong r = b;
        b = a % b;
        a = r;
    }
    return a;
}

int main()
{
    /**
     *  method 1
     *  0 == 1e6 - 2000*a - 2000*b +  + 2*a*b;
     *  a <= (1000 - 3)/3 , b < (1000 - a)/2;
     */
//
//    int a, b;
//    bool found = false;
//    for(a = 1; a < (1000 - 3)/3 ; ++a)
//    {
//        for(b = 1; b < (1000- a)/2; ++b)
//        {
//            if(1e6 - 2000*a - 2000*b + 2*a*b == 0)
//            {
//                found = true;
//                break;
//            }
//        }
//        if (found)
//            break;
//    }
//    std::cout << a * b * sqrt(a*a + b*b);

    /**
     *  method 2
     *  gcd(a, b) = gcd(b, c) = gcd(c, a) = 1
     *  a = m2 - n2, b = 2mn, c = m2 + n2;
     */

    dllong s = 1000;
    dllong s2 = s / 2;
    dllong limit = (dllong)sqrt(s2) - 1;
    for(dllong i = 2; i < limit; ++i) {
        if (s2 % i == 0) {
            dllong sm = s2 / i;
            while (sm % 2 == 0) {
                sm = sm / 2;
            }
            dllong k = i % 2 == 1 ? i + 2 : i + 1;
            while(k < 2 * i && k <= sm){
                if(sm % k == 0 && gcd(k, i) == 1){
                    dllong d = s2 / (k * i);
                    dllong n = k - i;
                    dllong a = d * (i * i - n * n);
                    dllong b = 2 * d * i * n;
                    dllong c = d * (i * i + n * n);

                    std::cout << a << std::endl;
                    std::cout << b << std::endl;
                    std::cout << c << std::endl;
                    std::cout << a * b * c << std::endl;
                    goto end;
                }
                k += 2;
            }
        }
    }
end:;
    return 0;
}