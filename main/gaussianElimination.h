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
class GaussianElimination {

public:

	void solvingAlgorithm(float** matrix, int rows, int columns);
	void printMatrix(float** matrix, int rows, int columns);
	void printFractionMatrix(float** matrix, int rows, int columns);
private:

	// elementary row operation functions
	void multiplyRowByScalar(float** matrix, int rows, int columns, int row, float scalar);
	void interchangeRows(float** matrix, int rows, int columns, int rowA, int rowB);
	void addTwoRowsWithGivenRow(float** matrix, int rows, int columns, float* rowA, int rowB);

	// functions needed to help solve matrix
	void assignPivot(float** matrix, int rows, int columns, int totalPivots);
	bool checkZeros(float** matrix, int rows, int columns, int pivotRow, int pivotColumn);
	float* getRowMultipliedByScalar(float** matrix, int rows, int columns, int row, float scalar); // returns array of row multiplied by scalar

};



#endif /* GAUSSIANELIMINATION_H_ */
