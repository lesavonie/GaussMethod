#include <iostream>
#include <string>
#include "gaussMethod.h"
#include "fileinout.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	size_t size;
	cout << "Input matrix and vector size (5 or 6)" << endl;
	cin >> size;
	CFileInOut fio;
	CGaussMethod gauss;
	int goodRead;
	string fileOut_x;
	gauss.n = size;
	if (size == 5)
	{
		string fileIn_A_5x5("matrix_A_5x5.txt"), fileIn_b_5("vector_b_5.txt");
		fileOut_x = "vector_x_5.txt";
		goodRead = fio.read_A_b_fromFiles(fileIn_A_5x5, fileIn_b_5);
	}
	else if (size == 6)
	{
		string fileIn_A_6x6("matrix_A_6x6.txt"), fileIn_b_6("vector_b_6.txt");
		fileOut_x = "vector_x_6.txt";
		goodRead = fio.read_A_b_fromFiles(fileIn_A_6x6, fileIn_b_6);
	}
	else
	{
		cout << "error, you should input only 5 or 6" << endl;
		return 8;
	}
	if (goodRead)
	{
		cout << "Error #" << goodRead << endl;
		return goodRead;
	}
	bool goodSet = gauss.set_A_b(fio.get_A(), fio.get_b());
	if (!goodSet)
	{
		cout << "Error in set M ot v" << endl;
		return 5;
	}
	bool goodFind_x = gauss.find_x();
	bool goodPrint_x = fio.print_x_toFile(gauss.get_x(), fileOut_x);
	if (!goodFind_x)
	{
		cout << "Error in calculation of x" << endl;
		return 6;
	}
	else if (!goodPrint_x)
	{
		cout << "Error while printing x into the file" << endl;
		return 7;
	}
	else
		return 0;
	cin.get();
	return 0;
}}
