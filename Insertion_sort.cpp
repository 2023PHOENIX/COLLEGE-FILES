#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> &A)
{
	for (size_t i = 1; i < A.size(); i++)
	{
		int j;
		int x = A.at(i);
		j = i;
		while (A.at(j - 1) > x && j >= i)
		{
			A.at(j) = A.at(j - 1);
			j--;
		}
		A.at(j) = x;
	}
}
int main()
{
	vector<int> A;
	int n;	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int data;	cin >> data;
		A.push_back(data);
	}

	insertionSort(A);

	for (auto i : A)
		cout << i << " ";
} 