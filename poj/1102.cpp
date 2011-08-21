#include <iostream>
using namespace std;
string firstdrawer = "- -- -----";
string seconddrawer = "|   ||| ||";
string thirddrawer = "|||||  |||";
string fourthdrawer = "  ----- --";
string fifthdrawer = "| |   | | ";
string sixthdrawer = "|| |||||||";
string seventhdrawer = "- -- -- --";
void drawer(int n, char c)
{
	for (int i = 0; i < n; i ++)
	{
		cout << c ;
	}
}

int main()
{
	int n;
	string s;
	while (cin >> n >> s)
	{
		{
		int size;
		for ( size = s.length() - 1; size >= 0; size--)
		{
				if (s[size]!='1' && s[size] != '4')		
				break;
		}
		if (size != -1)
		{
		cout << " ";
		drawer(n, firstdrawer[s[0] - '0']);
		cout << " ";
		}

		for (int i = 1;  i <= size; i ++)
		{
			cout << " ";
			cout << " ";
			drawer(n, firstdrawer[s[i] - '0']);
			cout << " ";
		}
		}
		cout << endl;

		{
		for (int i = 0; i < n; i ++)
		{
			cout << seconddrawer[s[0] - '0'];
			drawer(n, ' ');
			cout << thirddrawer[s[0] - '0'];

			for (int i = 1; s[i] != 0; i ++)
			{
				cout << " ";
				cout << seconddrawer[s[i] - '0'];
				drawer(n, ' ');
				cout << thirddrawer[s[i] - '0'];
			}	
			cout << endl;
		}
		}
		
		{
		int size;
		for ( size = s.length() - 1; size >= 0; size--)
		{
				if (s[size]!='1' && s[size] != '7' && s[size] != '0')		
				break;
		}
		if (size != -1)	
		{
			cout << " ";
			drawer(n, fourthdrawer[s[0] - '0']);
			cout << " ";
		}
			for (int i = 1; i <= size; i ++)
			{
				cout << " ";
				cout << " ";
				drawer(n, fourthdrawer[s[i] - '0']);
				cout << " ";
			}
			cout << endl;
		}

		{
			for (int i = 0; i < n; i ++)
			{
				cout << fifthdrawer[s[0] - '0'];
				drawer(n, ' ');
				cout << sixthdrawer[s[0] - '0'];

				for (int i = 1; s[i] != 0; i ++)
				{
					cout << " ";
					cout <<fifthdrawer[s[i] - '0'];
					drawer(n, ' ');
					cout << sixthdrawer[s[i] - '0'];
				}
				cout << endl;
			}
		}

		{

		int size;
		for ( size = s.length() - 1; size >= 0; size--)
		{
				if (s[size]!='1' && s[size] != '4' && s[size] != '7')		
				break;
		}
		if (size != -1)
		{
			cout << " ";
			drawer(n, seventhdrawer[s[0] - '0']);
			cout << " ";
		}
			for (int i = 1; i <= size; i ++)
			{
				cout << " ";
				cout << " ";
				drawer(n, seventhdrawer[s[i] - '0']);
				cout << " ";
			}
		
			cout << endl;
		
		}
		cout << endl;
	}



}
