#include <iostream>
using namespace std;

string s;

int main()
{
	while (cin >> s)
	{
		if (s == "0")break;
		int sum = 0;
		int bin = 1;
		for (int i = s.length() - 1; i >= 0; -- i)
		{
			bin <<= 1;
			sum += (bin - 1) * (s[i] - '0');
		}
		cout << sum << endl;
	
	
	
	}




	return 0;
}
