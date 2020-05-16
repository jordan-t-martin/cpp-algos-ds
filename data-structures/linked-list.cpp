#include <iostream>

struct node {
    int data;
    node *next;
};

class linked_list {
private:
    node *head, *tail;
public:
    linked_list();

    void insert_end(int val);
    void insert_front(int val);
    void insert_after(node *a, int value);
    void remove_front();
    void remove_end(node *head);
    void remove_after(node *before);
    static void display(node *head);
    static void concatenate(linked_list a, linked_list b);

    inline node* get_head() { return head; }
    inline node* get_tail() { return tail; }
};

linked_list::linked_list() {
    head = NULL;
    tail = NULL;
}

// Inserts a new value at the end of the list
void linked_list::insert_end(int val) {
    // Create new node
    node *tmp = new node;
    tmp->data = val;
    tmp->next = NULL;

    // If list empty, make new node head/tail
    if(head == NULL) {
        head = tmp;
        tail = tmp;
    } 
    // Else attach to the end
    else {
        tail->next = tmp;
        tail = tail->next;
    }
}

// Inserts a new value at the front of the list
void linked_list::insert_front(int val) {
    // Create new node
    node *tmp = new node;
    tmp->data = val;
    // Attach current head as next and assign as new head
    tmp->next = head;
    head = tmp;
}

void linked_list::insert_after(node *a, int value) {
    // Create new node
    node *tmp = new node;
    tmp->data = value;
    
    // Connect new node to list after
    tmp->next = a->next;

    // Connect list before to new node
    a->next = tmp;
}

void linked_list::remove_front() {
    // If list empty, return
    if(head == NULL)
        return;
    // Reassign head to next and delete
    node *tmp = head;
    head = head->next;
    delete tmp;
}

void linked_list::remove_end(node *head) {
    // If list empty, return
    if(head == NULL)
        return;
    // If next node is last, delete
    else if (head->next->next == NULL) {
        node *tmp = head->next->next;
        head->next = NULL;
        delete tmp;
    }
    // Continue on list
    else {
        remove_end(head->next);
    }
}


void linked_list::remove_after(node *before) {
    // Store node to be deleted
    node *temp;
    temp = before->next;
    // Connect before with after
    before->next = temp->next;
    // Delete node
    delete temp;
}

// Recursively iterate across each node
void linked_list::display(node *head) {
    if(head == NULL) {
        std::cout << "NULL" << std::endl;
    }
    else {
        std::cout << head->data << " ";
        display(head->next);
    }
}

// Attaches two lists together
void linked_list::concatenate(linked_list a, linked_list b) {
    if(a.tail != NULL && b.head != NULL) {
        a.tail->next = b.head;
    }
}

int main() {
    // Concatenation example
    linked_list a;
    a.insert_end(1);
    a.insert_end(2);
    linked_list b;
    b.insert_end(3);
    b.insert_end(4);
    std::cout << "List A:" << std::endl;
    linked_list::display(a.get_head());
    std::cout << "List B:" << std::endl;
    linked_list::display(b.get_head());
    std::cout << "Concatenating lists..." << std::endl;
    linked_list::concatenate(a, b);
    linked_list::display(a.get_head());

    // Removal example
    linked_list c;
    c.insert_end(1);
    c.insert_end(2);
    c.insert_front(3);
    c.insert_front(4);
    c.insert_front(5);
    c.insert_after(c.get_head()->next, 20);
    std::cout << "Insert 1, 2 at end. 3, 4, 5 at front. 20 after 2nd node" << std::endl;
    linked_list::display(c.get_head());
    std::cout << "Removing end..." << std::endl;
    c.remove_end(c.get_head());
    linked_list::display(c.get_head());
    std::cout << "Removing front..." << std::endl;
    c.remove_front();
    linked_list::display(c.get_head());
    std::cout << "Removing after 2nd element..." << std::endl;
    c.remove_after(c.get_head()->next);
    linked_list::display(c.get_head());

    return 0;
}