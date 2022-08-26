// Name: Victor Huerta
// Date: March 9, 2022
// Project: Chapter 3 -Assignments

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include "input.h"
using namespace std;
int menuOption();
int menuOption2();
void Challenge1();
void Challenge3();
int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;

        case 1: Challenge1(); break;
            //case 2: Challenge2(); break;

        case 3: Challenge3(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

    return EXIT_SUCCESS;
}


int menuOption()
{
    system("cls");
    cout << "\n\tCMPR131 - Chapter 1 Software Development by Victor Huerta (2/19/2022)";
    cout << "\n\t" + string(100, char(205));
    cout << "\n\t\t1> ASCII Text To ASCII Numbers";
    cout << "\n\t\t2> Base Converter";
    cout << "\n\t\t3> Descriptive Statistics";
    cout << "\n\t" + string(100, char(196));
    cout << "\n\t\t0> Exit";
    cout << "\n\t" + string(100, char(205));
    cout << "\n";

    int option = inputInteger("\t\t  Option: ", 0, 3);
    system("cls");
    return option;
}

int minNumber(int*, int);
int maxNumber(int*, int);
int range(int* numberArr, int size);
int size(int* numberArr, int size);
int sum(int* numberArr, int size);
double findMean(int*, int);
double findMedian(int* numberArr, int size);
int standardDeviation(int* numberArr, int size);
double variance(int* numberArr, int size);
int midRange(int*, int);
int* arrayNumbers(int&);
double sumOfSquares(int* numberArr, int size);
void Challenge3()
{
    int* arr = nullptr;
    int arrSize = 0;
    do
    {
        switch (menuOption2())
        {
        case '0': { delete[] arr; arr = nullptr; exit(1); break; }
        case 'A':
        case 'a': {
            arr = arrayNumbers(arrSize);
            break;
        }
        case 'B':
        case 'b':
        {
            minNumber(arr, arrSize);
            break;
        }
        case 'C':
        case 'c': maxNumber(arr, arrSize); break;
        case 'D':
        case 'd': range(arr, arrSize); break;
        case 'e':
        case 'E': size(arr, arrSize); break;
        case 'F':
        case 'f': sum(arr, arrSize); break;
        case 'G':
        case 'g': findMean(arr, arrSize); break;
        case 'H':
        case 'h': findMedian(arr, arrSize); break;
        case 'K':
        case 'k': standardDeviation(arr, arrSize); break;
        case 'L':
        case 'l': variance(arr, arrSize); break;
        case 'M':
        case 'm': midRange(arr, arrSize); break;
        case 'Q':
        case 'q': sumOfSquares(arr, arrSize); break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

}

int menuOption2()
{
    system("cls");
    cout << "\n\t3> Descriptive Statistics";
    cout << "\n\t" + string(100, char(205));
    cout << "\n\t\tA> Read data file, store into a sorted dynamic array and display the data set";
    cout << "\n\t\tB> Minimum                     M> Mid Range";
    cout << "\n\t\tC> Maximum                     N> Quartiles";
    cout << "\n\t\tD> Range                       O> Interquartile Range";
    cout << "\n\t\tE> Size                        P> Outliers";
    cout << "\n\t\tF> Sum                         Q> Sum of Squares";
    cout << "\n\t\tG> Mean                        R> Mean Absolute Deviation";
    cout << "\n\t\tH> Median                      S> Root Mean Square";
    cout << "\n\t\tI> Frequencies                 T> Standard Error of the Mean";
    cout << "\n\t\tJ> Mode                        U> Coefficient of Variation";
    cout << "\n\t\tK> Standard Deviation          V> Relative Standard Deviation";
    cout << "\n\t\tL> Variance";
    cout << "\n\t\tW> Display all resultsand write to an output text file";
    cout << "\n\t" + string(100, char(196));
    cout << "\n\t\t0> Exit";
    cout << "\n\t" + string(100, char(205));
    cout << "\n";

    char option = inputChar("\t\t  Option: ");
    system("cls");
    return option;
}

int* arrayNumbers(int& size)
{
    int number;
    string fileName;
    int totalNumbers = 0;
    string line;

    cout << "Enter the name of a text file to read from: ";
    cin >> fileName;

    ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
            ++totalNumbers;
    }
    else
        cout << "ERROR opening the file.";
    myfile.close();
    size = totalNumbers;

    int* numbers;
    numbers = new int[totalNumbers];
    int count = 0;


    myfile.open(fileName);
    if (myfile.is_open())
    {
        cout << "Data set: " << endl;
        while (myfile >> number)
        {
            cout << number << "\n";
            numbers[count] = number;
            count++;
        }
        myfile.close();
    }
    else
        cout << "\nError opening the file.\n";

    return numbers;
}
int minNumber(int* numberArr, int size)
{
    int min;
    if (numberArr == nullptr)
    {
        cout << "Error: Data set is empty";
        return 0;
    }
    else
    {
        min = numberArr[0];
        for (int i = 0; i < size; i++) {
            if (numberArr[i] < min) {
                min = numberArr[i];
            }
        }
    }
    cout << "\nMinimum = " << min << endl;
    return min;
}

int maxNumber(int* numberArr, int size)
{
    int max;
    if (numberArr == nullptr)
    {
        cout << "Error: Data set is empty";
        return 0;
    }
    else
    {
        max = numberArr[0];
        for (int i = 0; i < size; i++) {
            if (numberArr[i] > max) {
                max = numberArr[i];
            }
        }
    }
    cout << "\nMaximum = " << max << endl;
    return max;
}

int midRange(int* numberArr, int size)
{
    int mRange = 0;
    if (numberArr == nullptr)
    {
        cout << "Error: Data set is empty";
        return 0;
    }
    else
    {
        mRange = ((maxNumber(numberArr, size) + minNumber(numberArr, size)) / 2);
        cout << "\nMid Range = " << mRange << endl;
        return mRange;
    }
}

double findMean(int* numberArr, int size)
{
    int sum = 0;
    if (numberArr == nullptr)
    {
        cout << "Error: Data set is empty";
        return 0;
    }
    else
    {
        for (int i = 0; i < size; i++)
            sum += numberArr[i];

        double mean = (double)sum / (double)size;
        cout << "Mean = " << mean << endl;
        return mean;
    }
}

double findMedian(int* numberArr, int size)
{
    if (numberArr == nullptr)
    {
        cout << "Error: Data set is empty";
        return 0;
    }
    else
    {
        sort(numberArr, numberArr + size);

        if (size % 2 != 0)
        {
            cout << "Median = " << (double)numberArr[size / 2] << endl;
            return (double)numberArr[size / 2];
        }
        else
        {
            int midValue = size / 2;
            cout << "Median = " << ((numberArr[midValue - 1] + numberArr[midValue]) / 2.0) << endl;
            return ((numberArr[midValue - 1] + numberArr[midValue]) / 2.0);
        }
    }
}

double sumOfSquares(int* numberArr, int size)
{
    double sumSquares = 0;
    double difference = 0;
    if (numberArr == nullptr)
    {
        cout << "Error: Data set is empty";
        return 0;
    }
    else
    {
        double mean = findMean(numberArr, size);
        for (int i = 0; i < size; i++)
        {
            difference = numberArr[i] - mean;

            sumSquares += (difference * difference);
        }
        cout << "Sum of Squares = " << sumSquares << endl;
        return sumSquares;
    }

}

double variance(int* numberArr, int size)
{
    double sumSquares = 0;
    double difference = 0;
    double variance = 0;
    if (numberArr == nullptr)
    {
        cout << "Error: Data set is empty";
        return 0;
    }
    else
    {
        double mean = findMean(numberArr, size);
        for (int i = 0; i < size; i++)
        {
            difference = numberArr[i] - mean;

            sumSquares += (difference * difference);
        }
    }
    variance = (sumSquares / (size - 1));
    cout << "Variance = " << variance << endl;
    return variance;
}

int sum(int* numberArr, int size)
{
    double total = 0;
    if (numberArr == nullptr)
    {
        cout << "Error: Data set is empty";
        return 0;
    }
    else
    {

        for (int i = 0; i < size; i++)
        {
            total += numberArr[i];
        }
        cout << "Total = " << total << endl;
        return total;
    }
}

int range(int* numberArr, int size)
{
    if (numberArr == nullptr)
    {
        cout << "Error: Data set is empty";
        return 0;
    }
    else
    {
        sort(numberArr, numberArr + size);
        cout << "Range = " << (numberArr[size - 1] - numberArr[0]);
        return (numberArr[size - 1] - numberArr[0]);
    }
}

int size(int* numberArr, int size)
{
    if (numberArr == nullptr)
    {
        cout << "Error: Data set is empty";
        return 0;
    }
    else
    {
        cout << "Size = " << size << endl;
        return size;
    }
}

int standardDeviation(int* numberArr, int size)
{
    if (numberArr == nullptr)
    {
        cout << "Error: Data set is empty";
        return 0;
    }
    else
    {
        double varianceNum = variance(numberArr, size);
        double stndrdDev = sqrt(varianceNum);

        cout << "\nStandard Deviation = " << stndrdDev << endl;
        return stndrdDev;
    }
}


using namespace std;
//Huy Ta 9/7/2021
class ASCII {
private:
    string inputText;
    int* array; // pointer for dynamic array
    int count;
    //precon: set modifier
    //postcon: modifier will change base on user input
public:
    ASCII() //constructor
    {
        count = 0;
    }
    //precon: set value into 0
    //postcon: value is postive
    void StringConverter() //convert string into ascii
    {
        for (int i = 0; i < inputText.length(); i++)
            array[count++] = int(inputText[i]);

        cout << "\tString is converted into ASCII:" << endl;


        for (int j = 0; j < count; j++)
            cout << array[j];
        cout << endl;
    }
    //precon: read string
    //postcon: convert into ascii

    void getString() //get string from user
    {
        cout << "\tPlease Enter A Text : ";
        cin.ignore();
        getline(cin, inputText);

        int number = inputText.length();
        array = new int[number]; // create a dynamic array of integer of size length of string
    }
    //precon: get string
    //postcon: save string as a number value






    void binaryFile(ofstream& file)  //binary function
    {
        for (int i = 0; i < count; i++)
            file.write(reinterpret_cast<const char*>(&array[i]), sizeof(int));

        cout << "\tSave value into Binary File: Complete" << endl;
    }
    //precon: take ascii 
    //postcon: store ascii value


    void readData(ifstream& file) //read binary 
    {
        int inputArray;
        cout << "\tASCII Value in binary file is : ";
        for (int i = 0; i < count; i++)
        {
            file.read((char*)&array[i], sizeof(array));
            cout << array[i];
        }
        cout << endl;
    }
    //precon: take data from binary file
    //postcon: display data in ascii
};


void Challenge1()
{

    ASCII obj;

    char menuOption;
    while (1) {
        cout << "1/ ASCII Text To ASCII Numbers" << endl;
        cout << ".........................................................." << endl;
        cout << "\tA/ Enter a text String" << endl;
        cout << "\tB/ Convert the text string to ASCII numbers" << endl;
        cout << "\tC/ Save the converted ASCII numbers into a binary file" << endl;
        cout << "\tD/ Read the binary file" << endl;

        cout << "\t0/ Return/Exit " << endl;
        cout << ".........................................................." << endl;
        cout << "\tOption: ";
        cin >> menuOption;

        fflush(stdin);

        cout << endl;

        switch (menuOption)
        {
        case 65: //ascii for A
            obj.getString();
            break;
        case 66: //ascii for B
            obj.StringConverter();
            break;
        case 67: //ascii for C

        {
            ofstream outputFile;
            outputFile.open("student.dat", ios::out | ios::binary);
            obj.binaryFile(outputFile);
            outputFile.close();
        }
        break;
        case 68: //ascii for D
        {
            ifstream inputFile;
            inputFile.open("student.dat", ios::out | ios::binary);
            obj.readData(inputFile);
            inputFile.close();
        }
        break;
        case 48: //ascii for 0
            exit(1);
        default:
            cout << "ERROR: Invalid Entries" << endl;
        }

        cout << endl;
        system("PAUSE");
        system("CLS");
    }


}