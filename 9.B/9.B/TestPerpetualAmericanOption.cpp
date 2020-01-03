#include "Option.h"
#include "PerpetualAmericanOption.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void main()
{
	ofstream fout("output.txt");


	double K, sig, r, U, b;
	cout << "K: "; cin >> K;
	cout << "sig: "; cin >> sig;
	cout << "r: "; cin >> r;
	cout << "b: "; cin >> b;
	cout << "S: "; cin >> U;


	vector<double> vecU = GenerateMeshArray(10, 50, 41);

	// B.b)
	// Use global functions.
	cout << "S = " << U << ", C = " << PerpetualCall(K, sig, r, U, b) << ", P = " << PerpetualPut(K, sig, r, U, b) << endl;
	fout << "S = " << U << ", C = " << PerpetualCall(K, sig, r, U, b) << ", P = " << PerpetualPut(K, sig, r, U, b) << endl;

	// Use instances of PerpetualAmericanOption class.
	PerpetualAmericanOptionData optionData;
	optionData.K = K;
	optionData.sig = sig;
	optionData.r = r;
	optionData.U = U;
	optionData.b = b;
	PerpetualAmericanOption perpetualOption(optionData);
	cout << "S = " << U << ", C = " << perpetualOption.Price() << endl;
	fout << "S = " << U << ", C = " << perpetualOption.Price() << endl;
	perpetualOption.toggle();
	cout << "S = " << U << ", P = " << perpetualOption.Price() << endl;
	fout << "S = " << U << ", P = " << perpetualOption.Price() << endl;
	perpetualOption.toggle();

	// B.c)
	// Compute prices for a range of underlying value
	vector<double> vecC1, vecP1;
	for (int j = 0; j < vecU.size(); j++)
	{
		vecC1.push_back(perpetualOption.PriceWithS(vecU[j]));
		perpetualOption.toggle();
		vecP1.push_back(perpetualOption.PriceWithS(vecU[j]));
		perpetualOption.toggle();
	}

	for (int j = 0; j < vecC1.size(); j++)
	{
		cout << "S = " << vecU[j] << ", C = " << vecC1[j] << ", P = " << vecP1[j] << endl;
		fout << "S = " << vecU[j] << ", C = " << vecC1[j] << ", P = " << vecP1[j] << endl;
	}

	fout << flush;
	fout.close();
}