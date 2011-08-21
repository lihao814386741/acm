#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
struct cmp{
	bool operator() (const string &s1, const string &s2)
	{
		if (s1.length() != s2.length())
		{
			return s1.length() < s2.length();
		}
		int c1 = count(s1.begin(), s1.end(), '1');
		int c2 = count(s2.begin(), s2.end(), '1');
		if (c1 != c2)
		{
			return c1 < c2;
		}
		return s1 < s2;
	
	}

};

int main()
{	
	multiset<string, cmp> ms;

	string s;

	while (cin >> s)
	{
		ms.insert(s);
	}
	
	for (multiset<string,cmp>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << endl;
	}


	return 0;
}
