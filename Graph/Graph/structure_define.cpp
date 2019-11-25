#include "structure_define.h"

void Vertex::print_neightbors()
{
	vector<pair<int, Vertex*>>::iterator i;
	for (i = adj.begin(); i != adj.end(); i++)
	{
		cout<<i->second->name<<endl;
	}
}


void graph::MSTPrim(string)
{
}

void graph::MSTKruskal()
{
}

map<string, pair<int, string>> graph::Dijkstra(string start)
{
	return map<string, pair<int, string>>();
}

void graph::BFS(const string&)
{
}

void graph::addvertex(const string& name)
{
	Vertex* v = new Vertex(name);
	work[name] = v;                   //add to vertexes list
	vertices.push_back(v);
	numV++;
}

void graph::addedge(string& from, string& to, int cost)
{
	vector<Edge*>::iterator i;
	for (i = edges.begin(); i != edges.end(); i++)
	{
		if ((i->vertex1->name == from && i->vertex2->name == to) || (i->vertex1->name == to && i->vertex2->name == from))
		{
			cout << "рясп╢к╠ъ" << endl;
			return;
		}
		Vertex* v1 = work[from];
		Vertex* v2 = work[to];
		Edge* temp = new Edge(v1,v2,cost);
		edges.push_back(temp);
	}
}
