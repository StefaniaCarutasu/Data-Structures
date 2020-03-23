#include <iostream>
using namespace std;
struct coada {

    int info;

    coada* prev, * next;

} *first, * last;
void push_left(int x)
{
    coada* nod = new coada;
    nod->info = x;
    nod->prev = NULL;

    nod->prev = first;

    if (first != NULL)
        first->prev = nod;
    else
    {
        first = nod;
        last = nod;
    }
    first = nod;
    cout << "Am inserat la stanga: " << x << '\n';

}
void push_right(int x)
{
    coada* nod = new coada;
    nod->info = x;
    nod->next = NULL;
    nod->prev = NULL;
    if (last == NULL)
    {
        last = nod;
        first = nod;
    }
    else
    {
        last->next = nod;
        nod->prev = last;
        last = nod;
    }
    cout << "Am inserat la dreapta: " << x << '\n';
}
void pop_left()
{
    if (first == NULL)
        cout << "Coada vida'\n'";
    else 
    {
        if (first->next == NULL)
        {
            cout <<"Am sters de la stanga: " << first->info << '\n';
            delete first;
        }
        else
        {
            coada* nod = new coada;
            nod = first;
            cout << "Am sters de la stanga: " << nod->info << '\n';
            first = first->next;
            first->prev = NULL;
            delete nod;
        }
    }

}
void pop_right()
{   
    if (last == NULL)
        cout << "Coada vida'\n'";
    else
    {
            coada* nod = new coada;
            nod = last;
            cout <<  "Am sters de la dreapta: " << nod->info << '\n';
            last = last->prev;
            last->next = NULL;
    }
}
int main()
{
    push_left(1);
    push_right(2);
    pop_right();
    pop_left();
    push_right(3);
    return 0;

}