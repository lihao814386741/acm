#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int>v;

	v.push_back(0);
	v.push_back(1);
	for (int i = 2; i < 50; i ++)
	{
		v.push_back(v[i - 1] + v[i - 2]);
	}

	while (cin >> n)
	{
		cout << v[n] << endl;
	
	
	
	}





	return 0;
}
