#include <iostream>
#include<list>
#include<vector>

template <typename TVertex = int, typename TEdge = double>
class Graph
{
	struct destination
	{
		int id;
		TVertex dest; // на какую вершину
		TEdge edge; // вес
	};
	struct vertex
	{
		int id;
		TVertex data; // данные в вершине
		std::vector<destination> dests; //
	}
	std::vector<vertex> table;

};