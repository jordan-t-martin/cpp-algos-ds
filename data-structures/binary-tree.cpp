#include <iostream>

struct node
{
    int value;
    node *left = NULL;
    node *right = NULL;
};

class btree
{
    public:
        btree();
        ~btree();

        void insert(int key);
        node *search(int key);
        void print_tree();
        void destroy_tree();

    private:
        void print_tree(node* leaf);
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);

        node *root;
};

btree::btree() {
    root = NULL;
}

btree::~btree() {
    destroy_tree();
}

void btree::insert(int key) {
    if(root != NULL) { insert(key, root); }
    // Tree is empty, create new root
    else
    {
        root = new node;
        root-> value = key;
    }
}

node* btree::search(int key) { return search(key, root); }

void btree::print_tree() { print_tree(root); }

void btree::destroy_tree() { destroy_tree(root); }

// Use recursion to find correct location for new leaf
void btree::insert(int key, node *leaf) {
    // Left of node
    if(key < leaf->value)
        // Recursion on left child
        if(leaf->left != NULL)
            insert(key, leaf->left); 
        // Create left child 
        else {
            leaf->left = new node;
            leaf->left->value = key;
        }
    // Right of node
    else if(key > leaf->value) {
        // Recursion on right child
        if(leaf->right != NULL) 
            insert(key, leaf->right);
        // Create right child
        else {
            leaf->right = new node;
            leaf->right->value = key;
        }
    }
}

// Use recursion to find leaf with key
node* btree::search(int key, node *leaf) {
    if(leaf != NULL) {
        // Found key
        if(key == leaf->value) { return leaf; }
        // Call recursively on left and right nodes
        else if(key < leaf->value) { search(key, leaf->left); }
        else if(key > leaf->value) { search(key, leaf->right); }
        // Did not find key
        return NULL;
    }
}

// Recursively traverse tree and delete nodes
void btree::print_tree(node* leaf) {
    if(leaf != NULL) {
        print_tree(leaf->left);
        print_tree(leaf->right);
        std::cout << leaf->value << " ";
    }
}

// Recursively traverse tree and delete nodes
void btree::destroy_tree(node* leaf) {
    if(leaf != NULL) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

int main() {
    btree a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(10);
    a.insert(8);
    a.insert(7);
    a.insert(100);
    a.print_tree();
}