#ifndef DESCRIPTIVESTATISTICS_H
#define DESCRIPTIVESTATISTICS_H

class DescriptiveStatistics {

private:
	int arraySize = 0;
	int* arr = nullptr;
public:
	void chooseOption();
	int menu();
	int* arrayNumbers(int&);
	int minNumber(int*, int);
	int maxNumber(int*, int);
	int range(int* numberArr, int size);
	int size(int* numberArr, int size);
	double sum(int* numberArr, int size);
	double findMean(int*, int);
	double findMedian(int* numberArr, int size);
	double standardDeviation(int* numberArr, int size);
	double variance(int* numberArr, int size);
	int midRange(int*, int);
	double sumOfSquares(int* numberArr, int size);
	double meanAbsDev(int* numberArr, int size);
	double getQuartile1(int* numberArr, int size);
	double getQuartile2(int* numberArr, int size);
	double getQuartile3(int* numberArr, int size);
	double rootMeanSquare(int* numberArr, int size);
	double standardErrorMean(int* numberArr, int size);
	double coeffecientVariation(int* numberArr, int size);
	double relativeStandardDev(int* numberArr, int size);
};

#endif