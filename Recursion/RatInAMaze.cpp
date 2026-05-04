//In this question we have given a 2D grid values size n*n filled with either 0 or 1.
//We are a Rat and at starting position (0,0) and our goal is to find all  the paths that leads us to our exit that is at (n-1,n-1)
//But there are some rules of movement , Rat can move upwards , downwards , left , right from its current cell position and no diagonal movements are allowed
//The Rat can move in a direction if only the value of that cell is 1 , but if it is 0 he cannot move in that direction
//We will recursively find all the paths that lead us to the goal cell
//if starting cell positon have value 0 , there are no solution exists , and if goal cell is 0 , there are no solution exists
#include<iostream>
#include<vector>
#include<string>

//An optimization can be done in space complexity by removing the 2d visited matrix,
//we can think that if a value is visited(value = 1) and we change its value to -1 , we can say that its visited , and if a value is 1 , we can say its unvisited  right now and we can use that path
//Maze[r][c] = 1 = vis[r][c] = false;


void PathFinider(std::vector<std::vector<int>>&Maze,int row,int col,std::vector<std::string>&Ans,std::string path,int& count){
// void PathFinider(std::vector<std::vector<int>>&Maze,int row,int col,std::vector<std::string>&Ans,std::string path,std::vector<std::vector<bool>>&Vis){
int n = Maze.size();
//Base Cases
if(row < 0 || col < 0 || row >= n || col >= n || Maze[row][col] == 0 || Maze[row][col] == -1){
return;
}
//Answer case
if(row == n-1 && col == n-1){
    Ans.push_back(path);
    count++;
    return;
}
// Vis[row][col] = true;//changing path availability to occupied for a particulat path
Maze[row][col] = -1;//Means the path is currently occupied for that recursive layer and we dont wanna go to that path again
PathFinider(Maze,row+1,col,Ans,path+"D",count);//Downward movement
PathFinider(Maze,row,col-1,Ans,path+"L",count);//Left movement
PathFinider(Maze,row,col+1,Ans,path+"R",count);//Right movement
PathFinider(Maze,row-1,col,Ans,path+"U",count);//Upward movement
// Vis[row][col] = false;//Changing path availability to available after a path is found
Maze[row][col] = 1;//We will free all the paths we included in previous recursive layer so different answers can be generated
}


//Function that gets Maze from main function and pass it to other function to find paths (helper function)
std::vector<std::string>ratInMaze(std::vector<std::vector<int>>&Maze){
std::vector<std::string>Ans;//An Array of strings to store all paths
int n = Maze.size();
int count = 0;
std::string Path="";//to store path for a particular recursion call
// std::vector<std::vector<bool>>Visited(n,std::vector<bool>(n,false));//An boolean array to prevent the rat from going to position from where it comes , for like if he do a downward movement , we dont want it to go the same cell again by upward movement
PathFinider(Maze,0,0,Ans,Path , count);
std::cout<<"No of paths: " <<count<<std::endl;
return Ans;
}



int main(){
std::vector<std::vector<int>>Maze={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
//for this particular Maze there are 2 paths available , we will find all
std::vector<std::string> Path = ratInMaze(Maze);
for(std::string path : Path){
    std::cout<<path<<std::endl;

}
return 0;
}