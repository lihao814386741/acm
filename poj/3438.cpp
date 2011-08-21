#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n --)
	{
		string s;
		cin >> s;
		char last = s[0];
		int count = 1;
		for (int i = 1; s[i]; ++ i)
		{
			if (s[i] == last)
			{
				++ count;

			}
			else 
			{
				cout << count << last ;
				last = s[i];
				count = 1;
			
			}
		
		}
		cout << count << last << endl;
	
	
	}


}
