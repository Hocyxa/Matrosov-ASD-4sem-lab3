#include <iostream>
#include<vector>

template <typename TVertex, typename TEdge = double>
class Graph
{
private:
	struct deep_information
	{
		int color = 0;
		TVertex prev;
		int t_open = 0;
		int t_close = 0;
	};
	struct destination
	{
		int id_d;
		TVertex dest; //вершина (куда)
		TEdge edge; // вес
	};
	struct vertex
	{
		int id_v;
		TVertex data; // данные в вершине
		std::vector<destination> dest; //куда
		deep_information info;
	};
	std::vector<vertex> table;
	int Index(TVertex Temp_Vertex)
	{
		for (size_t i = 0; i < table.size(); i++)
		{
			if (table[i].data == Temp_Vertex) return table[i].id_v;
		}
		return -1;
	}
public:
	void Add_Vertex(TVertex New_data)
	{
		if (Index(New_data) == -1)
		{
			vertex new_vertex;
			new_vertex.id_v = table.size();
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
		new_edge.dest = Dest;
		new_edge.edge = Edge;
		new_edge.id_d = Index(Dest);
		table[Index(Source)].dest.push_back(new_edge);
	}
	void Delete_Edge(TVertex Source, TVertex Dest)
	{
		int Index_Source = Index(Source);
		int Index_Dest = Index(Dest);
		if (Index_Source == -1 || Index_Dest == -1) throw "Edge not exist";
		for (size_t i = 0; i < table[Index_Source].dest.size(); i++)
		{
			if (table[Index_Source].dest[i].dest.id_d == Index_Dest)
			{
				for (size_t j = i; j < table[Index_Source].dest.size() - 1; j++)
				{
					table[Index_Source].dest[j] = table[Index_Source].dest[j + 1];
					table[Index_Source].dest[j].id_d--;
				}
				table[Index_Source].dest.pop_back();
				return;
			}
		}
	}
	void Delete_Vertex(TVertex Source)
	{
		int Index_Source = Index(Source);
		if (Index_Source == -1) throw "Vertex not exist";
		for (size_t i = 0; i < table.size(); i++)
		{
			if (i != Index_Source)
			{
				for (size_t j = 0; j < table[i].dest.size(); j++)
				{
					if (table[i].dest[j].dest == Source)
					{
						for (size_t k = j; k < table[i].dest.size() - 1; k++)
						{
							table[i].dest[k].dest = table[i].dest[k + 1].dest;
						}
						table[i].dest.pop_back();
					}
				}
			}
		}
		for (size_t i = Index_Source; i < table.size() - 1; i++)
		{
			table[i] = table[i + 1];
			table[i].id_v--;
		}
		table.pop_back();
	}
	void Print()
	{
		for (size_t i = 0; i < table.size(); i++)
		{
			std::cout << table[i].data << ": {";
			for (size_t j = 0; j < table[i].dest.size(); j++)
			{
				std::cout << table[i].dest[j].dest << "(" << table[i].dest[j].edge << ")";
			}
			std::cout << "}" << std::endl;
		}
	}

	void Deep_Search()
	{
		int t = 0;
		deep(table[0], t);
		for (size_t j = 0; j < table.size(); j++)
		{
			if (table[j].info.color == 0)
			{
				deep(table[j], t);
			}
		}
	}
	void deep(vertex v, int& t)
	{
		table[v.id_v].info.color = 1;
		table[v.id_v].info.t_open = t;
		t++;
		for (size_t i = 0; i < table[v.id_v].dest.size(); i++)
		{
			if (table[table[v.id_v].dest[i].id_d].info.color == 0)
			{
				table[table[v.id_v].dest[i].id_d].info.prev = table[v.id_v].data;
				deep(table[table[v.id_v].dest[i].id_d], t);
			}
		}
		table[v.id_v].info.color = 2;
		table[v.id_v].info.t_close = t;
		std::cout << table[v.id_v].data << ", ";
		t++;
	}

	void belman_ford(TVertex source, TVertex dest)
	{
		if (Index(source) == -1 || Index(dest) == -1) throw "Vertexs not exist";
		std::vector<double> d(table.size());
		for (size_t i = 0; i < table.size(); i++)
		{
			d[i] = INFINITY;
		}
		d[Index(source)] = 0;
		std::vector<std::vector<TVertex>> ways(table.size());
		for (size_t i = 0; i < table.size(); i++)
		{
			for (size_t j = 0; j < table[i].dest.size(); j++)
			{
				if (d[i] + (double)table[i].dest[j].edge < d[table[i].dest[j].id_d])
				{
					d[table[i].dest[j].id_d] = d[i] + (double)table[i].dest[j].edge;
					ways[table[i].dest[j].id_d] = ways[i];
					ways[table[i].dest[j].id_d].push_back(table[i].id_v + 1);
				}
			}
		}
		for (size_t i = 0; i < table.size(); i++)
		{
			ways[i].push_back(table[i].id_v + 1);
		}
		for (size_t j = 0; j < ways[Index(dest)].size(); j++)
		{
			std::cout << ways[Index(dest)][j] << "->";
		}
		std::cout << "end" << std::endl;
		std::cout << std::endl;
		if (d[Index(dest)] == INFINITY)
		{
			std::cout << std::endl << source << "->" << dest << "=" << "No way";
		}
		else std::cout << std::endl << source << "->" << dest << "=" << d[Index(dest)];
	
	}


};