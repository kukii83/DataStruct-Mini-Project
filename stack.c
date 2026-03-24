#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10
#define URL_LENGTH 100

typedef struct {
    char pages[MAX_SIZE][URL_LENGTH];
    int top;
} BrowserStack;

//initialize stack
void initStack(BrowserStack *stack) {
    stack->top = -1;
}

//check if full
int isFull(BrowserStack *stack) {
    return stack->top == MAX_SIZE - 1;
}

//check if empty
int isEmpty(BrowserStack *stack) {
    return stack->top == -1;
}

//visit func(push)
void visitPage(BrowserStack *stack, char *url) {
    if (isFull(stack)) {
        printf("[ERROR] History is full!\n");
        return;
    }
    stack->top++;
    strcpy(stack->pages[stack->top], url);
    printf("[VISITED] %s\n", url);
}

//back func(pop)
void goBack(BrowserStack *stack) {
    if (isEmpty(stack)) {
        printf("[ERROR] No history!\n");
        return;
    }
    printf("[BACK] Leaving: %s\n", stack->pages[stack->top]);
    stack->top--;
}

//current func(peek)
void currentPage(BrowserStack *stack) {
    if (isEmpty(stack)) {
        printf("[INFO] No page loaded.\n");
        return;
    }
    printf("[CURRENT] %s\n", stack->pages[stack->top]);
}

//history func (shows all elements in stack)
void showHistory(BrowserStack *stack) {
    if (isEmpty(stack)) {
        printf("[HISTORY EMPTY]\n");
        return;
    }

    printf("\n--- History ---\n");
    for (int i = stack->top; i >= 0; i--) {
        if (i == stack->top)
            printf("[TOP] %s\n", stack->pages[i]);
        else
            printf("      %s\n", stack->pages[i]);
    }
    printf("----------------\n");
}

int main() {
    BrowserStack history;
    int choice;
    char url[URL_LENGTH];

    initStack(&history);

    do {
        printf("\n===== Browser Menu =====\n");
        printf("1. Visit new page\n");
        printf("2. Go back\n");
        printf("3. Show current page\n");
        printf("4. Show history\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(url, URL_LENGTH, stdin);

                visitPage(&history, url);
                break;

            case 2:
                goBack(&history);
                break;

            case 3:
                currentPage(&history);
                break;

            case 4:
                showHistory(&history);
                break;

            case 0:
                printf("Exiting browser...\n");
                break;

            default:
                printf("[ERROR] Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}