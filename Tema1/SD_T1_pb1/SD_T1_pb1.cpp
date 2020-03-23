#include<iostream>
using namespace std;
struct stiva {

    int info;

    stiva* next;
    
}*varf;
void push(int x)
{
    stiva* nod = new stiva;
    nod->info = x;
    nod->next = varf;
    varf = nod;
    cout << "Am adaugat: " << x << '\n';
}
void pop()
{
    if (varf == NULL)
        cout << "Stiva vida";
    stiva* nod = new stiva;
    nod = varf;
    varf = varf->next;
    cout <<"Am sters: " << nod->info << '\n';
    delete nod;
}
int main()
{
    push(1);
    pop();
    push(2);
    push(3);

    return 0;
}