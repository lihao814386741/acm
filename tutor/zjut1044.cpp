#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct binstring{
	string name;
	int number;
};
bool cmp(const binstring &s1, const binstring &s2)
{
	return s1.number < s2.number;
}
int main()
{
	vector<binstring> list;
	binstring temp;
	while (cin >> temp.name)
	{
		temp.number = count(temp.name.begin(), temp.name.end(), '1');
		list.push_back(temp);	
	}

	sort(list.begin(), list.end(), cmp);

	for (vector<binstring>::iterator it = list.begin(); it != list.end(); it ++)
	{
		cout << (*it).name << endl;
	
	}




	return 0;
}
