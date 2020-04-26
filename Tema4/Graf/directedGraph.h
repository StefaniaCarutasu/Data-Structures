#pragma once
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class directedGraph
{
	vector<int> listaAdiacenta[10000];
	bool visited[10000] = { false };
	void initializareVisited();
	int ok = 0;
public:
	void addNode(int); //construieste si/sau modifica lista de adiacenta
	void addEdge(int, int); //construieste si/sau modifica lista de adiacenta
	int hasEdge(int, int); // return 1 daca exista muchie
	void BFS(int);	//
	void DFS(int);
	int twoCycles();
};

