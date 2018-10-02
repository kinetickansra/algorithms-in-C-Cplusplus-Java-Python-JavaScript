#include <unordered_map>

class TrieNode {
    public : 
    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;
    

    TrieNode(char data) {
       this -> data = data;
       isTerminal = false;
    }
};
