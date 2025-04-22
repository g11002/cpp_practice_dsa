#include <iostream>
#include <queue>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// BinaryTree class
class BinaryTree {
private:
    Node* root;

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    int countNodes(Node* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int height(Node* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    bool search(Node* node, int key) {
        if (!node) return false;
        if (node->data == key) return true;
        return search(node->left, key) || search(node->right, key);
    }

    void deleteTree(Node* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BinaryTree() {
        root = nullptr;
    }


    void insert(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                temp->left = newNode;
                return;
            } else {
                q.push(temp->left);
            }

            if (!temp->right) {
                temp->right = newNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }

    void displayLevelOrder() {
        cout << "Level Order Traversal: ";
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }

    int totalNodes() {
        return countNodes(root);
    }

    int treeHeight() {
        return height(root);
    }

    bool searchValue(int val) {
        return search(root, val);
    }

    void clearTree() {
        deleteTree(root);
        root = nullptr;
        cout << "Tree deleted successfully.\n";
    }
};

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    tree.displayInorder();
    tree.displayPreorder();
    tree.displayPostorder();
    tree.displayLevelOrder();

    cout << "Total Nodes: " << tree.totalNodes() << endl;
    cout << "Height of Tree: " << tree.treeHeight() << endl;

    int key = 30;
    cout << "Searching for " << key << ": "
         << (tree.searchValue(key) ? "Found" : "Not Found") << endl;

    tree.clearTree();

    return 0;
}
