#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
using namespace std;
#define PRIME_NUM 65538
int prime[PRIME_NUM];

bool judge_prime(int n)
{
	if (n % 2 == 0 && n != 2) 
	{
		return false; 
	}
	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
		{
			return false;
		}
	
	}


	return true;
}
bool judge_pal(int n)
{
	if ((n >= 100 && n < 1000) && ((n % 10) == (n /100)))
	{
		return true;
	}
	return false;
}
int main()
{
	int n;
	 
	while (cin >> n)
	{
		if (judge_prime(n) && judge_pal(n))
		{
			cout << "Yes" << endl;
		}
		else 
		{
			cout << "No" << endl;
		}
	
	}



	return 0;
}
