#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "TypeRedefinitions.h"
#include "structures/Vector.h"

// this holds references to data in 
// a seperate string_matrix_t object
class csv_row_t {
private:
    std::vector<char>* char_storage_ptr = NULL;
    std::vector<int>* index_vec_ptr = NULL;

public:
    csv_row_t(std::vector<char>* stor, std::vector<int>* ind) {
        this->char_storage_ptr = stor;
        this->index_vec_ptr = ind;
    }

    size_t size(void) {
        return index_vec_ptr->size();
    }

    std::string operator[](int index) {
        char* c_str = &char_storage_ptr->at(index_vec_ptr->at(index));
        return std::string(c_str);
    }

};

// the point of this storage method 
// is to take as little space as possible
class string_matrix_t {
private:
    std::vector<char> char_storage;
    std::vector<std::vector<int>> index_lut;

public:

    ~string_matrix_t(void) {
        // these arent really needed as 
        // std::vector deletes its own memory
        char_storage.clear();
        index_lut.clear();
    }

    csv_row_t row(int index) {
        return csv_row_t{&char_storage, &index_lut.at(index)};
    }

    // import to note that this is NOT the number of elements 
    // in the matrix, it is the number of rows in the matrix, 
    // each of which can have a different number of columns
    size_t size(void) {
        return index_lut.size();
    }

    csv_row_t operator[](int row) {
        return this->row(row);
    }

    int IndexOf(int row, std::string token) {
        auto r = this->row(row);
        int s = r.size();
        for(int i = 0; i < s; i++) {
            if(r[i] == token)
                return i;
        }

        throw std::runtime_error("string_matrix_t::IndexOf -> token not found in row");
    }

    int IndexOf(int row, int __token) {
        return IndexOf(row, std::to_string(__token));
    }

    void clear(void) {
        char_storage.clear();
        index_lut.clear();
    }

    std::string at(int row, int column) {
        int char_index = index_lut.at(row).at(column);
        char* c_str = &char_storage[char_index];
        return std::string(c_str);
    }

    void pushStringVector(std::vector<std::string>& s_vec) {
        int current_row = index_lut.size();
        index_lut.push_back(std::vector<int>());
        auto& v = index_lut[current_row];

        for(auto& str : s_vec) {
            v.push_back(char_storage.size());
            for(char c : str)
                char_storage.push_back(c);
            char_storage.push_back('\0');
        }
    }

    friend std::ostream& operator<<(std::ostream& os, string_matrix_t& sm) {
        for(int i = 0; i < sm.index_lut.size(); i++) {
            auto& vec = sm.index_lut.at(i);
            for(int ind : vec)
                os << &sm.char_storage.at(ind) << ", ";
            os << std::endl;
        }
        return os;
    }

};

namespace IO {

    void LoadCSV(std::string filename, string_matrix_t& sm) {
        std::ifstream f(filename);
        sm.clear();
        
        std::vector<std::string> str_vec;
        std::string stra, strb;        

        //int iters = 0;

        while(std::getline(f, stra, (char)0x0D) /*&& iters < 3*/ ) {
            strb.clear();
            for(char c : stra) {
                switch(c) {
                    case ',':
                        str_vec.push_back(strb);
                        strb.clear();
                        break;
                    default:
                        strb.push_back(c);
                        break;
                }
            }
            str_vec.push_back(strb);
            sm.pushStringVector(str_vec);
            str_vec.clear();
            //iters++;
        }

        f.close();
    }

    void LoadVector(std::string filename, real_set_t& rs) {
        std::fstream f(filename, std::ios::in);
        rs.clear();
        real_t r;
        while(f >> r)
            rs.push_back(r);
    }

    void LoadMatrix(std::string filename, real_matrix_t& rm) {
        std::fstream f(filename, std::ios::in);
        rm.clear();

        real_set_t rs;
        std::string str;

        while(std::getline(f, str)) {
            rs.clear();
            std::stringstream ss(str);

            real_t r;
            while(ss >> r) {
                rs.push_back(r);
            }
            rm.push_back(rs);
        }

    }

    real_t MakeReal(std::string str) {
        return std::stod(str);
    }

}
