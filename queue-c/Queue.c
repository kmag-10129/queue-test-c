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

int queue_size(queue* q) 
{
	return q->total;
}

q_error queue_add(queue* q, void* element) 
{
	// store the initial total
	int preTotal = q->total;

	// if we have hit the maximum size...
	if (q->size == q->total) {
		int size = q->size * 2; // double the maximum size
		void** elements = realloc(q->elements, sizeof(void*) * size); // reallocate more memory, double the maximum size of the queue.
		if (elements) {
			q->elements = elements; // reassign the queue elements to the larger memory version
			q->size = size; // update the maximum size of the queue
		}
	}



	q->elements[q->total++] = element; // assign element to the next free space in the queue.
	
	if (q->total > preTotal) return Q_SUCCESS;
	else return Q_ERROR;
}

void* queue_firstelem(queue* q)
{
	
}