#include "check.h"

int CheckA(char * string, int j) {
 int ind = 1;
 for (int i = 0; i < (j-2)/2; i++) { 
  if (string[i] != string[j - i - 1]) {
   ind = 0;
   break;
  }
 }
return ind;
}

void Check() {

 setlocale(LC_ALL, "ru");

 string path = "myfyle.txt";

 ofstream fout;

 fout.open(path, ofstream::app);

 if (!fout.is_open()) {
   cout << "Ошибка открытия файла!" << endl;
  } else {
   fout << "\n";
  }

 fout.close();

 fout.is_open();

 ifstream fin;
  
 fin.open(path);

 if (!fin.is_open()) {
  cout << "Ошибка открытия файла!" << endl;
 } else {
  cout << "Файл открыт!" << endl;
  string str;
  char psc1[200];
  int sc1 = 0, sc2 = 0, sc3 = 0, sc4 = 0, sc5 = 0, sc6 = 0, j = 0;
  while (!fin.eof()) {
   str = "";
   getline(fin, str);
   cout << str << endl;
  for (long unsigned int i = 0; i < str.length(); i++) {
   if (str[i] == '{') {
    sc1++;
    psc1[j] = '{';
    cout << j <<endl;
    j++;
   }
   if (str[i] == '}' && sc1) {
    sc2++;
    psc1[j] = '{';
    cout << j <<endl;
    j++;
   }
   if (str[i] == '(') {
    sc3++;
    psc1[j] = '(';
    cout << j <<endl;
    j++;
   }
   if (str[i] == ')') {
    sc4++;
    psc1[j] = '(';
    cout << j <<endl;
    j++;
   }
   if (str[i] == '[') {
    sc5++;
    psc1[j] = '[';
    cout << j <<endl;
    j++;
   }
   if (str[i] == ']') {
    sc6++;
    psc1[j] = '[';
    cout << j <<endl;
    j++;
   }
  }
 }
 cout << "KZKZKZK" <<endl;
 for (int m = 0; m < j; m++) {
  cout << psc1[m] <<endl;
 }
 if (CheckA(psc1, j) == 1) {
  if (sc1 == sc2)
   cout << "Балансирование {}, не нужно" << endl;
  if (sc1 > sc2)
   cout << "Необходимо добавить " << sc1 - sc2 << " } " << endl;
  if (sc2 > sc1)
   cout << "Необходимо добавить " << sc2 - sc1 << " { " << endl;
  if (sc3 == sc4)
   cout << "Балансирование (), не нужно" << endl;
  if (sc3 > sc4)
   cout << "Необходимо добавить " << sc3 - sc4 << " ) " << endl;
  if (sc4 > sc3)
   cout << "Необходимо добавить " << sc4 - sc3 << " ( " << endl;
  if (sc5 == sc6)
   cout << "Балансирование [], не нужно" << endl;
  if (sc5 > sc6)
   cout << "Необходимо добавить " << sc5 - sc6 << " ] " << endl;
  if (sc6 > sc5)
   cout << "Необходимо добавить " << sc6 - sc5 << " [ " << endl;
  } else {
   cout << "Несбалансированны скобки (перепутаны местами)" << endl;
  }  
 }
fin.close();
}
