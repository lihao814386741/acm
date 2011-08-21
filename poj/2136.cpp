#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string letter;
	int count[256] = {};

	for (int i = 0; i < 4; ++ i)
	{
		getline(cin, letter);
		for (int j = 0; letter[j]; ++ j)
		{
			count[letter[j]] ++;
		}
	}
	int max = 0;

	for (int i = 'A'; i <= 'Z'; ++ i )
		max = max > count[i] ? max : count[i];
	for (int i = 0; i < max; ++ i)
	{
		string output = "";
		for (int j = 'A'; j <= 'Z'; ++j)
		{
			if (max - count[j] <= i)
				output += "*";
			else 
				output += " ";
	 		output += " ";
		}
		int pos;
		for (int j = 0; output[j];  ++ j)
			if (output[j] == '*')
				pos = j;
		for (int j = 0; j <= pos; ++ j)
			cout << output[j];
		cout << endl;
	}
	cout << "A";
	for (char i = 'B'; i <= 'Z'; ++ i)
		cout << " " << i;
	cout << endl;




	return 0;
}


