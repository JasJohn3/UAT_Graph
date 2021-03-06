// UAT_Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
//#include <iostream>
#include "UatGraph_NodeBased.h"
#include "UatGraph_AdjacencyList.h"
//#include <stdlib.h>
//#include <time.h>

using namespace std;

bool Testing_NodeBased()
{
	std::cout << "\n\nNode List Test!\n\n" << std::endl;
	bool success = true;
	srand(time(NULL));
	

	



	/*
		Test UatGraph_NodeBased Constructor(s)
	*/
	
	UatGraph_NodeBased<int> Graph_Node;


	/*
		Test creating lots of nodes and edges
	*/
	for (int i = 0; i < 20; ++i)
	{
		int j = i - 1;
		if (Graph_Node.Insert(i) == nullptr) { success = false; std::cout << "Insert Function Failure!" << std::endl; }
		std::cout << "Vertex Successfully Create with value " << i << std::endl;
		if (j >= 0)
		{
			//adding a new edge for the given graph
			Graph_Node.AddEdge(Graph_Node.FindVertex(j), Graph_Node.FindVertex(i));
			//this performs a check on the recent created edge values.  If the edge exists, continue to success statment.  Otherwise, print failure statement.
			if (!Graph_Node.IsEdge(Graph_Node.FindVertex(j), Graph_Node.FindVertex(i))) {
				success = false; std::cout << "Add Edge Function Failed!" << std::endl;
			}
			std::cout << "Edge successfully created at Vertex " << j << " and Vertex " << i << std::endl;
		}
	}
	if (success)
	{
		std::cout << "\n\nAuto Node Constructor success: True\n\n"<< std::endl;
	}

	/* 
		 Test functions of the UatGraph_NodeBased class and affiliated classes
	*/
	//Testing Remove Edge Method
	Graph_Node.AddEdge(Graph_Node.FindVertex(2), Graph_Node.FindVertex(3));
	bool Test_Add_Edge = Graph_Node.IsEdge(Graph_Node.FindVertex(2), Graph_Node.FindVertex(3));
	Graph_Node.RemoveEdge(Graph_Node.FindVertex(2), Graph_Node.FindVertex(3));
	bool Test_Remove_Edge = Graph_Node.IsEdge(Graph_Node.FindVertex(2), Graph_Node.FindVertex(3));
	if (Test_Add_Edge != Test_Remove_Edge)
	{
		std::cout << "Remove Edge Test Success!\n" << endl;
	}
	else { std::cout << "Remove Edge Test Failure!\n" << std::endl; }

	//testing our size function
	if (Graph_Node.Size() == 20)
	{
		std::cout << "Size of Graph " << Graph_Node.Size() << std::endl;
		std::cout << "\nSize Test Success!" << std::endl;
	}
	else
	{
		std::cout << "Size Test Failed" << std::endl;
	}

	//Testing Remove Vertex
	Graph_Node.RemoveVertex(1);
	if (!Graph_Node.FindVertex(1))
	{
		std::cout << "\nRemove Node Test Success!\n" << std::endl;
	}
	else { std::cout << "\nRemove Node Test Failure!\n" << std::endl; }
	std::cout << "\n\nNode List Test Complete!\n\n" << std::endl;
	system("pause");
	return false;
}

bool Testing_AdjacencyList()
{
	std::cout << "\n\nAdjacency List Test!\n\n" << std::endl;
	bool success = true;
	/*
		Test UatGraph_NodeBased Constructor(s)
	*/
	UatGraph_AdjacencyList<int> Graph_Node;

	/*
		Test creating lots of nodes and edges
	*/
	for (int i = 0; i < 20; ++i)
	{
		int j = i - 1;
		Graph_Node.AddVertex(i);
		std::cout << "Vertex Successfully Create with value " << i << std::endl;
		if (j >= 0)
		{

			Graph_Node.AddEdge(Graph_Node.FindVertex(j), Graph_Node.FindVertex(i));
			std::cout << "Edge successfully created at Vertex " << j << " and Vertex " << i << std::endl;
		}
	}


	if (success)
	{
		std::cout << "\n\nAuto Node Constructor success: True\n\n" << std::endl;
	}
	/*
		Test functions of the UatGraph_NodeBased class and affiliated classes
	*/

	//testing our size function
	if (Graph_Node.GraphSize()== 20)
	{
		std::cout << "Size of Graph " << Graph_Node.GraphSize() << std::endl;
		std::cout << "\nSize Test Success!" << std::endl;
	}

	cout << "Manual Graph Verification: " << std::endl;
	Graph_Node.PrintAdjacencyList();

	//Testing NumberofEdges Method
	if (Graph_Node.NumberOfEdges(1) == 2)
	{
		std::cout << "\nNumber of Edges Test Success!" << std::endl;
	}
	else { std::cout << "\nNumber of Edges Test Failure!" << std::endl; }

	//testing isEdge method
	if (Graph_Node.IsEdge(2))
	{
		std::cout << "\nEdges Test Success!" << std::endl;
	}
	else { std::cout << "\nEdges Test Failure!" << std::endl; }

	//testing isVertex Method
	if (Graph_Node.IsVertex(2))
	{
		std::cout << "\nVertex Test Success!" << std::endl;
	}
	else { std::cout << "\nVertex Test Failure!" << std::endl; }
	std::cout << "\n\nAdjacency List Test Complete!\n\n" << std::endl;
	system("pause");

	return false;
}

int main()
{
	// Call testing functions
	Testing_NodeBased();
	Testing_AdjacencyList();
	// Test UatGraph_NodeBased Constructor(s)
	
	// Test functions of the UatGraph_NodeBased class and affiliated classes



	return 0;
}


