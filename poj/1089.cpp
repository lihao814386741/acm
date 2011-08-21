#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Num{
	int left;
	int right;
};
vector<Num> list;

bool cmp(const Num &s1, const Num &s2)
{
	return s1.left != s2.left ? s1.left < s2.left : s1.right < s2.right;
}

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i ++)	
		{
			Num temp;
			cin >> temp.left;
			cin >> temp.right;
			list.push_back(temp);
		}
		sort(list.begin(), list.end(), cmp);

		int start, end;
		
		start = list[0].left, end = list[0].right;
		
		for (int i = 1; i < n; i ++)
		{
				if (list[i].left > end)	
				{
					cout << start << " " << end << endl;
					start = list[i].left;
					end = list[i].right;
				}
				else 
				{
					end = list[i].right > end ? list[i].right : end;
				
				}
		}

		cout << start << " " << end << endl;	
	
	
	
	}





	return 0;

}
