#pragma once

struct Queue;

Queue* makeQueue();

void enqueue(Queue *queue, int value);

int dequeue(Queue *queue);

void deleteQueue(Queue *queue);