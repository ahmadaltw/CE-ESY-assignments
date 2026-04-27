#include <stdio.h>
#include <string.h>

#define SIZE 5   // Buffer size

// Circular buffer structure
typedef struct {
    char buffer[SIZE];
    int head;   // write index
    int tail;   // read index
    int count;  // number of elements
} CircularBuffer;

// Initialize buffer
void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// Check if buffer is full
int isFull(CircularBuffer *cb) {
    return (cb->count == SIZE);
}

// Check if buffer is empty
int isEmpty(CircularBuffer *cb) {
    return (cb->count == 0);
}

// Write data to buffer
void writeBuffer(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow\n");
        return;
    }

    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE;  // move head
    cb->count++;
}

// Read data from buffer
char readBuffer(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow\n");
        return '\0';
    }

    char data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE;  // move tail
    cb->count--;

    return data;
}

int main() {
    CircularBuffer cb;
    init(&cb);

    char name[50];

    // Read input
    printf("Enter your name: ");
    scanf("%s", name);

    // Add required text
    strcat(name, "CE-ESY");

    // Write characters to buffer
    for (int i = 0; i < strlen(name); i++) {
        writeBuffer(&cb, name[i]);
    }

    // Read and print from buffer
    while (!isEmpty(&cb)) {
        printf("%c", readBuffer(&cb));
    }

    printf("\n");

    return 0;
}
