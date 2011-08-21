#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
struct postion{
	int x;
	int y;
}pos[256];
int dis[256][256];
int main()
{

	int n;
	int count = 0;
	while (cin >> n && n)
	{
		++ count;
		for (int i = 0; i < n; ++ i)
		{
			cin >> pos[i].x >> pos[i].y;
		}
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < n; ++ j)
				dis[i][j] = (pos[i].x - pos[j].x) * (pos[i].x - pos[j].x) + (pos[i].y - pos[j].y) * (pos[i].y - pos[j].y);
		for (int k = 0; k < n; ++ k)
			for (int i = 0; i < n; ++ i)
				for (int j = 0; j < n; ++ j)
				{
					int max = dis[i][k] > dis[k][j] ? dis[i][k] : dis[k][j];
					if (max < dis[i][j])
						dis[i][j] = max;
				}
		printf("Scenario #%d\n", count);

		printf("Frog Distance = %.3f\n\n", sqrt(dis[0][1]));
		
	
	}



	return 0;
}
