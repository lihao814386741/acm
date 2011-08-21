#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	string::iterator it;

	while (cin >> s)
	{
		int max = 0;

		for (int i = 0; s[i] != 0; i ++)
		{
			int len;
			for (len = 0; i - len >= 0 && i + len < s.length(); len ++)
			{
				if (s[i - len] != s[i + len])
				{
					break;
				}
			}	
//			cout << "len * 2 + 1:" << len * 2 + 1 << endl ;
			if ((len - 1) * 2 + 1 > max)
			{
				max = (len - 1) * 2  + 1;
			}
		}
//		cout << "s.length():" << s.length() << endl;
		for (int i = 0; s[i] != 0; i ++)
		{
			int len;
			for ( len = 1; i - len + 1 >= 0 && i + len < s.length(); len ++)
			{
//					cout << "s[i - len + 1] s[i + len]:" << s[i - len + 1] << " " << s[i + len] << endl;
				if (s[i - len + 1] != s[i + len])
				{
//					cout << "LEN:" << len << endl;
					break;
				}
			}
//			cout << "len * 2:" << len * 2 << endl;
			if ((len - 1) * 2 > max)
			{
				max = (len - 1) * 2;
			
			}
		
		
		}
	
		cout << max << endl;
	
	}






	return 0;
}
