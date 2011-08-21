#include <iostream>
using namespace std;

int main()
{	
	string s;
	while (getline(cin, s))
	{
		if (s == "#")
			break;
		for (int i = 0; s[i]; ++ i)
		{
			if (s[i] == ' ')
				cout << "%20";
			else if (s[i] == '!')
				cout << "%21";
			else if (s[i] == '$')
				cout << "%24";
			else if (s[i] == '%')
				cout << "%25";
			else if (s[i] == '(')
				cout << "%28";
			else if (s[i] == ')')
				cout << "%29";
			else if (s[i] == '*')
				cout << "%2a";
			else 
				cout << s[i];
		}
		cout << endl;
	
	
	
	
	}

	
}
