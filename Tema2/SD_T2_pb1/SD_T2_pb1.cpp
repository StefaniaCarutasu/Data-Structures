#include<iostream>
using namespace std;
int n = 100;

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
void inserare(int valoare, int dimensiune, int h[])
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

int main()
{
	return 0;
}