
#include <iostream>
using namespace std;

class Node {
public:
    char data[50];
    Node* next;
};

Node* top = NULL;

void push() {
    Node* newnode = new Node;

    cout << "Enter task: ";
    cin >> newnode->data;

    newnode->next = top;
    top = newnode;

    cout << "Task added successfully\n";
}

void pop() {
    if (top == NULL) {
        cout << "Stack is Empty\n";
    }
    else {
        Node* temp = top;

        cout << "Removed task: " << temp->data << endl;

        top = top->next;
        delete temp;
    }
}

void peek() {
    if (top == NULL) {
        cout << "Stack is Empty\n";
    }
    else {
        cout << "Top task: " << top->data << endl;
    }
}

void display() {
    if (top == NULL) {
        cout << "Stack is Empty\n";
    }
    else {
        Node* temp = top;

        cout << "Stack elements:\n";

        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}




// queue

//#include <iostream>
// using namespace std;

// class Node {
// public:
//     char data[50];
//     Node* next;
// };

// Node* front = NULL;
// Node* rear = NULL;

// void enqueue() {
//     Node* newnode = new Node;

//     cout << "Enter task: ";
//     cin >> newnode->data;

//     newnode->next = NULL;

//     if (front == NULL) {
//         front = rear = newnode;
//     }
//     else {
//         rear->next = newnode;
//         rear = newnode;
//     }

//     cout << "Task added successfully\n";
// }

// void dequeue() {
//     if (front == NULL) {
//         cout << "Queue is Empty\n";
//     }
//     else {
//         Node* temp = front;

//         cout << "Removed task: " << temp->data << endl;

//         front = front->next;

//         if (front == NULL) {
//             rear = NULL;
//         }

//         delete temp;
//     }
// }

// void peek() {
//     if (front == NULL) {
//         cout << "Queue is Empty\n";
//     }
//     else {
//         cout << "Front task: " << front->data << endl;
//     }
// }

// void display() {
//     if (front == NULL) {
//         cout << "Queue is Empty\n";
//     }
//     else {
//         Node* temp = front;

//         cout << "Queue elements:\n";

//         while (temp != NULL) {
//             cout << temp->data << endl;
//             temp = temp->next;
//         }
//     }
// }

// int main() {
//     int choice;

//     do {
//         cout << "\n--- QUEUE MENU ---\n";
//         cout << "1. Enqueue\n";
//         cout << "2. Dequeue\n";
//         cout << "3. Peek\n";
//         cout << "4. Display\n";
//         cout << "5. Exit\n";

//         cout << "Enter choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 enqueue();
//                 break;

//             case 2:
//                 dequeue();
//                 break;

//             case 3:
//                 peek();
//                 break;

//             case 4:
//                 display();
//                 break;

//             case 5:
//                 cout << "Exit\n";
//                 break;

//             default:
//                 cout << "Invalid choice\n";
//         }

//     } while (choice != 5);

//     return 0;
// }
