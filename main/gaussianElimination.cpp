/*
 * gaussianElimination.cpp
 *
 *  Created on: Sep 16, 2024
 *      Author: kylel
 */

#include "gaussianElimination.h"
using namespace std;

void GaussianElimination::solvingAlgorithm() {

}

void GaussianElimination::printMatrix(int** matrix, int rows, int columns) {

	cout << "Test" << endl;

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}


