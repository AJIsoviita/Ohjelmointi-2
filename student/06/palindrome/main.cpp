#include <iostream>
#include <string>
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
  int len = (s.length() - 1);

  if (s.at(0) == s.at(len))
  {
      s.erase(len);
      s.erase(0);
      if(s.length() > 1)
          palindrome_recursive(s);
      else
          return true;
  }
  return false;
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
