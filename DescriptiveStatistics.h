#pragma once


class DescriptiveStatistics {

private:
	int arraySize = 0;
	int* arr = nullptr;

public:
	void chooseOption();
	int menu();
	int minNumber(int*, int);
	int maxNumber(int*, int);
	int range(int* numberArr, int size);
	int size(int* numberArr, int size);
	int sum(int* numberArr, int size);
	double findMean(int*, int);
	double findMedian(int* numberArr, int size);
	int standardDeviation(int* numberArr, int size);
	double variance(int* numberArr, int size);
	int midRange(int*, int);
	int* arrayNumbers(int&);
	double sumOfSquares(int* numberArr, int size);
};