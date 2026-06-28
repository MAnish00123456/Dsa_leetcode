// A celebrity is a person who is known to all but does not know anyone at a party.
//  A party is being organized by some people. A square matrix mat[][] of size n*n is used to represent people at the party such that if an element of row i 
//  and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

//eliminate candidates from pair of 2 candidates who can never be a celebritt
        //if arr[i][j] == 1 , means i know j so i can never be celebrity , remove i 
        //if arr[i][j] == 0 means i dont know j so j can never be a celebrity , remove j

//you get a potential candidate in the end , then check if everyone knows that candidate and candidate doesnt know anyone
        // arr[celeb][i] = 0 for all i
        // arr[i][celeb] = 1 for all i

//use stack to eliminte candidates

#include<iostream>
#include<vector>

class Solution {
    public:
      int celebrity(std::vector<std::vector<int>>& mat) {
          // code here
          std::vector<int>st;
          int candidates = mat.size();
          st.reserve(candidates);
          for(int i = 0 ; i < candidates ; i++)st.push_back(i);
          
          while(st.size() > 1){
              int cand1 = st.back();
              st.pop_back();
              
              int cand2 = st.back();
              st.pop_back();
              
              if(mat[cand1][cand2] == 1){
                  st.push_back(cand2);
              }
              else{
                      st.push_back(cand1);
              }
          }
          
          int potentialceleb = st.back();
          st.pop_back();
          int Ans = potentialceleb;
          for(int i = 0 ; i < candidates ; i++){
              if(i != potentialceleb){
                  if(mat[potentialceleb][i] != 0 || mat[i][potentialceleb] != 1){
                   Ans = -1;
                   break;
                  }
              }
          }
          return Ans;
      }
  };
  
  int main(){
      Solution sol1;
      std::vector<std::vector<int>>mat = {{1,1,1},{0,1,0},{1,0,1}};
      int ans = sol1.celebrity(mat);
      std::cout<<ans;
      return 0;
  }