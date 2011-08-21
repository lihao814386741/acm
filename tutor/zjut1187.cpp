#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int prime_num = 65537;
int prime[prime_num];
bool judgeprime[65538] = {false};
void init()
{
	prime[0] = 2;
	int x = 1;
	judgeprime[2] = true;
	

	for (int i = 3; i <= prime_num; i += 2)
	{
		bool isprime = true;
		for (int j = 0; j < x; j ++)
		{
			if (i % prime[j] == 0)
			{
				isprime = false;
				break;
			}
		}
		
		if (isprime)
		{
			judgeprime[i] = true;
//			cout << i << endl;
			prime[x] = i;
			x ++;
		}
	}
}

bool isprim(int n)
{
	if (n <= prime_num)
	{
		return judgeprime[n];
	}
	int len = sqrt(n) + 1e-8;

	for (int i = 0; prime[i] <= len; i++)
	{
		if (n % prime[i] == 0)
		{
			return false;
		}
	}
	return true;

}
bool ispal(int n)
{
	string temp = "";
	char temptemp[10];
	sprintf(temptemp, "%d", n);
	for (int i = 0; temptemp[i] != 0; i++)
	{
		temp += temptemp[i];
	}
	
	reverse(temp.begin(), temp.end());
	
//	cout << temptemp << " " << temp.c_str()  << endl;
//	cout << (strcmp(temptemp, temp.c_str()) == 0) << endl;
	if (strcmp(temptemp, temp.c_str()) == 0 && n < 100000)
	{
		return true;
	}
	return false;
}

int main()
{
	int n;
	init();
	while (cin >> n)
	{
		if (n < 100000 && ispal(n) && isprim(n))
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
