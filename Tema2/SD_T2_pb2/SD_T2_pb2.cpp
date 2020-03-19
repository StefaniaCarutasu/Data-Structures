#include<iostream>
using namespace std;
void heapify(int v[], int n, int i)
{
    int max = i; 
    int stg = 2 * i + 1; 
    int dr = 2 * i + 2;
    if (stg < n && v[stg] > v[max])
        max = stg; 
    if (dr < n && v[dr] > v[max])
        max = dr;
    if (max != i)
    {
        swap(v[i], v[max]);
        heapify(v, n, max);
    }
}
void heapSort(int v[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);

    
    for (int i = n - 1; i >= 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}


int main()
{
    int n, v[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    heapSort(v, n);
    cout << "Vectorul sortat este: \n";
    for (int i = 0; i < n; i++)
        cout << v[i];
    return 0;
}
