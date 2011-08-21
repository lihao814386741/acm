#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (!n)
		{
			cout << "          0-->0" << endl;
			continue;
		}
		
		cout.width(11);
		cout << n << (n > 0 ? "-->" : "-->-") ;
		string s;
		s = "";

		for (int i = n; i; i /= 2)
		{
			s += i % 2 == 0? "0" : "1";
		}
		reverse (s.begin(), s.end());
		cout << s << endl;

	
	
	
	}







	return 0;
}
