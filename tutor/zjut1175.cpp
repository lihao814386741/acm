#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int n;
	double q, sum;
	cout.precision(3);
	
	while (cin >> n >> q)
	{
		if (q == 1)
		{
			sum = 1 + n;
		}
		else 
		{
			sum = (1 - pow(q, n + 1)) / (1 - q);
		}
		cout << fixed << sum << endl;
	
	
	}





	return 0;	
}



