#include<iostream>
using namespace std;
struct stiva {

    int info;

    stiva* next;

} *pointer_global_element_varf;

void push(int x)
{
    if (pointer_global_element_varf == NULL)
    {
        pointer_global_element_varf->info = x;
        pointer_global_element_varf->next = NULL;
    }
    stiva* nod = new stiva;
    nod->info = x;
    nod->next = pointer_global_element_varf;
    pointer_global_element_varf = nod;
}
void pop()
{
    if (pointer_global_element_varf == NULL)
        return;
    stiva* nod = new stiva;
    nod = pointer_global_element_varf;
    pointer_global_element_varf = pointer_global_element_varf->next;
    cout << nod->info;
    delete nod;
}
int main()
{
    pointer_global_element_varf = NULL;
    push(1);
    pop();
    push(2);
    push(3);

    return 0;
}