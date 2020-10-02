#include<iostream>
#include<vector>

using namespace std;
void Sswap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubblesort(vector<int> &A)
{
	for (size_t i = 0; i < A.size() - 1; i++)
		for (size_t j = 0; j < A.size()-1-i; j++)
		{
			if (A.at(j) > A.at(j + 1))
				Sswap(&A.at(j), &A.at(j + 1));
		}
}

int main()
{
	vector<int> A;
	int n;	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int data;	cin >> data;
		A.push_back(data);
	}
	
	bubblesort(A);
	for (auto i : A)
		cout << i << " ";
}