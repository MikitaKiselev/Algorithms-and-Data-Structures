#include <iostream>
#include <fstream>
#include <vector>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int key) {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insert_elem(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    else {
        if (key > root->key) {
            root->right = insert_elem(root->right, key);
        }
        else if (key < root->key) {
            root->left = insert_elem(root->left, key);
        }
    }
    return root;
}

Node* find_min(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}


Node* delete_elem(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }
    if (key < root->key) {
        root->left = delete_elem(root->left, key);
    }
    else if (key > root->key) {
        root->right = delete_elem(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = find_min(root->right);
        root->key = temp->key;
        root->right = delete_elem(root->right, temp->key);
    }
    return root;
}

void pre_order_traversal(Node* node, std::vector<int>& arr) {
    if (node) {
        arr.push_back(node->key);
        pre_order_traversal(node->left, arr);
        pre_order_traversal(node->right, arr);
    }
}

int main() {
    std::ifstream file("input.txt");
    int x;
    file >> x;

    Node* root = nullptr;
    int key;
    while (file >> key) {
        root = insert_elem(root, key);
    }
    root = delete_elem(root, x);
    std::vector<int> arr;
    pre_order_traversal(root, arr);

    std::ofstream outFile("output.txt");
    for (int key : arr) {
        outFile << key << "\n";
    }
    return 0;
}