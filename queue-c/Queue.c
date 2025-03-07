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


//void* queue_firstelem(queue* q)
//{
//	// accesses the first element IF there actually is something in the queue
//	if (q->total > 0) 	return q->elements[0];
//
//	else return NULL;
//}

//void* queue_lastelem(queue* q) 
//{
//	// the last element is always the total elements - 1 (arrays start at 0). only access if something is actually in the queue.
//	if (q->total > 0) 	return q->elements[q->total - 1];
//	else return NULL;
//}

// this function replaces the two above functions!
void* queue_getelem(queue* q, char mode) 
{
	int target;
	if (q->total > 0)
	{
		switch (mode)
		{
		case 'f': // 'f'irst
			target = 0;
			break;
		case 'l': // 'l'ast
			target = q->total - 1;
			break;
		default: // ANYTHING ELSE
			return NULL;
		}
		return q->elements[target];
	}
	else return NULL;
}

q_error queue_remove(queue* q) {
	// note that if the size of q is 0 then there is no first value to remove!
	if (q->total == 0) return Q_ERROR;

	// the general algorithm is as follows:
	// - set the first value to NULL
	q->elements[0] = NULL;
	// - shift all other values in the queue to the left.
	for (int i = 0; i < q->total - 1; i++) {
		q->elements[i] = q->elements[i + 1];
		q->elements[i + 1] = NULL;
	}
	
	// decreases the total items in the queue object by 1 after shift.
	q->total--;
	return Q_SUCCESS;
}

q_error queue_destroy(queue* q) 
{
	free(q->elements); // free up void pointers taken up by the element info
	q->size = 0;
	q->total = 0;

	// check if all have been cleared
	if ((q->size == 0) && (q->total == 0)) return Q_SUCCESS;

	else return Q_ERROR;
}