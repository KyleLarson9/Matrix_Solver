/*
 * gaussianElimination.cpp
 *
 *  Created on: Sep 16, 2024
 *      Author: kylel
 */

#include "gaussianElimination.h"
using namespace std;

void GaussianElimination::solvingAlgorithm(float** matrix, int rows, int columns) {

	int totalPivots = 0;
	int pivotRow = 0;
	int pivotColumn = 0;
	float* rowMultipliedByScalar = new float[columns];

	while(pivotColumn < columns - 1) {

		// assign first pivot
		assignPivot(matrix, rows, columns, totalPivots);

		// normalize pivot
		float currentPivot = matrix[pivotRow][pivotColumn];
		if(matrix[pivotRow][pivotColumn] != 1) {
			float scalar = 1 / currentPivot;
			multiplyRowByScalar(matrix, rows, columns, pivotRow, scalar);
		}


		// check for zeros under current pivot
		bool allZerosUnderPivot = checkZeros(matrix, rows, columns, pivotRow, pivotColumn);

		if(allZerosUnderPivot) {
			totalPivots++;
			pivotRow++;
			pivotColumn++;
			continue;
		} else {

			// start row operations
			int currentPivotValue = matrix[pivotRow][pivotColumn];

			for(int i = pivotRow + 1; i < rows; i++) {

				float currentElementValue = matrix[i][pivotColumn];
				if(matrix[i][pivotColumn] != 0) {

					// multiply currentPivot row by scalar according to value of currentElement
					float scalar = - currentElementValue * currentPivotValue;

					rowMultipliedByScalar = getRowMultipliedByScalar(matrix, rows, columns, pivotRow, scalar);
					addTwoRowsWithGivenRow(matrix, rows, columns, rowMultipliedByScalar, i);

				}
			}
			totalPivots++;
			pivotRow++;
			pivotColumn++;
		}
	}
	delete[] rowMultipliedByScalar;

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
    int a = rowA - 1;
    int b = rowB - 1;

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
	cout << endl << endl;

}


