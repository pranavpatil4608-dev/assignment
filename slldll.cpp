
#include <iostream>
using namespace std;

class Node {
public:
    char name[30];
    char phone[15];
    Node* next;
};

Node* head = NULL;

void addContact() {
    Node* newnode = new Node;

    cout << "Enter name: ";
    cin >> newnode->name;

    cout << "Enter phone: ";
    cin >> newnode->phone;

    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    cout << "Contact added\n";
}

void display() {
    Node* temp = head;

    if (temp == NULL) {
        cout << "List is empty\n";
        return;
    }

    while (temp != NULL) {
        cout << "\nName: " << temp->name;
        cout << "\nPhone: " << temp->phone << endl;

        temp = temp->next;
    }
}

void searchContact() {
    char key[15];

    cout << "Enter phone number: ";
    cin >> key;

    Node* temp = head;

    while (temp != NULL) {
        int i = 0;

        while (temp->phone[i] == key[i] && temp->phone[i] != '\0') {
            i++;
        }

        if (temp->phone[i] == key[i]) {
            cout << "Contact found\n";
            cout << temp->name << " " << temp->phone << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Contact not found\n";
}

void deleteContact() {
    char key[15];

    cout << "Enter phone number: ";
    cin >> key;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        int i = 0;

        while (temp->phone[i] == key[i] && temp->phone[i] != '\0') {
            i++;
        }

        if (temp->phone[i] == key[i]) {
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Contact not found\n";
    } else {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Contact deleted\n";
    }
}

void reverse() {
    Node* prev = NULL;
    Node* current = head;
    Node* nextnode;

    while (current != NULL) {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }

    head = prev;

    cout << "List reversed\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- SLL CONTACT MANAGEMENT ---";
        cout << "\n1. Add Contact";
        cout << "\n2. Display Contacts";
        cout << "\n3. Search Contact";
        cout << "\n4. Delete Contact";
        cout << "\n5. Reverse List";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addContact(); break;
            case 2: display(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: reverse(); break;
            case 0: cout << "Exit\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}




// #include <iostream>
// using namespace std;

// class Node {
// public:
//     char name[30];
//     char phone[15];
//     Node* prev;
//     Node* next;
// };

// Node* head = NULL;

// // ADD CONTACT
// void addContact() {
//     Node* newnode = new Node;

//     cout << "Enter name: ";
//     cin >> newnode->name;

//     cout << "Enter phone number: ";
//     cin >> newnode->phone;

//     newnode->prev = NULL;
//     newnode->next = NULL;

//     if (head == NULL) {
//         head = newnode;
//     } else {
//         Node* temp = head;

//         while (temp->next != NULL) {
//             temp = temp->next;
//         }

//         temp->next = newnode;
//         newnode->prev = temp;
//     }

//     cout << "Contact added successfully\n";
// }

// // DISPLAY CONTACTS
// void display() {
//     Node* temp = head;

//     if (head == NULL) {
//         cout << "List is empty\n";
//         return;
//     }

//     while (temp != NULL) {
//         cout << "\nName: " << temp->name;
//         cout << "\nPhone: " << temp->phone << endl;

//         temp = temp->next;
//     }
// }

// // SEARCH CONTACT
// void searchContact() {
//     char key[15];

//     cout << "Enter phone number to search: ";
//     cin >> key;

//     Node* temp = head;

//     while (temp != NULL) {
//         int i = 0;

//         while (temp->phone[i] == key[i] && temp->phone[i] != '\0') {
//             i++;
//         }

//         if (temp->phone[i] == key[i]) {
//             cout << "Contact found\n";
//             cout << "Name: " << temp->name << endl;
//             cout << "Phone: " << temp->phone << endl;
//             return;
//         }

//         temp = temp->next;
//     }

//     cout << "Contact not found\n";
// }

// // DELETE CONTACT
// void deleteContact() {
//     char key[15];

//     cout << "Enter phone number to delete: ";
//     cin >> key;

//     Node* temp = head;

//     while (temp != NULL) {
//         int i = 0;

//         while (temp->phone[i] == key[i] && temp->phone[i] != '\0') {
//             i++;
//         }

//         if (temp->phone[i] == key[i]) {
//             break;
//         }

//         temp = temp->next;
//     }

//     if (temp == NULL) {
//         cout << "Contact not found\n";
//     } else {
//         if (temp->prev == NULL) {
//             head = temp->next;
//         } else {
//             temp->prev->next = temp->next;
//         }

//         if (temp->next != NULL) {
//             temp->next->prev = temp->prev;
//         }

//         delete temp;
//         cout << "Contact deleted successfully\n";
//     }
// }

// // REVERSE LIST
// void reverse() {
//     Node* temp = NULL;
//     Node* current = head;

//     while (current != NULL) {
//         temp = current->prev;

//         current->prev = current->next;
//         current->next = temp;

//         current = current->prev;
//     }

//     if (temp != NULL) {
//         head = temp->prev;
//     }

//     cout << "List reversed successfully\n";
// }

// // MAIN FUNCTION
// int main() {
//     int choice;

//     do {
//         cout << "\n--- DLL CONTACT MANAGEMENT ---";
//         cout << "\n1. Add Contact";
//         cout << "\n2. Display Contacts";
//         cout << "\n3. Search Contact";
//         cout << "\n4. Delete Contact";
//         cout << "\n5. Reverse List";
//         cout << "\n0. Exit";

//         cout << "\nEnter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 addContact();
//                 break;

//             case 2:
//                 display();
//                 break;

//             case 3:
//                 searchContact();
//                 break;

//             case 4:
//                 deleteContact();
//                 break;

//             case 5:
//                 reverse();
//                 break;

//             case 0:
//                 cout << "Program ended\n";
//                 break;

//             default:
//                 cout << "Invalid choice\n";
//         }

//     } while (choice != 0);

//     return 0;
// }
