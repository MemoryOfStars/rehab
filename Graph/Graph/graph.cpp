#include<iostream>
#include<stdlib.h>
#include<vector>
#include"structure_define.h"

using namespace std;

int main()
{
	Graph g = Graph();
	g.addvertex("A");
	g.addvertex("B");
	g.addvertex("C");
	g.addvertex("D");
	g.addvertex("E");
	g.addvertex("F");
	g.addedge("A", "B", 4);
	g.addedge("A", "E", 7);
	g.addedge("A", "F", 3);
	g.addedge("B", "C", 20);
	g.addedge("B", "D", 10);
	g.addedge("C", "F", 6);
	g.addedge("D", "E", 11);
	g.MSTKruskal();
	return 0;
}