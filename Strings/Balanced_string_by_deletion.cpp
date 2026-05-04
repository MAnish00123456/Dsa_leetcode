

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>

class Solution {
    public:
        int minimumDeletions(std::string str) {
    
            // Count of 'a' characters to the right of each index
            int count_a_right = 0;
           std:: vector<int> Count_a_right(str.size(), 0);
    
            // Build suffix array:
            // Count_a_right[i] = number of 'a's in substring (i+1 ... end)
            for (int i = str.size() - 2; i >= 0; i--) {
                if (str[i + 1] == 'a') {
                    count_a_right++;
                    Count_a_right[i] = count_a_right;
                } else {
                    Count_a_right[i] = Count_a_right[i + 1];
                }
            }
    
            int count_b_left = 0;   // number of 'b's seen so far (left side)
            int Min_del = INT_MAX;
    
            // Try every possible split point i:
            // left side → remove all 'b'
            // right side → remove all 'a'
            for (int i = 0; i < str.size(); i++) {
    
                // update count of 'b' on left side
                if (i > 0 && str[i - 1] == 'b') {
                    count_b_left++;
                }
    
                // total deletions = 'b' on left + 'a' on right
                Min_del =std:: min(Min_del, count_b_left + Count_a_right[i]);
            }
    
            return Min_del;
        }
    };

int main(){
    std::string str = "bbaaaaabb";
    Solution sol1;
    int Min_del = sol1.minimumDeletions(str);
    std::cout<<Min_del;
    return 0;
}