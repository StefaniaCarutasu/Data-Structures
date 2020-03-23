#include<iostream>

using namespace std;

struct coordonate
{
	int i, j;
}v[100], coada[100];

int k=-1, M[100][100];

void push(int i,int j, coordonate coada[])
{
	k++;
	coordonate x; 
	x.i = i; x.j = j;
	coada[k] = x;
}
void pop()
{
	if (k == -1)
	{
		
		return;
	}
	else
	{
		for (int i = 0; i < k - 1; i++)
			coada[i] = coada[i + 1];
		k--;
	}
}
int main()
{
	int m, i, j, c=2;

	cin >> m;

	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
			cin >> M[i][j];

	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
		{
			if (M[i][j] == 1)
			{
				push(i, j, coada);
				M[i][j] = c;
				int n = 0;
				while (n <= k)
				{
					int c1 = coada[n].i, c2 = coada[n].j;
					if (c1+1 < m && c1+1 >= 0 && c2 < m && c2 >= 0 && M[c1+1][c2] == 1) //jos
					{
						push(c1+1, c2, coada);
						M[c1+1][c2] = c;
					}
					if (c1-1 < m && c1-1 >= 0 && c2 < m && c2 >= 0 && M[c1 - 1][c2] == 1) //sus
					{
						push(c1 -1, c2, coada);
						M[c1 - 1][c2] = c;
					}
					if (c1 < m && c1 >= 0 && c2+1 < m && c2+1 >= 0 && M[c1][c2+1] == 1) //dreapta
					{
						push(c1, c2+1, coada);
						M[c1][c2+1] = c;
					}
					if (c1 < m && c1 >= 0 && c2-1 < m && c2-1 >= 0 && M[c1][c2-1] == 1) //stanga
					{
						push(c1, c2-1, coada);
						M[c1][c2-1] = c;
					}
					n++;
				}
				pop();
				c++;
			}
		}

	cout << '\n';

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
			cout << M[i][j] << ' ';
		cout << '\n';
	}

return 0;
}