#include <stdio.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Deque;

void init(Deque *dq){
    dq->front = -1;
    dq->rear = -1;
}

int empty(Deque *dq){
    return dq->front == -1;
}

int size(Deque *dq){
    if(empty(dq)) return 0;
    return dq->rear - dq->front + 1;
}

void push_front(Deque *dq, int val){
    if(dq->front == 0){
        printf("Overflow\n");
        return;
    }
    if(empty(dq)){
        dq->front = dq->rear = 0;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = val;
}

void push_back(Deque *dq, int val){
    if(dq->rear == MAX-1){
        printf("Overflow\n");
        return;
    }
    if(empty(dq)){
        dq->front = dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = val;
}

void pop_front(Deque *dq){
    if(empty(dq)){
        printf("Underflow\n");
        return;
    }
    if(dq->front == dq->rear){
        dq->front = dq->rear = -1;
    } else {
        dq->front++;
    }
}

void pop_back(Deque *dq){
    if(empty(dq)){
        printf("Underflow\n");
        return;
    }
    if(dq->front == dq->rear){
        dq->front = dq->rear = -1;
    } else {
        dq->rear--;
    }
}

int front(Deque *dq){
    if(empty(dq)) return -1;
    return dq->arr[dq->front];
}

int back(Deque *dq){
    if(empty(dq)) return -1;
    return dq->arr[dq->rear];
}

void clear(Deque *dq){
    dq->front = dq->rear = -1;
}

void reverse(Deque *dq){
    int i = dq->front, j = dq->rear;
    while(i < j){
        int temp = dq->arr[i];
        dq->arr[i] = dq->arr[j];
        dq->arr[j] = temp;
        i++;
        j--;
    }
}

void display(Deque *dq){
    if(empty(dq)){
        printf("Deque is empty\n");
        return;
    }
    for(int i = dq->front; i <= dq->rear; i++){
        printf("%d ", dq->arr[i]);
    }
    printf("\n");
}

int main(){
    Deque dq;
    init(&dq);

    push_back(&dq,10);
    push_back(&dq,20);
    push_front(&dq,5);
    push_back(&dq,30);

    printf("Deque: ");
    display(&dq);

    printf("Front: %d\n", front(&dq));
    printf("Back: %d\n", back(&dq));
    printf("Size: %d\n", size(&dq));

    pop_front(&dq);
    pop_back(&dq);

    printf("After deletion: ");
    display(&dq);

    reverse(&dq);
    printf("After reverse: ");
    display(&dq);

    clear(&dq);
    printf("After clear: ");
    display(&dq);

    return 0;
}