#include <iostream>
#include <queue>
#define NUM 128
using namespace std;
int status[NUM][NUM];
int count[NUM][NUM];
int direct[2][4] = {
{0, 0, 1, -1},
{1, -1, 0, 0}
};
int r, c;
struct pos
{
	int dis;
	int x;
	int y;
};
int bfs(int x, int y)
{
	queue<pos> list;
	pos temp;

	temp.x = x, temp.y = y;
	temp.dis = 1;
	list.push(temp);
	int ans = 1;
	while (!list.empty())
	{
		temp = list.front();
		list.pop();
//		cout << temp.x << " " << temp.y << endl;
		for (int i = 0; i < 4; i ++)
		{
			pos temptemp;
			if (temp.x + direct[0][i] >= 0 && temp.x + direct[0][i] <= r - 1 && temp.y + direct[1][i] >= 0 && temp.y + direct[1][i] <= c - 1)
			{
				temptemp.x = temp.x + direct[0][i];
				temptemp.y = temp.y + direct[1][i];
				temptemp.dis = temp.dis;
			}
			else 
			{
				continue;
			}
			if (status[temptemp.x][temptemp.y] < status[temp.x][temp.y])
			{
				if (count[temptemp.x][temptemp.y] != -1)
				{
					temptemp.dis += count[temptemp.x][temptemp.y];
					if (temptemp.dis > ans)
					{
						ans = temptemp.dis;
					}
				}
				else 
				{
					temptemp.dis ++;
					if (temptemp.dis > ans)
					{
						ans = temptemp.dis;
					}
					list.push(temptemp);
					
				}
			}

		
		}
	
	
	
	}

	return ans;


}
int main()
{
	while (cin >> r >> c)
	{
		for (int i = 0; i < r; i ++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> status[i][j];
				count[i][j] = -1;
			}
		}
		int ans = 0;

		for (int i = 0; i < r; i ++)
		{
			for (int j = 0; j < c; j ++)
			{
				int temp = bfs(i, j);
				count[i][j] = temp;
//				cout << "temp" <<temp << endl;

				ans = ans < temp ? temp : ans;
			}
		}
		cout << ans << endl;
	
	
	}



	return 0;
}
