#define TF "%Y-%m-%d"
#define DEBUG true
#define DBPATH "data.csv"

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

// for __trimm
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

class Btc
{
public:
    Btc(void)
    {
        this->_load_csv();
    }

    void process_input(std::ifstream& infile)
    {
        std::string line;

        std::getline(infile, line); // skip the header
        while (std::getline(infile, line))
        {
            this->_handle_input_line(line, '|');
        }
    }

private:
    static const bool debug = DEBUG;
    std::map<std::string, float> db;
    void _load_csv(void)
    {
        const char *filepath = DBPATH;
        std::string line;
        std::ifstream infile(filepath);
        if (!infile.is_open())
        {
            std::cerr << "ERROR: the programm expects to be able to use the file" << filepath;
            std::cerr << " but could not be open it. Check the path, name and permissions." << std::endl;
            exit(30);
        }
        std::getline(infile, line); // skip the header
        while (std::getline(infile, line))
        {
            this->_load_line(line, ',');
        }
        if (debug)
            std::cout << " ====== Finished initing DB ======" << std::endl;
    }

    void _load_line(std::string &line, char delim)
    {
        std::string segment, date;
        std::stringstream ss(line);

        std::getline(ss, segment, delim);
        if (debug)
            std::cout << "DEBUG: loading data: date: " << segment;
        if (!__valid_date(segment))
        {
            std::cerr << std::endl
                      << "ERROR: loading data: invalid date: " << segment << std::endl;
            exit(10);
        }
        date = segment;

        std::getline(ss, segment, ',');
        if (!__isNumeric(segment))
        {
            std::cerr << std::endl
                      << "ERROR: loading data: invalid price: " << segment << std::endl;
            exit(10);
        }
        float price = handle_float(segment);
        if (debug)
            std::cout << " set to: " << price << std::endl;

        if (std::getline(ss, segment, ','))
        {
            std::cerr << std::endl
                      << "ERROR: loading data: more than two columns: what is this?:" << segment << std::endl;
            exit(10);
        }

        db.insert(std::pair<std::string, float>(date, price));
    }

    float find_price(std::string valid_date)
    {
        std::map<std::string, float>::iterator it = db.lower_bound(valid_date);
        if (debug)
            std::cout << "                                                   "
                      << "DEBUG: lower bound of " << valid_date << " is " << it->first << std::endl;
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

    float handle_float(std::string &str)
    {
        float price = std::atof(str.c_str());
        return price;
    }

    void _handle_input_line(std::string &line, char delim)
    {
        std::string segment;
        std::stringstream ss(line);

        std::getline(ss, segment, delim);
        if (!__valid_date(segment) || __trim(segment).size() != 10)
        {
            std::cerr << "ERROR: processing input: invalid date: " << segment << std::endl;
            return;
        }
        float price = find_price(segment);
        std::cout << "date: " << __trim(segment) << " => ";
        std::cout.width(8);
        std::cout << price << " * "; // << std::endl;

        std::getline(ss, segment, ',');
        float amount = handle_float(segment);
        if (!__isNumeric(__trim(segment)) || amount < 0 || amount > 1000)
        {
            std::cerr << "ERROR: invalid amount: " << segment << std::endl;
            return;
        }
        std::cout.width(4);
        std::cout << amount << " = " << (price * amount) << std::endl;
    }

    bool __valid_date(std::string date)
    {
        struct tm tm;
        if (strptime((date).c_str(), TF, &tm))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool __isNumeric(std::string str)
    {
        int len = str.length();
        char c;

        for (int i = 0; i < len; i++)
        {
            c = str[i];
            if (i == 0 && (c == '-' || c == '+'))
                continue;
            else if (i == len - 1 && c == 'f')
                continue;
            else if (isdigit(c) || c == '.')
                continue;
            else
                return (false);
        }
        return (true);
    }

    // https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring
    inline std::string &__trim(std::string &s)
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                        std::not1(std::ptr_fun<int, int>(std::isspace))));
        s.erase(std::find_if(s.rbegin(), s.rend(),
                             std::not1(std::ptr_fun<int, int>(std::isspace)))
                    .base(),
                s.end());
        return s;
    }
};
