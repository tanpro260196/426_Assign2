#include "pch.h"
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

double bl;
double bu;
double theta = 0.000000001;
double k = 0.618;
double fx(double);
int n = 0;
int main()
{
    cout << "Enter lower bound: ";
	cin >> bl;
	cout << "Enter upper bound: ";
	cin >> bu;
	double I = bu - bl;
	double xl = bu - k * I;
	double xu = bl + k * I;
	double temp1 = fx(xl);
	double temp2 = fx(xu);
	while (abs(I) > theta)
	{
		n++;
		//cout << n << ". x interval: [" << xl << ", " << xu << "] - " << "Bound interval: [" << bl << ", " << bu << "] - ";
		if (temp1 <= temp2)
		{
			//cout << "Step 3\n";
			I = xu - bl;
			bu = xu;
			bl = bl;
			xl = bu - k * I;
			xu = xl;
			temp2 = temp1;
			temp1 = fx(xl);
		}
		else
		{
			//cout << "Step 4\n";
			bl = xl;
			bu = bu;
			I = bu - bl;
			xl = xu;
			xu = bl + k * I;
			temp1 = temp2;
			temp2 = fx(xu);
		}

	}
	cout << "\n\n\nMin point of f(x) is at interval: [" << fx(xl) << ", " << fx(xu) << "]\n";
	cout << "x interval: [" << xl << ", " << xu << "]\n";
	cout << "Number of iteration: " << n << "\n\n\n\n\n";
	cin.get();
	return 0;

}

double fx(double x)
{
	//double f = x * cos(M_PI*x*x);
	//double f = 4 * pow(x, 2) - 12 * x + 9;
	double f = 3 * pow(x, 5) - 7 * pow(x, 3) - 54 * x + 21;
	return f;
}
