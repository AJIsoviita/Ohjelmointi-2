#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <cctype>
using namespace std;

int check(string avain)
{

  int len;
  string isoavain = avain;
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  len = avain.length();

  if (len != 26)
  {
      cout <<"Error! The encryption key must contain 26 characters." << endl;
      return EXIT_FAILURE;
  }
  for_each(isoavain.begin(), isoavain.end(), [](char & c){
           c = tolower(c);
  });
  if (isoavain != avain)
  {
      cout<<"Error! The encryption key must contain only lower case characters."<<endl;
      return EXIT_FAILURE;
  }
  for (int i = 0; i < avain.size(); i++)
  {
   size_t n = count(avain.begin(), avain.end(), avain[i]);
   if (n > 1)
   {
       cout<<"Error! The encryption key must contain all alphabets a-z."<<endl;
       return EXIT_FAILURE;
   }
  }
}

int encrypt(string teksti, string avain)
{
    int i = 1;
    size_t pos;
    while (i <= 26)
    {
    while ((pos = teksti.find(teksti[i])) != string::npos)
    {
        teksti.replace(pos, 1, avain[i]);
    }
    ++i;
    }
}

int main()
{
  cout << "Enter the encryption key: ";
  string salausavain;
  cin >> salausavain;
  check(salausavain);
  cout << "Enter the text to be encrypted: ";
  string text;
  cin >> text;
  cout << encrypt(text, salausavain);
}
