#pragma once

/*
    A lot of constants are defined in the ToolBox
*/

#include <iostream>
#include <vector>
#include <complex>

typedef double                 real_t;

typedef std::vector<real_t>    real_set_t;
std::ostream& operator<<(std::ostream& os, real_set_t& rs) {
    if(rs.size() > 0) {
        os << '[' << rs[0];
        for(int i = 1; i < rs.size(); i++) {
            os << ", " << rs[i];
        }
        os << ']';
    }
    return os;
}

// real matrix type. allows easy modification after instantiation
typedef std::vector<std::vector<real_t>> real_matrix_t;
std::ostream& operator<<(std::ostream& os, real_matrix_t& rm) {
    os << "[\n";

    for(auto& v : rm)
        os << v << std::endl;

    os << ']';
    return os;
}

typedef std::complex<real_t>   complex_t;
typedef std::vector<complex_t> complex_set_t;

// more memory efficient matrix type. cannot be changed 
// after instantiation. if this is required, use the 
// other matrix type
class const_matrix_t {
private:
    real_t* rPtr;
    int rows = 0, columns = 0;

public:
    const_matrix_t(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        int sz = rows * columns;

        this->rPtr = new real_t[sz];
        for(int i = 0; i < sz; i++)
            rPtr[i] = 0.0;
    }

    ~const_matrix_t(void) {
        delete[] this->rPtr;
    }

    real_t at(int row, int column) {
        return rPtr[(row*this->columns) + column];
    }

    size_t elements(void) {
        return (this->rows * this->columns);
    }

    // this returns a 'row' identified by a row index
    // this can then be used to index into a specific column
    real_t* operator[](int index) {
        return rPtr + (index * this->columns);
    }

};

namespace zValue {
    const real_t _70 = 1.04;
    const real_t _75 = 1.15;
    const real_t _80 = 1.281552;
    const real_t _85 = 1.44;
    const real_t _90 = 1.644854;
    const real_t _95 = 1.959964;
    const real_t _96 = 2.05;
    const real_t _98 = 2.326;
    const real_t _99 = 2.575829;

    // high precision zValues
    const real_t _99_5   = 2.807034;
    const real_t _99_9   = 3.290527;
    const real_t _99_99  = 3.890592;
    const real_t _99_999 = 4.417173;
} // end of namespace zValue

// confidence interval has mean and range
struct confidence_interval_t {
private:
    bool max_min = false;

public:
    real_t mean, range;

    void useMeanRange(void) {
        max_min = false;
    }

    void useMaxMin(void) {
        max_min = true;
    }

    friend std::ostream& operator<<(std::ostream& os, confidence_interval_t& ci) {
        if(ci.max_min) {
            real_t max = ci.mean - ci.range;
            real_t min = ci.mean + ci.range;
            os << "[min: " << (min < max ? min : max) << ", max: "
                << (max < min ? min : max) << ']';
        }
        else {
            os << "[mean: " << ci.mean << ", range: " << ci.range << ']';
        }
        return os;
    }
};

// standard deviation has two forms: population and sample
namespace SD {
    const int population = 0;
    const int sample = 1;
} // end of namespace SD

// sorting sets of data
namespace SortMethod {
    const int increasing = 0;
    const int decreasing = 1;
}


void WaitForKeypress(void) {

    puts("\nPress ENTER to continue...");

    char c = '\n';
    do {
        c = getchar();
    } while(c != '\n');
}

#include <termios.h>
#include <stdio.h>
#include <unistd.h>

// this will need some macro spaghetti to fix for Windows users
static int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

// I KNOW ITS STUPID TO CREATE A CLASS AROUND DATA 
// THAT TAKES ONE BYTE (cough cough..Java)
class Boolean {
private:
    bool __b;

public:
    Boolean(bool b = true) {
        this->__b = b;
    }

    friend std::ostream& operator<<(std::ostream& os, Boolean b) {
        os << (b.__b ? "YES" : "NO"); // instead of 1 or 0
        return os;
    }

    bool operator()(void) {
        return __b;
    }

};

// used to get either y or n from the user
Boolean GetYesNo(void) {
    auto str = "\nPress y/n to continue: ";

    while(true) {
        std::cout << str;
        int result = getch();
        switch(result) {
            case 121: // y
            case 89:  // Y
                return true;
            case 110: // n
            case 78:  // N
                return false;
            default:
                break;
        }
    }
}
