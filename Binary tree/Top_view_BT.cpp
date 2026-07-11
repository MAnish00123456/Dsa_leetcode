#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void printTopView(Node* root){
std::queue<std::pair<Node*,int>>q;
std::map<int,Node*> hash;

q.push({root,0});

while(!q.empty()){
auto [n,d] = q.front();
q.pop();
if(hash.find(d) == hash.end()){
    hash[d] = n;
}
if(n->left != nullptr)q.push({n->left,d-1});
if(n->right != nullptr)q.push({n->right,d+1});
}
for(const auto& [k,v] : hash){
    std::cout<<v->value<<" ";
}
}

int main(){
    // std::vector<int> Preorder_sequence ={1,2,3,4,5,6,7};
    std::vector<int> Preorder_sequence ={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = BuildTree(Preorder_sequence);
    printTopView(root);
    return 0;
}