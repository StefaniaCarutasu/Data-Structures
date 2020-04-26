#include "directedGraph.h"

void directedGraph::addNode(int a)
{
	vector<int> v;
	listaAdiacenta[a]=v;
}

void directedGraph::addEdge(int source, int target)
{
	listaAdiacenta[source].push_back(target);
}

int directedGraph::hasEdge(int source, int target)
{
	for (auto i : listaAdiacenta[source])
		if (i == target)
			return 1;
	return 0;
}

void directedGraph::initializareVisited()
{
	this->visited[10000] = { false };
}

void directedGraph::BFS(int node)
{
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
	ok = 1;
}

void directedGraph::DFS(int node)
{
	if (ok)
		initializareVisited();
	visited[node] = true;
	cout << node << " ";
	for (auto i : listaAdiacenta[node])
		if (!visited[i])
			DFS(i);
	ok = 0;
}

int directedGraph::twoCycles()
{
	int contor = 0;
	for (int i = 0; i < 10000; i++)
		for (int j = 0; j < 10000; j++)
		{
			vector<int>::iterator it = find(listaAdiacenta[j].begin(), listaAdiacenta[j].end(), i);
			vector<int>::iterator itt = find(listaAdiacenta[i].begin(), listaAdiacenta[i].end(), j);
			if (it != listaAdiacenta[j].end() && itt != listaAdiacenta[i].end())
				contor++;
		}

	return contor;
}