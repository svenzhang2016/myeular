#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;

string sum(const string& left, const string& right) noexcept
{
	int tail = 0;
	string ans;
	bool leftEnd = false;
	bool rightEnd = false;
	auto leftIndex = left.length() - 1;
	decltype(leftIndex) rightIndex = right.length() - 1;

	auto sum = [&tail](int first, int second)
	{
		int temp = first + second + tail;
		tail = 0;
		if (temp > 9)
		{
			tail = temp / 10;
		}
		return static_cast<char>(temp % 10 + '0');
	};

	while (!leftEnd || !rightEnd)
	{
		if (leftEnd && !rightEnd)
		{
			ans = sum(0, right[rightIndex] - '0') + ans;
			if (rightIndex == 0)
			{
				rightEnd = true;
			}
			else
			{
				rightIndex--;
			}
		}
		else if (!leftEnd && rightEnd)
		{
			ans = sum(left[leftIndex] - '0', 0) + ans;
			if (leftIndex == 0)
			{
				leftEnd = true;
			}
			else
			{
				leftIndex--;
			}
		}
		else
		{
			ans = sum(left[leftIndex] - '0', right[rightIndex] - '0') + ans;
			if (leftIndex == 0)
			{
				leftEnd = true;
			}
			else
			{
				leftIndex--;
			}

			if (rightIndex == 0)
			{
				rightEnd = true;
			}
			else
			{
				rightIndex--;
			}
		}
	}

	if (tail > 0)
	{
		ans = static_cast<char>(tail + '0') + ans;
	}
	return ans;
}

int main()
{
	string ans = "0";
	ifstream in("./data.txt");
	string temp;
	while (getline(in, temp))
	{
		ans = sum(ans, temp);
	}
	in.close();
	cout << ans.substr(0, 10) << endl;
	return 0;
}