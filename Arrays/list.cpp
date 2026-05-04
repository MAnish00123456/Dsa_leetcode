#include<iostream>
#include<map>
#include<list>
#include<queue>
int main(){
    // std::list<int> list={1,2,3};
    // for(auto i:list){
    //     std::cout<<i<<"\t";
    // }

    // std::list<int> li;
    // li.push_back(1);
    // li.push_back(2);
    // li.push_back(3);
    // li.push_back(4);
    // li.push_back(5);
    // std::cout<<"size of the list before pop is:"<<li.size()<<std::endl;
    // li.pop_back();
    // std::cout<<"size of the list after pop is:"<<li.size()<<std::endl;
    
    // for(auto i:li){
    //     std::cout<<i<<"\t";
    // }
    

    // //pair
    // std::pair<int,std::pair<int,char>> p={1,{1,'a'}};
    // std::cout<<p.first<<std::endl;
    // std::cout<<p.second.first<<std::endl;


    //basically this uses a max or min heap internally
    // std::priority_queue<int> q1;//for printing greatest to lowest element 
    // std::priority_queue<int,std::vector<int>,std::greater<int>> q1;//for printing in reverse order aka lowest element to greatest element
    // q1.push(3);
    // q1.push(2);
    // q1.push(13);
    // q1.push(10);
    // while(!q1.empty()){
    //     std::cout<<q1.top()<<"\t";
    //     q1.pop();
    // }


    //upper case letter comes before lower case
    //prints in lexicographical order
    std::map<std::string,int> data;
    data["fridge"]=100;
    data["carpets"]=200;
    data["cushion"]=120;
    data["bulb"]=120;
    data["sofa"]=30;
    data["televesion"]=10;
    data.insert({"age",18});

    //jst simply use emplace for in place construction
    data.emplace("class",9);
    // for(auto keyval:data){
    //     std::cout<<keyval.first<<"\t"<<keyval.second<<std::endl;
    // }

if(data.find("hello")!=data.end()){
}
else{
    std::cout<<"sry";

}
    //kitni keys exist karti hai jinki name fridge hai , ans:1
    // std::cout<<data.count("fridge");
}