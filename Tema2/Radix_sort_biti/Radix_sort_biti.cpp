#include<iostream> 
#include<vector>
using namespace std;
int n;
int maxV(vector<int> v, int n)
{
	int maxim = v[0];
	for (auto& x: v)
		if (x > maxim)
			maxim = x;
	return maxim;
}

void countSort(vector<int>& v, int shift, int n)
{
	int i;
	vector <int> count(256), aux(n);
	if (shift == 0) 
	{
		for (i = 0; i < n; i++)
			count[v[i] & 255]++;
		for (i = 1; i < count.size(); i++)
			count[i] += count[i - 1];
		for (i = n - 1; i >= 0; i--) 
		{
			aux[count[v[i] & 255] - 1] = v[i];
			count[v[i] & 255]--;
		}
	}
	else 
	{
		for (i = 0; i < n; i++)
			count[v[i] >> shift]++;
		for (i = 1; i < count.size(); i++)
			count[i] += count[i - 1];
		for (i = n - 1; i >= 0; i--) 
		{
			aux[count[v[i] >> shift] - 1] = v[i];
			count[v[i] >> shift]--;
		}
	}
	v = aux;

}


void radixSort(vector<int>& v, int n)
{

	int max = maxV(v,n);
	int shift = 0;
	while (max >> shift) 
	{
		countSort(v, shift, n);
		shift += 8;
	}

}
void citire(int& n, vector<int>& v)
{
	int x;
	cout << "Introduceti lunimea vectorului: ";
	cin >> n;
	cout << "Introduceti " << n << " elemente: ";
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
}
void afisare(vector<int> v)
{
	cout << "Vectorul sortat este: ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}

int main()
{
	vector<int> v;
	int x;
	citire(n, v);
	radixSort(v,n);
	afisare(v);
	return 0;
}

