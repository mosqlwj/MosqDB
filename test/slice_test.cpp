//
// Created by lwj on 22-8-30.
//
#include <iostream>

#include "slice.h"

int main() {
    mosqdb::Slice s("hello");
    std::cout << "size:" << s.Size()
              << " str:"  << s.ToString()
              << " char:" << s[1]
              << " empty:" <<s.Empty()
              << std::endl;
    mosqdb::Slice s2("hello world");
    std::cout << s2.Compare(s) << std::endl;
    std::cout << s2.StartWith(s) << std::endl;

    return 0;
}