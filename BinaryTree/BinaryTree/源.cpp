#include<iostream>
#include<stack>

using namespace std;

typedef struct tree_node
{
	struct tree_node* parent;
	struct tree_node* left;
	struct tree_node* right;
	char data;
}node;

string stri = "dca##b##efg##h###";

void createLeftChild(node* root, node* left, char data)
{
	root->left = left;
	left->parent = root;
	left->data = data;
	left->left = NULL;
	left->right = NULL;
}

void createRightChild(node* root, node* right, char data)
{
	root->right = right;
	right->parent = root;
	right->data = data;
	right->left = NULL;
	right->right = NULL;
}


node* create_tree(string str)
{
	node* T = (node*)malloc(sizeof(node));
	T->data = str[0];
	T->left = NULL;
	T->right = NULL;
	//putchar(T->data);
	stack<node*> stk;
	stk.push(T);
	int id = 1;
	while (!stk.empty())
	{
		node* temp = stk.top();
		if (stk.top()->left == NULL&&str[id-1] != '#')
		{
			if (str[id] != '#')
			{
				node* new_node = (node*)malloc(sizeof(node));
				createLeftChild(stk.top(), new_node, str[id]);
				stk.push(new_node);
			}
			id++;
		}
		else
		{
			if (stk.top()->right == NULL)
			{
				if (str[id] != '#')
				{
					node* new_node = (node*)malloc(sizeof(node));
					createRightChild(stk.top(),new_node,str[id]);
					stk.push(new_node);
				}
				else 
				{
					stk.pop();
				}
				id++;
			}
			else
			{
				stk.pop();
			}
		}
	}
	return T;
}

void later(node* root)
{
	if (root == NULL)
	{
		return;
	}
	else 
	{
		later(root->left);
		later(root->right);
		putchar(root->data);
	}
}

int main()
{
	node* T = create_tree(stri);
	//putchar(T->left->data);
	later(T);
}