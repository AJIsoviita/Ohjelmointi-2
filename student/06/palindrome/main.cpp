#include <iostream>
#include <string>
#include <sstream>
#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif

using namespace std;

bool palindrome_recursive(string s)
{
  RECURSIVE_FUNC
  // Do not remove RECURSIVE_FUNC declaration, it's necessary for automatic testing to work
  // ------------


  // Add your implementation here

  if (s.at(0) != s.at(s.length()-1))
          return false;
  else
  {
      if(s.length() > 3)
      {
          s = s.substr(1, s.length() - 2);
          if(!palindrome_recursive(s)) return false;
      }
      return true;
  }
}

// Do not modify rest of the code, or the automated testing won't work.
#ifndef UNIT_TESTING
int main()
{
    cout << "Enter a word: ";
    string word;
    cin >> word;

    if(palindrome_recursive(word)){
        cout << word << " is a palindrome" << endl;
    } else {
        cout << word << " is not a palindrome" << endl;
    }
}
#endif
