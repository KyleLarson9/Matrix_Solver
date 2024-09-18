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

	void solvingAlgorithm();
	void printMatrix(int** matrix, int rows, int columns);
	void multiplyRowByScalar(int** matrix, int rows, int columns, int row, int scalar);
	void interchangeRows(int** matrix, int rows, int columns, int rowA, int rowB);
	void addTwoRows(int** matrix, int rows, int columns, int rowA, int rowB);

	void assignPivot();

private:

	void checkZeros();

};



#endif /* GAUSSIANELIMINATION_H_ */
