#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{

	int n;
	cin >> n;
	for (int z = 0; z < n;  z++)
	{
		int number;
		cin >> number;
		vector<int> list;
		bool isyes = true;

		for (int i = 0; i < number; i ++)
		{
			int temp;
			cin >> temp;
			list.push_back(temp);
		}
		if (number >= 2)
		{
			sort(list.begin(), list.end());
			int diff = list[1] - list[0];
			for (int i = 0; i < number - 1; i++)
			{
				if (diff != list[i + 1] - list[i])
				{
					isyes = false;
					break;
				}
				
			}
		}
		if (isyes)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	
	}





	return 0;
}
