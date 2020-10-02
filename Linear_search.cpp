#include<iostream>
#include<vector>
using namespace std;
int check(vector<int> A,int num)
{
	int flag = -1;

	for (size_t i = 0; i < A.size(); i++)
	{
		if (A.at(i) == num)
			flag = i;


	}
	return flag;
}
int main()
{
	int n;	cin >> n;

	vector<int> A;
	for (size_t i = 0; i < n; i++)
	{
		int data;	cin >> data;
		A.push_back(data);
	}
	int num;
	cout << "enter your number :";
	cin >> num;
	
	int result = check(A, num);

	cout << result << endl;

	


}