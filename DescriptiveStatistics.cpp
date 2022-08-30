#include <iostream>
#include <DescriptiveStatistics.h>

void chooseOption()
{
    int* arr = nullptr;
    int arrSize = 0;
    do
    {
        switch (menu())
        {
        case '0': { delete[] arr; arr = nullptr; exit(1); break; }
        case 'A':
        case 'a': { 
            break;
        }
        case 'B':
        case 'b':
        {   
            break;
        }
        case 'C':
        case 'c': cout << "hi" << endl; break;
        case 'D':
        case 'd': cout << "hi" << endl;break;
        case 'e':
        case 'E': cout << "hi" << endl;break;
        case 'F':
        case 'f': cout << "hi" << endl;break;
        case 'G':
        case 'g': cout << "hi" << endl;break;
        case 'H':
        case 'h': cout << "hi" << endl;break;
        case 'K':
        case 'k': cout << "hi" << endl;break;
        case 'L':
        case 'l': cout << "hi" << endl;break;
        case 'M':
        case 'm': cout << "hi" << endl;break;
        case 'Q':
        case 'q': cout << "hi" << endl;break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

}

int menu()
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