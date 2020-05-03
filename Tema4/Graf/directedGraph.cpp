#include "directedGraph.h"

int directedGraph::noOfNodes = 0;	//initializam numarul de noduri cu 0

void directedGraph::addNode(int a)
{
	vector<int> v;	//cream o lista de adiacenta vida initial
	listaAdiacenta[a]=v;	//adaugam un nou nod in graf
	noOfNodes++;	//incrementam numarul de noduri ale grafului
}

void directedGraph::addEdge(int source, int target)
{
	listaAdiacenta[source].push_back(target);	//adaugam nodul target la lista de adiacenta a nodului source
}

int directedGraph::hasEdge(int source, int target)
{
	for (auto i : listaAdiacenta[source])	//parcurgem lista de adiacenta a lui source si vedem daca gasim nodul target
		if (i == target)
			return 1;
	return 0;
}

void directedGraph::initializareVisited()
{
	for (int i = 0; i < 10001; i++)
		visited[i] = false;
}

void directedGraph::BFS(int node)
{
	initializareVisited();
	vector<int> queue;
	visited[node] = true;   //marcam ca vizitat
	queue.push_back(node);	//adaugam la coada
	while (queue.size())
	{
		cout << *queue.begin() << " ";		//afsez nodul
		for (auto i : listaAdiacenta[*queue.begin()])
		{
			if (!visited[i])	//daca nu a fost vizitat il marchez si il adaug la coada
			{
				visited[i] = true;
				queue.push_back(i);
			}
		}
		queue.erase(queue.begin());		//sterg primul nod din coada si continui algoritmul cu urmatoarul nod
	}
}

void directedGraph::DFS(int node)
{
	visited[node] = true;
	cout << node << " ";
	for (auto i : listaAdiacenta[node])
		if (!visited[i])
			DFS(i);
}

int directedGraph::twoCycles()
{
	int contor = 0;	//starea initiala: nu avem niciun 2-ciclu
	vector< vector<int>> verif(noOfNodes+1);
	for (int i = 0; i <= noOfNodes; i++)
		for (int j = 0; j <= noOfNodes; j++)
			verif[i].push_back(0);	//retin daca am verificat daca am muchie intre i si j si intre j si i
	for (int i = 1; i < noOfNodes + 1; i++)
		for (int j = 1; j < noOfNodes + 1; j++)
		{
			if(hasEdge(i,j)==1 && hasEdge(j,i)==1 && verif[i][j] == 0) 
				contor++;	//incrementam numarul de cicluri cu proprietatea din cerinta
			verif[i][j] = 1; verif[j][i] = 1;	//marcam ca verificat
		}

	return contor;	//returnam numarul de 2-cicluri gasite
}