#pragma once
typedef enum  {
	Q_SUCCESS,
	Q_ERROR
} q_error;

typedef struct {
	int size; // how many elements are in the queue
} queue;

// constructor
// since there's no default constructor like in c++ we will need to write a function (and test) for that
q_error queue_create(queue* q);