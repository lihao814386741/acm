#include <iostream>
#include <set>
using namespace std;


int main()
{
	int f12 = 1;

	for (int i = 1; i <= 12; i ++)
	{
		f12 *= i;
	}
	int num = 0;
	int n;
	multiset<int> s;

	while (cin >> n)
	{
		if (f12 % n == 0)
		{
			multiset<int>::iterator it = s.find(f12 / n);
			if (it != s.end())
			{
				num ++;
				s.erase(it);
			}
			else 
			{
				s.insert(n);
			}
		}
	}
	cout << num << endl;

	



	return 0;
}
