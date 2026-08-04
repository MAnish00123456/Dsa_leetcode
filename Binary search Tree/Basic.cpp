// BST is a special type of binary tree , also known as binary seach tree. It follows the property of bianry search 
//all nodes in left subtree have less value than parent node and all nodes in right subtree have higher value than parent node
//An inorder traversal of this tree will provide values in ascending order
//we assume bst have distinct values in question until mentioned

#include<iostream>
#include<vector>

class Node{
public:
int val;

Node* left , *right;
Node(int val){
    this->val = val;
    left = right = nullptr;
}
};


class BST{

    public:
    BST(){};

    //this method used for building the tree
    Node* insert(Node* root ,  int val){
        if(!root){
            return new Node(val);
        }

        if(val < root->val){
            root->left = insert(root->left,val);
        }
        if(val > root->val){
            root->right = insert(root->right,val);
        }
        return root;

    }

    //if array is unsorted
    Node* buildTree(std::vector<int>&nums){
        if(nums.size() == 0)return nullptr;
        Node* root = nullptr;
        for(int val : nums){
            root = insert(root,val);
        }
        return root;
    }
    
    //if array is sorted
    Node* buildSortedArrayToTree(std::vector<int>& nums){
        if(nums.size() == 0)return nullptr;

        auto buildTree =  [&](auto&& self,int st , int end)->Node*{
            if(st > end)return nullptr;
            int mid = st + (end-st)/2;
            Node* root = new Node(nums[mid]);

            root->left = self(self,st,mid-1);
            root->right = self(self,mid+1,end);

            return root;
        };

        return buildTree(buildTree,0,nums.size()-1);
    }

    //insert value in bst
    Node* insertInTree(Node* root , int key){
        if(!root)return new Node(key);

        if(key < root->val){
            root->left = insertInTree(root->left,key);
        }
        if(key > root->val){
            root->right = insertInTree(root->right,key);
        }
        return root;
    }

    //search a key in bst
    bool search(Node* root,int key){
        if(!root)return false;

        if(key == root-> val)return true;
        if(key < root->val)return search(root->left,key);
        return search(root->right,key);
    }

    Node* inorderSuccessor(Node* root){
        Node* curr = root->right;
        while(curr != nullptr && curr->left != nullptr){
            curr = curr->left;
        }
        return curr;
    }
    Node* delNode(Node* root , int key){
        //deleting a node involves 3 cases:
            //case i -> node has no childrens
            //case ii -> node has either one of the children
            //case iii -> node have both childrens

                //first search the node and then delete it
            if(!root)return root;
            if(key < root->val){
                root->left =  delNode(root->left,key);
            }
            else if(key > root->val){
               root->right =  delNode(root->right,key);
            }
            else{
                //root == key
                if(root->left == nullptr){
                    //2 things either root have no right children or have right children
                    //combined case 1 and case 2 in this piece of code
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }
                if(root->right == nullptr){
                    Node* tmp = root->left;
                    delete root;
                    return tmp;
                }

                //root has both childrens
                //so find inorder successor(IS) for key node , then swap values of the IS node with key node. then call delNode function for this IS node , then it will be either case i or ii then
                //inorder successor of the given node is the smallest node value  present to the right of the key node which is just greater than key node
                else{
                    Node* IS = inorderSuccessor(root);
                    root->val = IS->val;
                    root->right = delNode(root->right,IS->val);
                }
            }
            return root;
    }

    void PrintTree(Node* root){
        if(!root)return;

        PrintTree(root->left);
        std::cout<<root->val<<" ";
        PrintTree(root->right);

    }


};

int main(){
    std::vector<int>nums = {10,-1,-5,6,8,12,19,20};
    std::vector<int> sortednums = {1,2,4,5,8,9,10};
    BST bstTree;
    Node* root = bstTree.buildTree(nums);
    std::cout<<"Using unsorted array : "<<std::endl;
    bstTree.PrintTree(root);
    std::cout<<std::endl;
    // std::cout<<"using sorted array : "<<std::endl;
    // Node* root1 = bstTree.buildSortedArrayToTree(sortednums);
    // bstTree.PrintTree(root1);
    bstTree.insertInTree(root,-19);
    bstTree.PrintTree(root);
    std::cout<<std::endl;
    if(bstTree.search(root,-19))std::cout<<"key found";
    else std::cout<<"key not found";
    bstTree.delNode(root,-1);
    std::cout<<std::endl;
    // bstTree.delNode(root,10);
    bstTree.PrintTree(root);
return 0;

}