# CE-ESY-assignments

Circular Buffer Implementation (C)

This program implements a fixed-size circular buffer to store and retrieve characters.


---

Data Structure

buffer[SIZE]: array used to store data

head: index where the next element will be written

tail: index where the next element will be read

count: current number of elements in the buffer



---

Core Functions

init()
Initializes the buffer by setting:

head = 0

tail = 0

count = 0



---

isFull()
Returns true if:

count == SIZE


---

isEmpty()
Returns true if:

count == 0


---

writeBuffer()

Writes a character at head index

Moves head forward using:


(head + 1) % SIZE

Increases count

If buffer is full → prints "Buffer Overflow" and ignores input



---

readBuffer()

Reads a character from tail index

Moves tail forward using:


(tail + 1) % SIZE

Decreases count

If buffer is empty → prints "Buffer Underflow"



---

Main Function Flow

1. Initialize buffer


2. Read user input (name)


3. Append "CE-ESY" to the name


4. Write each character into the buffer


5. Read characters from buffer and print them


6. Loop continues until buffer becomes empty




---

Key Behavior

The buffer uses circular indexing to reuse array space

Writing continues from the beginning after reaching the end

Overflow occurs when trying to write into a full buffer

Underflow occurs when trying to read from an empty buffer



---

Example

Input:

Ali

After appending:

ahmadCE-ESY

If SIZE = 5:

Only first 5 characters stored

Remaining characters cause Overflow


Output:

ahmad


---

Notes

All operations run in constant time O(1)

No dynamic memory allocation is used

Suitable for embedded systems applications
