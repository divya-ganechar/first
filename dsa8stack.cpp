//program that implement Stack (its operations) using Array
#include <iostream>
using namespace std;

const int MAX = 5;   // maximum size of stack

int stackArr[MAX];
int top = -1;        // when top = -1, stack is empty

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(int x) {
    if (isFull()) {
        cout << "Stack is full! Cannot push " << x << "\n";
    } else {
        top = top + 1;
        stackArr[top] = x;
        cout << x << " pushed into stack.\n";
    }
}

int pop() {
    if (isEmpty()) {
        cout << "Stack is empty! Cannot pop.\n";
        return -1;  // indicate error
    } else {
        int value = stackArr[top];
        top = top - 1;
        cout << value << " popped from stack.\n";
        return value;
    }
}

int peek() {
    if (isEmpty()) {
        cout << "Stack is empty! No top.\n";
        return -1;
    } else {
        return stackArr[top];
    }
}

int main() {
    int choice, value;
    while (true) {
        cout << "\n1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek / Top\n";
        cout << "4. Is Empty?\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
        }
        else if (choice == 2) {
            pop();
        }
        else if (choice == 3) {
            int t = peek();
            if (t != -1)
                cout << "Top element is: " << t << "\n";
        }
        else if (choice == 4) {
            if (isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}