/*
 * gaussianElimination.cpp
 *
 *  Created on: Sep 16, 2024
 *      Author: kylel
 */

#include "gaussianElimination.h"
using namespace std;

// currently for matrices with 1 unique solution

void GaussianElimination::solvingAlgorithm(float** matrix, int rows, int columns) {

	// manual for now

	// assign first pivot
	int totalPivots = 0;
	int pivotRow = 0;
	int pivotColumn = 0;

	assignPivot(matrix, rows, columns, totalPivots);

	cout << "Current pivot is: " << matrix[pivotRow][pivotColumn] << endl << endl;
	printMatrix(matrix, rows, columns);
	cout << endl;
	// make value of current pivot 1 if not already

	if(matrix[pivotRow][pivotColumn] != 1) {
		float currentPivot = matrix[pivotRow][pivotColumn];
		float scalar = 1 / currentPivot;
		cout << "Scalar is: " << scalar << endl;
		multiplyRowByScalar(matrix, rows, columns, pivotRow, scalar);
	}

	printMatrix(matrix, rows, columns);

}


void GaussianElimination::assignPivot(float** matrix, int rows, int columns, int totalPivots) {
    // assign current pivot
    int currentPivotRow = totalPivots;
    int currentPivotColumn = totalPivots;
    int currentPivot = matrix[currentPivotRow][currentPivotColumn];



    if(currentPivot == 1 || currentPivotRow > rows || currentPivotColumn > columns) {
    	return;
    }

    int bestPivotRow = currentPivotRow;

    for(int i = currentPivotRow + 1; i < rows; i++) {
    	int possiblePivot = matrix[i][currentPivotColumn];

    	if(possiblePivot == 1) {
    		bestPivotRow = i;
    		break;
    	} else if(abs(possiblePivot) > abs(matrix[bestPivotRow][currentPivotColumn])) {
    		bestPivotRow = i;
    	}
    }

    if(bestPivotRow != currentPivotRow) {
    	interchangeRows(matrix, rows, columns, currentPivotRow + 1, bestPivotRow + 1);
    }

}

bool GaussianElimination::checkZeros(float** matrix, int rows, int columns, int pivotRow, int pivotColumn) {

	bool allZeros = false;
	int maximumZerosBelowPivot = rows - (pivotRow + 1);
	int zeroCount = 0;

	for(int i = pivotRow + 1; i < rows; i++) {
		int currentIndexValue = matrix[i][pivotColumn];

		if(currentIndexValue == 0) {
			zeroCount++;
		}
	}

	if(zeroCount == maximumZerosBelowPivot) {
		allZeros = true;
	}

	return allZeros;
}

// elementary row operation functions

void GaussianElimination::multiplyRowByScalar(float** matrix, int rows, int columns, int row, float scalar) {

	for(int j = 0; j < columns; j++) {
		float currentElement = matrix[row][j];
		currentElement = matrix[row][j] * scalar;
		matrix[row][j] = currentElement;
	}

}

void GaussianElimination::addTwoRows(float** matrix, int rows, int columns, int rowA, int rowB) {

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

}

// painfully inefficient but its a start
void GaussianElimination::interchangeRows(float** matrix, int rows, int columns, int rowA, int rowB) {

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

void GaussianElimination::printMatrix(float** matrix, int rows, int columns) {

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}


