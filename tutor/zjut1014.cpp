#include <iostream>
using namespace std;

int main()
{
	string s;

	while (cin >> s)
	{
		int sum = 0;
		for (int i = 0; s[i] != 0; i ++)
		{
			sum += s[i] - '0';
		}
		cout << sum << endl;
	
	
	}




	return 0;
}
