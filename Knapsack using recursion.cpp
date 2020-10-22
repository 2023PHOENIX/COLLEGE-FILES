#include<bits/stdc++.h>

using namespace std;


int k(vector<int> w, vector<int> v, int MW, int n)
{
	if (n == 0 || MW == 0)
		return 0;
	if (MW >= w[n])
		return max(v[n] + k(w, v, MW - w[n], n - 1), k(w, v, MW - w[n], n - 1));
	else
		return  k(w, v, MW - w[n], n - 1);
}
int main()
{
	vector<int> w{ 10,20,30 };
	vector<int> v{ 60,100,120 };
	int n = w.size();
	int MW = 50;
	cout << k(w, v, MW, n-1);

	
}