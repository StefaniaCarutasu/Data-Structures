#include <iostream>
using namespace std;

struct BST
{
    int cheie;
    struct BST* stg, * dr;
}*radacina;

BST* insert(BST* radacina, int info)
{
    if (radacina == NULL)
    {
        BST* aux = new BST;
        aux->cheie = info;
        aux->stg = aux->dr = NULL;
        return aux;
        radacina = aux;
    }
    else
    {
        BST* x = radacina;
        if (info < x->cheie)
            x->stg = insert(x->stg, info);
        else if (info > x->cheie)
            x->dr = insert(x->dr, info);
    }
    return radacina;
}

int cautare(int info)
{
    BST* x = radacina;
    while (x != NULL)
    {
        if (x->cheie == info)
            return 1;
        else
        {
            if (info < x->cheie)
                x = x->stg;
            else x = x->dr;
        }
    }
    return 0;
}
int main()
{
    int n;
    cout << "Introduceti numarul de noduri: ";
    cin >> n;
    cout << "Introduceti cele " << n << " chei: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i == 0)
            radacina = insert(radacina, x);
        else insert(radacina, x);
    }
    int k1, k2;
    cout << "Introduceti 2 numere: ";
    cout << "k1 = ";
    cin >> k1;
    cout << "k2 = ";
    cin >> k2;
    if (k1 > k2)
        swap(k1, k2);
    cout << "Intervalul de cautare este (" << k1 << ", " << k2 << ")";
    k1++;
    while (k1 < k2)
    {
        cautare(k1);
        k1++;
    }
    return 0;
}
