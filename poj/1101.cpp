#include <iostream>
#include <stdio.h>
#include <queue>
#define NUM 80
using namespace std;

int direct[2][4] = 
{
{ 0, 1,-1, 0},
{-1, 0, 0, 1}
};
struct Direct{
	bool isbegin;
	int x;
	int y;
	int directx;
	int directy;
	int segment;
};
char status[NUM][NUM];
bool isvisited[NUM][NUM];
int width, height;
int bfs(int x1, int y1, int x2, int y2);
int main()
{
	int test_case = 0;
	while (cin >> width >> height)
	{
		test_case ++;
		if (!width && !height)
		{
			break;
		}

		for (int i = 0; i <= height + 1; i ++)
		{
			for (int j = 0; j <= width + 1; j ++)
			{
				status[i][j] = ' ';
			}
		}
		getchar();
		for (int i = 1; i <= height; i++)
		{
			for (int j = 1; j <= width; j++)
			{
				char c;
				c = getchar();
				if (c == 'X')
				{
					status[i][j] = 'X';
				}
				else 
				{
					status[i][j] = ' ';
				}
//				cout << c << " " << i << " " << j << endl;
			}
			getchar();
		}

		

		int x1, y1, x2, y2;
	
		cout << "Board #" << test_case << ":" << endl;
		int pair_case = 0;
		while (cin >> x1 >> y1 >> x2 >> y2)
		{
			pair_case ++;
			if(!x1 && !y1 && !x2 && !y2)
			{
				break;
			}

			for (int i = 0; i <= height + 1; i ++)
			{
				for (int j = 0; j <= width + 1; j ++)
				{
					isvisited[i][j] = false;
				}
			
			}
			int path = bfs(y1, x1, y2, x2);
			if (path != -1)
			{
				cout << "Pair " << pair_case << ": " << path <<" segments." << endl;
			}
			else 
			{
				cout << "Pair " << pair_case << ": impossible." << endl;
			}

				
		
		
		
		}
	
		cout << endl;	
	
	
	}

	return 0;
}
int bfs(int x1, int y1, int x2, int y2)
{
	Direct postion;
	postion.x = x1;
	postion.y = y1;
	postion.isbegin = true;
	postion.segment = 0;
	queue<Direct> list;
	list.push(postion);
	int ans = -1;

	while (list.empty() != true)
	{
		Direct temp;
		temp = list.front();
		if (temp.x == x2 && temp.y == y2)
		{
			if (temp.segment < ans || ans == -1)
			{
				ans = temp.segment;
			}
		}

		list.pop();
		if (status[temp.x][temp.y] == 'X' && temp.isbegin != true)
		{
			continue;
		}
		if (isvisited[temp.x][temp.y] == true)
		{
			continue;
		}
		isvisited[temp.x][temp.y] = true;

	//	cout << temp.x << " " << temp.y << endl;	
		bool flag = false;

		if (!temp.isbegin)
		{
			Direct temptemp3;	
			if ((temp.x + temp.directx >= 0 && temp.x + temp.directx <= height + 1) && (temp.y + temp.directy >= 0 && temp.y + temp.directy <= width + 1) )
			{
				temptemp3.x = temp.x + temp.directx;
				temptemp3.y = temp.y + temp.directy;
				temptemp3.isbegin = temp.isbegin;
				temptemp3.directx = temp.directx;
				temptemp3.directy = temp.directy;
				temptemp3.segment = temp.segment;
			}
				list.push(temptemp3);
			flag = true;
		
		
		
		}
		for (int i = 0; i < 4; i++)
		{
			if (flag && temp.directx == direct[0][i] && temp.directy == direct[1][i])
			{
				continue;
			}
			Direct temptemp;	
			if ((temp.x + direct[0][i] >= 0 && temp.x + direct[0][i] <= height + 1) && (temp.y + direct[1][i] >= 0 && temp.y + direct[1][i] <= width + 1) )
			{
				temptemp.x = temp.x + direct[0][i];
				temptemp.y = temp.y + direct[1][i];
				temptemp.isbegin = temp.isbegin;
				temptemp.directx = temp.directx;
				temptemp.directy = temp.directy;
				temptemp.segment = temp.segment;
			}
			else
			{
				continue;
			}
			if (temptemp.isbegin)
			{
				temptemp.isbegin = false;
				temptemp.directx = direct[0][i];
				temptemp.directy = direct[1][i];
				temptemp.segment = 1;
			}
			else 
			{
				if (temptemp.directx == direct[0][i] && temptemp.directy == direct[1][i])
				{
					;
				}
				else 
				{
					temptemp.segment ++;
					temptemp.directx = direct[0][i];
					temptemp.directy = direct[1][i];
				}
			}
			list.push(temptemp);
		}	
	}
	return ans;

}
