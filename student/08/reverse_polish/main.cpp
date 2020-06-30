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
    string juttu;
    vector<string> numberot;
    getline(cin, juttu);
    int vastaus = 0;
    bool first = true;
    if(juttu.find_first_not_of("0123456789+/*-# ") == std::string::npos)
    {
        numberot = split(juttu,' ', true);
        numberot.pop_back();
        while(numberot.size() > 0)
        {
            if(numberot.at(0).find_first_not_of("0123456789") == std::string::npos && first)
            {
                first = false;
                if(numberot.at(1).find_first_not_of("0123456789") == std::string::npos)
                {
                    if(numberot.at(2).find_first_not_of("0123456789") == std::string::npos)
                    {
                        if(numberot.back() == "/")
                        {
                            if(numberot.at(1) == "0")
                            {
                                cout << "Error: Division by zero";
                                return EXIT_FAILURE;
                            }
                            vastaus += (stoi(numberot.at(0)) / stoi(numberot.at(1)));
                            numberot.erase(numberot.begin(),numberot.begin()+1);
                            numberot.pop_back();

                        }
                        else if(numberot.back() == "+")
                        {
                            vastaus += (stoi(numberot.at(0)) + stoi(numberot.at(1)));
                            numberot.erase(numberot.begin(),numberot.begin()+1);
                            numberot.pop_back();
                        }
                        else if(numberot.back() == "-")
                        {
                            vastaus += (stoi(numberot.at(0)) - stoi(numberot.at(1)));
                            numberot.erase(numberot.begin(),numberot.begin()+1);
                            numberot.pop_back();

                        }
                        else if(numberot.back() == "*")
                        {
                            vastaus += (stoi(numberot.at(0)) * stoi(numberot.at(1)));
                            numberot.erase(numberot.begin(),numberot.begin()+1);
                            numberot.pop_back();
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
                    if(numberot.at(2) == "/")
                    {
                        if(numberot.at(1) == "0")
                        {
                            cout << "Error: Division by zero";
                            return EXIT_FAILURE;
                        }
                        vastaus += (stoi(numberot.at(0)) / stoi(numberot.at(1)));
                        numberot.erase(numberot.begin(),numberot.begin()+1);
                        numberot.pop_back();
                    }
                    else if(numberot.at(2) == "+")
                    {
                        vastaus += (stoi(numberot.at(0)) + stoi(numberot.at(1)));
                        numberot.erase(numberot.begin(),numberot.begin()+1);
                        numberot.pop_back();
                    }
                    else if(numberot.at(2) == "-")
                    {
                        vastaus += (stoi(numberot.at(0)) - stoi(numberot.at(1)));
                        numberot.erase(numberot.begin(),numberot.begin()+1);
                        numberot.pop_back();
                    }
                    else if(numberot.at(2) == "*")
                    {
                        vastaus += (stoi(numberot.at(0)) * stoi(numberot.at(1)));
                        numberot.erase(numberot.begin(),numberot.begin()+1);
                        numberot.pop_back();
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
                if(numberot.at(0).find_first_not_of("0123456789") == std::string::npos)
                {
                    if(numberot.at(1).find_first_not_of("0123456789") == std::string::npos)
                    {
                        if(numberot.back() == "/")
                        {
                            if(numberot.at(1) == "0")
                            {
                                cout << "Error: Division by zero";
                                return EXIT_FAILURE;
                            }
                            vastaus = (vastaus / stoi(numberot.at(0)));
                            numberot.erase(numberot.begin());
                            numberot.pop_back();

                        }
                        else if(numberot.back() == "+")
                        {
                            vastaus = (vastaus + stoi(numberot.at(0)));
                            numberot.erase(numberot.begin());
                            numberot.pop_back();
                        }
                        else if(numberot.back() == "-")
                        {
                            vastaus = (vastaus - stoi(numberot.at(0)));
                            numberot.erase(numberot.begin());
                            numberot.pop_back();

                        }
                        else if(numberot.back() == "*")
                        {
                            vastaus = (vastaus * stoi(numberot.at(0)));
                            numberot.erase(numberot.begin());
                            numberot.pop_back();
                        }
                        else
                        {
                            cout << "Error: Too few operators";
                            return EXIT_FAILURE;
                        }
                    }
                    else
                    {
                        if(numberot.at(1) == "/")
                        {
                            if(numberot.at(0) == "0")
                            {
                                cout << "Error: Division by zero";
                                return EXIT_FAILURE;
                            }
                            vastaus = (vastaus / stoi(numberot.at(0)));
                            numberot.erase(numberot.begin(),numberot.begin()+1);
                        }
                        else if(numberot.at(1) == "+")
                        {
                            vastaus = (vastaus + stoi(numberot.at(0)));
                            numberot.erase(numberot.begin(),numberot.begin()+1);

                        }
                        else if(numberot.at(1) == "-")
                        {
                            vastaus = (vastaus - stoi(numberot.at(0)));
                            numberot.erase(numberot.begin(),numberot.begin()+1);
                        }
                        else if(numberot.at(1) == "*")
                        {
                            vastaus = (vastaus * stoi(numberot.at(0)));
                            numberot.erase(numberot.begin(),numberot.begin()+1);

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
        cout << "Correct: " << vastaus << " is the result";
        return EXIT_SUCCESS;
}
