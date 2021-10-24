#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if (q->size == MAX_QUEUE_SIZE) {
		printf("ENQUEUE fail!\n");
		return;
	}
	q->proc[q->size] = proc;
	q->size++;
	printf("ENQUEUE successful!\n");
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size == 0) {
		printf("DEQUEUE fail!\n");
		return NULL;
	}
	int index = 0;
	struct pcb_t *temp = q->proc[0];
	for (int i = 0; i < q->size; i++) {
		if (q->proc[i]->priority > temp->priority) {
			index = i;
			temp = q->proc[i];
		}
	}
	q->proc[index] = NULL;
	q->size--;
	printf("DEQUEUE successful!\n");
	return temp;
}

