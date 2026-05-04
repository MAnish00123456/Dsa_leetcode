// A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. 
// For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
// Given a string s, return the longest substring of s that is nice. If there are multiple,
//  return the substring of the earliest occurrence. If there are none, return an empty string.


/*
========================================================
LEETCODE 1763 - Longest Nice Substring
========================================================

MAIN IDEA:
A substring is "nice" if:
For every letter present, both lowercase and uppercase exist.

Example:
"aA"      -> nice
"aAB"     -> not nice (because B exists but b doesn't)
"YazaAay" -> longest nice substring = "aAa"

--------------------------------------------------------
WHAT DO lower AND upper STORE?
--------------------------------------------------------

We use two integers as BITMASKS:

int lower = 0;   // stores lowercase letters present
int upper = 0;   // stores uppercase letters present

Each bit represents one letter:

bit 0  -> a / A
bit 1  -> b / B
bit 2  -> c / C
...
bit 25 -> z / Z

If a bit is ON (1), that means that letter is present.

--------------------------------------------------------
HOW DOES THIS WORK?
--------------------------------------------------------

Suppose current character is 'c'

s[k] - 'a' = 2

Then:
1 << 2 = 4

Binary:
00000100

This means:
"Turn ON bit 2"

So:
lower |= (1 << (s[k] - 'a'));

means:
"Mark lowercase 'c' as present"

--------------------------------------------------------
EXAMPLE 1:
substring = "ac"

Initially:
lower = 0
upper = 0

See 'a':
lower |= (1 << ('a' - 'a'))
lower |= (1 << 0)
lower |= 1

Binary:
lower = 00000001

Meaning:
'a' is present

See 'c':
lower |= (1 << ('c' - 'a'))
lower |= (1 << 2)
lower |= 4

Binary:
lower = 00000101

Meaning:
'a' and 'c' are present

So:
lower = 5

BUT IMPORTANT:
We don't care about decimal 5.
We care about which bits are ON.

--------------------------------------------------------
EXAMPLE 2:
substring = "aA"

See 'a':
lower = 00000001
upper = 00000000

See 'A':
lower = 00000001
upper = 00000001

Now:
lower == upper

This means:
Every lowercase letter present also has uppercase present
and every uppercase letter present also has lowercase present

So substring is NICE.

--------------------------------------------------------
EXAMPLE 3:
substring = "aAB"

See 'a':
lower = 00000001
upper = 00000000

See 'A':
lower = 00000001
upper = 00000001

See 'B':
lower = 00000001
upper = 00000011

Now:
lower != upper

Why?
Because:
'a'/'A' pair exists
but 'B' exists and 'b' does not

So substring is NOT nice.

--------------------------------------------------------
WHY DOES "lower == upper" MEAN NICE?
--------------------------------------------------------

Because both masks represent the same set of letters.

If lower == upper, it means:
- every lowercase letter seen also has uppercase version
- every uppercase letter seen also has lowercase version

So the substring satisfies the "nice" condition.

--------------------------------------------------------
APPROACH
--------------------------------------------------------

1) Try every possible starting index i
2) Expand substring from i to k
3) Keep updating lower and upper masks
4) If lower == upper, substring is nice
5) Store longest nice substring

TIME COMPLEXITY:
O(n^2)

SPACE COMPLEXITY:
O(1)

========================================================
*/



#include<iostream>
#include<string>

        std::string longestNiceSubstring(std::string s) {
            int n = s.size();
            std::string ans = "";
    
            // Try every possible starting index of substring
            for (int i = 0; i < n; i++) {
                // lower stores lowercase letters present in current substring
                // upper stores uppercase letters present in current substring
                int lower = 0, upper = 0;
    
                // Extend substring from i to k
                for (int k = i; k < n; k++) {
    
                    // If current character is lowercase:
                    // turn ON the corresponding bit in lower
                    if (islower(s[k])) {
                        lower |= (1 << (s[k] - 'a'));
                    }
                    // If current character is lowercase:
                    // turn ON the corresponding bit in lower
    
                    else {
                        upper |= (1 << (s[k] - 'A'));
                    }
    
                    /*
                    A substring is "nice" if for every letter present,
                    both lowercase and uppercase forms are present.
    
                    lower mask = lowercase letters present
                    upper mask = uppercase letters present
    
                    If both masks are equal, it means:
                    every lowercase letter seen also has uppercase present,
                    and every uppercase letter seen also has lowercase present.
                    */
                    if (lower == upper) {
    
                        // Update answer only if current nice substring is longer
                        if (k - i + 1 > ans.size()) {
                            ans = s.substr(i, k - i + 1);
                        }
                    }
                }
            }
    
            return ans;
        }

int main(){
    std::string str = "abaABzB";
    std::string ans = longestNiceSubstring(str);
    std::cout<<"Longest nice substring is : "<<ans;
}