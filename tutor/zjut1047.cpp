#include <cstdio>

using namespace std;

int main()
{
	int c; 
	while ((c = getchar()) != EOF)
	{
		if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';
		else if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
		putchar(c);
	}


	return 0;
}
