#include "huffman.h"
//left smaller
bool compare(pair<string, int> a, pair<string, int> b)
{
	return a.second < b.second;
}
tree_node* huffman::get_root()
{
	return this->huff_root;
}
/***************************************

取两个最小权值节点作为左右孩子，
构造新节点，权值为左右孩子之和
放入原集合（若不放回原集合无法得到最短编码）

***************************************/
huffman::huffman(vector<pair<string, int>> freq)
{
	sort(freq.begin(),freq.end(), compare);     //order the frequncy map
	vector<pair<string, int>>::iterator iter;
	tree_node* subroot = NULL;
	tree_node* new_subroot = NULL;

	iter = freq.begin();
	tree_node* left = new tree_node;
	tree_node* right = new tree_node;
	left->left = NULL; left->right = NULL; left->weight = iter->second; left->word = iter->first;
	iter++;
	right->left = NULL; right->right = NULL; right->weight = iter->second; right->word = iter->first;
	subroot = new tree_node;
	subroot->left = left;
	subroot->right = right;
	subroot->weight = left->weight + right->weight;
	subroot->word = "";
	iter++;
	for (; iter != freq.end(); iter++)
	{
		new_subroot = new tree_node;
		tree_node* temp = new tree_node;
		temp->left = NULL; temp->right = NULL; temp->word = iter->first; temp->weight = iter->second;
		if (iter->second <= subroot->weight)
		{
			new_subroot->left = temp;
			new_subroot->right = subroot;
			new_subroot->weight = new_subroot->left->weight + new_subroot->right->weight;
		}
		else 
		{
			new_subroot->left = subroot;
			new_subroot->right = temp;
			new_subroot->weight = new_subroot->left->weight + new_subroot->right->weight;
		}
		subroot = new_subroot;
		new_subroot = NULL;
	}

	huff_root = subroot;
}

void huffman::get_code(tree_node* root, string code)
{
	if (root == NULL)
	{
		return;
	}
	else if (root->left == NULL && root->right == NULL)
	{
		str_code[root->word] = code;
	}
	else
	{
		get_code(root->left, code+"0");
		get_code(root->right, code+"1");
	}
}
