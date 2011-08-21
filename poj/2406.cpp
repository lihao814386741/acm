#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pi[1000005];
void count(char s[]);
int main()
{	
	char s[1000005];
	while(scanf("%s", s) != EOF)
	{
		if (strcmp(s, ".") == 0)break;
		
		count(s);
		int length = strlen(s);
		int len = length  - 1  - pi[length - 1];

		if (length % len == 0)
		{
			printf("%d\n", length / len);
		}
		else 
		{			
			printf("1\n");
		}

		
	}


	return 0;
}
void count(char s[])
{
	pi[0] = -1;
	int j  = -1;
	for(int i = 1; s[i] ; i++)
	{
		while (j >= 0 && s[j + 1] != s[i]) j = pi[j];

		if (s[j + 1] == s[i]) j++;

		pi[i] = j;
	}

}
