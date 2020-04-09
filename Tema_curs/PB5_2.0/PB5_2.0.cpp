#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	cout << "Introduceti numarul n=";
	cin >> n;
	for (int i = 0; i <= n; i++)
		v.push_back(0);
	cout << "Introduceti cele " << n << " numere: ";
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v[x]++;
	}
	for (int i = 1; i <= n; i++)
		if (v[i] == 2)
			cout << "Numarul care apare de 2 ori este: " << i;
	return 0;
}