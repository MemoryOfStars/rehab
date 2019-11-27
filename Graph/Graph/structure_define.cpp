#include "structure_define.h"

bool compare(Edge* a, Edge* b)
{
	return a->weight < b->weight;
}
void Vertex::print_neightbors()
{
	vector<pair<int, Vertex*>>::iterator i;
	for (i = adj.begin(); i != adj.end(); i++)
	{
		cout<<i->second->name<<endl;
	}
}


void Graph::MSTPrim(string start)
{
	int* lowcost = new int[numV];
	int* mst     = new int[numV];
	for (int i = 0; i < numV; i++)
	{
		lowcost[i] = -1;
		mst[i]     = (int)start[0] - 65;    //all nodes' father is start
	}
	mst[(int)start[0] - 65] = 0;
	lowcost[(int)start[0] - 65] = 0;

	vector<Edge*> mini_tree;
	vector<Vertex*> mini_nodes;

	mini_nodes.push_back(work[start]);
	Vertex* temp = work[start];
	vector<pair<int, Vertex*>>::iterator iter;
	int adj_index;                    //邻接表中的节点序号
	int new_node_index;
	int new_edge_index;
	
	while (mini_nodes.size() < numV)
	{
		int cost_temp = -1;
		//改动mst和lowcost
		for (iter = temp->adj.begin(); iter != temp->adj.end(); iter++)
		{
			adj_index = (int)(iter->second->name[0]) - 65;
			if (mst[adj_index] != -1)//node not in mst
			{
				if (lowcost[adj_index] == -1 || lowcost[adj_index] >= iter->first)//当前点不可达 或 通过temp到达当前点的距离更近
				{
					lowcost[adj_index] = iter->first;
					mst[adj_index] = temp->name[0] - 65;
				}
			}
		}
		for (int i = 0; i < numV; i++)
		{
			//cant reach                    already in mst                 smaller edge cost                      
			if ((lowcost[i] != -1) && (lowcost[i] != 0) && ((lowcost[i] < cost_temp) || (cost_temp == -1)))
			{
				cost_temp = lowcost[i];
				new_node_index = i;
			}
		}
		for (int i = 0; i < edges.size(); i++)
		{
			if (((edges[i]->vertex1 == node_index[mst[new_node_index]]) && (edges[i]->vertex2 == node_index[new_node_index])) ||
				((edges[i]->vertex2 == node_index[mst[new_node_index]]) && (edges[i]->vertex1 == node_index[new_node_index])))
			{
				new_edge_index = i;
				break;
			}
		}
		temp = node_index[new_node_index];
		mini_nodes.push_back(temp);
		mini_tree.push_back(edges[new_edge_index]);
		lowcost[new_node_index] = 0;
		mst[new_node_index] = 0;
	}
	for (int i = 0; i < mini_tree.size(); i++)
	{
		cout << mini_tree[i]->vertex1->name << "-->" << mini_tree[i]->vertex2->name << endl;
	}
}

void Graph::MSTKruskal()
{
	vector<Edge*> mini_tree;

	int* father = new int[numV];
	int* rank   = new int[numV];

	vector<Edge*>::iterator iter;
	for (int i = 0; i < numV; i++)
	{
		father[i] = i;
		rank[i] = 1;
	}
	sort(edges.begin(),edges.end(),compare);    //compare:returns whether a's cost<b's cost

	for (int i = 0;i < edges.size(); i++)
	{
		int index1 = (int)edges[i]->vertex1->name[0] - 65;
		int index2 = (int)edges[i]->vertex2->name[0] - 65;
		if (father[index1] != father[index2])  //not in the same set
		{
			mini_tree.push_back(edges[i]);
			if (rank[index1] >= rank[index2])  //merge two set
			{
				for (int j = 0; j < numV; j++)
				{
					if (father[j] == father[index1])
						rank[j] += rank[index2];
				}
				rank[index2] = rank[index1];
				father[index2] = father[index1];
			}
			else
			{
				for (int j = 0; j < numV; j++)
				{
					if (father[j] == father[index2])
						rank[j] += rank[index1];
				}
				rank[index1] = rank[index2];
				father[index1] = father[index2];
			}
		}
	}

	for (int i = 0; i < mini_tree.size(); i++)
	{
		cout << mini_tree[i]->vertex1->name << "->" << mini_tree[i]->vertex2->name << endl;
	}
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

void Graph::DFS(const string& start)
{
	stack<Vertex*> s;
	bool *visited = new bool[numV];
	for (int i = 0; i < numV; i++) { visited[i] = false; }
	s.push(work[start]);
	while (!s.empty())
	{
		Vertex* temp = s.top();
		int index = (int)(temp->name[0]) - 65;
		vector<pair<int, Vertex*>>::iterator iter;
		if (!visited[index])
		{
			cout << temp->name << endl;
			visited[index] = true;
		}
		for (iter = temp->adj.begin(); iter != temp->adj.end(); iter++)
		{
			if (!visited[(int)iter->second->name[0] - 65])
			{
				s.push(iter->second);
				break;
			}
		}
		if (iter == temp->adj.end())
			s.pop();
	}
}

void Graph::addvertex(const string& name)
{
	Vertex* v = new Vertex(name);
	work[name] = v;                   //add to vertexes list
	node_index[numV] = v;
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
			cout << "已有此边" << endl;
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
