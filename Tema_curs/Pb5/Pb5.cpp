#include <iostream>
#include <vector>
using namespace std;
int n;
void citire(vector<int>& v)
{
    cout << "Introduceti cele " << n << " elemente ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

int mediana(vector<int> v)
{
    if (v.size() % 2 == 0)
        return (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
    else return v[v.size() / 2];
}

int medianaVect(vector<int> v1, vector<int> v2)
{
    if (v1.size() <= 2)
    {
        vector<int> aux;
        unsigned int i = 0, j = 0;
        while (i < v1.size() && j < v2.size())
        {
            if (v1[i] < v2[j])
            {
                aux.push_back(v1[i]);
                i++;
            }
            else
            {
                aux.push_back(v2[j]);
                j++;
            }
        }
        while (i < v1.size())
        {
            aux.push_back(v1[i]);
            i++;
        }
        while (j < v2.size())
        {
            aux.push_back(v2[j]);
            j++;
        }
        return (aux[aux.size() / 2] + aux[aux.size() / 2 - 1]) / 2;
    }
    else
    {
        int x = mediana(v1);
        int y = mediana(v2);
        if (x > y)
        {
            vector<int> aux;
            for (unsigned int i = 0; i < v1.size() / 2; i++)
                aux.push_back(v1[i]);
            v1.clear();
            v1 = aux;
            aux.clear();
            for (unsigned int i = v2.size() / 2 + 1; i < v2.size(); i++)
                aux.push_back(v2[i]);
            v2.clear();
            v2 = aux;
        }
        else
        {
            if (x < y)
            {
                vector<int> aux;
                for (unsigned i = v1.size() / 2 + 1; i < v1.size(); i++)
                    aux.push_back(v1[i]);
                v1.clear();
                v1 = aux;
                aux.clear();
                for (unsigned int i = 0; i < v2.size() / 2; i++)
                    aux.push_back(v2[i]);
                v2.clear();
                v2 = aux;
            }
            else return x;
            
        }
        for (auto& i : v1)
            cout << i << " ";
        cout << '\n';
        for (auto& i : v2)
            cout << i << " ";
        cout << '\n';
        return medianaVect(v1, v2);
    }
}

int main()
{
    vector<int>v, w;
    cout << "Introduceti lungimea vectorului: ";
    cin >> n;
    citire(v);
    citire(w);
    cout << medianaVect(v, w);
}