#ifndef RPN_HPP
# define RPN_HPP
# include <stack>
# include <string>
# include <iostream>
# include <limits>

class Rpn {
public: //////////////////////////////////////////////////
    Rpn(std::string input) {
        this->input = input;
    };
    std::string input;
    std::stack<int> stack;
    // int result;

    void do_ops(std::string word) {
        if (stack.size() < 2) {
            exit_msg("Syntax error!", 2);
        }
        int b = get_last();
        int a = get_last();
        int result;
        if (word == "+")
            result = a + b;
        else if (word == "-")
            result = a - b;
        else if (word == "*")
            result = a * b;
        else if (word == "/") {
            if (b == 0)
                exit_msg("Error: Devision by zero!", 5);
            result = a / b;
        }
        stack.push(result);
    }

    void exit_msg(std::string msg, int n) {
        std::cerr << "rpn: " << msg << std::endl;
        exit(n);
    }

    bool is_int(long n) {
        int imin = std::numeric_limits<int>::min();
        int imax = std::numeric_limits<int>::max();

        return (n <= imax && n >= imin);
    }

    void run() {
        std::string::iterator it = input.begin();
        while (it != this->input.end()) {
            std::string word = get_next_word(it);
            if (word == "+" || word == "-" || word == "*" || word == "/")
                do_ops(word);
            else {
                long n = atol(word.c_str());
                if (n == 0 && word != "0")
                    exit_msg("Bad input: Only ingeter numbers allowed!", 1);
                if (!is_int(n))
                    exit_msg("One of the input numbers is beyond integer limits!", 6);
                stack.push(n);
            }
        }
        if (stack.size() == 1) {
            int result = stack.top();
            std::cout << "rpn: result: " << result << std::endl;
            exit(0);
        }
        else {
            exit_msg("Syntax error!", 2);
        }
    }

    std::string get_next_word(std::string::iterator &it) {
        skip_whitespace(it);
        std::string::iterator start = it;
        while (!std::isspace(*it) && it != this->input.end()) {
            it++;
        }
        std::string result = std::string(start, it);
        return result;
    };

    std::string::iterator skip_whitespace(std::string::iterator &start) {
        while (std::isspace(*start) && start != this->input.end()) {
        start++;
        }
        return start;
    }
    int get_last() {
        int last = stack.top();
        stack.pop();
        return last;
    }

};

#endif