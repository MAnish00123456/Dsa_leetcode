#include<iostream>
#include<vector>

void spiralordermatrix(std::vector<std::vector<int>> &matrix,int row,int column){
    int rows=row;
    int cols=column;
    int top=0;
    int left=0;
    int right=cols-1;
    int bottom=rows-1;
    std::vector<int> v;
    while((top<=bottom)&&(left<=right)){

        //for 1st row(left to right)
        for(int i=left;i<=right;i++){
            // std::cout<<matrix[top][i]<<"\t"
            v.push_back(matrix[top][i]);
        }

        top=top+1;//row incremented

        //for last column(top to bottom)
        for(int i=top;i<=bottom;i++){
            v.push_back(matrix[i][right]);
        }

        right=right-1;//column decremented
        
        //check if traversing row is possible
        if(top<=bottom){
            //for last row(right to left)
            for(int i=right;i>=left;i--){
                v.push_back(matrix[bottom][i]);
            }
            bottom=bottom-1;//row decremented
        }

        //check if column exists to traverse
        if(left<=right){
            //for 1st column(bottom to top)
            for(int i=bottom;i>=top;i--){
                v.push_back(matrix[i][left]);
            }
            left=left+1;//column incremented
        }

    }
    int size=v.size();
std::cout<<size<<std::endl;
for(int i=0;i<v.size();i++){
    std::cout<<v[i]<<"\t";
}

}


int main(){
    std::vector<std::vector<int>> matrix ={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

size_t row=matrix.size();
size_t col=0;
if(!matrix.empty()){
    col=matrix[0].size();
}
// std::cout<<row<<" \t"<<col;
spiralordermatrix(matrix,row,col);



}