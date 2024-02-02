// https://man7.org/linux/man-pages/man3/strptime.3.html
// https://stackoverflow.com/questions/19482378/how-to-parse-and-validate-a-date-in-stdstring-in-c

#define TF "%Y-%m-%d"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <ctime>

void handle_date(std::string& str) {
    std::string date(str);
    // time_t t;
    char buf[100];
    struct tm tm;
    strptime(date.c_str(), TF, &tm);
    strftime(buf, sizeof(buf), TF, &tm);
    std::cout << "date:  " << buf;
}

void handle_price(std::string& str) {
    std::string price(str);
        std::cout << " | price: " << price << std::endl;
}

void hand_file(char * filepath) {
    std::string line;
    std::string segment;
    std::ifstream infile(filepath);
    std::getline(infile, line); // skip the header

    while (std::getline(infile, line))
    {
        std::stringstream ss(line);
        std::getline(ss, segment, ',');
        handle_date(segment);
        std::getline(ss, segment, ',');
        handle_price(segment);
    }
}

std::string next_day(std::string & date) {
    // https://stackoverflow.com/questions/19482378/how-to-parse-and-validate-a-date-in-stdstring-in-c
    struct tm tm;
    char buf[100];
    time_t tt;
    std::string result;

    strptime(date.c_str(), TF, &tm);
    tm.tm_mday += 1;
    tt = mktime(&tm); 
    tm = *localtime(&tt);
    strftime(buf, sizeof(buf), TF, &tm);
    result = buf;
    return result;
}

int main(int argc, char** argv) {
    argc++;

    char * filename = argv[1];

    hand_file(filename);

    std::cout << "++++++++++++++++" << std::endl;
    std::string test("2024-12-31");
    
    std::cout << next_day(test) << std::endl;
}
