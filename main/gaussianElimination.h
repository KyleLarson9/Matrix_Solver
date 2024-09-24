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

	void solvingAlgorithm(float** matrix, int rows, int columns);
	void printMatrix(float** matrix, int rows, int columns);

private:

	// elementary row operation functions
	void multiplyRowByScalar(float** matrix, int rows, int columns, int row, float scalar);
	void interchangeRows(float** matrix, int rows, int columns, int rowA, int rowB);
	void addTwoRows(float** matrix, int rows, int columns, int rowA, int rowB);

	// functions needed to help solve matrix
	void assignPivot(float** matrix, int rows, int columns, int totalPivots);
	bool checkZeros(float** matrix, int rows, int columns, int pivotRow, int pivotColumn);

};



#endif /* GAUSSIANELIMINATION_H_ */
