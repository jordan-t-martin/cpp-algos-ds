#include <iostream>

struct node {
    int value;
    node *next;
};

class Stack {
public:
    Stack();

    node* create_node(int value);
    bool isEmpty(node *root);
    void push(int value);
    int pop();
    int peek();
    void display(node *root);

    inline node* get_root() { return root; }
private:
    node *root;
};

Stack::Stack() {
    root = NULL;
}

bool Stack::isEmpty(node *root) {
    return (root == NULL);
}

node* Stack::create_node(int value) {
    node *new_node = new node();
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void Stack::push(int value) {
    node *new_node = create_node(value);
    new_node->next = root;
    root = new_node;
}

int Stack::pop() {
    if(isEmpty(root)) 
        return INT_MIN;
        
    node *tmp = root;
    root = root->next;
    int pop_val = tmp->value;
    delete tmp;
    return pop_val;
}

int Stack::peek() {
    if(isEmpty(root))
        return INT_MIN;
    return root->value;
}

// Recursively iterate across each node
void Stack::display(node *root) {
    if(root == NULL) {
        std::cout << "NULL" << std::endl;
    }
    else {
        std::cout << root->value << " ";
        display(root->next);
    }
}

int main() {
    Stack a;
    a.push(1);
    a.push(2);
    a.push(5);
    a.push(10);
    a.display(a.get_root());

    std::cout << "Popping top node...\n";
    std::cout << a.pop() << std::endl; 
    std::cout << "Peeking top node...\n";
    std::cout << a.peek() << std::endl; 
  
    return 0; 
}