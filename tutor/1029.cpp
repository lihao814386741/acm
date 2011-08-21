#include <iostream>
#include <cmath>

using namespace std;
int get_fibonacci(int i)
{
	double sqrt5 = sqrt(5.0);
	return (pow(1.0 + sqrt5 / 2, i) - pow(1.0 - sqrt5 / 2, i)) / sqrt5 + 1e-8;
}




int main()
{



	return 0;
}
