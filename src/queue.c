#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if (q->size == MAX_QUEUE_SIZE) {						// if size == 0, return nothing.
		// printf("ENQUEUE fail!\n");
		return;
	}
	q->proc[q->size] = proc;								// push new proc at the end.
	q->size++;
	// printf("ENQUEUE successful!\n");
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size == 0) {										// if size == MAXSIZE, return NULL.
		// printf("DEQUEUE fail!\n");
		return NULL;
	}
	int index = 0;
	struct pcb_t *temp = q->proc[0];
	for (int i = 0; i < q->size; i++) {						// using loop to findout the highest pri porc.
		if (q->proc[i]->priority > temp->priority) {
			index = i;
			temp = q->proc[i];
		}
	}
	q->proc[index] = q->proc[q->size - 1];					// move the last proc to highest pri proc.
	q->proc[q->size - 1] = NULL;							// assign the last proc to NULL.
	q->size--;												// size -= 1.
	// printf("DEQUEUE successful!\n");
	return temp;
}

