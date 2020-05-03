#include "directedGraph.h"
#include<iostream>
using namespace std;

int main()
{
	directedGraph G;
	int n;
	cout << "Introduceti numarul de noduri: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		G.addNode(i);
		for (int j = 1; j <= n; j++)
			if ((j % i == 0 || i % j == 0) && i != j)
				G.addEdge(i, j);
	}

	G.initializareVisited();
	cout << "DFS: ";
	G.DFS(1);
	cout << '\n';
	G.initializareVisited();
	cout << "BFS: ";
	G.BFS(1);
	cout << '\n';
	cout << "Numarul de two cycles: " << G.twoCycles();
	return 0;
}
