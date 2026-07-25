// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
//     //LCA = first node at which node p and node q exists in its subtrees
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
//         auto dfs = [&](auto&& self , TreeNode* root)->TreeNode*{

//             if(root == nullptr)return nullptr;//nullnode have no ancestor

//             if(root->val == p->val || root->val == q->val)return root;//a node can be ancestor of his own

//             //for each node , find its leftLCA and its rightLCA
//             TreeNode* lftLCA = self(self,root->left);
//             TreeNode* rtLCA = self(self,root->right);

//             if(lftLCA && rtLCA)return root;
//             else if(lftLCA)return lftLCA;
//             else return rtLCA;
//         };
//         return dfs(dfs,root);
//     }
// };



// class Solution {
//     //Binary Lifting best when we are provided with queries and need to find ancestors for each query efficiently

//     //to uniquely mark each node with id 0 tp n-1
//     unordered_map<TreeNode*,int>NodeToid;
//     //reverse lookup array to find nodes with given id(0 - n-1)
//     vector<TreeNode*>idToNode;
//     //depth array to store depth for each node
//     vector<int>depth;
//     //ancestor table to store ancestors for each node at every 2^j jump (j = 0,1,2...)
//     vector<vector<int>>Ancestor;

//     //return total nodes count , fillup maps and vectors
//     int Getdepth(TreeNode* root , int crntDpth ,int& idCounter){
//         if(!root)return 0;
//     //uniquely identify each node
//         int crntId = idCounter++;
//         NodeToid[root] = crntId;
//     //store depth of each node and id to node
//         if(crntId >= depth.size()){
//             depth.resize(crntId+1);
//             idToNode.resize(crntId+1);
//             }
//         depth[crntId] = crntDpth;
//         idToNode[crntId] = root;
//     //to return total number of nodes in tree
//       int lftCnt =   Getdepth(root->left,crntDpth+1,idCounter);
//        int rtCnt =   Getdepth(root->right,crntDpth+1,idCounter);

//        return lftCnt+rtCnt+1;
//     }
//     //fill parent nodes(1st jump)
//     void fillUp(TreeNode* node , TreeNode* parent){
//         int nodeId = NodeToid[node];
//         int prntId = parent?NodeToid[parent]:-1;

//         Ancestor[nodeId][0] = prntId;

//         if(node->left)fillUp(node->left,node);
//         if(node->right)fillUp(node->right,node);
//     }

// public:
//     //using binary lifting now
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         int idCounter = 0;
//         int rows = Getdepth(root,0,idCounter);
//         int cols = log2(rows)+1;//max no of jumps the deepest node can make
//         Ancestor.resize(rows,vector<int>(cols,-1));
//         //fill parent nodes (aka 1st ancestor for each node)
//         fillUp(root,nullptr);

//         //fill remaining ancestors
//         for(int j = 1 ;  j < cols; j++){
//             for(int i = 0 ; i < rows ; i++){
//                 if(Ancestor[i][j-1] != -1){
//                     Ancestor[i][j] = Ancestor[Ancestor[i][j-1]][j-1];
//                 }
//             }
//         }

//         int u = NodeToid[p];
//         int v = NodeToid[q];
//         //make u deepest node to jump upwards
//         if(depth[u] < depth[v])swap(u,v);
//         int diff = depth[u] - depth[v];//diff = k , kth ancestor of node
//         for(int j = 0 ; j < cols ; j++){
//             if(diff & (1 << j)){
//                 u = Ancestor[u][j];
//             }
//         }
//     //if after shifting the deepest node both nodes are at same , return the parent node
//         if(u == v)return depth[u] == depth[NodeToid[p]]?p:q;

//     //move both nodes upwards simultaneously
//     //only moves when current jump provides an ancestor at that jump and moving both nodes at that jump dont have same ancestor at that jump
//     for(int j = cols-1; j >= 0 ; j--){
//         if(Ancestor[u][j] != -1 && Ancestor[u][j] != Ancestor[v][j]){
//             u = Ancestor[u][j];
//             v = Ancestor[v][j];
//         }
//     }
//     //now the next ancestor of node u(aka parent node) will be our LCA
//     int LCAid = Ancestor[u][0];
    
//     //get Node from idToNode using LCAid in O(1)
//     return idToNode[LCAid];
//     }
// };
