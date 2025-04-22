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

class DoublyLinkedList {
private:
    Node* start;
public:
    DoublyLinkedList() {
        start = nullptr;
    }

    void createList() {
        int num;
        cout << "\n Enter -1 to end";
        cout << "\n Enter the data : ";
        cin >> num;
        while (num != -1) {
            Node* newNode = new Node(num);
            if (!start) {
                start = newNode;
            } else {
                Node* ptr = start;
                while (ptr->next) ptr = ptr->next;
                ptr->next = newNode;
                newNode->prev = ptr;
            }
            cout << "\n Enter the data : ";
            cin >> num;
        }
    }

    void display() {
        Node* ptr = start;
        while (ptr) {
            cout << "\t" << ptr->data;
            ptr = ptr->next;
        }
        cout << endl;
    }

    void insertBeg() {
        int num;
        cout << "\n Enter the data : ";
        cin >> num;
        Node* newNode = new Node(num);
        if (start) {
            start->prev = newNode;
            newNode->next = start;
        }
        start = newNode;
    }

    void insertEnd() {
        int num;
        cout << "\n Enter the data : ";
        cin >> num;
        Node* newNode = new Node(num);
        if (!start) {
            start = newNode;
            return;
        }
        Node* ptr = start;
        while (ptr->next) ptr = ptr->next;
        ptr->next = newNode;
        newNode->prev = ptr;
    }

    void insertBefore() {
        int num, val;
        cout << "\n Enter the data : ";
        cin >> num;
        cout << "\n Enter the value before which the data has to be inserted : ";
        cin >> val;

        Node* ptr = start;
        while (ptr && ptr->data != val) ptr = ptr->next;

        if (!ptr) return;  // Not found

        Node* newNode = new Node(num);
        newNode->next = ptr;
        newNode->prev = ptr->prev;

        if (ptr->prev) {
            ptr->prev->next = newNode;
        } else {
            start = newNode;
        }
        ptr->prev = newNode;
    }

    void insertAfter() {
        int num, val;
        cout << "\n Enter the data : ";
        cin >> num;
        cout << "\n Enter the value after which the data has to be inserted : ";
        cin >> val;

        Node* ptr = start;
        while (ptr && ptr->data != val) ptr = ptr->next;

        if (!ptr) return;  // Not found

        Node* newNode = new Node(num);
        newNode->prev = ptr;
        newNode->next = ptr->next;

        if (ptr->next) {
            ptr->next->prev = newNode;
        }
        ptr->next = newNode;
    }

    void deleteBeg() {
        if (!start) return;
        Node* temp = start;
        start = start->next;
        if (start) start->prev = nullptr;
        delete temp;
    }

    void deleteEnd() {
        if (!start) return;
        Node* ptr = start;
        if (!ptr->next) {
            delete ptr;
            start = nullptr;
            return;
        }
        while (ptr->next) ptr = ptr->next;
        ptr->prev->next = nullptr;
        delete ptr;
    }

    void deleteAfter() {
        int val;
        cout << "\n Enter the value after which the node has to be deleted : ";
        cin >> val;
        Node* ptr = start;
        while (ptr && ptr->data != val) ptr = ptr->next;

        if (!ptr || !ptr->next) return;

        Node* temp = ptr->next;
        ptr->next = temp->next;
        if (temp->next) temp->next->prev = ptr;
        delete temp;
    }

    void deleteBefore() {
        int val;
        cout << "\n Enter the value before which the node has to be deleted : ";
        cin >> val;
        Node* ptr = start;
        while (ptr && ptr->data != val) ptr = ptr->next;

        if (!ptr || !ptr->prev) return;

        Node* temp = ptr->prev;
        if (temp == start) {
            deleteBeg();
        } else {
            temp->prev->next = ptr;
            ptr->prev = temp->prev;
            delete temp;
        }
    }

    void deleteList() {
        while (start) {
            deleteBeg();
        }
    }

    void menu() {
        int option;
        do {
            cout << "\n\n *****MAIN MENU *****"
                 << "\n 1: Create a list"
                 << "\n 2: Display the list"
                 << "\n 3: Add a node at the beginning"
                 << "\n 4: Add a node at the end"
                 << "\n 5: Add a node before a given node"
                 << "\n 6: Add a node after a given node"
                 << "\n 7: Delete a node from the beginning"
                 << "\n 8: Delete a node from the end"
                 << "\n 9: Delete a node before a given node"
                 << "\n 10: Delete a node after a given node"
                 << "\n 11: Delete the entire list"
                 << "\n 12: EXIT"
                 << "\n\n Enter your option : ";
            cin >> option;

            switch (option) {
            case 1: createList(); cout << "\n DOUBLY LINKED LIST CREATED"; break;
            case 2: display(); break;
            case 3: insertBeg(); break;
            case 4: insertEnd(); break;
            case 5: insertBefore(); break;
            case 6: insertAfter(); break;
            case 7: deleteBeg(); break;
            case 8: deleteEnd(); break;
            case 9: deleteBefore(); break;
            case 10: deleteAfter(); break;
            case 11: deleteList(); cout << "\n DOUBLY LINKED LIST DELETED"; break;
            }
        } while (option != 12);
    }
};

int main() {
    DoublyLinkedList list;
    list.menu();
    return 0;
}
