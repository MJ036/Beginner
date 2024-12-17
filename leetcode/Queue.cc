#include "mai.h"
using namespace std;
#define DEFAULT_CAPACITY 8
#define MAX_PREALLOC 1024
typedef int E;
 
typedef struct {
    E* elements;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;
 
// API
Queue* queue_create();
void queue_destroy(Queue* q);
 
void queue_push(Queue* q, E val);
E queue_pop(Queue* q);
E queue_peek(Queue* q);
 
bool queue_empty(Queue* q);



// API
Queue* queue_create() {
	Queue* q = calloc(1,sizeof(Queue));
	if (!q) {
		printf("create Queue failed");
		exit(1);
	}
	q->elements = malloc(DEFAULT_CAPACITY * sizeof(E));
	q->capacity = DEFAULT_CAPACITY;
	return q;
}
void queue_destroy(Queue* q) {
	free(q->elements);
	free(q);
	return;
}

void grow_capacity(Queue* q) {
	int new_capacity = q->capacity < MAX_PREALLOC ? q->capacity << 1 : q->capacity + MAX_PREALLOC;
	//不能realloc，如果换了一片内存空间，front和rear的指向也要改变
	E* new_element = malloc(new_capacity * sizeof(E));
	if (!new_element) {
		printf("grow Queue failed");
		exit(1);
	}
	for (int i = 0; i < q->size; i++) {
		new_element[i] = q->elements[(q->front + i) % q->capacity];
	}
	q->elements = new_element;
	free(q);
	q->front = 0;
	q->rear = q->size;
	q->capacity = new_capacity;
}

//队尾添加，队头删除
void queue_push(Queue* q, E val) {
	if (q->size == q->capacity) {
		grow_capacity(q);
	}
	q->elements[q->rear] = val;
	q->rear = (q->rear + 1) % q->capacity;
	q->size++;
}
E queue_pop(Queue* q) {
	if (queue_empty(q)) {
		printf("Error: queue is empty\n");
		exit(1);
	}
	E val = q->elements[q->front];
	q->front = (q->front + 1) % q->capacity;
	q->size--;
	return val;
}
E queue_peek(Queue* q) {
	if (queue_empty(q)) {
		printf("Queue is null");
		exit(1);
	}
	return q->elements[q->front];
}

bool queue_empty(Queue* q) {
	return q->size == 0;
}


