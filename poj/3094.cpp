#include <iostream>
using namespace std;

string s;
int main()
{
	while (getline(cin, s))
	{
		if (s == "#")break;
		int sum = 0;
		for (int i = 0; s[i]; ++ i)
		{
			if (s[i] == ' ')	
				continue;
			else 
				sum += (i + 1) * (s[i] - 'A' + 1);
		}
		cout << sum << endl;
	
	
	
	}





	return 0;
}
