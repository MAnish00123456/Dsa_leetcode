//This file takes us through the process how linked list works internally

#include<iostream>

//a list is a collection of nodes which stores data and pointer to next node(stores address of nextnode)
class Node{
    public:
    int data;
    Node * next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

//linked list implementation

class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head=NULL;
        tail=NULL;
    }

    //1st method , Push_front , adding values to front of list
    void Push_front(int val){
        Node* newNode = new Node(val);
        //case 1 : when list is empty
        if(head==NULL){
            head = tail = newNode;
            return;
        }

        //case 2 : when list have some nodes already
       else{
           (*newNode).next=head;
           head=newNode;
       } 
    }

    //2nd method , Push_back , adding values to last of list
    void Push_back(int val){
        Node* newNode = new Node(val);

        if(head==NULL){
            head=tail=newNode;
            return;
        }
     else{
        tail->next=newNode;
        newNode=NULL;
     }
    }

    //3rd method :- Pop_front
    void Pop_front(){
        Node *temp = head;
        if(head == NULL){
            std::cout<<"linked list is empty";
            return;
        }
        else{
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }

    //4rth method :- Pop-back()
    void Pop_back(){
        //if we dont have tail ponter , we use this
        // Node *temp = head;
        // Node *prev;
        // if(head == NULL){
        //     std::cout<<"Empty linked list";
        //     return;
        // }
        // while(temp->next != NULL){
        //     prev = temp;
        //     temp = temp->next;
        // }
        // tail = prev;
        // prev->next = NULL;
        // delete temp;

        //if we have tail pointer we use this

        Node *temp = head;
        if(head == NULL){
            std::cout<<"Empty linked list";
            return;
        }
        while(temp->next != tail){
            temp = temp->next;
        }
        tail = temp;
        temp=temp->next;
        tail->next = NULL;   
        delete temp;
    }

    //5th method -> Insert(val,pos)
    void insert(int val , int pos){
        if(pos < 0)return;
        if(pos == 0){
            Push_front(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;

        for(int i = 0 ; i < pos-1 ; i++){
            if(temp == NULL){
                std::cout<<"empty linked list";
                return ;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    //6th method :-> Seacrh
    void Search(int val){
        Node *temp = head;
        if(head == NULL){
            std::cout<<"Empty linked list";
            return;
        }
        
        while(temp->next != NULL && temp->data != val){
            temp=temp->next;
        }
        if(temp->data == val){
            std::cout<<"found the data "<<std::endl;
            return;
        }
        std::cout<<"data not exist"<<std::endl;
    }


    //Print list function
    void PrintList(){
        Node* temp = head;
        while(temp != NULL){
            std::cout<<temp->data<<"->";
            temp = temp->next;
        }
        std::cout<<"NULL"<<std::endl;
    }
};


int main(){
    //create a new list 
    List ll;
    ll.Push_front(1);
    ll.Push_front(2);
    ll.Push_front(3);
    ll.Push_back(4);
    // ll.PrintList();
    // ll.Pop_back();
    ll.insert(6,0);
    ll.PrintList();
    ll.Search(3);
    ll.Search(7);
    return 0;
}