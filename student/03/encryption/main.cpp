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

string encrypt(string teksti, string avain)
{
 string teksti2 = teksti;
 int i = 0;
 int x = 0;
 while(i, i < teksti.size())
 {
 if (teksti[i] == teksti2[i])
     replace(teksti.begin(), teksti.end(), teksti[i], avain[i]);
 i++;
 }
 return teksti;
}

int main()
{
  cout << "Enter the encryption key: ";
  string salausavain;
  cin >> salausavain;
  if (check(salausavain) == false) return EXIT_FAILURE;
  cout << "Enter the text to be encrypted: ";
  string text;
  cin >> text;
  cout << "Encrypted text: " << encrypt(text, salausavain) << endl;
}
