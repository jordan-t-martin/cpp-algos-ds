#include <cstddef>

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
        void destroy_tree();

    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);

        node *root;
};

btree::btree()
{
    root=NULL;
}

btree::btree()
{
    destroy_tree();
}

void btree::insert(int key)
{
    if(root != NULL) { insert(key, root); }
    else
    {
        root = new node;
        root-> value = key;
    }
}

node* btree::search(int key) { return search(key, root); }

void btree::destroy_tree() { destroy_tree(root); }

void btree::insert(int key, node *leaf)
{
    if(key < leaf->value)
        if(leaf->left != NULL) { insert(key, leaf->left); }
        else
        {
            leaf->left = new node;
            leaf->left->value = key;
        }
    else if(key > leaf->value)
    {
        if(leaf->right != NULL) {insert(key, leaf->right); }
        else
        {
            leaf->right = new node;
            leaf->right->value = key;
        }
    }
}

void btree::search(int key, node *leaf)
{
    if(leaf != NULL)
    {
        if(key == leaf->value) { return leaf; }
        else if(key < leaf->value) { search(key, leaf->left); }
        else if(key > leaf->value) { search(key, leaf->right); }
        return NULL;
    }
}

void btree::destroy_tree(node* leaf)
{
    if(leaf != NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf; // what does delete do?
    }
}