#include<iostream> 
using namespace std;

int maxV(int v[], int n)
{
	int max = v[0];
	for (int i = 1; i < n; i++)
		if (v[i] > max)
			max = v[i];
	return max;
}

void countSort(int v[], int n, int exp)
{
	int aux[100], count[10] = { 0 }, i;

	for (i = 0; i < n; i++)
		count[(v[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		aux[count[(v[i] / exp) % 10] - 1] = v[i];
		count[(v[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		v[i] = aux[i];
}


void radixSort(int v[], int n)
{

	int max = maxV(v, n);
	for (int exp = 1; max / exp > 0; exp *= 10)
		countSort(v, n, exp);
}

void citire(int& n, int v[])
{
	cout << "Introduceti numarul de elemente: ";
	cin >> n;
	cout << "Introduceti " << n << " numere: ";
	for (int i = 0; i < n; i++)
		cin >> v[i];
}
 
void afisare(int v[], int n)
{
	cout << "Vectorul sortat este: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
}

int main()
{
	int n, v[100];
	citire(n, v);
	radixSort(v, n);
	afisare(v, n);
	return 0;
}
