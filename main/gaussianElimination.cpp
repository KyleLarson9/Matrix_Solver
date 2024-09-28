/*
 * gaussianElimination.cpp
 *
 *  Created on: Sep 16, 2024
 *      Author: kylel
 */

#include "gaussianElimination.h"
using namespace std;

// doesn't take into account all zero column -- it would  need to skip row for pivots
// doesn't work for extremely small float values (it won't do anything)
// doesn't work for free variables

float** GaussianElimination::reducedRowEchelonForm(float** matrix, int rows, int columns) {

	int pivotColumn = 0;
	int pivotRow = 0;
	float* rowMultipliedByScalar = new float[columns];

	while(pivotColumn < columns - 1) {

		// assign pivot
		findBestPivot(matrix, rows, columns, pivotColumn);

		// normalize pivot
		float currentPivot = matrix[pivotColumn][pivotRow];
		if(currentPivot != 1) {
			float scalar = 1 / currentPivot;
			multiplyRowByScalar(matrix, rows, columns, pivotRow, scalar);
		}

		if(checkZeros(matrix, rows, columns, pivotRow)) { // if all zeros except for column increment pivot
			// check if it is an all zero column
			pivotRow++;
			pivotColumn++;
			continue;
		} else {

			// starting from first non zero element, destroy that element with pivot (skipping over pivot of course

			for(int i = 0; i < rows; i++) {
				if(i != pivotRow && matrix[i][pivotColumn] != 0) {
					float scalar = - matrix[i][pivotColumn];
					rowMultipliedByScalar = getRowMultipliedByScalar(matrix, rows, columns, pivotRow, scalar);
					addTwoRowsWithGivenRow(matrix, rows, columns, rowMultipliedByScalar, i);
				}
			}
			pivotRow++;
			pivotColumn++;
		}
	}
	delete[] rowMultipliedByScalar;

	return matrix;
}

bool GaussianElimination::checkZeros(float** matrix, int rows, int columns, int pivotColumn) {

	bool allZeros = false;

	int maxPossibleZeros = rows - 1;
	int zeroCount = 0;

	for(int i = 0; i < rows; i++) {
		if(matrix[i][pivotColumn] == 0) {
			zeroCount++;
		}
	}

	if(zeroCount == maxPossibleZeros)
		allZeros = true;

	return allZeros;
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

void GaussianElimination::findBestPivot(float** matrix, int rows, int columns, int totalPivots) {
    // assign current pivot
    int currentPivotRow = totalPivots;
    int currentPivotColumn = totalPivots;
    int currentPivot = matrix[currentPivotRow][currentPivotColumn];

    if(currentPivot == 1 || currentPivotRow > rows || currentPivotColumn > columns) {
    	return;
    }

    int bestPivotRow = currentPivotRow;

    if(currentPivot == 0) {
    	for(int i = currentPivotRow; i < rows; i++) {
    		// get the first non zero element
    		int currentIndexValue = matrix[i][currentPivotColumn];
    		if(currentIndexValue != 0) {
    			bestPivotRow = i;
    			break;
    		}
    	}
    }

    for(int i = currentPivotRow + 1; i < rows; i++) {
    	int currentIndexValue = matrix[i][currentPivotColumn];

    	if(currentIndexValue == 1) {
    		bestPivotRow = i;
    		break;
    	}

    }

    if(bestPivotRow != currentPivotRow) {
    	interchangeRows(matrix, rows, columns, currentPivotRow, bestPivotRow);
    }

}

// elementary row operation functions

void GaussianElimination::addTwoRowsWithGivenRow(float** matrix, int rows, int columns, float* row1, int row2Number) {

	for (int j = 0; j < columns; j++) {
        matrix[row2Number][j] += row1[j];  // add rows from existing row
    }
}


void GaussianElimination::multiplyRowByScalar(float** matrix, int rows, int columns, int row, float scalar) {

	for(int j = 0; j < columns; j++) {
		float currentElement = matrix[row][j];
		if(currentElement != 0) {
			currentElement = matrix[row][j] * scalar;
			matrix[row][j] = currentElement;
		}
	}

}

void GaussianElimination::interchangeRows(float** matrix, int rows, int columns, int rowA, int rowB) {

	// Adjust indices from 1-based to 0-based
    int a = rowA;
    int b = rowB;

    if (a < 0 || a >= rows || b < 0 || b >= rows) {
        return;
    }

    // Swap the rows in the matrix
    for (int j = 0; j < columns; j++) {
        std::swap(matrix[a][j], matrix[b][j]);
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
	cout << endl;

}
