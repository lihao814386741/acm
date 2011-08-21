#include <iostream>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		for (int i = 0; s[i] != 0; i ++)
		{
			if (s[i] == '0')cout << '1' ;
			else if (s[i] == '1') cout << '0';
		}
		cout << endl;
	
	}


}
