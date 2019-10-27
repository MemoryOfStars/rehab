/*
   List Structure Practice
*/

#include<iostream>
#include<stdlib.h>

using namespace std;
typedef struct 
{
	int data = 0;
	node* next = NULL;
}node;

node *head = NULL;
node *tail = NULL;

int CreateList(int data)
{
	node* new_list_head = (node*)malloc(sizeof(node));
	if (new_list_head == NULL) {
		return -1;
	}
	new_list_head->data = data;
	new_list_head->next = NULL;
	head = new_list_head;
	tail = new_list_head;
	return 0;
}

int add_node_tail(int data)
{
	node* new_node = (node*)malloc(sizeof(node));
	if (new_node == NULL) {
		return -1;
	}
	new_node->data = data;
	new_node->next = NULL;
	tail->next = new_node;
	tail = tail->next;
	return 0;
}

int delete_node(int index)
{
	node* list_iter = head;
	for (int i = 0; 
		(list_iter != NULL) && ((i + 1) < index); 
		i++, list_iter = list_iter->next);
	if (list_iter == NULL)
		return -1;
	if (list_iter == head) {
		
	}
	node* target = list_iter->next;
	list_iter->next = list_iter->next->next;
	free(target);
	return 0;
}

void printList(node* list_head)
{
	node* list_iter = list_head;
	while (list_iter != NULL)
	{
		printf("%d\n", list_iter->data);
		list_iter = list_iter->next;
	}
}

int main(char argc, char** argv)
{
	if (CreateList(0) != 0) {
		printf("list init failed\n");
		return;
	}
	for (int i = 0; i < 10; i++) {
		
	}
	return 0;
}