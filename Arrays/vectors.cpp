#include<iostream>
#include<vector>
#include<algorithm>
// int main(){
//     // std::vector<int> v(5);
//     // std::vector<int> v;
//     // std::vector<int> vec (4,1);
//     // for(int i=0;i<5;i++){
//     //     int num;
//     //     std::cout<<"enter number:";
//     //     std::cin>>num;
//     //     v.push_back(num);
//     // }
//     // auto min=std::min_element(vec.begin(),vec.end());
//     // int minvalue=*min;
//     // for(int j=0;j<5;j++){
//     //     std::cout<<v[j]<<"\t"<<"\n";
//     // }
//     // // for each loop
//     // for(int nums:vec){
//     //     std::cout<<nums<<"\t"<<"\n";
//     // }
//     // std::cout<<"successful";
//     // std::cout<<"\n"<<minvalue<<std::endl;

// }
// push_back=adding element in the end
// pop_back=removing last element
// .front()=points to first number of iterator
// .back()=points to first number of iterator

int main(){
    // std::vector<int> vec;
    // vec.push_back(1);
    // vec.push_back(12);
    // vec.push_back(13);
    // vec.pop_back();
    // std::cout<<*(vec.end()-1)<<std::endl;
    // std::cout<<vec.size()<<std::endl;
    // std::cout<<vec.capacity()<<std::endl;
    // for(int i:vec){
    //     std::cout<<i<<"\t";
    // }
    // std::vector<int>::iterator it;
    // for(it=vec.begin();it!=vec.end();it++){
    //     std::cout<<*(it)<<"\t";
    // }
    // std::cout<<"\n";
    // for(auto itt=vec.rbegin();itt!=vec.rend();itt++){
    //     std::cout<<*(itt)<<"\t";
    // }
    // std::vector<std::vector<int>> vec(2,std::vector<int>(3,1));//2=row, std::vector<int>(3,1) means 3 columns and initial value set to 1
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<3;j++){
    //         std::cout<<vec[i][j]<<"\t";
    //     }
    //     std::cout<<"\n";
    // }
    // std::vector<char> chara;
    // chara.push_back('a');
    // std::cout<<chara[0];
    // std::vector<std::string> str;
    // str.push_back("hello");
    // std::cout<<"\n"<<str[0];

    std::vector<std::vector<std::string>> mat(3,std::vector<std::string>(3,"manish"));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<mat[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
}
