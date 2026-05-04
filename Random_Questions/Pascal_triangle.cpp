//given number of rows , we need to return pascal triangle for that number of rows
//for ex : rows = 5 
//triangle =           1
            //        1 1
            //      1  2  1
            //    1  3   3  1
            //   1  4   6  4  1

            // next row = (previous row shifted left) + (previous row shifted right)
#include<iostream>
#include<vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>>Ans;
    std::vector<int>nums={1};
    Ans.push_back(nums);
    int currRow = 1;
    while(currRow < numRows){
        // copy previous row
        std::vector<int>temp = nums;
        // add 0 padding on both sides
        // helps to generate next row easily
        temp.insert(temp.begin(),0);
        temp.push_back(0);
        int i = 0 , j = i+1;
        nums.clear();
        while(j < temp.size()){
            int val = temp[i] + temp[j];
            nums.push_back(val);
            i++;
            j++;
        }   
        Ans.push_back(nums);
        currRow++;
    }
    return Ans;
}

int main(){
    std::vector<std::vector<int>>Ans = generate(6);
    int n = Ans.size();

for(int i = 0; i < n; i++){

    // spacing
    for(int j = 0; j < n - i - 1; j++){
        std::cout << "  ";
    }

    // values with spacing
    for(int val : Ans[i]){
        std::cout << val << "   ";
    }

    std::cout << std::endl;
}
return 0;
}