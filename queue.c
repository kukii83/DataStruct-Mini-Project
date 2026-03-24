#include <stdio.h>
#include <string.h>

#define max_size 10
#define name_length 50

typedef struct {
    char customers[max_size][name_length];
    int front;
    int rear;
    int count;
} TicketQueue;

//initialize queue
void initQueue(TicketQueue *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

//check if full
int isFull(TicketQueue *queue) {
    return queue->count == max_size;
}

//check if empty
int isEmpty(TicketQueue *queue) {
    return queue->count == 0;
}

//enqueue
void joinLine(TicketQueue *queue, char *name) {
    if (isFull(queue)) {
        printf("[ERROR] Line is full!\n");
        return;
    }
    queue->rear = (queue->rear + 1) % max_size;
    strcpy(queue->customers[queue->rear], name);
    queue->count++;
    printf("[JOINED] %s joined the line.\n", name);
}

//dequeue
void serveCustomer(TicketQueue *queue) {
    if (isEmpty(queue)) {
        printf("[INFO] No one in line.\n");
        return;
    }
    printf("[SERVED] %s\n", queue->customers[queue->front]);
    queue->front = (queue->front + 1) % max_size;
    queue->count--;
}

//peek
void whoIsNext(TicketQueue *queue) {
    if (isEmpty(queue)) {
        printf("[INFO] No one waiting.\n");
        return;
    }
    printf("[NEXT] %s\n", queue->customers[queue->front]);
}

//display
void showQueue(TicketQueue *queue) {
    if (isEmpty(queue)) {
        printf("[QUEUE EMPTY]\n");
        return;
    }

    printf("\n--- Queue ---\n");
    for (int i = 0; i < queue->count; i++) {
        int index = (queue->front + i) % max_size;
        if (i == 0)
            printf("[FRONT] %s\n", queue->customers[index]);
        else if (i == queue->count - 1)
            printf("[REAR ] %s\n", queue->customers[index]);
        else
            printf("        %s\n", queue->customers[index]);
    }
    printf("-------------\n");
}

int main() {
    TicketQueue counter;
    int choice;
    char name[name_length];

    initQueue(&counter);

    do {
        printf("\n===== Ticket Counter Menu =====\n");
        printf("1. Join line (ENQUEUE)\n");
        printf("2. Serve customer (DEQUEUE)\n");
        printf("3. Who is next?\n");
        printf("4. Show queue\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, name_length, stdin);
                name[strcspn(name, "\n")] = '\0';
                joinLine(&counter, name);
                break;

            case 2:
                serveCustomer(&counter);
                break;

            case 3:
                whoIsNext(&counter);
                break;

            case 4:
                showQueue(&counter);
                break;

            case 0:
                printf("Closing counter...\n");
                break;

            default:
                printf("[ERROR] Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}