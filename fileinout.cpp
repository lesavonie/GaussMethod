#include "fileinout.h"


vector<double> CFileInOut::get_A()
{
	return A;
}

vector<double> CFileInOut::get_b()
{
	return b;
}

int CFileInOut::read_A_b_fromFiles(string file_A, string file_b)
{
	fileExists_A = false;
	fileExists_b = false;
	goodData_x = false;
	fileName_A = file_A;
	fileName_b = file_b;
	fstream fIn_A, fIn_b;
	fIn_A.open(fileName_A.c_str(), std::ios::in);
	if (!fIn_A.is_open())
	{
		cout << "Error while opening the file '" << fileName_A << "'" << endl;
		return 1;
	}
	double t;
	A.clear();
	while (fIn_A >> t)
		A.push_back(t);
	fIn_A.close();
	fileExists_A = true;
	if (A.empty())
	{
		cout << "The file '" << fileName_A << "' is empty" << endl;
		return 2;
	}

	fIn_b.open(fileName_b.c_str(), std::ios::in); //преобразование string в const char*
	if (!fIn_b.is_open())
	{
		cout << "Error while opening the file '" << fileName_b << "'" << endl;
		return 3;
	}
	b.clear();
	while (fIn_b >> t)
		b.push_back(t);
	fIn_b.close();
	fileExists_b = true;
	if (!b.size())
	{
		cout << "The file '" << fileName_b << "' is empty" << endl;
		return 4;
	}

	return 0;
}

bool::CFileInOut::print_x_toFile(vector<double> x, string file_x)
{
	goodData_x = false;
	fileName_x = file_x;
	if (x.empty())
	{
		cout << "x is empty" << endl;
		return goodData_x;
	}
	fstream fOut_x;
	fOut_x.open(fileName_x.c_str(), std::ios_base::out);
	if (!fOut_x.is_open())
	{
		cout << "The file '" << fileName_x << "' isn't open for writing to" << endl;
		return goodData_x;
	}
	for (size_t i = 0; i < x.size(); i++)
	{
		fOut_x << std::fixed << std::setprecision(2) << x[i] << " ";
	}
	fOut_x.close();
	goodData_x = true;
	return goodData_x;
}
