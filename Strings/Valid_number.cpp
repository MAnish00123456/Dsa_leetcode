#include<iostream>
#include<string>


class Solution {
    public:
        // We validate the string using flags:
        // digitSeen     → at least one digit must appear (before or after 'e')
        // exponentSeen  → only one 'e' or 'E' allowed
        // dotSeen       → only one '.' allowed and NOT after exponent
        // countPlusMinus→ at most two signs: one at start, one after 'e/E'
    
        bool isNumber(std::string s) {
            int n = s.size();
            if(n == 0) return false;
    
            bool digitSeen = false;
            bool exponentSeen = false;
            bool dotSeen = false;
            int countPlusMinus = 0;
    
            for(int i = 0 ; i < n ; i++){
                char ch = s[i];
    
                // 1) Digit: mark that we’ve seen a digit
                if(isdigit(ch)){
                    digitSeen = true;
                }
    
                // 2) Sign (+ / -):
                // allowed at the start OR immediately after 'e'/'E'
                else if(ch == '-' || ch == '+'){
    
                    // at most two signs overall (start + after exponent)
                    if(countPlusMinus == 2) return false;
    
                    // if not at start, must come right after e/E
                    // IMPORTANT: use && here (not ||)
                    if(i > 0 && (s[i-1] != 'e' && s[i-1] != 'E')){
                        return false;
                    }
    
                    // sign cannot be the last character
                    if(i == n-1) return false;
    
                    countPlusMinus++;
                }
    
                // 3) Decimal point:
                // only one dot allowed and not after exponent
                else if(ch == '.'){
                    if(dotSeen) return false;        // multiple dots
                    if(exponentSeen) return false;   // dot after e/E not allowed
    
                    // "." alone is invalid (needs at least one digit somewhere)
                    if(i == n-1 && !digitSeen) return false;
    
                    dotSeen = true;
                }
    
                // 4) Exponent (e / E):
                // only one allowed, and must come after at least one digit
                else if(ch == 'e' || ch == 'E'){
                    if(exponentSeen || !digitSeen) return false;
    
                    // cannot be first or last character
                    if(i == 0 || i == n-1) return false;
    
                    exponentSeen = true;
    
                    // After 'e', we need digits again (reset digitSeen)
                    digitSeen = false;
                }
    
                // 5) Any other character → invalid
                else{
                    return false;
                }
            }
    
            // must end having seen a digit (handles cases like "1e", "e3", "+")
            return digitSeen;
        }
    };

    int main(){
        Solution sol1;
        std::string str = "-123.456e789";
        if(sol1.isNumber(str)){
            std::cout<<"valid";
        }
        else{
            std::cout<<"invalid";
        }
        return 0;
    }