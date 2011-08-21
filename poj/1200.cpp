#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
using namespace std;
#define MAX_STRING 16000010
bool hash[MAX_STRING] = {false};

char s[MAX_STRING];
int main()
{
	int n, nc;
	int ascii[128];
	while (scanf("%d %d", &n, &nc) != EOF) 
	{
        memset(hash,0,sizeof(hash));
		memset(ascii,0,sizeof(ascii));

		scanf("%s", s);
		
		int count = 1;
		for (int i = 0; s[i] && count <= nc; i ++)
		{
			if (!ascii[s[i]])
			{
				ascii[s[i]] = count;
				count ++;
			}
		}
			int len = strlen(s) - n + 1;

			int p = pow(nc, 1.0 * ( n - 1)) + 1e-8;

			int counti = 0;
			int sum = 0;
			for (int i = 0; i < n; i ++)
			{
				sum = sum * nc + ascii[s[i]] - 1;
			}
			for (int i = 0;; i ++)
			{
				if (!hash[sum])
				{
					hash[sum] = true;
					counti ++;
				}
				if (i >= len - 1)
				{
					break;
				}

				sum -= p * (ascii[s[i]] - 1);
				sum *= nc;
				sum += ascii[s[i + n]] - 1;
			}


		
			printf("%d\n", counti);	
	
	
	
	
	
	
	
	}




	return 0;
}
