#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


//AHMET SENYUVA 181180067


typedef struct Node Node;
typedef struct Queue Queue;

struct Node
{
	Node* next;
	char* data;
	int number;
};

struct Queue
{
	Node* head;
	Node* tail;
};

Queue* list;

Queue* create_queue();
//void enqueue(Node*, Queue*);
void enqueue_seq(Node*, Queue*);
Node* create_node();
bool is_queue_empty(Queue*);
bool search_node(int);

void read_commands()
{
	FILE* input = fopen("Data.dat", "r");

	if (!input)
		return;

	char str[80];
	char* data_ptr;
	char* num_ptr;
	int num;

	while (fgets(str, 40, input))
	{
		char* ptr = strtok(str, "\n");

		if (!ptr)
			return;

		num_ptr = ptr + strlen(ptr) - 3;
		data_ptr = (char*)calloc(1, 40);

		if(data_ptr)
			strncpy(data_ptr, ptr, strlen(ptr) - 3);

		sscanf(num_ptr, "%d", &num);


		//////////////////
		 if (!search_node(num)) {
			Node* node = create_node();
			node->data = data_ptr;
			node->number = num;
			enqueue_seq(node, list);
		}
	}
}

int main() {

	list = create_queue();
	read_commands();

	FILE* out = fopen("Sorted.dat", "w");
	Node* temp = list->head;

	while (temp)
	{
		printf("%d\t%s\n", temp->number, temp->data);
		fprintf(out, "%d\t%s\n", temp->number, temp->data);
		temp = temp->next;
	}

	fclose(out);
}

Queue* create_queue()
{
	Queue* que = (Queue*)malloc(sizeof(Queue));

	if (!que)
		return NULL;

	que->head = que->tail = NULL;

	return que;
}

/*void enqueue(Node* node, Queue* que)
{
	if (is_queue_empty(que))
	{
		que->head = que->tail = node;
		return;
	}

	que->tail->next = node;
	que->tail = node;
}*/

void enqueue_seq(Node* node, Queue* que)
{

	if (is_queue_empty(que))
	{
		que->head = que->tail = node;
		return;
	}

	Node* temp = que->head;

	while (temp)
	{
		if (!temp->next) // ONLY ONE ITEM IN LIST
		{
			if (temp->number < node->number) // IF NEW ITEM HIGHER
			{
				temp->next = node;
			}
			else // IF NEW ITEM LOWER
			{
				node->next = temp;
				temp = node;
				temp->next = NULL;
			}
			break;
		}

		else if (temp->number < node->number && temp->next->number > node->number)
		{
			node->next = temp->next;
			temp->next = node;
			//temp = node;
			break;
		}
		temp = temp->next;
	}
}

Node* create_node()
{
	Node* node = (Node*)malloc(sizeof(Node));

	if (!node)
		return 0;

	node->next  = NULL;
	node->data = malloc(40 * sizeof(char));

	if (!node->data)
		return 0;

	return node;
}

bool is_queue_empty(Queue* que)
{
	return que->head == NULL;
}

bool search_node(int num) {
	Node* node = list->head;

	while (node) {
		if (node->number == num)
			return true;

		node = node->next;
	}
	return false;
}
