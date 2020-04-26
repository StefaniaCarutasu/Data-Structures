#include<iostream>
using namespace std;

struct BST
{
    int cheie;
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
        if (info< x->cheie)
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

BST* minim(BST* radacina)
{
    BST* aux = radacina;
    while (aux && aux->stg != NULL)
        aux = aux->stg;
    return aux;
}

BST* stergere(BST* radacina, int info)
{
    if (radacina == NULL) return radacina;
    if (info < radacina->cheie)
        radacina->stg = stergere(radacina->stg, info);
    else if (info > radacina->cheie)
        radacina->dr = stergere(radacina->dr, info);
    else
    {
        if (radacina->stg == NULL)
        {
            struct BST* temp = radacina->dr;
            free(radacina);
            return temp;
        }
        else if (radacina->dr == NULL)
        {
            struct BST* temp = radacina->stg;
            free(radacina);
            return temp;
        }
        BST* temp = minim(radacina->dr);
        radacina->cheie = temp->cheie; 
        radacina->dr = stergere(radacina->dr, temp->cheie);
    }
    return radacina;
}
  

int main()
{
    int n, x;
    cout << "Introduceti nr de noduri: ";
    cin >> n;
    cout << "Introduceti cheile: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (i == 0)
            radacina = insert(radacina, x);
        else insert(radacina, x);
    }
    SDR(radacina);
    cout << '\n';
    RSD(radacina);
    cout << '\n';
    cout << "Introduceti un numar pentru a fi cautat: ";
    cin >> x;
    cout << cautare(x) << '\n';
    cout << "Introduceti un numar pentru a fi cautat: ";
    cin >> x;
    cout << cautare(x) << '\n';
    cout << "Introduceti un numar pentru a fi sters: ";
    cin >> x;
    stergere(radacina,x);
    SDR(radacina);
    cout << '\n';
    RSD(radacina);
    return 0;
}