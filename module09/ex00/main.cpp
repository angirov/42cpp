// https://man7.org/linux/man-pages/man3/strptime.3.html
// https://stackoverflow.com/questions/19482378/how-to-parse-and-validate-a-date-in-stdstring-in-c

#define TF "%Y-%m-%d"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <ctime>
#include <map>
#include <cstdlib>
class Btc {
public:
    void hand_file(char * filepath) {
        std::string line;
        std::ifstream infile(filepath);

        std::getline(infile, line); // skip the header
        while (std::getline(infile, line))
        {
            this->hand_line(line);
        }
    }

private:
    // map<std::string, float> db;
    std::string handle_date(std::string& str) {
        std::string date(str);
        char buf[100];
        struct tm tm;
        // std::string result;

        strptime(date.c_str(), TF, &tm);
        strftime(buf, sizeof(buf), TF, &tm);

        return buf;
    }

    float handle_price(std::string& str) {
        float price = std::atof(str.c_str());
        return price;
    }

    void hand_line(std::string &line) {
        std::string segment;

        std::stringstream ss(line);
        std::getline(ss, segment, ',');
        
        std::cout << "date:  " << handle_date(segment);

        std::getline(ss, segment, ',');
        std::cout << " | price: " << handle_price(segment) << std::endl;
    }

    std::string next_day(std::string & date) {
        // https://stackoverflow.com/questions/19482378/how-to-parse-and-validate-a-date-in-stdstring-in-c
        struct tm tm;
        char buf[100];
        time_t tt;
        std::string result;

        strptime(date.c_str(), TF, &tm); // Str is Parsed to Time
        tm.tm_mday += 1;
        tt = mktime(&tm); // change format and normalize the date e.g. 2024-01-32 > 2024-02-01, 2024-02-31 > 2024-03-02
        tm = *localtime(&tt); // reverse the format change
        strftime(buf, sizeof(buf), TF, &tm); // Str is built From Time
        result = buf;
        return result;
    }
};

int main(int argc, char** argv) {
    argc++;

    char * filename = argv[1];
    Btc btc;
    btc.hand_file(filename);

    std::cout << "++++++++++++++++" << std::endl;
    std::string test("2024-01-31");
    
}
