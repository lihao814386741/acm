#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#define COURSE_NUM 16
using namespace std;

struct student{
	string name;
	double score;
};
bool cmp(const student &s1, const student & s2)
{	
	return s1.score != s2.score ? s1.score > s2.score : s1.name < s2.name;
	
}
int main()
{
	int n;
	int course_number;
	int student_number;
	vector<double> score;
	vector<student> list;

	cin >> n;
	for (int z = 0; z < n; z ++)
	{
		cin >> course_number;

		for (int i = 0; i < course_number; i++)
		{
			double temp;
			cin >> temp;
			score.push_back(temp);
		}
		cin >> student_number;
		for (int i = 0; i < student_number; i++)
		{
			student temp;
			cin >> temp.name;
			double sum = 0;
			for (int j = 0; j < course_number; j ++)
			{
				double scoretemp;
				cin >> scoretemp;
				if (scoretemp + 1e-8 > 60)
				{
					sum += (scoretemp - 50) / 10 * score[j];
				}
			}
			temp.score = sum / 10;
			list.push_back(temp);
			




		}
	
		sort(list.begin(), list.end(), cmp);
		cout << (!z ? "" : "\n") ;
		cout << "class " << z + 1 << ":" << endl;
		for (vector<student>::iterator it = list.begin(); it != list.end(); it ++)
		{
			cout << fixed << setprecision(2);
			cout << left << setw(11);
			cout << (*it).name << (*it).score << endl; 
		}



			score.clear();
			list.clear();
	
	
	
	}



	return 0;
}
