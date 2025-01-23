#include "Queue.h"

// Queue implementation in C

q_error queue_create(queue* q)
{
	q->size = INIT_SIZE; // initial size is defined in header. should be able to expand down the line.
	q->total = 0; // number of elements currently in queue starts at zero
	q->elements = malloc(sizeof(void*) * q->size); // allocate memory as if we had 4 elements in queue.

	if ((q->size == 0)) return Q_ERROR; // for testing purposes.
	else return Q_SUCCESS;
}