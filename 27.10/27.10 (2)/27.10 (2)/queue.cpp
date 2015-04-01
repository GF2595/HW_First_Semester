#include <cstdlib>
#include <iostream>
#include "queue.h"

using namespace std;

struct QueueElement {
	int value;
	QueueElement *next;
};

struct Queue {
	QueueElement *first;
};

Queue* makeQueue()
{
	Queue *newQueue = new Queue;
	newQueue->first = nullptr;
	
	return newQueue;
}

void enqueue(Queue *queue, int value)
{
	QueueElement *newElement = new QueueElement;
	newElement->value = value;
	newElement->next = nullptr;

	if (queue->first != nullptr)
	{
		QueueElement *temp = queue->first;

		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		temp->next = newElement;
	}
	else
	{
		queue->first = newElement;
	}
}

int dequeue(Queue *queue)
{
	if (queue->first == nullptr)
	{
		return -1;
	}

	QueueElement *temp = queue->first;
	int tempValue = temp->value;

	queue->first = temp->next;	

	delete[]temp;

	return tempValue;
}

void deleteQueue(Queue *queue)
{
	while (queue->first != nullptr)
	{
		QueueElement *temp = queue->first;

		queue->first = temp->next;

		delete[]temp;
	}
}