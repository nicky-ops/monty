# 0x19. C - Stacks, Queues - LIFO, FIFO
* A variable is declared when the compiler is informed that a variable exists (and this is its type); it does not allocate the storage for the variable at that point.
* A variable is defined when the compiler allocates the storage for the variable.
## Stacks
* A stack is a linear data structure that follows the LIFO(Last in fisrts out) rule. Both insertion and deletion takes place from one end. A stack can be implemented in two ways:
1. Statically: allows the static memory alocation of its data elements. The stack inherits all the characteristics of an array.
2. Dynamically: dynamic memoty allocation of its data elements. The stack inherits all the characterisitics of a linked list.
### Applications of Stacks in C
* Number reversal: A stack helps you reverse a number or a word entered as a sequence of digits or characters respectively.
* Undo operation: Implementation of a stack helps you perform the “undo” operation in text editors or word processors. Here, all the changes done in the text editor are stored in a stack.
* Infix to postfix conversion: Using stacks, you can perform the conversion of an infix expression to a postfix expression.
* Backtracking: Stacks are finding applications in puzzle or maze problem-solving.
* Depth-first search (DFS): Stacks allow you to perform a searching algorithm called the depth-first search.

## Queues in C
* A queue is a linear data structure that follows the FIFO(first in first out rule). Insertion is done from the back (the rear end) and deletion is done from the front. A queue can be implemented in two ways:
1. Statically: Array implementation of queues allows the static memory allocation of its data elements.
2. Dynamically: Linked list implementation of queues follow the dynamic memory allocation of its data elements. 

