/*
 * main.cpp
 *
 *  Created on: Sep 1, 2024
 *      Author: kylel
 */
#include <iostream>
#include "createMatrix.h"
#include "gaussianElimination.h"

using namespace std;

int main() {

	CreateMatrix createMatrix;
	GaussianElimination gaussianElimination;

	createMatrix.setMatrixSize(3, 3);
	createMatrix.createCustomMatrix();

	int** matrix = createMatrix.getMatrix();
	int totalRows = createMatrix.getRows();
	int totalColumns = createMatrix.getColumns();

	gaussianElimination.printMatrix(matrix, totalRows, totalColumns);
	cout << endl;
	gaussianElimination.solvingAlgorithm(matrix, totalRows, totalColumns);
	cout << endl;
	gaussianElimination.printMatrix(matrix, totalRows, totalColumns);

	return  0;

}

