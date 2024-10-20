#include<stdio.h>
#include<stdlib.h>

int *stack, max, top = -1;

void push(int ele) {
    if (top == max - 1)
        printf("Stack overflow\n");
    else
        stack[++top] = ele;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return (stack[top--]);
    }
}

void display() {
    int i;
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements are: ");
        for (i = top; i >= 0; i--)
            printf("%d\t", stack[i]);
        printf("\n");
    }
}

void palindrome() {
    int num, rem, ncopy;
    printf("Enter the value of num: ");
    scanf("%d", &num);
    ncopy = num;
    top = -1; // Reset the stack

    // Push all digits of num onto the stack
    while (num != 0) {
        rem = num % 10;
        push(rem);
        num = num / 10;
    }

    // Compare digits from original number with popped digits
    while (ncopy != 0) {
        rem = ncopy % 10;
        if (rem != pop()) {
            printf("Given number is not a palindrome\n");
            top = -1; // Reset the stack
            return;
        }
        ncopy = ncopy / 10;
    }
    printf("It is a palindrome\n");
}

int main() {
    int choice, ele;
    printf("Enter the size of the stack: ");
    scanf("%d", &max);

    // Allocate memory for the stack
    stack = (int*)malloc(max * sizeof(int));

    while (1) {
        printf("\nEnter your choice: \n");
        printf("1 for push\n2 for pop\n3 for display\n4 for palindrome\n5 for exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2:
                ele = pop();
                if (ele != -1)
                    printf("Deleted element is: %d\n", ele);
                break;
            case 3:
                display();
                break;
            case 4:
                palindrome();
                break;
            case 5:
                free(stack); // Free the allocated memory before exit
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
