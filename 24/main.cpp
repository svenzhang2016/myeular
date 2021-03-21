/**
A permutation is an ordered arrangement of objects. For example, 3124 is one
possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are
listed numerically or alphabetically, we call it lexicographic order. The
lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5,
6, 7, 8 and 9?
*/
#include <iostream>
#include <algorithm>
#include <chrono>
int main()
{
    auto t0 = std::chrono::high_resolution_clock::now();
    int myints[] = {0,1,2,3,4,5,6,7,8,9};
    std::sort(myints, myints+10);
    std::cout << "The 10! possible permutations with elements:\n";
    long long i = 0;
    do{
        if(++i == 1000000) break;
    }while(std::next_permutation(myints, myints+10));
    std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] <<  ' ' << 
    myints[3] << ' ' << myints[4] << ' ' << myints[5] << ' ' <<
    myints[6] << ' ' << myints[7] << ' ' << myints[8] << ' ' <<
    myints[9] << std::endl;

    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Time addition(ms): " << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << std::endl;
}

// int millionth = 1000000;

// int main() {
//     int a[10] = {0,1,2,3,4,5,6,7,8,9};
//     int k , l;
//     int tmp;
//     for(int n = 2; n <= millionth; n++)
//     {
//         k = 0;
//         for(int i = 0; i < 10 - 1; i++)
//         {
//             if(a[i] < a[i+1])
//             {
//                 k = i;
//             }
//         }
//         l = 0;
//         for(int i = 0; i < 10; ++i)
//         {
//             if(a[k] < a[i])
//             {
//                 l = i;
//             }
//         }
//         tmp = a[k];
//         a[k] = a[l];
//         a[l] = tmp;

//         for(int i = k + 1, j = 9; i < j; i++, j--)
//         {
//             tmp = a[i];
//             a[i] = a[j];
//             a[j] = tmp;
//         }
//     }
//     for(int i = 0; i < 10; i++)
//     {
//         std::cout << a[i];
//     }
// }