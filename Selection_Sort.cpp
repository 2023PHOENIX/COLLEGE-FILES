#include<iostream>
#include<vector>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(vector<int> &A)
{
	

	for (int i = 0; i < A.size(); i++)
	{
		int k = i;
		for (int j = i+1; j < A.size(); j++)
		{
			if (A.at(j) < A.at(k))
				k = j;

		}
		swap(&A.at(i), &A.at(k));

	}
}

int main()
{
	vector<int> A;
	int n;	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int data; cin >> data;
		A.push_back(data);
	}
	selectionSort(A);
	for (auto i : A)
		cout << i << " ";
}