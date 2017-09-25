#include "queue.h"

#define NQ 100000+7

static int queue[NQ];
static int front, back;

void QUEUEinit() {
    front = back = 0;
}

void QUEUEinsert(int v) {
    queue[back++] = v;
}

int QUEUEempty() {
    return back == front;
}

int QUEUEpop() {
    return queue[front++];
}

