#include "check.h"

int CheckA(char * string, int j) {
int result = 1;
 for (int i = 0; i < j; i++) {
  if (string[i] == '{' && string[i + 1] == '}') {
   string[i] = '0';
   string[i + 1] = '0';
   i++;
  }
  if (string[i] == '(' && string[i + 1] == ')') {
   string[i] = '0';
   string[i + 1] = '0';
   i++;
  }
  if (string[i] == '[' && string[i + 1] == ']') {
   string[i] = '0';
   string[i + 1] = '0';
   i++;
  }
  }
  char ind = 0;
  for (int i = 0; i < j; i++) {
   if (string[i] == '{' && string[i + 1] == '0') {
   string[i] = '0';
   ind = '}';
  } else if (string[i] == '[' && string[i + 1] == '0') {
   string[i] = '0';
   ind = ']';
  } else if (string[i] == '(' && string[i + 1] == '0') {
   string[i] = '0';
   ind = ')';
  } else if (string[i] == '0' && string[i + 1] == '0') {
   ;
  } else if (string[i] == '0' && string[i + 1] == ind) {
   string[i + 1] = '0';
   i = 0;
  } else if (string[i] == '[' && string[i + 1] == '[') {
   ind = ']';
  } else if (string[i] == '[' && string[i + 1] == '{') {
   ind = ']';
  } else if (string[i] == '[' && string[i + 1] == '(') {
   ind = ']';
  } else if (string[i] == '(' && string[i + 1] == '(') {
   ind = ')';
  } else if (string[i] == '(' && string[i + 1] == '{') {
   ind = ')';
  } else if (string[i] == '(' && string[i + 1] == '[') {
   ind = ')';
  } else if (string[i] == '{' && string[i + 1] == '(') {
   ind = '}';
  } else if (string[i] == '{' && string[i + 1] == '[') {
   ind = '}';
  } else if (string[i] == '{' && string[i + 1] == '{') {
   ind = '}';
  } else if (string[i] == '0' && string[i + 1] == '{') {
   ;
  } else if (string[i] == '0' && string[i + 1] == '[') {
   ;
  } else if (string[i] == '0' && string[i + 1] == '(') {
   ;
  } else {
   cout << "No balance!" << endl;
   result = 0;
   break;
  }
  int z = 0;
  for (int i = 0; i < j; i++) {
  if (string[i] != '0') {
  z = 1;
  break;
  } else {
  z = 2;
  }
  }
  if (z == 2) {
   cout << "All right!" << endl;
   result = 1;
   break;
  }
  }
return result;
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
  for (long unsigned int i = 0; i < str.length(); i++) {
   if (str[i] == '{') {
    sc1++;
    psc1[j] = '{';
    j++;
   }
   if (str[i] == '}' && sc1) {
    sc2++;
    psc1[j] = '}';
    j++;
   }
   if (str[i] == '(') {
    sc3++;
    psc1[j] = '(';
    j++;
   }
   if (str[i] == ')') {
    sc4++;
    psc1[j] = ')';
    j++;
   }
   if (str[i] == '[') {
    sc5++;
    psc1[j] = '[';
    j++;
   }
   if (str[i] == ']') {
    sc6++;
    psc1[j] = ']';
    j++;
   }
  }
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
