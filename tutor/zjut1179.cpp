#include <iostream>
using namespace std;


int main()
{
	int n;

	cout.precision(3);
	while (cin >> n)
	{
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			sum += temp;
		}

		cout << fixed << sum / n << endl;
	
	}



	return 0;
}
