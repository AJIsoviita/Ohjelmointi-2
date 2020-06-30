#include <iostream>
#include <vector>


using namespace std;

std::vector<std::string> split(const std::string& s,
                               const char delimiter,
                               const bool ignore_empty = false) {
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos) {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty())) {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty())) {
        result.push_back(tmp);
    }
    return result;
}

int main()
{
    cout << "Input an expression in reverse Polish notation (end with #):" << endl;
    cout << "EXPR> ";
    string item;
    vector<string> numbers;
    getline(cin, item);
    int total = 0;
    bool first = true;
    if(item.find_first_not_of("0123456789+/*-# ") == std::string::npos)
    {
        numbers = split(item,' ', true);
        numbers.pop_back();
        while(numbers.size() > 0)
        {
            if(numbers.at(0).find_first_not_of("0123456789") == std::string::npos && first)
            {
                first = false;
                if(numbers.at(1).find_first_not_of("0123456789") == std::string::npos)
                {
                    if(numbers.at(2).find_first_not_of("0123456789") == std::string::npos)
                    {
                        if(numbers.back() == "/")
                        {
                            if(numbers.at(1) == "0")
                            {
                                cout << "Error: Division by zero";
                                return EXIT_FAILURE;
                            }
                            total += (stoi(numbers.at(0)) / stoi(numbers.at(1)));
                            numbers.erase(numbers.begin(),numbers.begin()+1);
                            numbers.pop_back();

                        }
                        else if(numbers.back() == "+")
                        {
                            total += (stoi(numbers.at(0)) + stoi(numbers.at(1)));
                            numbers.erase(numbers.begin(),numbers.begin()+1);
                            numbers.pop_back();
                        }
                        else if(numbers.back() == "-")
                        {
                            total += (stoi(numbers.at(0)) - stoi(numbers.at(1)));
                            numbers.erase(numbers.begin(),numbers.begin()+1);
                            numbers.pop_back();

                        }
                        else if(numbers.back() == "*")
                        {
                            total += (stoi(numbers.at(0)) * stoi(numbers.at(1)));
                            numbers.erase(numbers.begin(),numbers.begin()+1);
                            numbers.pop_back();
                        }

                    }
                    else
                    {
                        cout << "Error: Too few operators";
                        return EXIT_FAILURE;
                    }
                }
                else
                {
                    if(numbers.at(2) == "/")
                    {
                        if(numbers.at(1) == "0")
                        {
                            cout << "Error: Division by zero";
                            return EXIT_FAILURE;
                        }
                        total += (stoi(numbers.at(0)) / stoi(numbers.at(1)));
                        numbers.erase(numbers.begin(),numbers.begin()+1);
                        numbers.pop_back();
                    }
                    else if(numbers.at(2) == "+")
                    {
                        total += (stoi(numbers.at(0)) + stoi(numbers.at(1)));
                        numbers.erase(numbers.begin(),numbers.begin()+1);
                        numbers.pop_back();
                    }
                    else if(numbers.at(2) == "-")
                    {
                        total += (stoi(numbers.at(0)) - stoi(numbers.at(1)));
                        numbers.erase(numbers.begin(),numbers.begin()+1);
                        numbers.pop_back();
                    }
                    else if(numbers.at(2) == "*")
                    {
                        total += (stoi(numbers.at(0)) * stoi(numbers.at(1)));
                        numbers.erase(numbers.begin(),numbers.begin()+1);
                        numbers.pop_back();
                    }
                    else
                    {
                        cout << "Error: Too few operands";
                        return EXIT_FAILURE;
                    }
                }
            }

            else if(!first)
            {
                if(numbers.at(0).find_first_not_of("0123456789") == std::string::npos)
                {
                    if(numbers.at(1).find_first_not_of("0123456789") == std::string::npos)
                    {
                        if(numbers.back() == "/")
                        {
                            if(numbers.at(1) == "0")
                            {
                                cout << "Error: Division by zero";
                                return EXIT_FAILURE;
                            }
                            total = (total / stoi(numbers.at(0)));
                            numbers.erase(numbers.begin());
                            numbers.pop_back();

                        }
                        else if(numbers.back() == "+")
                        {
                            total = (total + stoi(numbers.at(0)));
                            numbers.erase(numbers.begin());
                            numbers.pop_back();
                        }
                        else if(numbers.back() == "-")
                        {
                            total = (total - stoi(numbers.at(0)));
                            numbers.erase(numbers.begin());
                            numbers.pop_back();

                        }
                        else if(numbers.back() == "*")
                        {
                            total = (total * stoi(numbers.at(0)));
                            numbers.erase(numbers.begin());
                            numbers.pop_back();
                        }
                        else
                        {
                            cout << "Error: Too few operators";
                            return EXIT_FAILURE;
                        }
                    }
                    else
                    {
                        if(numbers.at(1) == "/")
                        {
                            if(numbers.at(0) == "0")
                            {
                                cout << "Error: Division by zero";
                                return EXIT_FAILURE;
                            }
                            total = (total / stoi(numbers.at(0)));
                            numbers.erase(numbers.begin(),numbers.begin()+1);
                        }
                        else if(numbers.at(1) == "+")
                        {
                            total = (total + stoi(numbers.at(0)));
                            numbers.erase(numbers.begin(),numbers.begin()+1);

                        }
                        else if(numbers.at(1) == "-")
                        {
                            total = (total - stoi(numbers.at(0)));
                            numbers.erase(numbers.begin(),numbers.begin()+1);
                        }
                        else if(numbers.at(1) == "*")
                        {
                            total = (total * stoi(numbers.at(0)));
                            numbers.erase(numbers.begin(),numbers.begin()+1);

                        }
                        else
                        {
                            cout << "Error: Too few operands";
                            return EXIT_FAILURE;
                        }
                    }

                }
                else
                {
                    cout << "Error: Expression must start with a number";
                    return EXIT_FAILURE;
                }
            }
        }
    }
        else
        {
            cout << "Error: Unknown character" << endl;
            return EXIT_FAILURE;
        }
        cout << "Correct: " << total << " is the result";
        return EXIT_SUCCESS;
}
