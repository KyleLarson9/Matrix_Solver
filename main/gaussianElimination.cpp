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

	printMatrix(matrix, rows, columns);
	cout << endl << endl;
	// manual for now

	// assign first pivot
	int totalPivots = 0;
	int pivotRow = 0;
	int pivotColumn = 0;

	assignPivot(matrix, rows, columns, totalPivots);
	printMatrix(matrix, rows, columns);
	cout << endl << endl;

	// make value of current pivot 1 if not already
	if(matrix[pivotRow][pivotColumn] != 1) {
		float currentPivot = matrix[pivotRow][pivotColumn];
		float scalar = 1 / currentPivot;
		multiplyRowByScalar(matrix, rows, columns, pivotRow, scalar);
	}

	printMatrix(matrix, rows, columns);
	cout << endl << endl;

	// check zeros under pivot
	//    If all elements under pivot are 0, move onto the next columns (swap pivot)
	//    else start row operations
	bool allZerosUnderPivot = checkZeros(matrix, rows, columns, pivotRow, pivotColumn);

	if(allZerosUnderPivot) {
		totalPivots++;
		pivotRow++;
		pivotColumn++;
		assignPivot(matrix, rows, columns, totalPivots); // move to next pivot
	} else { // start row operations

		// find first non zero entry
		int currentPivotValue = matrix[pivotRow][pivotColumn];

		for(int i = pivotRow + 1; i < rows; i++) { // start from entry below current pivot

			if(matrix[i][pivotColumn] != 0) {
				int currentElementRow = i;
				float currentElementValue = matrix[i][pivotColumn];
				float* rowMultipliedByScalar = new float[columns];

				// multiply currentPivot row by scalar according to value of currentElement
				float scalar = - currentElementValue * currentPivotValue;

				rowMultipliedByScalar = getRowMultipliedByScalar(matrix, rows, columns, pivotRow, scalar);
				addTwoRowsWithGivenRow(matrix, rows, columns, rowMultipliedByScalar, currentElementRow);
				printMatrix(matrix, rows, columns);
				cout << endl << endl;

			}
		}

	}
}

float* GaussianElimination::getRowMultipliedByScalar(float** matrix, int rows, int columns, int row, float scalar) {
	// return 1D array of row multiplied by scalar

	float* rowMultipliedByScalar = new float[columns];

	for(int j = 0; j < columns; j++) {
		float currentElement = matrix[row][j];
		currentElement = currentElement * scalar;
		rowMultipliedByScalar[j] = currentElement;
	}

	return rowMultipliedByScalar;
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

void GaussianElimination::addTwoRowsWithGivenRow(float** matrix, int rows, int columns, float* row1, int row2Number) {

	float* row2 = new float[columns];
	float* newRow = new float[columns];

	// get row2
	for(int j = 0; j < columns; j++) {
		row2[j] = matrix[row2Number][j];
	}

	// add the two rows
	for(int j = 0; j < columns; j++) {
		newRow[j] = row1[j] + row2[j];
	}

	// implement new row into matrix
	for(int j = 0; j < columns; j++) {
		matrix[row2Number][j] = newRow[j];
	}
}

void GaussianElimination::multiplyRowByScalar(float** matrix, int rows, int columns, int row, float scalar) {

	for(int j = 0; j < columns; j++) {
		float currentElement = matrix[row][j];
		currentElement = matrix[row][j] * scalar;
		matrix[row][j] = currentElement;
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


