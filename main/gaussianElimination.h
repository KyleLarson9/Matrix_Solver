/*
 * gaussianElimination.h
 *
 *  Created on: Sep 16, 2024
 *      Author: kylel
 */

#ifndef GAUSSIANELIMINATION_H_
#define GAUSSIANELIMINATION_H_

#include <iostream>

class GaussianElimination {

public:

	void solvingAlgorithm(int** matrix, int rows, int columns);
	void printMatrix(int** matrix, int rows, int columns);

private:

	// elementary row operation functions
	void multiplyRowByScalar(int** matrix, int rows, int columns, int row, int scalar);
	void interchangeRows(int** matrix, int rows, int columns, int rowA, int rowB);
	void addTwoRows(int** matrix, int rows, int columns, int rowA, int rowB);

	// functions needed to help solve matrix
	void assignPivot(int** matrix, int rows, int columns, int totalPivots);
	bool checkZeros(int** matrix, int rows, int columns, int pivotRow);

};



#endif /* GAUSSIANELIMINATION_H_ */
