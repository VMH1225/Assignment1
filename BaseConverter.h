#include <iostream>

using namespace std;
class baseConv {
private:

public:
	void menu2()
	{
		cout << "\t\t2> Base Converter\n" << "\t\t" + string(100, char(205)) << endl
			<< "\t\t\tA> Enter an integer number (base 10)\n" << "\t\t\tB> Speccify and converting base\n"
			<< "\t\t\tC> Display all converted bases (2... 36)\n"
			<< "\t\t" + string(100, char(196)) << endl << "\t\t\t0> return\n" << "\t\t" + string(100, char(205)) + '\n';
	}

	char AlfaCase(int remain)
	{
		switch (remain)
		{
		case 10:return 'A'; break;
		case 11:return 'B'; break;
		case 12:return 'C'; break;
		case 13:return 'D'; break;
		case 14:return 'E'; break;
		case 15:return 'F'; break;
		case 16:return 'G'; break;
		case 17:return 'H'; break;
		case 18:return 'I'; break;
		case 19:return 'J'; break;
		case 20:return 'K'; break;
		case 21:return 'L'; break;
		case 22:return 'M'; break;
		case 23:return 'N'; break;
		case 24:return 'O'; break;
		case 25:return 'P'; break;
		case 26:return 'Q'; break;
		case 27:return 'R'; break;
		case 28:return 'S'; break;
		case 29:return 'T'; break;
		case 30:return 'U'; break;
		case 31:return 'V'; break;
		case 32:return 'W'; break;
		case 33:return 'X'; break;
		case 34:return 'Y'; break;
		case 35:return 'Z'; break;
		default: break;
		}
	}

	void convertorWrite(int current_val, int base)
	{
		int	remain = current_val % base;
		current_val = (current_val - remain) / base;
		if (current_val == 0)
		{
			if (remain > 9)
			{
				char val = AlfaCase(remain);
				cout << val;
				return;
			}
			else
			{
				cout << remain;
				return;
			}
		}
		convertorWrite(current_val, base);
		if (remain > 9)
		{
			char val = AlfaCase(remain);
			cout << val;
			return;
		}
		cout << remain;
		return;
	}

	void specification(int i)
	{
		if (i == 2)
		{
			cout << " - binary ";
		}
		else if (i == 8)
		{
			cout << " - octal ";
		}
		else if (i == 16)
		{
			cout << " - hex ";
		}
	}

	void set2()
	{
		char option;
		int input = NULL;
		do
		{
			menu2();
			option = inputChar("\t\tOption: ");
			switch (option)
			{
			case 'a':
			case 'A': input = inputInteger("\t\t\tEnter an integer number of base 10: ", true); break;
			case 'b':
			case 'B':
			{
				int base = inputInteger("\t\t\tPlease enter the base (2...36) to convert: ", 2, 36);
				cout << "\n\t\t\t";
				cout << input << "(base of 10) = ";
				convertorWrite(input, base);
				cout << "(base of " << base;
				specification(base);
				cout << ")\n";
				break;
			}
			case 'c':
			case 'C':
				cout << "\t\t\t" << input << "(base of 10) =\n";
				for (int i = 2; i <= 36; i++)
				{
					cout << "\t\t\t\t";
					convertorWrite(input, i);
					cout << " (base of " << i;
					specification(i);
					cout << ")\n";
				}
				break;
			case 48: //for input 0
				system("cls");
				return;
			default:
				cout << "Please enter an avaliable option\n";
				cout << "Press any Key to continue\n";
				system("pause");
				break;
			}
		} while (true);
	}
};