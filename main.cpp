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
#include "input.h"
#include "DescriptiveStatistics.h"
using namespace std;
int menuOption();
//int menuOption2();
//void Challenge1();
//void Challenge3();
void Challenge4();


int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;

        case 1: /*challenge1()*/; break;
            //case 2: challenge2(); break;     
        case 3: Challenge4(); break;
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

void Challenge4() {
    cout << "hi" << endl;
    DescriptiveStatistics data1;
    data1.chooseOption();

}

//
//using namespace std;
////Huy Ta 9/7/2021
//class ASCII {
//private:
//    string inputText;
//    int* array; // pointer for dynamic array
//    int count;
//    //precon: set modifier
//    //postcon: modifier will change base on user input
//public:
//    ASCII() //constructor
//    {
//        count = 0;
//    }
//    //precon: set value into 0
//    //postcon: value is postive
//    void StringConverter() //convert string into ascii
//    {
//        for (int i = 0; i < inputText.length(); i++)
//            array[count++] = int(inputText[i]);
//
//        cout << "\tString is converted into ASCII:" << endl;
//
//
//        for (int j = 0; j < count; j++)
//            cout << array[j];
//        cout << endl;
//    }
//    //precon: read string
//    //postcon: convert into ascii
//
//    void getString() //get string from user
//    {
//        cout << "\tPlease Enter A Text : ";
//        cin.ignore();
//        getline(cin, inputText);
//
//        int number = inputText.length();
//        array = new int[number]; // create a dynamic array of integer of size length of string
//    }
//    //precon: get string
//    //postcon: save string as a number value
//
//
//
//
//
//
//    void binaryFile(ofstream& file)  //binary function
//    {
//        for (int i = 0; i < count; i++)
//            file.write(reinterpret_cast<const char*>(&array[i]), sizeof(int));
//
//        cout << "\tSave value into Binary File: Complete" << endl;
//    }
//    //precon: take ascii 
//    //postcon: store ascii value
//
//
//    void readData(ifstream& file) //read binary 
//    {
//        int inputArray = 0;
//        cout << "\tASCII Value in binary file is : ";
//        for (int i = 0; i < count; i++)
//        {
//            file.read((char*)&array[i], sizeof(array));
//            cout << array[i];
//        }
//        cout << endl;
//    }
//    //precon: take data from binary file
//    //postcon: display data in ascii
//};
//
//
//void Challenge1()
//{
//
//    ASCII obj;
//
//    char menuOption;
//    while (1) {
//        cout << "1/ ASCII Text To ASCII Numbers" << endl;
//        cout << ".........................................................." << endl;
//        cout << "\tA/ Enter a text String" << endl;
//        cout << "\tB/ Convert the text string to ASCII numbers" << endl;
//        cout << "\tC/ Save the converted ASCII numbers into a binary file" << endl;
//        cout << "\tD/ Read the binary file" << endl;
//
//        cout << "\t0/ Return/Exit " << endl;
//        cout << ".........................................................." << endl;
//        cout << "\tOption: ";
//        cin >> menuOption;
//
//        fflush(stdin);
//
//        cout << endl;
//
//        switch (menuOption)
//        {
//        case 65: //ascii for A
//            obj.getString();
//            break;
//        case 66: //ascii for B
//            obj.StringConverter();
//            break;
//        case 67: //ascii for C
//
//        {
//            ofstream outputFile;
//            outputFile.open("student.dat", ios::out | ios::binary);
//            obj.binaryFile(outputFile);
//            outputFile.close();
//        }
//        break;
//        case 68: //ascii for D
//        {
//            ifstream inputFile;
//            inputFile.open("student.dat", ios::out | ios::binary);
//            obj.readData(inputFile);
//            inputFile.close();
//        }
//        break;
//        case 48: //ascii for 0
//            exit(1);
//        default:
//            cout << "ERROR: Invalid Entries" << endl;
//        }
//
//        cout << endl;
//        system("PAUSE");
//        system("CLS");
//    }
//
//
//}