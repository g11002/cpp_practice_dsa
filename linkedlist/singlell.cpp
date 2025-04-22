#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* start;

public:
    LinkedList() {
        start = nullptr;
    }

    void create_list() {
        int num;
        cout << "Enter -1 to end\n";
        cout << "Enter the data: ";
        cin >> num;

        while (num != -1) {
            Node* newnode = new Node(num);
            if (start == nullptr) {
                start = newnode;
            } else {
                Node* ptr = start;
                while (ptr->next != nullptr)
                    ptr = ptr->next;
                ptr->next = newnode;
            }
            cout << "Enter the data: ";
            cin >> num;
        }
    }

    void display() {
        Node* ptr = start;
        cout << "List: ";
        while (ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    void insert_begin() {
        int num;
        cout << "Enter the data: ";
        cin >> num;
        Node* newnode = new Node(num);
        newnode->next = start;
        start = newnode;
    }

    void insert_end() {
        int num;
        cout << "Enter the data: ";
        cin >> num;
        Node* newnode = new Node(num);
        if (start == nullptr) {
            start = newnode;
            return;
        }
        Node* ptr = start;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = newnode;
    }

    void insert_before() {
        int num, val;
        cout << "Enter the data: ";
        cin >> num;
        cout << "Enter the value before which to insert: ";
        cin >> val;

        Node* newnode = new Node(num);
        if (start == nullptr) return;

        if (start->data == val) {
            newnode->next = start;
            start = newnode;
            return;
        }

        Node* ptr = start;
        Node* preptr = nullptr;

        while (ptr != nullptr && ptr->data != val) {
            preptr = ptr;
            ptr = ptr->next;
        }

        if (ptr != nullptr) {
            preptr->next = newnode;
            newnode->next = ptr;
        }
    }

    void insert_after() {
        int num, val;
        cout << "Enter the data: ";
        cin >> num;
        cout << "Enter the value after which to insert: ";
        cin >> val;

        Node* newnode = new Node(num);
        Node* ptr = start;

        while (ptr != nullptr && ptr->data != val) {
            ptr = ptr->next;
        }

        if (ptr != nullptr) {
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
    }

    void delete_begin() {
        if (start == nullptr) return;
        Node* temp = start;
        start = start->next;
        delete temp;
    }

    void delete_end() {
        if (start == nullptr) return;

        if (start->next == nullptr) {
            delete start;
            start = nullptr;
            return;
        }

        Node* ptr = start;
        Node* preptr = nullptr;

        while (ptr->next != nullptr) {
            preptr = ptr;
            ptr = ptr->next;
        }

        preptr->next = nullptr;
        delete ptr;
    }

    void delete_node() {
        int val;
        cout << "Enter the value to delete: ";
        cin >> val;

        if (start == nullptr) return;

        if (start->data == val) {
            delete_begin();
            return;
        }

        Node* ptr = start;
        Node* preptr = nullptr;

        while (ptr != nullptr && ptr->data != val) {
            preptr = ptr;
            ptr = ptr->next;
        }

        if (ptr != nullptr) {
            preptr->next = ptr->next;
            delete ptr;
        }
    }

    void delete_after() {
        int val;
        cout << "Enter the value after which to delete: ";
        cin >> val;

        Node* ptr = start;
        while (ptr != nullptr && ptr->data != val)
            ptr = ptr->next;

        if (ptr != nullptr && ptr->next != nullptr) {
            Node* temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
        }
    }

    void delete_list() {
        Node* ptr = start;
        while (ptr != nullptr) {
            Node* temp = ptr;
            cout << "\n" << ptr->data << " is being deleted...";
            ptr = ptr->next;
            delete temp;
        }
        start = nullptr;
        cout << "\nList Deleted.\n";
    }

    void sort_list() {
        if (start == nullptr || start->next == nullptr) return;

        Node* ptr1 = start;
        while (ptr1->next != nullptr) {
            Node* ptr2 = ptr1->next;
            while (ptr2 != nullptr) {
                if (ptr1->data > ptr2->data) {
                    swap(ptr1->data, ptr2->data);
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }
};

// ------------------- Main Function ------------------------

int main() {
    LinkedList list;
    int option;

    do {
        cout << "\n\n***** MAIN MENU *****";
        cout << "\n1 : Create a list";
        cout << "\n2 : Display the list";
        cout << "\n3 : Add a node at the beginning";
        cout << "\n4 : Add a node at the end";
        cout << "\n5 : Add a node before a given node";
        cout << "\n6 : Add a node after a given node";
        cout << "\n7 : Delete a node from the beginning";
        cout << "\n8 : Delete a node from the end";
        cout << "\n9 : Delete a given node";
        cout << "\n10 : Delete a node after a given node";
        cout << "\n11 : Delete the entire list";
        cout << "\n12 : Sort the list";
        cout << "\n13 : EXIT";
        cout << "\nEnter your option: ";
        cin >> option;

        switch (option) {
            case 1: list.create_list(); break;
            case 2: list.display(); break;
            case 3: list.insert_begin(); break;
            case 4: list.insert_end(); break;
            case 5: list.insert_before(); break;
            case 6: list.insert_after(); break;
            case 7: list.delete_begin(); break;
            case 8: list.delete_end(); break;
            case 9: list.delete_node(); break;
            case 10: list.delete_after(); break;
            case 11: list.delete_list(); break;
            case 12: list.sort_list(); break;
            case 13: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (option != 13);

    return 0;
}