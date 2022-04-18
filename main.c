#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

typedef struct 
{
	int value;
}element;

element queue[SIZE];

int front = -1;
int rear = -1;

// Function Definitions
void print_list();
void add_element(int);
void remove_element();
void options();
void normalize_queue();
bool is_empty();
bool is_full();
bool enqueue(element*);
element* dequeue();

int main() 
{
	options();
	return 0;
}

void print_list()
{
	if (is_empty())
		printf("queue is empty");

	else
	{
		int size = rear - front + 1;
		for (int i = 0; i < size; i++)
			printf("%d ", queue[i].value);
	}
	printf("\n");
}

void add_element(int num)
{
	element* elem = (element*)malloc(sizeof(element));
	elem->value = num;

	// que boşken nası eklicez?
	if (num >= queue[rear].value)
	{
		if (enqueue(elem) == true)
		{
			printf("The element has been successfully added\n");
			//return;
		}
		else if (enqueue(elem) == false)
		{
			printf("The element adding is failed\n");
			//return;
		}
	}
	else
	{
		int size = rear - front + 1;

		if (num < queue[rear].value && num <= queue[front].value)
		{
			if (enqueue(elem) == true)
			{
				printf("The element has been successfully added\n");
				//return;
			}
			else if (enqueue(elem) == false)
			{
				printf("The element adding is failed\n");
				//return;
			}
		}

		for (int i = 0; i < size; i++)
		{
			if (num > queue[rear].value && num <= queue[front].value) //eşitlik durumuna bak
			{
				if (enqueue(elem) == true)
				{
					printf("The element has been successfully added\n");
					//return;
				}
				else if (enqueue(elem) == false)
				{
					printf("The element adding is failed\n");
					//return;
				}
			}
			enqueue(dequeue());
			normalize_queue(); // NORMALIZES THE QUEUE
		}
	}
}

void remove_element()
{
	dequeue();
	normalize_queue();
}

void options()
{
	int input;
	char str[] = "---------OPTIONS--------\n0- Print\n1- Add\n2- Remove\n3- Exit\nSelect (0-3)? :";
	//printf("%s", str);
	int num;

	while (true)
	{
		printf("%s", str);
		scanf("%d", &input);

		switch (input)
		{
		case 0:
			print_list();
			break;
		case 1:
			printf("Enter the value to add: ");
			scanf("%d", &num);
			add_element(num);
			break;
		case 2:
			remove_element();
			break;
		default:
			return 0;
			break;
		}
	}

}

void normalize_queue()
{
	if (front > 0)
	{
		int size = rear - front + 1;
		for (int i = 0; i < size; i++)
		{
			queue[i] = queue[front + i];
		}
		rear = rear - front;
		front = 0;
	}
}

bool is_empty()
{
	if (front == -1 && rear == -1)
		return 1;
	return 0;
}

bool is_full()
{
	if (rear == SIZE - 1)
		return 1;
	return 0;
}

bool enqueue(element* elem)
{
	if (is_full())
		return false;
	else if (is_empty())
		front = rear = 0;
	else
		rear++;
	queue[rear] = *elem;
	return true;
}

element* dequeue()
{
	if (is_empty())
		return;
	else if (front == rear)
	{
		front = rear = -1;
		return &queue[front + 1];
	}
	else
	{
		front++;
		return &queue[front - 1];
	}
}