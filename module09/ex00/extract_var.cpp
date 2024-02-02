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
#include <cstdio>

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
            this->handle_data_line(line);
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
    std::string extract_date(std::string &str)
    {
        std::string date(str);
        char buf[100];
        struct tm tm;
        // std::string result;

        strptime(date.c_str(), TF, &tm);
        strftime(buf, sizeof(buf), TF, &tm);

        return buf;
    }

    double extract_number(std::string &str)
    {
        double price;
        if(sscanf(str.c_str(), "%lf", &price) != 1)
            return price;
        return std::numeric_limits<float>::quiet_NaN();
    }

    void handle_data_line(std::string &line)
    {
        std::stringstream ss(line);

        std::list<std::string> segments = split_string(line, '|');
        if (segments.size() != 2)
            std::cout << "Error: bad input." << std::endl;
        if (handle_input_date(segments.front()))
        {
            float price = find_price(segments.front());
            std::cout << " => $" << price << "$\t"; // << std::endl;
            segments.pop_front();
            float amount = extract_number(segments.front());
            std::cout << " * " << amount << "\t= " << (price * amount) << "$" << std::endl;
        }
    }
    bool handle_input_date(std::string date) {
        std::cout << "TODO: validate" << date << std::endl;
        return true;
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

    void handle_input_line(std::string &line, char delim)
    {
        std::string segment;

        std::stringstream ss(line);

        std::getline(ss, segment, delim);
        std::string date = extract_date(segment);
        std::cout << "date: " << date;
        float price = find_price(date);
        std::cout << " => $" << price << "$\t"; // << std::endl;

        std::getline(ss, segment, ',');
        float amount = extract_number(segment);
        std::cout << " * " << amount << "\t= " << (price * amount) << "$" << std::endl;
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

    // std::string s("2015-01-03");
    // std::cout << next_day(s, -1) << std::endl;
}
