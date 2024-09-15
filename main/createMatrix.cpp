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
			matrix[i][j] = rand() % 100;
		}
	}
}

void CreateMatrix::printRandomMatrix() {

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
