#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
	getchar();
		if (!m && !n)
		{
			break;
		}
		char c;
		int count = 0;
		for (int i = 0; i < m; i ++)
		{
			for (int j = 0; j < n; j ++)
			{
				c = getchar();
				if (c == '*')
				{
					count ++;
				}
			}
			getchar();
		
		}
		cout << count << endl;
	
	}



}
