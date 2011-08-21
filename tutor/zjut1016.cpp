#include <iostream>
using namespace std;


int array[1024][1024];

int main()
{
	int n;
	cin >> n;

	for (int z = 0; z < n; z ++)
	{
		int huge;
		cin >> huge;
		for (int i = 0; i < huge; i++)
		{
			for (int j = 0; j < huge; j++)
			{
				cin >> array[i][j];
			}
		}

		bool isright = true;
		int len = huge / 2;
		for (int i = 0; i < huge ; i ++)
		{
			for (int j = 0; j < len; j ++)
			{
				if (array[i][j] != array[i][huge - 1 - j])
				{
					isright = false;
					break;
				}
			
			}
			if (!isright)
			{
				break;
			}
		
		}
		for (int i = 0; i < len; i ++)
		{
			for (int j = 0; j < huge; j ++)
			{
				if (array[i][j] != array[huge - 1 - i][j])
				{
					isright = false;
					break;
				}
				
			}
			if (!isright)
			{
				break;
			}
		}
		if (isright)
		{
			cout << "yes" << endl;
		}
		else 
		{
			cout << "no" << endl;
		}
	
	
	
	}



	return 0;
}

