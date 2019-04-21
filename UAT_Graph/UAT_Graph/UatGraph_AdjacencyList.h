#pragma once
#include <vector>

template <typename T>
class UatGraph_AdjacencyList
{
public:
	UatGraph_AdjacencyList()
	{
		graph_adjacencylist = new vector<list<T>*>();
	}

	~UatGraph_AdjacencyList()
	{
		for (list<T>* iter : *graph_adjacencylist)
		{
			if (iter != nullptr)
			{
				delete iter;
			}
		}
		delete graph_adjacencylist;
	}

	list<T>* AddVertex(T data)
	{
		// Attempt to find
		if (IsVertex(data))
		{
			cout << "Vertex is already in the graph. Duplicate NOT added." << endl;
			return nullptr;
		}
		else
		{
			list<T>* new_vertex = new list<T>();		// Create new list to house the vertex and its edges
			new_vertex->push_back(data);				// Data is added as the first element in the list
			graph_adjacencylist->push_back(new_vertex);	// list pointer is added to the graph
			return new_vertex;
		}
	}

	bool AddEdge(list<T>* vertex, T data)
	{
		if(!IsVertex(vertex))
		{
			cout << "Vertex specified does not exist. Cannot add edge to a non-existant vertex." << endl;
			return false;
		}
		if (!IsVertex(data))
		{
			vertex->push_back(data);
			return true;
		}
		else
		{
			list<T>* new_vertex = AddVertex(data);
			new_vertex->push_back(data);
			return true;
		}
	}

	bool AddEdge(list<T>* starting_vertex, list<T>* ending_vertex)
	{
		if(!IsVertex(starting_vertex) || !IsVertex(ending_vertex))
		{
			cout << "Cannot AddEdge because one of the specified vertices does not exist in the graph." << endl;
			return false;
		}
		if (!IsEdge(starting_vertex, ending_vertex->front()))
		{
			starting_vertex->push_back(ending_vertex->front());
			return true;
		}
		return false;
	}

	bool IsVertex(T data)
	{
		for (list<T>* iter : *graph_adjacencylist)
		{
			if (iter->front() == data)
			{
				return true;
			}
		}
		return false;
	}

	bool IsVertex(list<T>* vertex_to_find)
	{
		for (list<T>* iter : *graph_adjacencylist)
		{
			if (iter == vertex_to_find)
			{
				return true;
			}
		}
		return false;
	}

	bool IsEdge(T edge_to_find)
	{
		for (list<T>* iter : *graph_adjacencylist)
		{
			if (IsEdge(iter, edge_to_find))
			{
				return true;
			}
		}
		return false;
	}

	bool IsEdge(list<T>* vertex, T edge_to_find)
	{
		for (T i : *vertex)
		{
			// skip checking the primary vertex and only check edges
			if (vertex->front() == i)
			{
				continue;
			}
			if (i == edge_to_find)
			{
				return true;
			}
		}
		return false;
	}

	list<T>* FindVertex(T data)
	{
		for (list<T>* iter : *graph_adjacencylist)
		{
			if (iter->front() == data)
			{
				return iter;
			}
		}
		return nullptr;
	}

	void PrintAdjacencyList()
	{
		for (list<T>* iter : *graph_adjacencylist)
		{
			for (T i : *iter)
			{
				// skip checking the primary vertex and only check edges
				if (iter->front() == i)		// Prints the Vertex 
				{
					cout << "Vertex = " << i << "   Edges = ";
				}
				else	// Prints the Edges
				{
					cout << i << " ";
				}
			}
			cout << endl;
		}
	}

	int NumberOfEdges(T vertex_data)
	{
		list<T>* vertex = FindVertex(vertex_data);

		if(vertex != nullptr)
		{
			return NumberOfEdges(vertex);
		}
		return -1;
	}

	int NumberOfEdges(list<T>* vertex)
	{
		return vertex->size();
	}

	int GraphSize()
	{
		return graph_adjacencylist->size();
	}

private:
	vector<list<T>*>* graph_adjacencylist;
};