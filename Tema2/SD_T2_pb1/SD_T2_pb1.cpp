#include<iostream>
using namespace std;
void repozitionareS(int index, int dimensiune, int h[])
{
	int fiu_stg, fiu_dr, min;
	fiu_stg = 2 * index;
	fiu_dr = 2 * index + 1;
	if (fiu_dr >= dimensiune)
	{
		if (fiu_stg >= dimensiune)
			return;
		else min = fiu_stg;
	}
	else
	{
		if (h[fiu_stg] <= h[fiu_dr])
			min = fiu_stg;
		else min = fiu_dr;
	}
	if (h[index] > h[min])
	{
		swap(h[min], h[index]);
		repozitionareS(min, dimensiune, h);
	}

}

void stergere(int &dimensiune, int h[])
{
	if (dimensiune == 0)
		cout << "Heap vid";
	else
	{	
		cout << "Minimul este: " << h[0] << '\n';
		h[0] = h[dimensiune - 1];
		dimensiune--;
		if (dimensiune > 0)
			repozitionareS(0, dimensiune, h);
	}
}

void mutareI(int index, int dimensiune, int h[])
{
	int tata;
	if (index != 0)
	{
		if (index % 2)
			tata = (index - 1) / 2;
		else tata = index / 2;
		if (h[tata] > h[index])
		{
			swap(h[tata], h[index]);
			mutareI(tata, dimensiune, h);
		}
	}
}
void inserare(int valoare, int dimensiune, int h[], int n)
{
	if (dimensiune == n)
		cout << "Overflow";
	else
	{
		dimensiune++;
		h[dimensiune - 1] = valoare;
		mutareI(dimensiune - 1, dimensiune, h);
	}
}


void citire(int &n, int v[])
{
	cout << "Introduceti lungimea vectorului: ";
	cin >> n;
	cout << '\n' << "Introduceti cele " << n << " numere: ";
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		inserare(x, i, v, n);
	}
}
void afisare(int n, int v[])
{
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}
}
int main()
{
	int v[100], n;
	citire(n, v);
	afisare(n, v);
	return 0;
}