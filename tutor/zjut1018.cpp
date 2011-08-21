#include <iostream>
using namespace std;


int main()
{
	int test_case;

	cin >> test_case;

	for (int z= 0; z < test_case; z++)
	{
		double R;
		int I;
		cin >> R >> I;
		int a = R + 1e-8;
		bool iscorrect = false;
		if (R + 1e-8 - a >= 0.5)
		{
			if (a + 1 == I)
			{
				iscorrect = true;
			}
		}
		else 
		{
			if (a == I)
			{
				iscorrect = true;
			}
		
		}
		if (iscorrect)
		{
			cout << "Correct" << endl;
		}
		else
		{
			cout << "Not Correct" << endl;
		}

	
	
	
	
	}




	return 0;

}
