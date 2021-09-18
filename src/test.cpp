#include "check.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
char test[30] = "[]{}[]{}([{}])";
char test1[30] = "[{]{}[]{}([{}])";
char test2[30] = "[{]{}[]{}}([{}])";
char test3[30] = "[{]}[]{}([{}])";
char test4[30] = "[}{}[]{}([{}])";
if (CheckA(test, 14) == 1) {
 cout << "SUCCSES!" << endl;
} else {
 cout << "ERROR!" << endl;
}
if (CheckA(test1, 15) == 0) {
 cout << "SUCCSES!" << endl;
} else {
 cout << "ERROR!" << endl;
}
if (CheckA(test2, 16) == 0) {
 cout << "SUCCSES!" << endl;
} else {
 cout << "ERROR!" << endl;
}
if (CheckA(test3, 14) == 0) {
 cout << "SUCCSES!" << endl;
} else {
 cout << "ERROR!" << endl;
}
if (CheckA(test4, 14) == 0) {
 cout << "SUCCSES!" << endl;
} else {
 cout << "ERROR!" << endl;
}
return 0;
}
