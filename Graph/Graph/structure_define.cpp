#include "structure_define.h"


void Vertex::print_neightbors()
{
	vector<pair<int, Vertex*>>::iterator i;
	for (i = adj.begin(); i != adj.end(); i++)
	{
		cout<<i->second->name<<endl;
	}
}


void Graph::MSTPrim(string)
{
}

void Graph::MSTKruskal()
{
}

map<string, pair<int, string>> Graph::Dijkstra(string start)
{
	return map<string, pair<int, string>>();
}

void Graph::BFS(const string& start)
{
	queue<Vertex*> q;
	bool* visited = new bool[numV];
	for (int i = 0; i < numV; i++)visited[i] = false; //initialize visited[]
	q.push(work[start]);
	while (!q.empty())
	{
		Vertex* temp = q.front();
		int index = (int)(temp->name[0]) - 65;
		vector<pair<int, Vertex*>>::iterator iter;
		if (!visited[index])
		{
			cout << temp->name << endl;
			visited[index] = true;
			for (iter = temp->adj.begin(); iter != temp->adj.end(); iter++)
			{
				q.push(iter->second);
			}
		}
		q.pop();
	}
}

void Graph::DFS(const string&)
{
}

void Graph::addvertex(const string& name)
{
	Vertex* v = new Vertex(name);
	work[name] = v;                   //add to vertexes list
	vertices.push_back(v);
	numV++;
}

void Graph::addedge(const string& from, const string& to, int cost)
{
	//vector<Edge*>::iterator i;
	int i = 0;
	for (; i < edges.size(); i++)
	{
		if ((edges[i]->vertex1->name == from && edges[i]->vertex2->name == to) ||
			(edges[i]->vertex1->name == to && edges[i]->vertex2->name == from))
		{
			cout << "рясп╢к╠ъ" << endl;
			return;
		}
	}
	Vertex* v1 = work[from];
	Vertex* v2 = work[to];
	Edge* temp = new Edge(v1,v2,cost);
	edges.push_back(temp);
	pair<int, Vertex*> adj1 = make_pair(cost, v2);  //add to v1's adj
	pair<int, Vertex*> adj2 = make_pair(cost, v1);  //add to v2's adj
	v1->adj.push_back(adj1);
	v2->adj.push_back(adj2);
	
}
