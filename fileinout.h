#ifndef FILE_IN_OUT_
#define FILE_IN_OUT_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::fstream;

class CFileInOut
{
private:
	bool fileExists_A, fileExists_b, goodData_x;
	string fileName_A, fileName_b, fileName_x;
	vector<double> A;
	vector<double> b;
public:
	CFileInOut() : fileExists_A(false), fileExists_b(false), goodData_x(false),
		fileName_A("no file for A"), fileName_b("no file for b"), fileName_x("no file for x")
	{}
	vector<double> get_A();
	vector<double> get_b();
	int read_A_b_fromFiles(string file_A, string file_b);
	bool print_x_toFile(vector<double> x, string file_x);
};

#endif 
