#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

Node* insertElem(Node* root, Node* node) {
    if (root == nullptr) {
        return node;
    }
    else {
        if (node->key > root->key) {
            root->right = insertElem(root->right, node);
        }
        else if (node->key < root->key) {
            root->left = insertElem(root->left, node);
        }
        return root;
    }
}

void preOrderTraversal(Node* node, vector<int>& arr) {
    if (node) {
        arr.push_back(node->key);
        preOrderTraversal(node->left, arr);
        preOrderTraversal(node->right, arr);
    }
}

int main() {
    ifstream inputFile("input.txt");
    int key;
    Node* root = nullptr;

    while (inputFile >> key) {
        root = insertElem(root, new Node(key));
    }
    inputFile.close();

    vector<int> outputArr;
    preOrderTraversal(root, outputArr);

    ofstream outputFile("output.txt");
    for (int key : outputArr) {
        outputFile << key << "\n";
    }
    outputFile.close();

    return 0;
}