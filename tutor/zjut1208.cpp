#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct cmp
{
	bool operator()(const string &s1, const string &s2)
	{
		return s1.length() != s2.length()? s1.length() < s2.length() : s1 < s2;
	}


};
bool ispal(string s)
{
	string temp = s;
	reverse(s.begin(), s.end());
//	cout << s << " " << temp << " " << (s.compare(temp) == 0)<< endl;
	if (s.compare(temp) == 0)
	{
		return true;
	}
	return false;


}

int main()
{
	string s;
	multiset<string, cmp> ms;

	while (cin >> s)
	{
		if (ispal(s))
		{
			ms.insert(s);
		}
	}
	for (multiset<string, cmp>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << endl;
	}
	
	return 0;
}
