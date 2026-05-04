//Book allocation problem
//in this problem we have been given a array 'A' in which each ith index shows the total no of pages that book have. 
// we have been given N books and M no of students , and we have to find maximum allowed minimum no of pages to a student.
//Each student must have atleast one book and pages should be allocated in a contiguous order.
//return -1 if no assignment is possible , in cases of when students count are greater than number of books

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
//this checks if current no of pages allocation satisfy the condition or not
bool isValid(std::vector<int>& BooksPages,int NoOfStudents,int MaximumAllowedPages){
int stu=1;
int pages=0;
for(int i=0;i<BooksPages.size();i++){
    if(BooksPages[i]>MaximumAllowedPages){return false;}
    if(pages+BooksPages[i]<=MaximumAllowedPages){
        pages=pages+BooksPages[i];
    }
    else{
        stu++;
        pages=BooksPages[i];
    }
}
return stu>NoOfStudents?false:true;
}

int maxallowedminNOofpages(std::vector<int>& BooksPages, int N){
    int books=BooksPages.size();
    int students=N;
    int end=0;
    for(int i=0;i<books;i++){
        end+=BooksPages[i];
    }
    int st=*max_element(BooksPages.begin(),BooksPages.end());//the minimum possible maximum pages must be at least the largest single book; otherwise the allocation is impossible
    int ans=-1;
    if(students>books) return -1;
    while(st<=end){
        int mid=st + (end-st)/2;
        if(isValid(BooksPages,students,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return ans;
}
int main(){
    std::vector<int> BooksPages={2,1,3,4};
    int NOofStudents=2;
    int maxPages=maxallowedminNOofpages(BooksPages,NOofStudents);
    std::cout<<"Maximum no of pages allocated to a student that is overall minimum : "<<maxPages;
    return 0;
}