#ifndef _GAUSS_METHOD_
#define _GAUSS_METHOD_

#include <iostream>
#include <vector>
#include <cmath> 
#include <cfloat>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class CGaussMethod
{
private:
	bool goodData;
	vector<vector<double>> M;
	vector<double> v;
	vector<double> x;
public:
	size_t n;
	CGaussMethod(size_t n = 4) : goodData(false), n(n) {}
	bool set_A_b(vector<double> A, vector<double> b);
	bool find_x();
	vector<double> get_x();
};

#endif 

