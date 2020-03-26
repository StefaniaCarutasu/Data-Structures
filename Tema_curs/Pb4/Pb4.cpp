#include<iostream>
using namespace std;

void countSort(int n, int v[])
{
	int w[100], frecv[100] = { 0 }, max = v[0];
	for (int i = 0; i < n; i++)
	{
		if (v[i] > max)
			max = v[i];
		frecv[v[i]]++;
	}

	for (int i = 1; i <= max; i++)
		frecv[i] += frecv[i - 1];

	for (int i = 0; i < n; i++)
	{
		if (frecv[v[i]] != 0)
		{
			w[frecv[v[i]] - 1] = v[i];
			frecv[v[i]]--;
		}
	}
	for (int i = 0; i < n; i++)
		v[i] = w[i];

}

void citire(int& n, int v[])
{
	cout << "Introduceti numarul de numere";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
}

int main()
{
	int n, v[100], nr;
	bool ok = false;
	citire(n, v);
	countSort(n, v);
	for (int i = 0; i < n - 1 && ok == false; i++)
		if (v[i] == v[i + 1])
		{
			ok = true;
			nr = v[i];
		}
	cout << "Numarul care apare de 2 ori este: " << nr;

	return 0;
}