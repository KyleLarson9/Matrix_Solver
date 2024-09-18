/*
 * gaussianElimination.cpp
 *
 *  Created on: Sep 16, 2024
 *      Author: kylel
 */

#include "gaussianElimination.h"
using namespace std;


// algorithm methods




void GaussianElimination::multiplyRowByScalar(int** matrix, int rows, int columns, int row, int scalar) {

	for(int j = 0; j < columns; j++) {
		int currentElement = matrix[row - 1][j];
		currentElement = matrix[row - 1][j] * scalar;
		matrix[row - 1][j] = currentElement;
	}

}

void GaussianElimination::addTwoRows(int** matrix, int rows, int columns, int rowA, int rowB) {

	// will add rowA with rowB and replace rowB with the sum of the two rows

	int row1[columns];
	int row2[columns];
	int newRow[columns];

	// get values for each row in a 1D array
	for(int i = 0; i < rows; i++) {
		if(i + 1 == rowA) {
			for(int j = 0; j < columns; j++) {
				row1[j] = matrix[i][j];
			}
		} else if(i + 1 == rowB) {
			for(int j = 0; j < columns; j++) {
				row2[j] = matrix[i][j];
			}
		}
	}

	// multiply desired row by scalar in algorithm

	// add the two rows

	for(int i = 0; i < columns; i++) {
		int sum = row1[i] + row2[i];
		newRow[i] = sum;
	}

	for(int i = 0; i < rows; i++) {
		if(i + 1 == rowB) {
			for(int j = 0; j < columns; j++) {
				matrix[i][j] = newRow[j];
			}
		}
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}

// painfully inefficient but its a start
void GaussianElimination::interchangeRows(int** matrix, int rows, int columns, int rowA, int rowB) {

	int row1[columns];
	int row2[columns];

	// get values for each row in a 1D array
	for(int i = 0; i < rows; i++) {
		if(i + 1 == rowA) {
			for(int j = 0; j < columns; j++) {
				row1[j] = matrix[i][j];
			}
		} else if(i + 1 == rowB) {
			for(int j = 0; j < columns; j++) {
				row2[j] = matrix[i][j];
			}
		}
	}

	// swap rows in matrix
	for(int i = 0; i < rows; i++) {
		if(i + 1 == rowA) {
			for(int j = 0; j < columns; j++) {
				matrix[i][j] = row2[j];
			}
		} else if(i + 1 == rowB) {
			for(int j = 0; j < columns; j++) {
				matrix[i][j] = row1[j];
			}
		}

	}

}

// printing

void GaussianElimination::printMatrix(int** matrix, int rows, int columns) {

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}


