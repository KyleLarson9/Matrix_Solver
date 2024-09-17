/*
 * createMatrix.cpp
 *
 *  Created on: Sep 2, 2024
 *      Author: kylel
 */

#include "createMatrix.h"
using namespace std;

CreateMatrix::CreateMatrix(): rows(0), columns(0), matrix(nullptr) {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation
}

CreateMatrix::~CreateMatrix() {
	deallocateMatrix();
}

void CreateMatrix::setMatrixSize(int r, int c) {
	rows = r;
	columns = c;

	deallocateMatrix();

	// allocate memory for matrix
	matrix = new int*[rows];
	for(int i = 0; i < rows; i++) {
		matrix[i] = new int[columns];
	}
}

void CreateMatrix::generateRandomMatrix() {

	checkIfNull();

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
}

void CreateMatrix::createCustomMatrix() {

	checkIfNull();

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {

			int currentElementValue;

			if(j == columns - 1) {
				cout << "Enter solution for equation " << i + 1 << endl;
				cin >> currentElementValue;
			} else {
				cout << "Enter element " << "(" << i << ", " << j << ")" << endl;
				cin >> currentElementValue;
			}

			matrix[i][j] = currentElementValue;

		}
	}

}

void CreateMatrix::printMatrix() {

	checkIfNull();

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			if(matrix[i][j] < 10) {
				cout << matrix[i][j] << "  ";
			} else {
				cout << matrix[i][j] << " ";
			}
		}
		cout << endl;
	}

}

// helper functions

void CreateMatrix::deallocateMatrix() {
	if(matrix != nullptr) {
		for(int i = 0; i < rows; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
		matrix = nullptr;
	}
}

void CreateMatrix::checkIfNull() {
	if(matrix == nullptr) {
		cerr << "Matrix not initialized" << endl;
	}
}

// getters and setters

int** CreateMatrix::getMatrix() {
	return matrix;
}

int CreateMatrix::getRows() {
	return rows;
}

int CreateMatrix::getColumns() {
	return columns;
}
