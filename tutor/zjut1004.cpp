#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int n;
	bool judge_ans[4000] = {false};
	while (cin >> n)
	{
		int temp1, temp2;
		cin >> temp1;
		bool isjolly = true;
		for (int i = 0; i < n; i ++)
		{
			judge_ans[i] = false;
		}
		for (int i = 0; i < n - 1; i++)
		{
			cin >> temp2;
			if (abs(temp2 - temp1) < n && abs(temp2 - temp1) > 0)
			{
				judge_ans[abs(temp2 - temp1)] = true;
			}
temp1 = temp2;
		
		}
			bool istrue = true;
			for (int i = 1; i < n; i ++)
			{
				if (!judge_ans[i])
				{
					istrue = false;
					break;
				}
			}
			if (istrue)
			{
				cout << "Jolly" << endl;
			}
			else 
			{
				cout << "Not jolly" << endl;
			}
	
	
	
	}



}

