#include <iostream>
using namespace std;

int direct[2][8] = {
{-1,-1,-1, 0, 0, 1, 1, 1},
{-1, 0, 1,-1, 1,-1, 0, 1}
};

struct section{
	char status;
	bool isvisited;
};
int count;

section sec[128][128];
int  m, n;
int dfs(int x, int y)
{
	if ((x < 0 || x >= m) && (y < 0 || y >= n))	
	{
		return 0;
	}
	if (sec[x][y].isvisited)
	{
		return 0;
	}
	int sum = 0;
	
	if (sec[x][y].status == '@')
	{
		sum = 1;
	}
	else 
	{
		return 0;
	}

	sec[x][y].isvisited = true;
	for (int i = 0; i < 8; i ++)
	{
		sum += dfs(x + direct[0][i], y + direct[1][i]);
	}
	return sum;
	

}

int main()
{
	while (cin >> m >> n && m)
	{
		for (int i = 0; i < m; i ++)
		{
			for (int j = 0; j < n; j ++)
			{
					cin >> sec[i][j].status;
					sec[i][j].isvisited = false;
			}
		
		}
		int count = 0;
		for (int i = 0; i < m; i ++)
		{
			for (int j = 0; j < n; j ++)
			{
				if (sec[i][j].status == '@' && !sec[i][j].isvisited)				
				{
					int sum = dfs(i, j);
					count++;
				
				}
			}

		}
		cout << count << endl;

	}



	return 0;
}
