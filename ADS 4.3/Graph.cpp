#include <iostream>
#include<list>
#include<vector>

template <typename TVertex = int, typename TEdge = double>
class Graph
{
	struct destination
	{
		int id;
		TVertex dest; // �� ����� �������
		TEdge edge; // ���
	};
	struct vertex
	{
		int id;
		TVertex data; // ������ � �������
		std::vector<destination> dests; //
	}
	std::vector<vertex> table;

};