#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node* start = nullptr;

Node* createList(Node* start);
Node* display(Node* start);
Node* insertAtBeginning(Node* start);
Node* insertAtEnd(Node* start);
Node* insertBefore(Node* start);
Node* insertAfter(Node* start);
Node* deleteBeginning(Node* start);
Node* deleteEnd(Node* start);
Node* deleteBefore(Node* start);
Node* deleteAfter(Node* start);
Node* deleteList(Node* start);

int main() {
    int option;
    do {
        cout << "\n\n *****MAIN MENU *****\n"
             << " 1: Create a list\n"
             << " 2: Display the list\n"
             << " 3: Add a node at the beginning\n"
             << " 4: Add a node at the end\n"
             << " 5: Add a node before a given node\n"
             << " 6: Add a node after a given node\n"
             << " 7: Delete a node from the beginning\n"
             << " 8: Delete a node from the end\n"
             << " 9: Delete a node before a given node\n"
             << "10: Delete a node after a given node\n"
             << "11: Delete the entire list\n"
             << "12: EXIT\n\n"
             << " Enter your option: ";
        cin >> option;

        switch (option) {
            case 1: start = createList(start); cout << "\nDOUBLY LINKED LIST CREATED\n"; break;
            case 2: start = display(start); break;
            case 3: start = insertAtBeginning(start); break;
            case 4: start = insertAtEnd(start); break;
            case 5: start = insertBefore(start); break;
            case 6: start = insertAfter(start); break;
            case 7: start = deleteBeginning(start); break;
            case 8: start = deleteEnd(start); break;
            case 9: start = deleteBefore(start); break;
            case 10: start = deleteAfter(start); break;
            case 11: start = deleteList(start); cout << "\nDOUBLY LINKED LIST DELETED\n"; break;
        }
    } while (option != 12);

    return 0;
}

Node* createList(Node* start) {
    int num;
    cout << "\nEnter -1 to end";
    cout << "\nEnter the data: ";
    cin >> num;

    while (num != -1) {
        Node* newNode = new Node(num);
        if (!start) {
            newNode->next = newNode->prev = newNode;
            start = newNode;
        } else {
            Node* last = start->prev;
            newNode->next = start;
            newNode->prev = last;
            last->next = newNode;
            start->prev = newNode;
        }
        cout << "Enter the data: ";
        cin >> num;
    }
    return start;
}

Node* display(Node* start) {
    if (!start) {
        cout << "\nList is empty.\n";
        return start;
    }
    Node* ptr = start;
    do {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    } while (ptr != start);
    cout << endl;
    return start;
}

Node* insertAtBeginning(Node* start) {
    int num;
    cout << "\nEnter the data: ";
    cin >> num;
    Node* newNode = new Node(num);

    if (!start) {
        newNode->next = newNode->prev = newNode;
        start = newNode;
    } else {
        Node* last = start->prev;
        newNode->next = start;
        newNode->prev = last;
        last->next = start->prev = newNode;
        start = newNode;
    }
    return start;
}

Node* insertAtEnd(Node* start) {
    int num;
    cout << "\nEnter the data: ";
    cin >> num;
    Node* newNode = new Node(num);

    if (!start) {
        newNode->next = newNode->prev = newNode;
        start = newNode;
    } else {
        Node* last = start->prev;
        newNode->next = start;
        newNode->prev = last;
        last->next = start->prev = newNode;
    }
    return start;
}

Node* insertBefore(Node* start) {
    if (!start) return start;
    int num, val;
    cout << "\nEnter the data: ";
    cin >> num;
    cout << "Enter the value before which to insert: ";
    cin >> val;

    Node* ptr = start;
    do {
        if (ptr->data == val) {
            Node* newNode = new Node(num);
            newNode->next = ptr;
            newNode->prev = ptr->prev;
            ptr->prev->next = newNode;
            ptr->prev = newNode;
            if (ptr == start) start = newNode;
            return start;
        }
        ptr = ptr->next;
    } while (ptr != start);

    cout << "Value not found.\n";
    return start;
}

Node* insertAfter(Node* start) {
    if (!start) return start;
    int num, val;
    cout << "\nEnter the data: ";
    cin >> num;
    cout << "Enter the value after which to insert: ";
    cin >> val;

    Node* ptr = start;
    do {
        if (ptr->data == val) {
            Node* newNode = new Node(num);
            newNode->prev = ptr;
            newNode->next = ptr->next;
            ptr->next->prev = newNode;
            ptr->next = newNode;
            return start;
        }
        ptr = ptr->next;
    } while (ptr != start);

    cout << "Value not found.\n";
    return start;
}

Node* deleteBeginning(Node* start) {
    if (!start) return start;
    if (start->next == start) {
        delete start;
        return nullptr;
    }
    Node* last = start->prev;
    Node* temp = start;
    start = start->next;
    start->prev = last;
    last->next = start;
    delete temp;
    return start;
}

Node* deleteEnd(Node* start) {
    if (!start) return start;
    if (start->next == start) {
        delete start;
        return nullptr;
    }
    Node* last = start->prev;
    last->prev->next = start;
    start->prev = last->prev;
    delete last;
    return start;
}

Node* deleteBefore(Node* start) {
    if (!start || start->next == start) return start;
    int val;
    cout << "\nEnter the value before which to delete: ";
    cin >> val;

    Node* ptr = start;
    do {
        if (ptr->data == val) {
            if (ptr == start) start = deleteEnd(start);
            else {
                Node* temp = ptr->prev;
                temp->prev->next = ptr;
                ptr->prev = temp->prev;
                delete temp;
            }
            return start;
        }
        ptr = ptr->next;
    } while (ptr != start);

    cout << "Value not found.\n";
    return start;
}

Node* deleteAfter(Node* start) {
    if (!start || start->next == start) return start;
    int val;
    cout << "\nEnter the value after which to delete: ";
    cin >> val;

    Node* ptr = start;
    do {
        if (ptr->data == val) {
            Node* temp = ptr->next;
            if (temp == start) start = deleteBeginning(start);
            else {
                ptr->next = temp->next;
                temp->next->prev = ptr;
                delete temp;
            }
            return start;
        }
        ptr = ptr->next;
    } while (ptr != start);

    cout << "Value not found.\n";
    return start;
}

Node* deleteList(Node* start) {
    while (start) {
        start = deleteBeginning(start);
    }
    return nullptr;
}
