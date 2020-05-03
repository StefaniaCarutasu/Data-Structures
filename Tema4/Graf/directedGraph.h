#pragma once
#include<iostream>
#include<vector>
using namespace std;
class directedGraph
{
	vector<int> listaAdiacenta[10001];
	bool visited[10001];
	static int noOfNodes;
public:

	void initializareVisited();
	void addNode(int); //construieste si/sau modifica lista de adiacenta
	void addEdge(int, int); //construieste si/sau modifica lista de adiacenta
	int hasEdge(int, int); // return 1 daca exista muchie
	void BFS(int);	
	void DFS(int);
	int twoCycles();
};

