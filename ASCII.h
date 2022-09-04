#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*void ASCII_Converter(string letter)
{
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        cout << int(x) << endl;
    }
}*/
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

        cout << "\tString is converted into ASCII: " << endl;

        cout << "\n\t\t";
        for (int j = 0; j < count; j++)
        {
            cout << array[j] << " ";
        }
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
        cout << "\tASCII Value in binary file is : " << endl;

        cout << "\n\t\t";
        for (int i = 0; i < count; i++)
        {
            file.read((char*)&array[i], sizeof(array));
            cout << array[i] << " ";
        }
        cout << endl;
    }
    //precon: take data from binary file
    //postcon: display data in ascii
    void ascii_menu()
    {
        ASCII obj;
        string choice;
        bool keepRunning = true;
        do {

            cout << "\n\tCMPR131 - Chapter 1 Software Development Arturo Sanchez (2/19/2022)";
            cout << "\n\t" + string(100, char(205));
            cout << "\n\t\tA> Enter a text string";
            cout << "\n\t\tB> Convert the text string to ASCII numbers";
            cout << "\n\t\tC> Save the Converted ASCII numbers into a binaryy file";
            cout << "\n\t\tD> Read the binary file";
            cout << "\n\t" + string(100, char(196));
            cout << "\n\t\t0> Exit";
            cout << "\n\t" + string(100, char(205));
            cout << "\n";

            cout << "Option: ";
            cin >> choice;

            //Checks if users input is 0
            //Clears the screen, sets keepRunning to false, to end the do/while loop and returns to the mainmenu() function
            if (choice == "0")
            {
                system("cls");
                keepRunning = false;
            }
            //Checks if users input is A
            //Asks for user input for inputText
            else if (choice == "A" || choice == "a")
            {
                obj.getString();
            }
            else if (choice == "B" || choice == "b")
            {
                obj.StringConverter();
            }
            else if (choice == "C" || choice == "c")
            {
                ofstream outputFile;
                outputFile.open("student.dat", ios::out | ios::binary);
                obj.binaryFile(outputFile);
                outputFile.close();
            }
            else if (choice == "D" || choice == "d")
            {
                ifstream inputFile;
                inputFile.open("student.dat", ios::out | ios::binary);
                obj.readData(inputFile);
                inputFile.close();
            }
            else
            {
                cout << "Please enter a proper variable" << endl;
            }
        } while (keepRunning == true);
    }
};