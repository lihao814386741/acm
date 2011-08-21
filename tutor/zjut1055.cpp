#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++ i)
		{
			cout << "a";
			for (int j = 0; j < n - i - 1; ++ j)
			{
				cout << " ";
			}
			for (int j = 0; j <= i; ++ j)
			{
				cout << "abcdefghijklmnopqrstuvwxyz"[j];
			}
			cout << endl;
		}
		cout << endl;	
	}



	return 0;
}
