#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	char str[1024];
	while (gets( str) != NULL)
	{
	if (strcmp(str, "END") == 0)
	{
		break;
	}
	for (char *c = str; *c != 0; c++)
	{
		if (*c == 'A' || *c == 'W' || *c == 'F')
		{
			cout << 'I';
		}
		else if (*c == 'D' || *c == 'P' || *c == 'G' || *c == 'B')
		{
			cout << 'e';
		}
		else if (*c == 'C')
		{
			cout << 'L';
		}
		else if (*c == 'M')
		{
			cout << 'o';
		}
		else if (*c == 'S')	
		{
			cout << 'v';
		}	
		else if (*c == 'L')
		{
			cout << 'Y';
		}
		else if (*c == 'X')
		{
			cout << 'u';
		}
		else 
		{
			cout << *c;
		}
	}
	cout << endl;
	}




	return 0;
}
