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

	createMatrix.setMatrixSize(2, 3);
	createMatrix.createCustomMatrix();

	gaussianElimination.printMatrix(createMatrix.getMatrix(), createMatrix.getRows(), createMatrix.getColumns());

	return  0;

}

