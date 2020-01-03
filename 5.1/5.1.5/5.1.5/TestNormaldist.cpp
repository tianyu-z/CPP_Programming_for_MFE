//Purpose: The test file of Normaldist
//Author: Tianyu Zhang
//Date: 07/06/18


#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	using namespace boost::math;	// ***Easy to forget***

	// Exponential distribution
	double scaleParameter1 = 0.5;
	// Adopt the default type is 'double'

	exponential_distribution<> myExponential0(scaleParameter1);
	cout << "Mean:" << mean(myExponential0)
		<< ",standard deviation: "
		<< standard_deviation(myExponential0) << endl;

	// Distributional properties
	double x = 15.5;

	cout << "pdf: " << pdf(myExponential0, x) << endl;
	cout << "cdf: " << cdf(myExponential0, x) << endl;

	float scaleParameter2 = 0.5;
	// Adopt the 'float' data type
	exponential_distribution<float> myExponential1(scaleParameter2);
	cout << "Mean: " << mean(myExponential1) 
		<< ", standard deviation: "
		<< standard_deviation(myExponential1) << endl;
	cout << "pdf: " << pdf(myExponential1, x) << endl;
	cout << "cdf: " << cdf(myExponential1, x) << endl;

	// Set precision
	cout.precision(10); // Number of values behind the comma

	
						// Other properties of exponential distribution
	cout << "\nexponential distribution: \n";
	cout << "mean: " << mean(myExponential0) << endl;
	cout << "variance: " << variance(myExponential0) << endl;
	cout << "median: " << median(myExponential0) << endl;
	cout << "mode: " << mode(myExponential0) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExponential0) << endl;
	cout << "kurtosis: " << kurtosis(myExponential0) << endl;
	cout << "characteristic function: " << chf(myExponential0, x) << endl;
	cout << "hazard: " << hazard(myExponential0, x) << endl;

	// Poisson distribution
	double mean = 3.0;
	poisson_distribution<double> myPoisson(mean);

	double val = 15.5;
	cout << endl << "pdf: " << pdf(myPoisson, val) << endl;
	cout << "cdf: " << cdf(myPoisson, val) << endl;

	vector<double> pdfs;
	vector<double> cdfs;

	double startpoint = 0.0;
	double endpoint = 15.0;

	// The num of subdivisions
	
	long N = 30;
	val = 0.0;
	double h = (endpoint - startpoint) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfs.push_back(pdf(myPoisson, val));
		cdfs.push_back(cdf(myPoisson, val));

		val += h;
	}

	cout << "pdf:" << endl;
	for (long j = 0; j < pdfs.size(); ++j)
	{
		cout << pdfs[j] << ", ";

	}


	cout << "\ncdf:" << endl;
	for (long j = 0; j < cdfs.size(); ++j)
	{
		cout << cdfs[j] << ", ";

	}

}
