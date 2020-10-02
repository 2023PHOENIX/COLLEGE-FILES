#include<iostream>
#include<vector>

using namespace std;

// LINEAR SEARCH

int main()
{
	vector<int> A;
	int n;	cin >> n;

	

	for (size_t i = 0; i < n; i++)
	{
		int data;	cin >> data;
		A.push_back(data);
	}

	int num;
	cout << "Enter your number : ";
	cin >> num;

	for (size_t i = 0; i < A.size(); i++)
	{
		if (num == A.at(i))
			cout << "number found at: " << num; break;
	}
	
}