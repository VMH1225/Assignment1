
#include "DescriptiveStatistics.h"
#include "input.h"
#include <iostream>
#include <string>
#include <fstream>
#include <math.h> 

using namespace std;

int DescriptiveStatistics::menu()
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

    char option = inputChar("Enter a menu option: ");
    system("cls");
    return option;
}

void DescriptiveStatistics::chooseOption()
{
    arr = nullptr;
    arraySize = 0;
    bool flag = true;
    do
    {
        switch (menu())
        {
        case '0': { delete[] arr; arr = nullptr; flag = false;  break; }
        case 'A':
        case 'a': { 
            arr = arrayNumbers(arraySize);
            break;
        }
        case 'B':
        case 'b': minNumber(arr, arraySize); break;
        case 'C':
        case 'c': maxNumber(arr, arraySize); break;
        case 'D':
        case 'd': range(arr, arraySize); break;
        case 'E':
        case 'e': size(arr, arraySize); break;
        case 'F':
        case 'f': sum(arr, arraySize); break;
        case 'G':
        case 'g': findMean(arr, arraySize); break;
        case 'H':
        case 'h': findMedian(arr, arraySize); break;
        case 'K':
        case 'k': standardDeviation(arr, arraySize); break;
        case 'L':
        case 'l': variance(arr, arraySize); break;
        case 'M':
        case 'm': midRange(arr, arraySize); break;
        case 'Q':
        case 'q': sumOfSquares(arr, arraySize); break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter. "; break;
        }
        cout << "\n";
        system("pause");
    } while (flag);

}

int* DescriptiveStatistics::arrayNumbers(int& size)
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
        cout << "\nERROR opening the file.\n";

    return numbers;
}

int DescriptiveStatistics::minNumber(int* numberarr, int size)
{
    int min;
    if (numberarr == nullptr)
    {
        cout << "error: data set is empty";
        return 0;
    }
    else
    {
        min = numberarr[0];
        for (int i = 0; i < size; i++) {
            if (numberarr[i] < min) {
                min = numberarr[i];
            }
        }
    }
    cout << "\nminimum = " << min << endl;
    return min;
}

int DescriptiveStatistics::maxNumber(int* numberArr, int size)
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

int DescriptiveStatistics::range(int* numberArr, int size)
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

int DescriptiveStatistics::size(int* numberArr, int size)
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



int DescriptiveStatistics::sum(int* numberArr, int size)
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

double DescriptiveStatistics::findMean(int* numberArr, int size)
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

double DescriptiveStatistics::findMedian(int* numberArr, int size)
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
            cout << "Median = " << (double)numberArr[(size-1) / 2] << endl;
            return (double)numberArr[(size+1) / 2];
        }
        else
        {
            int midValue = size / 2;
            cout << "Median = " << ((numberArr[midValue - 1] + numberArr[midValue]) / 2.0) << endl;
            return ((numberArr[midValue + 1] + numberArr[midValue]) / 2.0);
        }
    }
}



double DescriptiveStatistics::standardDeviation(int* numberArr, int size)
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
double DescriptiveStatistics::variance(int* numberArr, int size)
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
int DescriptiveStatistics::midRange(int* numberArr, int size)
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

double DescriptiveStatistics::sumOfSquares(int* numberArr, int size)
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

//pre:  needs a pointer to an array(not empty); size (size!=0)
    //post: using function findMedian gets the quartile 1
double DescriptiveStatistics::getQuartile1(int* numberArr, int size)
{
    if (size < 4)
        return -1;      //cannot get

    if (size >= 7)
    {
        if (size % 2 == 0)      //if even
            return (numberArr[(size / 4)] + numberArr[(size / 4) - 1]) / 2;
        else                //if odd
        {
            int temp = size + 1;
            return numberArr[temp / 4];
        }
    }
    else if (size == 6)
        return numberArr[1];
    else if (size == 5)
        return (numberArr[0] + numberArr[1]) / 2;
    else
        return numberArr[0];
}
//pre:  needs a pointer to an array, and its size
//post: using function findMedian gets the quartile 2
double DescriptiveStatistics::getQuartile2(int* numberArr, int size)
{
    return findMedian(numberArr, size);
}
//pre:  needs a pointer to an array, and its size
// only use if sorted
//post: using function findMedian gets the quartile 3
double DescriptiveStatistics::getQuartile3(int* numberArr, int size)
{
    if (size < 4)
        return -1;      //cannot get

    if (size >= 7)
    {
        if (size % 2 == 0)      //if even
            return (numberArr[(size / 4) * 3] + numberArr[((size / 4) * 3) - 1]) / 2;
        else               //if odd
        {
            int temp = size + 1;
            return numberArr[(temp / 4) * 3];
        }
    }
    else if (size == 6)
        return numberArr[4];
    else if (size == 5)
        return (numberArr[3] + numberArr[4]) / 2;
    else
        return numberArr[3];
}