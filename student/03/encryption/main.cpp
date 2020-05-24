#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <cctype>
using namespace std;

int check_key(string avain)
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
  for (size_t i = 0; i < avain.length(); i++)
  {
   size_t n = count(avain.begin(), avain.end(), avain[i]);
   if (n > 1)
   {
       cout<<"Error! The encryption key must contain all alphabets a-z."<<endl;
       return EXIT_FAILURE;
   }
  }
  return 0;
}

int check_word(string avain)
{
  string isoavain = avain;
  string alphabet = "abcdefghijklmnopqrstuvwxyz";

  for_each(isoavain.begin(), isoavain.end(), [](char & c){
           c = tolower(c);
  });
  if (isoavain != avain)
  {
      cout<<"Error! The encryption key must contain only lower case characters."<<endl;
      return EXIT_FAILURE;
  }
  for (string::iterator it=avain.begin(); it!=avain.end(); ++it)
  {
   if ((*it) < 0x61 || (*it) > 0x7A)
   {
       cout<<"Error! The encryption key must contain only lower case characters."<<endl;
       return EXIT_FAILURE;
   }
  }
  return 0;
}


string encrypt(string teksti, string avain)
{
 string alphabet = "abcdefghijklmnopqrstuvwxyz";
 int i = 0;
 for (char& c : teksti)
 {
 while (i < 26)
 {
 if (c == alphabet[i])
     c = avain[i];
 i++;
 }
 i=0;
 }
 return teksti;
}

int main()
{
  cout << "Enter the encryption key: ";
  string salausavain;
  cin >> salausavain;
  if (check_key(salausavain) == EXIT_FAILURE) return EXIT_FAILURE;
  cout << "Enter the text to be encrypted: ";
  string text;
  cin >> text;
  if (check_word(text) == EXIT_FAILURE) return EXIT_FAILURE;
  cout << "Encrypted text: " << encrypt(text, salausavain) << endl;
}
