#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{

	ifstream file("./data.txt");
	string line;

	int n = 15;
	int** data;
	data = new int* [n];

	int i = 0;
	int j;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			data[i] = new int[i + 1];
			stringstream ss(line);
			j = 0;
			while (ss >> data[i][j])
			{
				j++;
			}
			++i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << setw(2) << data[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (data[i + 1][j] > data[i + 1][j + 1])
			{
				data[i][j] = data[i][j] + data[i + 1][j];
			}
			else
			{
				data[i][j] = data[i][j] + data[i + 1][j + 1];
			}
		}
	}
	cout << "max value:" << data[0][0] << endl;

	for (int i = 0; i < n; ++i)
	{
		delete[] data[i];
	}
	delete[] data;

	return 0;
}