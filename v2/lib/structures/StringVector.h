#pragma once

#include "Vector.h"
#include <string>
#include <string.h>

class StringVector {
private:
    Vector<char> char_storage;
    Vector<int> char_index;

public:
    StringVector(void) { ; }
    
    void push_back(const char* str) {
        char_index.push_back(char_storage.size());
        int s = strlen(str);
        for(int i = 0; i < s; i++)
            char_storage.push_back(str[i]);
        char_storage.push_back('\0');
    }

    void push_back(std::string str) {
        this->push_back((const char*)str.c_str());
    }

    int size(void) {
        return char_index.size();
    }

    std::string at(int index) {
        // multiple bounds checks
        return std::string(&char_storage.at(char_index.at(index)));
    }

    std::string operator[](int index) {
        // no bounds checking
        return std::string(&char_storage[char_index[index]]);
    }

};