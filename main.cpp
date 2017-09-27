#include "trie.hpp"
#include <iostream>
#include <fstream>

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
    for(auto c : dictionary._unique_chars) {
        std::cout << c << " ";
    }
}
