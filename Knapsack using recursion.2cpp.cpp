#include<bits/stdc++.h>

using namespace std;

class item
{
public:

	int wt;
	int v;
};

int K(vector<item> it, int MW, int n)
{
	if (n == 0 || MW == 0)
		return 0;
	if (it.at(n).wt <= MW)
		return max(it.at(n).v + K(it, MW - it.at(n).wt, n - 1), K(it, MW, n - 1));
	else
		return K(it, MW, n - 1);
}

int main()
{
	cout << "ENTER SIZE: ";
	int n;	cin >> n;
	vector<item> A;
	for (int i = 0; i < n; i++)
	{
		item it;	cout << "Enter weight "<<i+1<< ": ";
		cin >> it.wt;
			cout << "Enter value "<<i+1<< ": ";
		cin>> it.v;
		A.push_back(it);
	}
	int MW;	
	cout << "ENter total weight: ";
	cin >> MW;
	cout << K(A, MW, A.size()-1);


}