/**
 * A palindromic number reads the same both ways.
 * The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <iostream>
#include <cstdlib>
#include <cstring>

bool isPalindrome(int value)
{
    std::string str = std::to_string(value);
    int len = str.length();
    for(int i = 0; i < len / 2; ++i)
    {
        if(str[i] != str[len - i - 1])
        {
            return  false;
        }
    }
    return true;
}
int main()
{
    int palindrome = 0;
    for(int i = 100; i < 1000; ++i)
    {
        for(int j = 100; j < 1000; ++j)
        {
            int value = i * j;
            if(isPalindrome(value))
            {
                if(value > palindrome)
                {
                    palindrome = value;
                }
            }
        }
    }
    std::cout << palindrome;
    return  0;
}