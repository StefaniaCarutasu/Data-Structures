#include <iostream>
#include<string.h>
using namespace std;
struct BST
{
    char cheie[100];
    struct BST* stg, * dr;
}*radacina;
void SDR(struct BST* radacina)
{
    if (radacina != NULL)
    {
        SDR(radacina->stg);
        cout << radacina->cheie << " ";
        SDR(radacina->dr);
    }
}

void RSD(struct BST* radacina)
{
    if (radacina != NULL)
    {
        cout << radacina->cheie << " ";
        RSD(radacina->stg);
        RSD(radacina->dr);
    }
}


BST* insert(BST* radacina, char info[100])
{
    if (radacina == NULL)
    {
        BST* aux = new BST;
        strcpy_s(aux->cheie, info);
        aux->stg = aux->dr = NULL;
        return aux;
        radacina = aux;
    }
    else
    {
        BST* x = radacina;
        if (strcmp(info, x->cheie)<=0)
            x->stg = insert(x->stg, info);
        else if (strcmp(info, x->cheie)>0)
            x->dr = insert(x->dr, info);
    }
    return radacina;
}
int main()
{
    int n; char c[100];
    cout << "Introduceti numarul de siruri: ";
    cin >> n;
    cout << "Introduceti cele " << n << " siruri de caractere: ";
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (i == 0)
            radacina = insert(radacina, c);
        else insert(radacina, c);
    }
    SDR(radacina);
    cout << "\n";
    RSD(radacina);
    return 0;
}


