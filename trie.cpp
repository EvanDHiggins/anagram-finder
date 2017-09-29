#include "trie.hpp"
#include <stack>
#include <sstream>
#include <iostream>

void Trie::insert(const std::string & str) {
    std::istringstream remaining(str);
    std::stack<TrieNode*> nodes;
    nodes.push(&_root);
    while(!nodes.empty()) {
        auto curr = nodes.top();
        nodes.pop();
        if(!remaining) {
            if(!curr->word) {
                curr->word = str;
                this->_num_words++;
            }
            return;
        }

        char c;
        remaining >> c;
        this->_unique_chars.insert(c);
        if(curr->nextNodes.find(c) == end(curr->nextNodes)) {
            curr->nextNodes[c] = TrieNode{};
            this->_num_nodes++;
        }
        nodes.push(&(curr->nextNodes[c]));
    }
}

bool Trie::contains(const std::string & str) const {
    std::istringstream remaining(str);
    const TrieNode *currNode = &this->_root;
    while(true) {
        if(!remaining) {
            return currNode->word ? currNode->word.value() == str : false;
        }
        char c;
        remaining >> c;
        if(currNode->nextNodes.find(c) != end(currNode->nextNodes)) {
            currNode = &currNode->nextNodes.at(c);
        } else {
            return false;
        }
    }
}

bool Trie::contains_prefix(const std::string & str) const {
    std::istringstream remaining(str);
    const TrieNode *currNode = &this->_root;
    while(true) {
        if(!remaining) {
            return true;
        }
        char c;
        remaining >> c;
        if(currNode->nextNodes.find(c) != end(currNode->nextNodes)) {
            currNode = &currNode->nextNodes.at(c);
        } else {
            return false;
        }
    }
}
