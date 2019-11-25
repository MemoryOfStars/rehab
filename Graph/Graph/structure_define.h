#pragma once
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>

using namespace std;

class Vertex
{
public:
	string name;
	vector<pair<int, Vertex*>> adj;  //pair(cost, Vertex)
	Vertex(string name) {
		this->name = name;
	}
	void print_neightbors();
};

class Edge 
{
public:
	Vertex* vertex1;
	Vertex* vertex2;
	int weight;
	Edge(Vertex* v1, Vertex* v2, int w) :vertex1(v1), vertex2(v2), weight(w) {}
};

class graph
{
	int numV;       //number of vertexes
	vector<Vertex*> vertices;                        //names of all vertices
	vector<Edge*> edges;                            //stores all edges in graph

	graph() {
		numV = 0;
	}
	map<string, Vertex*> work;                      //all vertexes and their names
	void MSTPrim(string);                           //implements Prim's algo
	void MSTKruskal();                              //implements Kruskal's algo
	map<string, pair<int, string> > Dijkstra(string start);//implements Dijkstra's algo
	void BFS(const string&);                       //implements BFS
	void addvertex(const string&);
	void addedge(string& from, string& to,int cost);
};