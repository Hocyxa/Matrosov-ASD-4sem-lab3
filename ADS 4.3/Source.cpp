#include "Graph.cpp"
#include <iostream>


int main()
{
	Graph<int, int> T;
	
	T.Add_Vertex(1);
	T.Add_Vertex(2);
	T.Add_Edge(1, 2, 5);
	



	T.Print();
	return 0;
}