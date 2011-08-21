#include <iostream>
using namespace std;
inline int gcd(int a, int b)
{
	int tmp;
	while (b)tmp = b, b = a % b, a = tmp;
	return a;
}
int main()
{

	int a, b;
	while (cin >> a >> b)
	{
		double c = a;
		cout <<  (int)(c / gcd(a, b) * b + 1e-8) << endl;
	}

	return 0;
}
