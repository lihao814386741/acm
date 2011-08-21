#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#define STRING_NUM 128
using namespace std;

int main()
{
	int test_case;
	string s;
	cin >> test_case;

	for (int z = 0;  z < test_case; z ++)
	{
		bool isbegin = false;
		bool isyes = false;
		while (getline(cin, s))
		{
			if (s.compare("#Doc") == 0)
			{
				isbegin = true;
			}
			else if (s.compare("#End") == 0) 
			{
				break;
			}
			if (isbegin)
			{
				transform(s.begin(), s.end(), s.begin(), ::tolower);
				if (s.find("animate") != string::npos)
				{
					isyes = true;
				}
			}
		}
		if (isyes)
		{
			cout << "Yes" << endl;
		}
		else 
		{
			cout << "No" << endl;
		}
	
	
	
	}





	return 0;
}
