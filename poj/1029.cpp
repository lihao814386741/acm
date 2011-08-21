#include <iostream>
#include <string>
#include <set>
#define NUM 128

using namespace std;

int main()
{
	int N, K;
	bool judge[NUM];
	int coininleft[NUM];
	int coininright[NUM];

	while (cin >> N >> K)
	{
		for (int i = 0; i <= N; ++ i)
			judge[i] = false;
		set<int> finalleft;
		set<int> finalright;
		for (int i = 0; i < K; ++ i)
		{
			int placenumber;
			cin >> placenumber;
			set<int> left;
			set<int> right;
			set<int> equal;
	
			for (int j = 0; j < placenumber; ++ j)
				cin >> coininleft[j];	
			for (int j = 0; j < placenumber; ++ j)
				cin >> coininright[j];
			string punc;
			cin >> punc;
			if (punc == "<")
			{
				for (int j = 0; j < placenumber; ++ j)
				{
					left.insert(coininleft[j]);
					finalleft.insert(coininleft[j]);
					right.insert(coininright[j]);	
					finalright.insert(coininright[j]);
				}
				for (int j = 1; j <= N; ++ j)
				{
					if (left.find(j) == left.end() && right.find(j) == right.end())
						judge[j] = true;
				}
				for (int j = 0; j < placenumber; ++ j)
				{
					if (finalright.find(coininleft[j]) != finalright.end())
					{
						judge[coininleft[j]] = true;
					}
					if (finalleft.find(coininright[j]) != finalleft.end())
					{
						judge[coininright[j]] = true;
					}
				}
			}
			else if (punc == ">")
			{
				for (int j = 0; j < placenumber; ++ j)
				{
					left.insert(coininright[j]);
					finalleft.insert(coininright[j]);
					right.insert(coininleft[j]);
					finalright.insert(coininleft[j]);
				}
				for (int j = 1; j <= N; ++ j)
				{
					if (left.find(j) == left.end() && right.find(j) == right.end())
						judge[j] = true;
				}
				for (int j = 0; j < placenumber; ++ j)
				{
					if (finalleft.find(coininleft[j]) != finalleft.end())
					{
						judge[coininleft[j]] = true;
					}
					if (finalright.find(coininright[j]) != finalright.end())
					{
						judge[coininright[j]] = true;
					}
				}
			}
			else if (punc == "=")
			{
				for (int j = 0; j < placenumber; ++ j)
				{
					judge[coininright[j]] = true;
					judge[coininleft[j]] = true;
				}
			}
		}
		
		int  count = 0;
		int ans = 0;
		for (int i = 1; i <= N; ++ i)
		{
			if (judge[i] == false)	
			{
				count ++;
				ans = i;
			}
		}
		if (count == 1)
		{
			cout << ans << endl;
		}
		else 
		{
			cout << 0 << endl;
		}
	}

	return 0;
}
