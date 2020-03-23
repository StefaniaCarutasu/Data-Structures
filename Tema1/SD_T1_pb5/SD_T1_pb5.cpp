#include<iostream>
using namespace std;
void citire(int& n, int v[])
{
	cout << "Introduceti lungimea vectorului: ";
	cin >> n;
	cout << "Introduceti elementele vectorului: ";
	for (int i = 0; i < n; i++)
		cin >> v[i];
}
int main()
{
	int n, v[100], nr, aparitii = 1;
	citire(n, v);
	nr = v[0];
	for (int i = 1; i < n; i++)
	{
		if (v[i] == nr)
			aparitii++;
		else aparitii--;
		if (aparitii < 0)
		{
			nr = v[i];
			aparitii = 1;
		}
	}
	aparitii = 0;
	for (int i = 0; i < n; i++)
		if (v[i] == nr)
			aparitii++;
	if (aparitii > n / 2)
		cout << "Numarul majoritar este: " << nr;
	else cout << "Nu exista element majoritar.";
	delete[] v;
	return 0;

}