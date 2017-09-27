#include <memory>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include "optional.hpp"

struct TrieNode {
    std::experimental::optional<std::string> word;
    std::unordered_map<char, TrieNode> nextNodes;
};

class Trie {
private:
    TrieNode _root;
    size_t _num_words;
    size_t _num_nodes;
public:
    std::unordered_set<char> _unique_chars;
    Trie() 
        : _root(), 
          _num_words(), 
          _num_nodes(1) 
    {}
    bool contains(const std::string & str) const;
    void insert(const std::string & str);
    size_t num_words() const { return _num_words; }
    size_t num_nodes() const { return _num_nodes; }
    size_t unique_chars() const { return _unique_chars.size(); }
};

std::ostream& operator<<(std::ostream& out, const TrieNode & node);
