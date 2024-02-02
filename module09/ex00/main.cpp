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
#include <list>
#include <limits>

#include <cstdlib>
#include <unistd.h>

void print_tm(struct tm &tm)
{
    std::cout << "tm.tm_mday: " << tm.tm_mday << std::endl;
    std::cout << "tm.tm_mon: " << tm.tm_mon << std::endl;
    std::cout << "tm.tm_year: " << tm.tm_year << std::endl;
}

class Btc
{
public:
    void handle_csv(char *filepath)
    {
        std::string line;
        std::ifstream infile(filepath);

        std::getline(infile, line); // skip the header
        while (std::getline(infile, line))
        {
            this->handle_data_line(line, ',');
        }
        std::cout << " ====== Finished initing DB ======" << std::endl;
    }

    void handle_input(char *filepath)
    {
        std::string line;
        std::ifstream infile(filepath);

        std::getline(infile, line); // skip the header
        while (std::getline(infile, line))
        {
            this->handle_input_line(line, '|');
        }
    }
    void iter_db()
    {
        std::map<std::string, float>::iterator it;
        for (it = db.end(); it != db.begin(); --it)
        {
            std::cout << it->first << std::endl;
        }
    }
    std::string earliest()
    {
        return db.begin()->first;
    }

    float find_price(std::string valid_date)
    {
        std::map<std::string, float>::iterator it = db.lower_bound(valid_date);
        if (it != db.end())
        {
            return it->second;
        }
        else
        {
            // https://stackoverflow.com/questions/13759749/intentionally-return-nan
            return std::numeric_limits<float>::quiet_NaN();
        }
    }
    // private:
    static const bool debug = DEBUG;
    std::map<std::string, float> db;
    std::string handle_date(std::string &str)
    {
        std::string date(str);
        char buf[100];
        struct tm tm;
        // std::string result;

        strptime(date.c_str(), TF, &tm);
        strftime(buf, sizeof(buf), TF, &tm);

        return buf;
    }

    float handle_float(std::string &str)
    {
        float price = std::atof(str.c_str());
        return price;
    }

    void handle_data_line(std::string &line, char delim)
    {
        std::string segment;

        std::stringstream ss(line);

        std::getline(ss, segment, delim);
        std::string date = handle_date(segment);
        if (debug)
            std::cout << "date: " << date;

        std::getline(ss, segment, ',');
        float price = handle_float(segment);
        if (debug)
            std::cout << " | set to: " << price << std::endl;
        db[date] = price; ///////////////////////////////////////////////// insert
    }

    std::list<std::string> split_string(std::string const line, char delim)
    {
        std::string segment;
        std::stringstream ss(line);
        std::list<std::string> result;

        while (std::getline(ss, segment, delim))
        {
            result.push_back(segment);
        }
        return result;
    }

    void handle_input_line(std::string &line, char delim)
    {
        std::string segment;

        std::stringstream ss(line);

        std::getline(ss, segment, delim);
        std::string date = handle_date(segment);
        std::cout << "date: " << date;
        float price = find_price(date);
        std::cout << " => $" << price << "$\t"; // << std::endl;

        std::getline(ss, segment, ',');
        float amount = handle_float(segment);
        std::cout << " * " << amount << "\t= " << (price * amount) << "$" << std::endl;
    }
    std::list<std::string> split_string(std::string &line, char delim)
    {
        std::string segment;
        std::stringstream ss(line);
        std::list<std::string> result;

        while (std::getline(ss, segment, delim))
        {
            result.push_back(segment);
        }
        return result;
    }

    bool valid_date(std::string date) {
        struct tm tm;
        if (strptime((date).c_str(), TF, &tm)){
            std::cout << "Valid date: " << date << std::endl;
            return true;
        } else {
            std::cout << "Invalid date: " << date << std::endl;
            return false;
        }
    }
};



int main(int argc, char **argv)
{
    argc++;

    char *csv_path = argv[1];
    char *input_path = argv[2];
    std::cout << csv_path << input_path << std::endl;
    Btc btc;
    btc.handle_csv(csv_path);
    btc.handle_input(input_path);
    // btc.iter_db();
    std::cout << btc.find_price("2015-05-02") << std::endl;
    std::cout << btc.find_price("3333-05-05") << std::endl;

    std::list<std::string> parts = btc.split_string("2022-12-02", '-');
    std::list<std::string>::iterator it;
    for (it = parts.begin(); it != parts.end(); ++it)
    {
        std::cout << *it << std::endl;
        // int part;
    }

    btc.valid_date("2022-12-02");
    btc.valid_date("2222-12-02");
    btc.valid_date("2022-13-02");
    btc.valid_date("2022-13-42");
    // std::string s("2015-01-03");
    // std::cout << next_day(s, -1) << std::endl;
}
