#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  setlocale(LC_ALL, "ru");

  string path = "myfyle.txt";

  ofstream fout;

  fout.open(path, ofstream::app);

  if (!fout.is_open())
  {
      cout << "Ошибка открытия файла!" << endl;
  }
  else
  {
      fout << "\n";
  }
  
  fout.close();

  fout.is_open();
  

  ifstream fin;
  fin.open(path);

  if (!fin.is_open())
  {
     cout << "Ошибка открытия файла!" << endl;
  }
  else 
  {

     cout << "Файл открыт!" << endl;
     string str;
     int sc1=0, sc2=0, sc3=0, sc4=0, sc5=0, sc6=0;
     while (!fin.eof())
     {
         str = "";
         getline(fin, str);
         cout << str << endl;
         for (int i=0;i < str.length();i++)
         {
           if (str[i] == '{')
           sc1++;
           if (str[i] == '}')
           sc2++;
           if (str[i] == '(')
           sc3++;
           if (str[i] == ')')
           sc4++;
           if (str[i] == '[')
           sc5++;
           if (str[i] == ']')
           sc6++;
         }
     }
     if (sc1==sc2)
     cout  <<"Балансирование {}, не нужно" << endl;
     if (sc1>sc2)
     cout <<"Необходимо добавить" << sc1-sc2 <<" } " << endl;
     if (sc2>sc1)
     cout <<"Необходимо добавить" << sc2-sc1 <<" { " << endl;
     
     if (sc3==sc4)
     cout  <<"Балансирование (), не нужно" << endl;
     if (sc3>sc4)
     cout <<"Необходимо добавить" << sc3-sc4 <<" ) " << endl;
     if (sc4>sc3)
     cout <<"Необходимо добавить" << sc4-sc3 <<" ( " << endl;

     if (sc5==sc6)
     cout  <<"Балансирование [], не нужно" << endl;
     if (sc5>sc6)
     cout <<"Необходимо добавить" << sc5-sc6 <<" ] " << endl;
     if (sc6>sc5)
     cout <<"Необходимо добавить" << sc6-sc5 <<" [ " << endl;


  }
  fin.close();
 return 0;
}

