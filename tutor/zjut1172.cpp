#include <iostream>
using namespace std;

int main()
{

	int len1 = 100 / 3;
	int len2 = 100 / 2;
	
	for (int i = 0; i <= len1 ; i++)
	{
		for (int j = 0; j <= len2; j++)
		{
			int len3 = (100 - i * 3 - j * 2) * 3;
			if (len3 + i + j == 100)
			{
				cout << i << " " << j << " " << len3 << endl;
			}
		
		
		
		}
	
	
	
	}






	return 0;
}
