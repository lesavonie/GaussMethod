#include "gaussMethod.h"

bool CGaussMethod::set_A_b(vector<double> A, vector<double> b)
{
	goodData = false;
	if (A.size() != n * n || b.size() != n)
	{
		cout << "Input vector sizes are incorrect" << endl;
		return goodData;
	}
	M.clear();
	v.clear();
	M.resize(n);
	v.resize(n);
	for (size_t i = 0; i < n; i++)
	{
		v[i] = b[i];
		M[i].resize(n);
		for (size_t j = 0; j < n; j++)
			M[i][j] = A[i * n + j];
	}
	goodData = true;
	return goodData;
}

vector<double> CGaussMethod::get_x()
{
	return x;
}

bool CGaussMethod::find_x()
{
	x.clear();
	x.resize(n);
	if (M.size() != n || v.size() != n)
	{
		goodData = false;
		cout << "M or v sizes are incorrect" << endl;
		return goodData;
	}
	for (size_t i = 0; i < n; i++)
		if (M[i].size() != n)
		{
			goodData = false;
			cout << "In M[" << i + 1 << "] error in size" << endl;
			return goodData;
		}
	double sum = 0, max = 0;
	size_t maxIndex = 0, k = 0;
	const double eps = DBL_EPSILON; //the precision
	while (k < n)
	{
		//searching for max element in column
		max = ::fabs(M[k][k]);
		maxIndex = k;
		for (size_t i = k + 1; i < n; i++)
		{
			if (::fabs(M[i][k]) > max)
			{
				max = ::fabs(M[i][k]);
				maxIndex = i;
			}
		}
		if (max < 0)
		{
			cout << "error because of zero column" << endl;
			break;
		}
		//swap max row with current row
		double tmp_v = v[k];
		v[k] = v[maxIndex];
		v[maxIndex] = tmp_v;
		for (size_t j = 0; j < n; j++)
		{
			double tmp_M = M[k][j];
			M[k][j] = M[maxIndex][j];
			M[maxIndex][j] = tmp_M;
		}
		//forward elimination
		for (size_t i = k; i < n; i++)
		{
			double d = M[i][k];
			if (::fabs(d) < eps) continue; //skip if element is zero
			for (size_t j = 0; j < n; j++)
				M[i][j] = M[i][j] / d;
			v[i] = v[i] / d;
			if (i == k) continue; //don't subtract an equation from itself
			for (size_t j = 0; j < n; j++)
				M[i][j] = M[k][j] - M[i][j];
			v[i] = v[k] - v[i];
		}
		k++;
	}
	//back substitution
	for (size_t k = n - 1; k > 0; k--)
	{
		x[k] = v[k];
		for (size_t j = 0; j < k; j++)
			v[j] = v[j] - M[j][k] * x[k];
	}
	x[0] = v[0];
	return goodData;
}
