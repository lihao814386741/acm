#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct parent{
	char parenthese;
	int pos;
};

int main()
{
	int test_case;
	stack<struct parent> s;
	cin >> test_case;
	while (test_case --)
	{
		int n;
	vector<char> list;
		cin >> n;
		int last = 0;
		for (int i = 0; i < n; ++ i)
		{
			int temp;
			cin >> temp;
			int len = temp - last;
			for (int j = 0; j < len; ++ j)
			{
				list.push_back('(');	
			}
			list.push_back(')');
			last = temp;
		}
		for (int i = 0; list[i]; ++ i)
		{
			if (list[i] == '(')	
			{
				struct parent p;
				p.parenthese = '(';
				p.pos = i;
				s.push(p);
			}
			if (list[i] == ')')
			{
				struct parent p;
				p = s.top();
				int count = 0;
				for (int j = p.pos; j <= i; ++ j)
				{
					if (list[j] == ')')
						++ count;
				}
				if (!list[i + 1])
					cout << count;
				else 
					cout << count << " ";
				s.pop();
			}
		}
	
		cout << endl;
	
		
	
	
	
	
	}






}
