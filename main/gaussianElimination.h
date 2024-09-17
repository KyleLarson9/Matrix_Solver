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

private:

	void interchangeRows(int** matrix, int rowA, int rowB);
	void multiplyRowByScalar(int** matrix, int row, int scalar);
	void addRows(int** matrix, int rowA, int rowB);

	void checkZeros();
};



#endif /* GAUSSIANELIMINATION_H_ */
