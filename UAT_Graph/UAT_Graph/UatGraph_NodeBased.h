#pragma once
#include <list>


using namespace std;

template <typename T>
class UatGraph_Vertex
{
private:
	T data;
	list<UatGraph_Vertex<T>*>* connected_vertices;
public:
	UatGraph_Vertex()
	{
		connected_vertices = new list<UatGraph_Vertex<T>*>();
		data = NULL;
	}

	UatGraph_Vertex(T node_data)
	{
		connected_vertices = new list<UatGraph_Vertex<T>*>();
		data = node_data;
	}

	~UatGraph_Vertex()
	{
		delete connected_vertices;
	}


	void AddEdge(UatGraph_Vertex<T>* vertex_connection)
	{
		if (vertex_connection != this)
		{
			connected_vertices->push_back(vertex_connection);
		}
	}


	bool VertexConnected(UatGraph_Vertex<T>* vertex_to_find)
	{
		for(UatGraph_Vertex<T>* i : *connected_vertices)
		{
			if(i == vertex_to_find)
			{
				return true;
			}
		}
		return false;
	}


	void RemoveEdge(UatGraph_Vertex<T>* edge_to_remove)
	{
		if (edge_to_remove != nullptr)
		{
			connected_vertices->remove(edge_to_remove);
		}
	}


	T GetData()
	{
		return data;
	}


	void SetData(T data_param)
	{
		data = data_param;
	}

};


template <typename T>
class UatGraph_NodeBased
{
private:
	list<UatGraph_Vertex<T>*>* graph;

public:
	UatGraph_NodeBased()
	{
		graph = new list<UatGraph_Vertex<T>*>;
	}


	UatGraph_NodeBased(UatGraph_Vertex<T>* initial_vertex)
	{
		graph = new list<UatGraph_Vertex<T>*>;
		Insert(initial_vertex);
	}


	~UatGraph_NodeBased()
	{
		for (UatGraph_Vertex<T>* iter : *graph)
		{
			if (iter != nullptr && iter != NULL)
			{
				delete iter;
			}
		}
		delete graph;
	}


	UatGraph_Vertex<T>* Insert(UatGraph_Vertex<T>* vertex)
	{
		graph->push_back(vertex);
		return vertex;
	}


	UatGraph_Vertex<T>* Insert(T data)
	{
		UatGraph_Vertex<T>* new_node = new UatGraph_Vertex<T>(data);
		return Insert(new_node);
	}


	void RemoveVertex(T data)
	{
		UatGraph_Vertex<T>* vertex_to_remove = FindVertex(data);
		RemoveVertex(vertex_to_remove);
	}


	void RemoveVertex(UatGraph_Vertex<T>* vertex_to_remove)
	{
		graph->remove(vertex_to_remove);
	}


	void AddEdge(UatGraph_Vertex<T>* start_vertex, UatGraph_Vertex<T>* end_vertex)
	{
		start_vertex->AddEdge(end_vertex);
	}


	void RemoveEdge(UatGraph_Vertex<T>* start_vertex, UatGraph_Vertex<T>* end_vertex)
	{
		start_vertex->RemoveEdge(end_vertex);
	}


	bool IsEdge(UatGraph_Vertex<T>* vertex_to_search_in, UatGraph_Vertex<T>* edge_to_check_for)
	{
		return vertex_to_search_in->VertexConnected(edge_to_check_for);
	}


	UatGraph_Vertex<T>* FindVertex(T data_to_find)
	{
		for (UatGraph_Vertex<T>* iter : *graph)
		{
			if (iter->GetData() == data_to_find)
			{
				return iter;
			}
		}
		return nullptr;
	}


	UatGraph_Vertex<T>* FindVertex(UatGraph_Vertex<T>* node_to_find)
	{
		for(UatGraph_Vertex<T>* iter : *graph)
		{
			if(iter == node_to_find)
			{
				return iter;
			}
		}
		return nullptr;
	}


	int Size()
	{
		return graph->size();
	}
};
