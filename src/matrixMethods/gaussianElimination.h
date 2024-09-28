/*
 * gaussianElimination.h
 *
 *  Created on: Sep 16, 2024
 *      Author: kylel
 */

#ifndef GAUSSIANELIMINATION_H_
#define GAUSSIANELIMINATION_H_

#include <iostream>
#include <algorithm>

using namespace std;

class GaussianElimination {

public:

	float** rowEchelonForm(float** matrix, int rows, int columns);
	float**  reducedRowEchelonForm(float** matrix, int rows, int columns);
	void printMatrix(float** matrix, int rows, int columns);

private:

	// elementary row operation functions
	void multiplyRowByScalar(float** matrix, int rows, int columns, int row, float scalar);
	void interchangeRows(float** matrix, int rows, int columns, int rowA, int rowB);
	void addTwoRowsWithGivenRow(float** matrix, int rows, int columns, float* rowA, int rowB);

	// functions needed to help solve matrix
	void findBestPivot(float** matrix, int rows, int columns, int totalPivots);
	float* getRowMultipliedByScalar(float** matrix, int rows, int columns, int row, float scalar); // returns array of row multiplied by scalar
	bool checkZeros(float** matrix, int rows, int columns, int pivotColumn);

};

#endif /* GAUSSIANELIMINATION_H_ */
