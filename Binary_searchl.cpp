#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int BinarySearch(vector<int> A, int num,int low,int high)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;

		if (A.at(mid) == num)
			return mid;
		if (A.at(mid) > num)
			return BinarySearch(A, num, low, mid - 1);
		else
			return BinarySearch(A, num, mid + 1, high);
	}
	return -1;
}
//BINARY SEARCH
int main()
{
	vector<int> A;
	int n;	cin >> n;
	for (size_t i = 0; i <n; i++)
	{
		int data;	cin >> data;
		A.push_back(data);
	}
	sort(A.begin(), A.end());
	int num;	cin >> num;
	cout << BinarySearch(A, num, 0, A.size() - 1);
}