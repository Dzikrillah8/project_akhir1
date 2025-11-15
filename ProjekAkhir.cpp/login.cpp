#include <iostream>
#include <fstream>
using namespace std;

struct Akun
{
   string username;
   string password;
};

void autentikasi(bool &isValidUser)
{
   const string filename = "akun.txt";
   ofstream fileWriter;
   ifstream fileReader;
   string linetext;
   string credentials[2];
   int pil;
   int i = 0;
   Akun akun;

   cout << "1.login" << endl;
   cout << "2.regis" << endl;
   cout << "pilih: ";
   cin >> pil;

   switch (pil)
   {
   case 1:
      cout << "username :";
      cin >> akun.username;
      cout << "password :";
      cin >> akun.password;

      fileReader.open(filename);

      while (getline(fileReader, linetext))
      {
         credentials[i] = linetext;
         i++;
      }
      fileReader.close();

      if (credentials[0] == akun.username && credentials[1] == akun.password)
      {
         isValidUser = true;

         cout << "\nLogin Succsess! Welcome " << akun.username << "! \n" << endl;

      }
      else
      {
         isValidUser = false;
      }

      break;
   case 2:
      cout << "username :";
      cin >> akun.username;
      cout << "password :";
      cin >> akun.password;

      fileWriter.open(filename);
      fileWriter << akun.username << endl;
      fileWriter << akun.password << endl;
      fileWriter.close();

      isValidUser = true;

      break;

   default:
      cout << "pilihan tidak sesuai" << endl;
      autentikasi(isValidUser);
      break;
   }
}

int main()
{
   bool isValidUser = false;
   int pilih;

   do {
    autentikasi(isValidUser);
    
   } while (!isValidUser);
   
   cout << "Hello.";

   return 0;
}