#pragma once
#include<iostream>
#include<string>

using namespace std;

typedef struct
{
	tree_node* left;
	tree_node* right;
	string word;
	int weight;
}tree_node;

