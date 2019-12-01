#pragma once
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct node
{
	struct node* left;
	struct node* right;
	string word;
	int weight;
}tree_node;

class huffman
{
private:
	tree_node* huff_root;
public:
	tree_node* get_root();
	map<string, string> str_code;
	huffman(vector<pair<string, int>>);
	void get_code(tree_node* root, string code="");
};
