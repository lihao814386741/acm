#include <iostream>
#include <cstring>
using namespace std;
int change(int n)
{
	if(n & 1) return (n + 1) >> 1;
	else return n >> 1;

}

int main()
{
	int  test_case;
	int room[410];
	while (cin >> test_case)
	{
		while (test_case --)
		{
			memset(room, 0, sizeof(room));
			int n;
			cin >> n;
			for (int i = 0; i < n; ++ i)
			{
				int temp1, temp2;
				int temp;
				cin >> temp1 >> temp2;
				if (temp1 > temp2)temp = temp1, temp1 = temp2, temp2 = temp;
			int 	min = change(temp1);
			int	ma = change(temp2);
				for (int j = min; j <= ma; ++ j)
				{
					++ room[j];
				}
			}
			int max = 0;
			for (int i = 0; i < 410; ++ i)
			{
				max = max >= room[i] ? max : room[i];
			}
			cout << max * 10 << endl;
		
		
		
		
		}

	
	
	
	
	
	
	
	}







	return 0;
}
