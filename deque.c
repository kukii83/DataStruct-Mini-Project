#include <stdio.h>
#include <string.h>

#define max 5
#define len 50

typedef struct {
    char data[max][len];
    int front, rear, count;
} Deque;

//initialize
void init(Deque *dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->count = 0;
}

//rear
void insertRear(Deque *dq, char *val) {
    if (dq->count == max) {
        printf("Full!\n");
        return;
    }
    dq->rear = (dq->rear + 1) % max;
    strcpy(dq->data[dq->rear], val);
    dq->count++;
}

//fromt
void insertFront(Deque *dq, char *val) {
    if (dq->count == max) {
        printf("Full!\n");
        return;
    }
    dq->front = (dq->front - 1 + max) % max;
    strcpy(dq->data[dq->front], val);
    dq->count++;
}

//hps front
void deleteFront(Deque *dq) {
    if (dq->count == 0) {
        printf("Empty!\n");
        return;
    }
    printf("Removed: %s\n", dq->data[dq->front]);
    dq->front = (dq->front + 1) % max;
    dq->count--;
}

//hps rear
void deleteRear(Deque *dq) {
    if (dq->count == 0) {
        printf("Empty!\n");
        return;
    }
    printf("Removed: %s\n", dq->data[dq->rear]);
    dq->rear = (dq->rear - 1 + max) % max;
    dq->count--;
}

//show
void show(Deque *dq) {
    if (dq->count == 0) {
        printf("Empty\n");
        return;
    }
    printf("Deque: ");
    for (int i = 0; i < dq->count; i++) {
        int idx = (dq->front + i) % max;
        printf("%s ", dq->data[idx]);
    }
    printf("\n");
}

int main() {
    Deque dq;
    char cmd, value[len];

    init(&dq);

    printf("Commands:\n");
    printf("r = insert rear\n");
    printf("f = insert front\n");
    printf("dr = delete rear\n");
    printf("df = delete front\n");
    printf("s = show\n");
    printf("q = quit\n\n");

    while (1) {
        printf("Enter command: ");
        scanf("%s", &cmd);

        if (cmd == 'r') {
            printf("Value: ");
            scanf("%s", value);
            insertRear(&dq, value);
        }
        else if (cmd == 'f') {
            printf("Value: ");
            scanf("%s", value);
            insertFront(&dq, value);
        }
        else if (cmd == 'd') {
            char type;
            scanf(" %c", &type);
            if (type == 'r') deleteRear(&dq);
            else if (type == 'f') deleteFront(&dq);
        }
        else if (cmd == 's') {
            show(&dq);
        }
        else if (cmd == 'q') {
            break;
        }
    }

    return 0;
}