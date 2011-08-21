#include <iostream>
using namespace std;
#define NUM 47
int main()
{
	unsigned f[NUM];
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i < NUM; i ++)
		f[i] = f[i - 1] + f[i - 2];
	int n;
	while (cin >> n)
	{
		cout << f[n] << endl;
	}




}
