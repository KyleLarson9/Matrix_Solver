/*
 * gaussianElimination.cpp
 *
 *  Created on: Sep 16, 2024
 *      Author: kylel
 */

#include "gaussianElimination.h"
using namespace std;

// currently for matrices with 1 unique solution

void GaussianElimination::solvingAlgorithm(int** matrix, int rows, int columns) {

	// assign first pivot
	int totalPivots = 0;
	int currentPivotRow = 0;
	assignPivot(matrix, rows, columns, totalPivots);

	// check zeros underPivot
	//    if all zeros, move pivot
	bool allZerosUnderPivot = checkZeros(matrix, rows, columns, currentPivotRow);
}


void GaussianElimination::assignPivot(int** matrix, int rows, int columns, int totalPivots) {
    // assign current pivot
    int currentPivotRow = totalPivots;
    int currentPivotColumn = totalPivots;
    int currentPivot = matrix[currentPivotRow][currentPivotColumn];

    if(currentPivot == 1) {
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

bool GaussianElimination::checkZeros(int** matrix, int rows, int columns, int pivotRow) {

	// return true if all element value under the current pivot are 0
	bool allZeros = false;
	int maximumZerosBelowPivot = rows - pivotRow;

	for(int i = pivotRow; i < rows; i++) {

	}

	// idea: get pivot row, and subtract it from the total amount of rows
	//    	 loop through each row and check the zeros in x column
	//       if there are as many zeros as the total number of rows minus pivot row return true

	return allZeros;
}

// elementary row operation functions

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


