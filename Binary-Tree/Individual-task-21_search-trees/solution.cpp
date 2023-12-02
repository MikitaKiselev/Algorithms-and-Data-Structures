#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
    int kids;

    Node(int key) {
        this->key = key;
        left = right = nullptr;
        height = -1;
        kids = -1;
    }
};

int get_height(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return node->height;
}

int get_kids(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return node->kids;
}

Node* insert_elem(Node* root, int key) {
    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        }
        else if (key > current->key) {
            current = current->right;
        }
        else {
            return root;
        }
    }

    Node* new_node = new Node(key);

    if (parent == nullptr) {
        return new_node;
    }
    else if (key < parent->key) {
        parent->left = new_node;
    }
    else {
        parent->right = new_node;
    }

    return root;
}

Node* delete_elem(Node* root, int key) {
    Node* parent = nullptr;
    Node* current = root;

    while (current != nullptr && current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    if (current == nullptr) {
        return root;
    }

    if (current->left == nullptr) {
        if (parent == nullptr) {
            return current->right;
        }
        else if (parent->left == current) {
            parent->left = current->right;
        }
        else {
            parent->right = current->right;
        }
        delete current;
    }
    else if (current->right == nullptr) {
        if (parent == nullptr) {
            return current->left;
        }
        else if (parent->left == current) {
            parent->left = current->left;
        }
        else {
            parent->right = current->left;
        }
        delete current;
    }
    else {
        Node* successor = current->right;
        parent = nullptr;

        while (successor->left != nullptr) {
            parent = successor;
            successor = successor->left;
        }

        current->key = successor->key;
        if (parent != nullptr) {
            parent->left = successor->right;
        }
        else {
            current->right = successor->right;
        }
        delete successor;
    }

    return root;
}


int count = 0;
int count2 = 0;
int x;

void pre_order_traversal(Node* root, std::vector<int>& arr) {
    std::stack<Node*> stack;
    Node* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            arr.push_back(current->key);
            if (current->right != nullptr) {
                stack.push(current->right);
            }
            current = current->left;
        }

        if (!stack.empty()) {
            current = stack.top();
            stack.pop();
        }
    }
}


void post_order_traversal(Node* node) {
    if (node) {
        post_order_traversal(node->left);
        post_order_traversal(node->right);
        node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
        node->kids = get_kids(node->left) + get_kids(node->right) + 2;
        if (get_height(node->left) == get_height(node->right) && get_kids(node->left) != get_kids(node->right)) {
            count++;
        }
    }
}





void in_order_traversal(Node* root) {
    std::stack<Node*> stack;
    Node* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();

        if (get_height(current->left) == get_height(current->right) && get_kids(current->left) != get_kids(current->right)) {
            count2++;
            if (count2 == count / 2 + 1) {
                x = current->key;
            }
        }

        current = current->right;
    }
}

int main() {
    std::ifstream file("in.txt");
    Node* root = nullptr;
    int key;

    while (file >> key) {
        root = insert_elem(root, key);
    }

    post_order_traversal(root);
    //std::cout << count;
    if (count % 2 != 0) {
        in_order_traversal(root);
        //std::cout << x;
        root = delete_elem(root, x);
    }

    std::vector<int> output_arr;
    pre_order_traversal(root, output_arr);

    std::ofstream output_file("out.txt");

    for (int key : output_arr) {
        output_file << key << std::endl;
    }

    return 0;
}