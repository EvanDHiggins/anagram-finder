#include "trie.hpp"
#include <iostream>
#include <fstream>
#include <set>
#include <vector>

//void find_words(const std::string & prefix,
                //std::multiset<char>& charset,
                //std::vector<std::string>& words,
                //const Trie& dict);

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Invalid args" << std::endl;
    }
    Trie dictionary;
    std::ifstream in(argv[1]);
    std::string word;
    while(getline(in, word)) {
        dictionary.insert(word);
    }
    std::cout << "Inserted " << dictionary.num_words() << " into dict" << std::endl;
    std::cout << dictionary.num_nodes() << " nodes in dict" << std::endl;
    std::cout << dictionary.unique_chars() << " unique chars in dict" << std::endl;
    for(const auto& c : dictionary._unique_chars) {
        std::cout << c << " ";
    }
    auto check_prefix = [&](const std::string & str) {
        std::string s = dictionary.contains_prefix(str) ? "does" : "doesn't"; 
        std::cout << "Dictionary " << s << " contain prefix " << str << std::endl;
    };
    auto check_word = [&](const std::string & str) {
        std::string s = dictionary.contains(str) ? "does" : "doesn't"; 
        std::cout << "Dictionary " << s << " contain word " << str << std::endl;
    };
    std::cout << "check word" << std::endl;
    check_word("hello");
    std::cout << "check word" << std::endl;
    check_prefix("hel");
    check_prefix("zxy");
}

//void find_words(const std::string & prefix,
                //std::multiset<char>& charset,
                //std::vector<std::string>& words,
                //const Trie& dict)
//{
    //if(!dict.contains_prefix(prefix)) {
        //return;
    //}
    //if(dict.contains(prefix)) {
        //words.push_back(prefix);
    //}

    //for(auto c : charset) {
        //charset.erase(charset.find(c));
        //find_words(prefix + c, charset, words, dict);
        //charset.insert(c);
    //}
//}
