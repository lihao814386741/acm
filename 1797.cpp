#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 0x3fffffff;
int dis[1010][1010];
int main()
{
	int test_case;
	cin >> test_case;
	for (int z = 0; z < test_case; ++ z)
	{
		cout << "Scenario #" << z + 1 << ":" << endl;
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < n; ++ j)
				dis[i][j] = inf;
		for (int i = 0; i < m; ++ i)
		{
			int temp1, temp2, temp3;
			scanf("%d %d %d", &temp1, &temp2, &temp3);
			dis[temp1 - 1][temp2 - 1] = dis[temp2 - 1][temp1 - 1] = temp3;
		}
		for (int k = 0; k < n; ++ k)
			for (int i = 0;i < n; ++ i)
				for (int j = 0; j < n; ++ j)	
				{
					int min = dis[i][k] > dis[k][j] ? dis[k][j] : dis[i][k];
					if (dis[i][j] != inf && min != inf && min > dis[i][j])
						dis[i][j] = min;
				}
		
		printf("%d\n", dis[0][n - 1]);

	
	
	
	
	
	}
	



	return 0;
}
