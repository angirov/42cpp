#include <string>
#include <iostream>

int main()
{
    std::string base = "123aaa-----aaa===aaa====";
    std::string str1 = "aaa";
    std::string str2 = "bbb";
    std::string ret = "";

    // std::cout << base.substr(1) << std::endl;

    std::size_t start = 0;
    std::size_t found = base.find(str1);
    while (found < base.npos)
    {
        ret += base.substr(start, found-start) + str2;
        start = found + str1.length();
        if (start >= base.length())
            std::cout << ret << std::endl; // return
        found = base.find(str1, start);
    }
    ret += base.substr(start);
    std::cout << ret << std::endl; // return
}