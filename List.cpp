#include "List.h"

// stack
void push(Node*& top, datatype value) {
    Node* newNode = new Node{ value, top, nullptr };
    top = newNode;
}

datatype pop(Node*& top) {
    if (!top) return -1;
    Node* temp = top;
    datatype value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

void showStack(Node* top) {
    while (top) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

// queue
void enqueue(Node*& front, Node*& rear, datatype value) {
    Node* newNode = new Node{ value, nullptr, nullptr };
    if (!rear) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

datatype dequeue(Node*& front, Node*& rear) {
    if (!front) return -1;
    Node* temp = front;
    datatype value = temp->data;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
    return value;
}

void showQueue(Node* front) {
    while (front) {
        cout << front->data << " ";
        front = front->next;
    }
    cout << endl;
}

// linked list
void add_begin(Node*& head, datatype value) {
    Node* newNode = new Node{ value, head, nullptr };
    if (head) head->prev = newNode;
    head = newNode;
}

void add_end(Node*& head, datatype value) {
    if (!head) {
        add_begin(head, value);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node{ value, nullptr, temp };
}

void del_begin(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
}

void del_end(Node*& head) {
    if (!head) return;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    if (temp->prev) temp->prev->next = nullptr;
    else head = nullptr;
    delete temp;
}

Node* search(Node* head, datatype key) {
    while (head) {
        if (head->data == key) return head;
        head = head->next;
    }
    return nullptr;
}

void add_mid(Node*& head, datatype key, datatype value) {
    Node* target = search(head, key);
    if (!target) return;
    Node* newNode = new Node{ value, target->next, target };
    if (target->next) target->next->prev = newNode;
    target->next = newNode;
}

void del_mid(Node*& head, datatype key) {
    Node* target = search(head, key);
    if (!target) return;
    if (target->prev) target->prev->next = target->next;
    if (target->next) target->next->prev = target->prev;
    if (target == head) head = target->next;
    delete target;
}

void showList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
