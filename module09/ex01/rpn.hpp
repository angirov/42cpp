#ifndef RPN_HPP
# define RPN_HPP
# include <stack>
# include <string>
# include <iostream>

class Rpn {
public: //////////////////////////////////////////////////
    Rpn(std::string input) {
        this->input = input;
    };
    std::string input;
    std::stack<int> stack;
    // int result;

    void do_ops(std::string word) {
        int b = get_last();
        int a = get_last();
        int result;
        if (word == "+")
            result = a + b;
        else if (word == "-")
            result = a - b;
        else if (word == "*")
            result = a * b;
        else if (word == "/")
            result = a / b;
        stack.push(result);
    }

    void run() {
        std::string::iterator it = input.begin();
        while (it != this->input.end()) {
            std::string word = get_next_word(it);
            if (word == "+" || word == "-" || word == "*" || word == "/")
                do_ops(word);
            else
                stack.push(atoi(word.c_str()));
        }
        int result = stack.top();
        std::cout << result << std::endl;
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