/*
 * createMatrix.cpp
 *
 *  Created on: Sep 2, 2024
 *      Author: kylel
 */

#include "createMatrix.h"
using namespace std;

CreateMatrix::CreateMatrix() : rows(0), columns(0), matrix(nullptr) {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation
}

CreateMatrix::~CreateMatrix() {
    deallocateMatrix(); // Ensure memory is released
}

void CreateMatrix::setMatrixSize(int r, int c) {
    rows = r;
    columns = c;

    // Allocate memory for the matrix here instead of the constructo ---- why?
   // deallocateMatrix(); // Deallocate any existing matrix before allocating new memory

    //
    matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[columns];
    }
}

void CreateMatrix::generateRandomMatrix() {
    if (matrix == nullptr) {
        std::cerr << "Matrix not initialized. Please set the matrix size first." << std::endl;
        return;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) { // Fixed the loop increment issue
            matrix[i][j] = rand() % 100; // Fill with random values between 0 and 99
        }
    }
}

void CreateMatrix::printRandomMatrix() {
    if (matrix == nullptr) {
        std::cerr << "Matrix not initialized. Please set the matrix size first." << std::endl;
        return;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void CreateMatrix::deallocateMatrix() {
    if (matrix != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = nullptr;
    }
}
