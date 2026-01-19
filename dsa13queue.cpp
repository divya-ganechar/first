//program that implement Queue(its operations) using Array

#include <iostream>
using namespace std;

#define SIZE 5   // Maximum size of the queue

class Queue {
    int arr[SIZE];  // Array to store queue elements
    int front, rear;

public:
    // Constructor to initialize front and rear
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Check if the queue is full
    bool isFull() {
        return (rear == SIZE - 1);
    }

    // Add (enqueue) element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL!\n";
            return;
        }
        if (front == -1) front = 0;  // First element
        arr[++rear] = value;
        cout << value << " added to the queue.\n";
    }

    // Remove (dequeue) element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << arr[front] << " removed from the queue.\n";
        front++;

        // Reset queue when all elements are removed
        if (front > rear)
            front = rear = -1;
    }

    // Show the front element
    void peek() {
        if (isEmpty())
            cout << "Queue is EMPTY!\n";
        else
            cout << "Front element: " << arr[front] << endl;
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Main function
int main() {
    Queue q;
    int choice, value;

    cout << "\nSimple Queue using Array\n";

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
