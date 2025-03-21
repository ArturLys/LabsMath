#include "template.h"
#pragma once
using namespace std;

typedef int datatype;

struct Node {
    datatype data;
    Node* next;
    Node* prev; 
};

void push(Node*& top, datatype value);
datatype pop(Node*& top);
void showStack(Node* top);

void enqueue(Node*& front, Node*& rear, datatype value);
datatype dequeue(Node*& front, Node*& rear);
void showQueue(Node* front);

void add_begin(Node*& head, datatype value);
void add_end(Node*& head, datatype value);
void del_begin(Node*& head);
void del_end(Node*& head);
Node* search(Node* head, datatype key);
void add_mid(Node*& head, datatype key, datatype value);
void del_mid(Node*& head, datatype key);
void showList(Node* head);

