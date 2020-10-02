#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &A, int low, int mid ,int high)
{
	int i = low;
	int k = low;
	int j = mid + 1;
	vector<int> B(A.size(), 0);

	while (i <= mid && j <= high)
	{
		if (A.at(i) < A.at(j))
			B.at(k++) = A.at(i++);
		else
			B.at(k++) = A.at(j++);


	}
	while (i <= mid)
	{
		B.at(k++) = A.at(i++);
	}
	while (j <= high)
	{
		B.at(k++) = A.at(j++);
	}
	for (int i = low; i <= high; i++)
		A.at(i) = B.at(i);

}
void mergeSort(vector<int> &A, int low, int high)
{
	if (low < high)
	{
		int mid = low + (high - low) / 2;
		mergeSort(A, low, mid);
		mergeSort(A, mid + 1, high);

		merge(A, low, mid, high);
	}
}
int main()
{
	
	vector<int> A{ 1,21,2,89,75,90,43 };

	mergeSort(A, 0, A.size() - 1);
	for (auto i : A)
		cout << i<<" ";


}