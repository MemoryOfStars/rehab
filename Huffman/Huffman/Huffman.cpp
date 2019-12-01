#include "huffman.h"
//left smaller
bool compare(tree_node* a, tree_node* b)
{
	return a->weight < b->weight;
}
tree_node* huffman::get_root()
{
	return this->huff_root;
}
/***************************************

ȡ������СȨֵ�ڵ���Ϊ���Һ��ӣ�
�����½ڵ㣬ȨֵΪ���Һ���֮��
����ԭ���ϣ������Ż�ԭ�����޷��õ���̱��룩

***************************************/
huffman::huffman(vector<pair<string, int>> freq)
{
	tree_node* freq_iter = NULL;
	vector<tree_node*> node_list;
	for (int i = 0; i < freq.size(); i++)
	{
		freq_iter = new tree_node;
		freq_iter->left   = NULL;           freq_iter->right = NULL; 
		freq_iter->weight = freq[i].second; freq_iter->word  = freq[i].first;
		node_list.push_back(freq_iter);
	}
	tree_node* left = NULL;
	tree_node* right = NULL;
	tree_node* subtree = NULL;
	while (node_list.size() > 1)
	{
		sort(node_list.begin(), node_list.end(), compare);
		left = node_list[0];
		right = node_list[1];
		node_list.erase(node_list.begin());
		node_list.erase(node_list.begin());
		subtree = new tree_node;
		subtree->left = left; subtree->right = right;
		subtree->weight = left->weight + right->weight;
		subtree->word = "";
		node_list.push_back(subtree);
	}
	
	huff_root = subtree;
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
