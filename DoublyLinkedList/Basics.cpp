#include<iostream>

class Node{
    public:
int data;
Node* prev;
Node* next;

Node(int val){
    data = val;
    prev = next = nullptr;
}
};

class DLL{
    Node* head;
    Node* tail;
    public:
    DLL(){
        head = tail = nullptr;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void push_back(int val){
        Node* newNode = new Node(val);

        if(!head){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

    }

    void pop_front(){
        if(!head){
            std::cout<<"Empty list";
            return;
        }

        Node* tmp = head;

        head = tmp->next;
        if(head){
            head->prev = nullptr;
        }else{
            tail = nullptr;
        }

        tmp->next = nullptr;

        delete(tmp);
    }

    void pop_back(){
        if(!head){
            std::cout<<"Empty list";
            return ;
        }
        Node* tmp = tail;

        tail = tail->prev;
        if(tail) tail->next = nullptr;
        
        if(tmp) tmp->prev = nullptr;
        
        delete(tmp);

    }

    void PrintList(){
        Node* temp = head;
        
        while(temp){
            std::cout<<temp->data<<" <=> ";
            temp=temp->next;
        }
        std::cout<<"null"<<std::endl;
        
    }
};


int main(){
DLL dll;
dll.push_front(3);
dll.push_front(2);
dll.push_front(1);

dll.PrintList();

dll.push_back(4);
dll.push_back(5);

dll.PrintList();

dll.pop_front();

dll.PrintList();

dll.pop_back();

dll.PrintList();

return 0;
}
