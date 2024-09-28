/*
 * main.cpp
 *
 *  Created on: Sep 1, 2024
 *      Author: kylel
 */
#include <iostream>

#include "createMatrix.h"
#include "../matrixMethods/gaussianElimination.h"
using namespace std;

int main() {

	CreateMatrix createMatrix;
	GaussianElimination gaussianElimination;

	createMatrix.setMatrixSize(3, 4);
	createMatrix.generateRandomMatrix();
	//createMatrix.createCustomMatrix();

	float** matrix = createMatrix.getMatrix();
	int totalRows = createMatrix.getRows();
	int totalColumns = createMatrix.getColumns();

	gaussianElimination.printMatrix(matrix, totalRows, totalColumns);

	float** rrefMatrix = gaussianElimination.reducedRowEchelonForm(matrix, totalRows, totalColumns);

	gaussianElimination.printMatrix(rrefMatrix, totalRows, totalColumns);

	return  0;

}

