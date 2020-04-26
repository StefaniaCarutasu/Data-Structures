#include "directedGraph.h"
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.erase(v.begin());
	v.push_back(3);
	for (auto i : v)
		cout << i <<" ";
	return 0;
}
