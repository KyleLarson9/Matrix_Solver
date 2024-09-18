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
	//createMatrix.createCustomMatrix();
	createMatrix.generateRandomMatrix();

	gaussianElimination.printMatrix(createMatrix.getMatrix(), createMatrix.getRows(), createMatrix.getColumns());

	cout << endl << endl;

	int rowA = 1;
	int rowB = 3;

	gaussianElimination.addTwoRows(createMatrix.getMatrix(), createMatrix.getRows(), createMatrix.getColumns(), rowA, rowB);

//	int rowToMultiply = 2;
//	int scalar = 5;
//	gaussianElimination.multiplyRowByScalar(createMatrix.getMatrix(), createMatrix.getRows(), createMatrix.getColumns(), rowToMultiply, scalar);
//	gaussianElimination.printMatrix(createMatrix.getMatrix(), createMatrix.getRows(), createMatrix.getColumns());
//
//	cout << endl << endl;
//
//	int rowA = 1;
//	int rowB = 3;
//	gaussianElimination.interchangeRows(createMatrix.getMatrix(), createMatrix.getRows(), createMatrix.getColumns(), rowA, rowB);
//
//	cout << endl << endl;
//
//	gaussianElimination.printMatrix(createMatrix.getMatrix(), createMatrix.getRows(), createMatrix.getColumns());

	return  0;

}

