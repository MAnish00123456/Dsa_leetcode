// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:

// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
// Example 1:

// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]

// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True

#include<iostream>
#include<string>

class TrieNode {
    public:
        TrieNode* children[26];
        bool isEndofword;
        TrieNode() {
            isEndofword = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };
    
    class Trie {
        TrieNode* root;
    
    public:
        Trie() { root = new TrieNode(); }
    
    public:
        void insert(std::string word) {
            TrieNode* curr = root;
            for (char ch : word) {
                if (curr->children[ch - 'a'] == nullptr) {
                    TrieNode* newNode = new TrieNode();
                    curr->children[ch - 'a'] = newNode;
                }
                curr = curr->children[ch - 'a'];
            }
            curr->isEndofword = true;
        }
    
        bool search(std::string word) {
            TrieNode* curr = root;
            for (char ch : word) {
                if (curr->children[ch - 'a'] == nullptr)
                    return false;
                curr = curr->children[ch - 'a'];
            }
            return curr->isEndofword;
        }
    
        bool startsWith(std::string prefix) {
            TrieNode* curr = root;
            for (char ch : prefix) {
                if (curr->children[ch - 'a'] == nullptr)
                    return false;
                curr = curr->children[ch - 'a'];
            }
            return true;
        }
    };
    
    /**
     * Your Trie object will be instantiated and called as such:
     * Trie* obj = new Trie();
     * obj->insert(word);
     * bool param_2 = obj->search(word);
     * bool param_3 = obj->startsWith(prefix);
     */

     int main() {
        // Fast I/O
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
    
        // Instantiate your Trie
        Trie* trie = new Trie();
        std::cout << "[";
    
        // 1. Initializing Trie
        std::cout << "null, ";
    
        // 2. insert("apple")
        trie->insert("apple");
        std::cout << "null, ";
    
        // 3. search("apple") -> should be true
        std::cout << (trie->search("apple") ? "true" : "false") << ", ";
    
        // 4. search("app") -> should be false
        std::cout << (trie->search("app") ? "true" : "false") << ", ";
    
        // 5. startsWith("app") -> should be true
        std::cout << (trie->startsWith("app") ? "true" : "false") << ", ";
    
        // 6. insert("app")
        trie->insert("app");
        std::cout << "null, ";
    
        // 7. search("app") -> should be true
        std::cout << (trie->search("app") ? "true" : "false");
    
        std::cout << "]\n";
    
        // Clean up memory
        delete trie;
        return 0;
    }
    