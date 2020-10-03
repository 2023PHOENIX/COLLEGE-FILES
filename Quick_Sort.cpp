#include<vector>
#include<iostream>

using namespace std;
void swap(int* X, int* Y)
{
	int temp = *X;
	*X = *Y;
	*Y = temp;
	
}
int partition(vector<int>& A, int low, int high)
{
	int pivot = A.at(high);
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (A.at(j) < pivot)
		{

			i++;
			swap(&A.at(j), &A.at(i));
		}

	}swap(&A.at(i+1), &A.at(high));
	return i + 1;
}
void quickSort(vector<int>& A, int low, int high)
{
	if (low < high)
	{
		auto P = partition(A, low, high);

		quickSort(A, low, P-1);
		quickSort(A, P + 1, high);
	}
}
int main()
{
	vector<int> A{ 1770,21,253,112 };
	quickSort(A, 0, A.size() - 1);
	for (auto i : A)
		cout << i << " ";
}