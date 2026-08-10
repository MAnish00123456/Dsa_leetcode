/*
 * Problem: Remove Outermost Parentheses (LeetCode 1021)
 * 
 * Description:
 * Given a valid parentheses string `s`, a "primitive" group is a non-empty 
 * balanced parentheses string that cannot be split further. The goal is to 
 * decompose `s` into its primitive groups, remove the outermost opening '(' 
 * and closing ')' from each group, and return the concatenated result.
 * 
 * Example:
 *   Input:  s = "(()())(())(()(()))"
 *   Groups: [ "(()())", "(())", "(()(()))" ]
 *   Stripped:[ "()()",   "()",   "()(()))" ]
 *   Output: "()()()()(()))"
 * 
 * Approach (State Tracking with Substring):
 *   - `depth`: Identifies the start of a new primitive block (transitions from 0 to 1).
 *   - `cnt`: Tracks balance within the sub-blocks. Increments on inner '(' and decrements on inner ')'.
 *   - `idx`: Dynamically stores the start index of the first character *inside* the primitive block.
 *   - Extracts valid inner segments using `s.substr(idx, i - idx + 1)` whenever `cnt == 0`.
 * 
 * Complexity:
 *   - Time Complexity: O(N) where N is the length of the string (Single pass).
 *   - Space Complexity: O(N) to store the modified output string.
 */

 //leetcode 1021

 #include<iostream>
 #include<string>

 class Solution {
    public:
        std::string removeOuterParentheses(std::string s) {
            int depth = 0;
            int cnt = 0; 
            int idx = -1;
            std::string ans = ""; // Make sure this matches the lowercase 'ans' used below
    
            for (int i = 0; i < s.size(); i++) {
                if (depth > 0) {
                    if (s[i] == '(') {
                        if (idx == -1) {
                            idx = i;
                        }
                        cnt++;
                    } else {
                        cnt--;
                        if (cnt == 0) {
                            ans += s.substr(idx, i - idx + 1);
                            idx = -1;
                        } else if (cnt < 0) {
                            depth = 0;
                            cnt = 0; //  Fixed: Change 'cnt == 0;' to 'cnt = 0;'
                        }
                    }
                } 
                else if (depth == 0) {
                    depth++;
                }
            }
            return ans;
        }
    };
    
int main(){
    Solution sol1;
    std::string str = "(()())(())(()(()))";
    std::cout<<"Ans : "<<sol1.removeOuterParentheses(str)<<std::endl;
    return 0;
}