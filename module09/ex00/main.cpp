// https://man7.org/linux/man-pages/man3/strptime.3.html
// https://stackoverflow.com/questions/19482378/how-to-parse-and-validate-a-date-in-stdstring-in-c

#define TF "%Y-%m-%d"
#define DEBUG true

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <ctime>
#include <map>
#include <cstdlib>
#include <unistd.h>

class Btc {
public:
    void handle_csv(char * filepath) {
        std::string line;
        std::ifstream infile(filepath);

        std::getline(infile, line); // skip the header
        while (std::getline(infile, line))
        {
            this->handle_data_line(line, ',');
        }
    }

    void handle_input(char * filepath) {
        std::string line;
        std::ifstream infile(filepath);

        std::getline(infile, line); // skip the header
        while (std::getline(infile, line))
        {
            this->handle_input_line(line, '|');
        }
    }
    void iter_db() {
        std::map<std::string, float>::iterator it;
        for (it = db.end(); it != db.begin(); --it) {
            std::cout << it->first << std::endl;
        }
    }
    std::string earliest() {
        return db.begin()->first;
    }
    std::string find_date(std::string valid_date) {
        while (valid_date != earliest()) {
            if (debug) {
                std::cout << "Searching for " << valid_date << std::endl;
                sleep(2);
            }
            if (db.find(valid_date) != db.end()) {
                return valid_date;
            } else {
                valid_date = day_arythm(valid_date, -1);
                std::cout << "New date: " << valid_date << std::endl;
            }
        }
        return "";
    }
private:
    static const bool debug = DEBUG;
    std::map<std::string, float> db;
    std::string handle_date(std::string& str) {
        std::string date(str);
        char buf[100];
        struct tm tm;
        // std::string result;

        strptime(date.c_str(), TF, &tm);
        strftime(buf, sizeof(buf), TF, &tm);

        return buf;
    }

    float handle_float(std::string& str) {
        float price = std::atof(str.c_str());
        return price;
    }

    void handle_data_line(std::string &line, char delim) {
        std::string segment;

        std::stringstream ss(line);

        std::getline(ss, segment, delim);
        std::string date = handle_date(segment);
        if (debug)
            std::cout << "date:  " << date;

        std::getline(ss, segment, ',');
        float price = handle_float(segment);
        if (debug)
            std::cout << " | price: " << price << std::endl;
        db[date] = price; ///////////////////////////////////////////////// insert
    }

    void handle_input_line(std::string &line, char delim) {
        std::string segment;

        std::stringstream ss(line);

        std::getline(ss, segment, delim);
        std::string date = handle_date(segment);
        std::cout << "date:  " << date;
        float price = db[date];
        std::cout << " | price: " << price << "$"; // << std::endl;

        std::getline(ss, segment, ',');
        float amount = handle_float(segment);
        std::cout << " * " << amount << " = " << (price * amount) << std::endl;
    }

    std::string day_arythm(std::string & date, int diff) {
        // https://stackoverflow.com/questions/19482378/how-to-parse-and-validate-a-date-in-stdstring-in-c
        struct tm tm;
        char buf[100];
        time_t tt;
        std::string result;

        strptime(date.c_str(), TF, &tm); // Str is Parsed to Time
        std::cout << "diff: " << diff << std::endl;
        std::cout << "tm.tm_mday: " << tm.tm_mday << std::endl;
        tm.tm_mday += diff;
        std::cout << "tm.tm_mday: " << tm.tm_mday << std::endl;
        tt = mktime(&tm); // change format and normalize the date e.g. 2024-01-32 > 2024-02-01, 2024-02-31 > 2024-03-02
        tm = *localtime(&tt); // reverse the format change
        std::cout << "tm: " << tm.tm_mday << std::endl;
        strftime(buf, sizeof(buf), TF, &tm); // Str is built From Time
        result = buf;
        return result;
    }
};

int main(int argc, char** argv) {
    argc++;

    char * csv_path = argv[1];
    char * input_path = argv[2];
    Btc btc;
    btc.handle_csv(csv_path);
    btc.handle_input(input_path);
    std::cout << "===============================" << std::endl;
    // btc.iter_db();
    std::cout << btc.find_date("2015-01-03") << std::endl;



    // std::string test("2024-01-31");
    
}
