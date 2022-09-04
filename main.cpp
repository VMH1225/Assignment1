// Name: Victor Huerta
// August 27, 2022
// Project: Chapter 3 -Assignments

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include "input.h"
#include "ASCII.h"
#include "DescriptiveStatistics.h"
#include "BaseConverter.h"

using namespace std;
int menuOption();

void challenge1();
void challenge2();
void challenge3();



int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;

        case 1: challenge1(); break; 
        case 2: challenge2(); break;     
        case 3: challenge3(); break;
        default: cout << "\t\terror - invalid option. please re-enter."; break;
        }
        cout << "\n";
   
    } while (true);

    return 0;
}

int menuOption()
{
    system("cls");
    cout << "\n\tcmpr131 - chapter 1 software development by victor huerta (2/19/2022)";
    cout << "\n\t" + string(100, char(205));
    cout << "\n\t\t1> ascii text to ascii numbers";
    cout << "\n\t\t2> base converter";
    cout << "\n\t\t3> descriptive statistics";
    cout << "\n\t" + string(100, char(196));
    cout << "\n\t\t0> exit";
    cout << "\n\t" + string(100, char(205));
    cout << "\n";

    int option = inputInteger("\t\t  option: ", 0, 3);
    system("cls");
    return option;
}
void challenge1() {
    ASCII obj;
    system("cls");
    obj.ascii_menu();
}
void challenge2(){
    baseConv obj;
    system("cls");
    obj.set2();
}
void challenge3() {
    DescriptiveStatistics data1;
    data1.chooseOption();
}
