#include "Graph.cpp"
#include <iostream>


int main()
{
	Graph<int, int> T;
	
	T.Add_Vertex(1);
	T.Add_Vertex(2);
	T.Add_Vertex(3);
	T.Add_Vertex(4);
	T.Add_Vertex(5);
	T.Add_Edge(1, 2, 05);
	T.Add_Edge(2, 3, 15);
	T.Add_Edge(3, 4, 25);
	T.Add_Edge(1, 4, 35);
	T.Add_Edge(3, 1, 45);
	T.Add_Edge(4, 2, 55);
	T.Print();


	std::cout << std::endl;
	
	T.belman_ford(1, 4);

	return 0;
}