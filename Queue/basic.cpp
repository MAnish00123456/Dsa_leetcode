//implement using linked list
//3 operations : front() , pop() , push()
//pop from front , push from rear

#include <iostream>

class Node{
public:
int value;
Node* next;
Node(int value){
    this ->  value = value;
    next = nullptr;
}
};

class Queue{
Node* head , *tail;
public:
Queue(){
    head = nullptr;
    tail = nullptr;
}

int front(){
    if(head == nullptr)return -1;

    return head->value;
}

void push(int value){
    Node* newNode = new Node(value);
    if(head == nullptr){
        head = tail = newNode;
        return;
    }
    tail -> next = newNode;
    tail = newNode;
}

void pop(){
    if(head == nullptr)return;
    Node* tmp = head;
    head = head -> next;
    tmp -> next = nullptr;
    delete tmp;

}

void print(){
    Node* tmp = head;
    while(tmp){
        std::cout<<tmp->value<<" -> ";
        tmp = tmp->next;
    }
    std::cout<<"NULL";
    std::cout<<std::endl;
}
};

int main(){
    Queue q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.print();
    q1.pop();
    q1.pop();
    q1.print();
    int val = q1.front();
    std::cout<<val;
    return 0;
}