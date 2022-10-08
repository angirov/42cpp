#include <string>
#include <iostream>
#include <fstream>

std::string replace(std::string base, std::string str1, std::string str2)
{
    std::string ret = "";

    std::size_t start = 0;
    std::size_t found = base.find(str1);
    while (found < base.npos)
    {
        ret += base.substr(start, found-start) + str2;
        start = found + str1.length();
        if (start >= base.length())
            return ret;
        found = base.find(str1, start);
    }
    ret += base.substr(start);
    return ret;
}


int main(int argc, char **argv)
{
    std::string ifname(argv[1]);
    std::ifstream infile(ifname.c_str());

    if (argc < 4)
    {
        std::cerr << "Error: wrong format "<< std::endl;
        return 1;
    }
    if (!infile)
    {
        std::cerr << "Error: cannot open " << ifname << std::endl;
        return 2;
    }

    std::string ofname = ifname + ".replace";
    std::ofstream outfile(ofname.c_str());

    std::string str1(argv[2]);
    std::string str2(argv[3]);

    std::string buff;
    while(getline(infile, buff))
        outfile << replace(buff, str1, str2) << std::endl;

    return 0;
}
