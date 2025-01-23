#pragma once
#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 4
typedef enum  {
	Q_SUCCESS,
	Q_ERROR
} q_error;

typedef struct queue {
	void** elements; // element values
	int total; // current number of items in queue
	int size; // maximum items in queue
} queue;

// constructor
// since there's no default constructor like in c++ we will need to write a function (and test) for that
q_error queue_create(queue* q);

// check the size of the queue
int queue_size(queue* q);

// adds an element to the end of the queue
q_error queue_add(queue* q, void* element);

// returns the first element of the queue
void* queue_firstelem(queue* q);