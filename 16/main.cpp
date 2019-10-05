#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string valueStr = "32768"; // 2^15
	string tempStr = "";
	int sum = 0;
	unsigned carry = 0;
	for (int i = 16; i <= 1000; i++)
	{
		int len = valueStr.length();
		tempStr.clear();
		stringstream ss;
		unsigned val = 0;
		for (int j = len - 1; j >= 0; --j)
		{
			ss.clear();
			val = 0;

			ss << valueStr[j];
			ss >> val;

			val = val * 2 + carry;
			if (val >= 10)
			{
				tempStr = to_string(val - 10) + tempStr;
				carry = 1;
			}
			else
			{
				tempStr = to_string(val) + tempStr;
				carry = 0;
			}
			//cout << "valueStr" << val << "temStr" << tempStr << endl;
		}
		if (carry == 1)
		{
			valueStr = "1" + tempStr;
			carry = 0;
		}
		else
		{
			valueStr = tempStr;
		}
	}
	
	for (int i = 0; i < valueStr.length(); ++i)
	{
		stringstream ss;
		ss.clear();
		unsigned val = 0;
		ss << valueStr[i];
		ss >> val;

		sum += val;
	}
	cout << "sum: " << sum << endl;

	return 0;
}