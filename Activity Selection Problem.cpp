#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Process {
public:
	int start;
	int end;
};
int Greatest(Process P1, Process P2)
{
	return (P1.end < P2.end);


}

void Total(vector<Process> P)
{
	sort(P.begin(), P.end(), Greatest);
	int i = 0;
	cout << P.at(i).start << " "<< P.at(i).end << " ";

	
	for (int j = 1; j < P.size();j++)
	{
		if (P.at(j).start >= P.at(i).end)
		{
			cout << " (" << P.at(j).start << " " << P.at(j).end << " )";
			i = j;
		}

	}



}
int main()
{
	vector<Process> P;
	int n;	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Process K; cin >> K.start >> K.end;
		P.push_back(K);
	}

	Total(P);

}