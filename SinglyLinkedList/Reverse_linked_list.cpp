//first solution i did

// class Solution {
    //     ListNode* head1;
    //     void push_front(int data){
    //         if(head1 == NULL){
    //             ListNode* newNode = new ListNode(data);
    //             head1 = newNode;
    //         }
    //         else{
    //             ListNode* newNode = new ListNode(data);
    //             ListNode*temp = head1;
    //             newNode->next = temp;
    //             head1 = newNode;
    //         }
    //     }
    
    //     void push_back(int data){
    //         ListNode* temp = head1;
    //         while(temp != NULL && temp->next != NULL){
    //             temp = temp->next;
    //         }
    //         if(temp == NULL)return;
    //         ListNode* newNode = new ListNode(data);
    //         temp->next = newNode;
    //     }
    
    //     void insert(int pos,int data){
    //         if(head1 == NULL){
    //             return;
    //         }
    //         else{
    //             ListNode*temp1 = head1;
    //             for(int i = 0 ; i < pos-1 ; i++){
    //                 if(temp1 == NULL){
    //                     return;
    //                 }
    //                 temp1=temp1->next;
    //             }
    //             if(temp1 == NULL)return;
    //            ListNode* newNode = new ListNode(data);
    //            newNode->next = temp->next;
    //             temp1->next = newNode;
    //         }
    //     }
    
    // public:
    //  Solution(){
    //         head1 = NULL;
    //     }
    //     ListNode* reverseList(ListNode* head) {
    //         vector<int>Listdata;
    //         ListNode* temp = head;
    //         while(temp!=NULL){
    //             Listdata.push_back(temp->val);
    //             temp = temp->next;
    //         }
    //         reverse(Listdata.begin() , Listdata.end());
    //         head = NULL;
    //         for(int i = 0 ; i < Listdata.size() ; i++){
    //             if(i == 0){
    //                 push_front(Listdata[i]);
    //             }
    //             else if(i == Listdata.size()-1){
    //                 push_back(Listdata[i]);
    //             }
    //             else{
    //                 insert(i,Listdata[i]);
    //             }
    //         }
    //         return head1;
    //     }
    // };


    //second solution , i learnt
    // class Solution{
    //     public:
    //     ListNode* reverseList(ListNode* head){
    //         ListNode* curr= head;
    //         ListNode* prev=NULL;
    //         if(head == NULL){
    //             return head;
    //         }
    //         while(curr != NULL){
    //             ListNode* forward = curr->next;
    //             curr->next = prev;
    //             prev = curr;
    //             curr = forward;
    //         }
    //         return prev;
    //     }
    // };