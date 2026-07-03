#include<iostream>
#include<vector>
#include<queue>

//A binary tree is a tree where each node have atmost 2 childrens
//Predorder sequence of binary tree is :- root left right

//node class forms a tree node where it stores values at that node and its left and right child node pointer
class Node{
    public:
    int value;
    Node* left;
    Node* right;

    Node(int value){
        this ->  value = value;
        left = right = nullptr;
    }
};

Node* BuildTree(std::vector<int>& sequence){//O(n)
    
            int idx = -1;
       auto Build = [&](auto&& self) -> Node*{
           idx++;
        if(idx >= sequence.size())return nullptr;
        if(sequence[idx] == -1)return nullptr;
        Node* root = new Node(sequence[idx]);
        root -> left = self(self);
        root -> right = self(self);
        return root;
        };

        return Build(Build);
}

//O(n) :- root, left, right
void preOrder_traversal(Node* root){
    std::cout<<"preorder traversal"<<std::endl;
    auto printTree = [&](auto&& self,Node* root)->void{
        if(root == nullptr)return;

        std::cout<<root->value<<" ";
        self(self,root->left);
        self(self,root->right);
    };

    printTree(printTree,root);
}

//O(n) :- left,root,right
void inorder_traversal(Node* root){
    std::cout<<"inorder traversal"<<std::endl;
    auto printTree = [&](auto&& self,Node* root)->void{
        if(root == nullptr)return;

        self(self,root->left);
        std::cout<<root->value<<" ";
        self(self,root->right);

    };
    printTree(printTree,root);
}

//O(n) :- left,right,root
void postOrder_traversal(Node* root){
    std::cout<<"postorder traversal"<<std::endl;
    auto printTree=[&](auto&& self , Node* root)->void{
        if(root == nullptr)return;
        self(self,root->left);
        self(self,root->right);
        std::cout<<root->value<<" ";
    };

    printTree(printTree,root);
}

//level wise printing , iterative ,  uses queue(BFS)
void LevelOrder(Node* root){
std::queue<Node*>q;
q.push(root);
q.push(nullptr);
std::cout<<"Level order traversal"<<std::endl;
while(!q.empty()){
    Node* root = q.front();
    q.pop();
    if(root == nullptr){
        if(!q.empty()){
            std::cout<<std::endl;
            q.push(nullptr);
            continue;
        }else{
            break;
        }
    }
    std::cout<<root->value<<" ";
    if(root->left)q.push(root->left);
    if(root->right)q.push(root->right);
}
return;
}
int main(){
    std::vector<int> Preorder_sequence ={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = BuildTree(Preorder_sequence);
    preOrder_traversal(root);
    std::cout<<std::endl;
    inorder_traversal(root);
    std::cout<<std::endl;
    postOrder_traversal(root);
    std::cout<<std::endl;
    LevelOrder(root);
    return 0;
}