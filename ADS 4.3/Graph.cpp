#include <iostream>
#include<list>
#include<vector>

template <typename TVertex, typename TEdge = double>
class Graph
{
private:
	struct destination
	{
		TVertex dest; //вершина (куда)
		TEdge edge; // вес
	};
	struct vertex
	{
		int id;
		TVertex data; // данные в вершине
		std::vector<destination> dest; //куда
	};
	std::vector<vertex> table;
	int Index(TVertex Temp_Vertex)
	{
		for (size_t i = 0; i < table.size(); i++)
		{
			if (table[i].data == Temp_Vertex) return table[i].id;
		}
		return -1;
	}
public:
	void Add_Vertex(TVertex New_data)
	{
		if (Index(New_data) == -1)
		{
			vertex new_vertex;
			new_vertex.id = table.size();
			new_vertex.data = New_data;
			table.push_back(new_vertex);
		}
		else throw "This vertex exists!";
	}
	void Add_Edge(TVertex Source, TVertex Dest, TEdge Edge)
	{
		if (Index(Source) == -1) throw "Source not exist";
		if (Index(Dest) == -1) throw "Destenation not exist";
		destination new_edge;
		new_edge.dest = Index(Dest);
		new_edge.edge = Edge;
		table[Index(Source)].dest.push_back(new_edge);
	}
	void Delete_Edge(TVertex Source, TVertex Dest)
	{
		int Index_Source = Index(Source);
		int Index_Dest = Index(Dest);
		if (Index_Source == -1 || Index_Dest == -1) throw "Edge not exist";
		for (size_t i = 0; i < table[Index_Source].dest[i].size(); i++)
		{
			if (table[Index_Source].dest[i].dest == Dest)
			{
				for (size_t j = i; j < table[Index_Source].dest.size() - 1; j++)
				{
					table[Index_Source].dest[i] = table[Index_Source].dest[i + 1];
				}
				table[Index_Source].dest.pop_back();
			}
		}
	}
	void Print()
	{
		for (size_t i = 0; i < table.size(); i++)
		{
			std::cout << table[i].data << ": {";
			for (size_t j = 0; j < table[i].dest.size(); j++)
			{
				std::cout << table[i].dest[j].dest + 1 << "(" << table[i].dest[j].edge << ")";
			}
			std::cout << "}" << std::endl;
		}
	}
};