#include <iostream>
#include <ToolBox.h>

using namespace std;

int main(int argc, char* argv[]) {

    auto my_function = [](real_t x) -> real_t { return sin(x); };

    auto res = Derive::newton({100, 0.0, 10.0, my_function});
    

    return 0;
}