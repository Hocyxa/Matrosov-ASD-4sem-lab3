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
	T.Add_Edge(1, 2, 7);
	T.Add_Edge(2, 1, 11);
	T.Add_Edge(1, 4, 100);
	T.Add_Edge(1, 5, 10);
	T.Add_Edge(5, 2, 20);
	T.Add_Edge(3, 1, 107);
	T.Add_Edge(2, 3, 5);
	T.Add_Edge(3, 4, 8);
	T.Add_Edge(2, 4, 10);
	
	std::cout << std::endl;
	T.Belman_Ford(1, 4);

	std::cout << std::endl;

	if (T.Get_Vertex(2) == T.Get_Vertex(2))
	{
		std::cout << "==" << std::endl;
	}
	else std::cout << "!=" << std::endl;
	T.Print();
	return 0;
}