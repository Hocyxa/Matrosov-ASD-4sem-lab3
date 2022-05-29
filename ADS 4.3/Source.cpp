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
	T.Add_Edge(1, 2, 5);
	T.Add_Edge(1, 3, 15);
	T.Add_Edge(1, 4, 52);

	T.Delete_Edge(1, 2);


	T.Print();
	return 0;
}