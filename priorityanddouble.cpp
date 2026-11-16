
#include <iostream>
using namespace std;

int data[20];
int priority[20];
int n = 0;

void insert() {
    int value, p;

    if (n == 20) {
        cout << "Queue is full\n";
        return;
    }

    cout << "Enter element: ";
    cin >> value;

    cout << "Enter priority: ";
    cin >> p;

    int i = n - 1;

    while (i >= 0 && priority[i] < p) {
        data[i + 1] = data[i];
        priority[i + 1] = priority[i];
        i--;
    }

    data[i + 1] = value;
    priority[i + 1] = p;
    n++;

    cout << "Element inserted\n";
}

void deleteElement() {
    if (n == 0) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Deleted element: " << data[0] << endl;

    for (int i = 0; i < n - 1; i++) {
        data[i] = data[i + 1];
        priority[i] = priority[i + 1];
    }

    n--;
}

void display() {
    if (n == 0) {
        cout << "Queue is empty\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "Element: " << data[i];
        cout << " Priority: " << priority[i] << endl;
    }
}

void increasePriority() {
    int value, p;

    cout << "Enter element: ";
    cin >> value;

    cout << "Enter new priority: ";
    cin >> p;

    int i = 0;

    while (i < n && data[i] != value) {
        i++;
    }

    if (i == n) {
        cout << "Element not found\n";
        return;
    }

    if (p < priority[i]) {
        cout << "New priority must be higher\n";
        return;
    }

    for (int j = i; j < n - 1; j++) {
        data[j] = data[j + 1];
        priority[j] = priority[j + 1];
    }

    n--;

    int j = n - 1;

    while (j >= 0 && priority[j] < p) {
        data[j + 1] = data[j];
        priority[j + 1] = priority[j];
        j--;
    }

    data[j + 1] = value;
    priority[j + 1] = p;
    n++;

    cout << "Priority increased\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- PRIORITY QUEUE ---";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display";
        cout << "\n4. Increase Priority";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insert(); break;
            case 2: deleteElement(); break;
            case 3: display(); break;
            case 4: increasePriority(); break;
            case 0: cout << "Exit\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}








// #include <iostream>
// using namespace std;

// #define MAX 5

// int arr[MAX];
// int front = -1;
// int rear = -1;

// bool isFull() {
//     return (front == 0 && rear == MAX - 1) ||
//            (front == rear + 1);
// }

// bool isEmpty() {
//     return front == -1;
// }

// void enqueueFront() {
//     int value;

//     if (isFull()) {
//         cout << "Deque is full\n";
//         return;
//     }

//     cout << "Enter element: ";
//     cin >> value;

//     if (isEmpty()) {
//         front = rear = 0;
//     } else if (front == 0) {
//         front = MAX - 1;
//     } else {
//         front--;
//     }

//     arr[front] = value;
//     cout << "Inserted at front\n";
// }

// void enqueueRear() {
//     int value;

//     if (isFull()) {
//         cout << "Deque is full\n";
//         return;
//     }

//     cout << "Enter element: ";
//     cin >> value;

//     if (isEmpty()) {
//         front = rear = 0;
//     } else if (rear == MAX - 1) {
//         rear = 0;
//     } else {
//         rear++;
//     }

//     arr[rear] = value;
//     cout << "Inserted at rear\n";
// }

// void dequeueFront() {
//     if (isEmpty()) {
//         cout << "Deque is empty\n";
//         return;
//     }

//     cout << "Deleted: " << arr[front] << endl;

//     if (front == rear) {
//         front = rear = -1;
//     } else if (front == MAX - 1) {
//         front = 0;
//     } else {
//         front++;
//     }
// }

// void dequeueRear() {
//     if (isEmpty()) {
//         cout << "Deque is empty\n";
//         return;
//     }

//     cout << "Deleted: " << arr[rear] << endl;

//     if (front == rear) {
//         front = rear = -1;
//     } else if (rear == 0) {
//         rear = MAX - 1;
//     } else {
//         rear--;
//     }
// }

// void display() {
//     if (isEmpty()) {
//         cout << "Deque is empty\n";
//         return;
//     }

//     int i = front;

//     cout << "Deque: ";

//     while (true) {
//         cout << arr[i] << " ";

//         if (i == rear) {
//             break;
//         }

//         i = (i + 1) % MAX;
//     }

//     cout << endl;
// }

// int main() {
//     int choice;

//     do {
//         cout << "\n--- DOUBLE ENDED QUEUE ---";
//         cout << "\n1. Enqueue Front";
//         cout << "\n2. Enqueue Rear";
//         cout << "\n3. Dequeue Front";
//         cout << "\n4. Dequeue Rear";
//         cout << "\n5. Display";
//         cout << "\n0. Exit";

//         cout << "\nEnter choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1: enqueueFront(); break;
//             case 2: enqueueRear(); break;
//             case 3: dequeueFront(); break;
//             case 4: dequeueRear(); break;
//             case 5: display(); break;
//             case 0: cout << "Exit\n"; break;
//             default: cout << "Invalid choice\n";
//         }

//     } while (choice != 0);

//     return 0;
// }
