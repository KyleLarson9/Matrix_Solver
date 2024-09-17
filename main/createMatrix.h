/*
 * createMatrix.h
 *
 *  Created on: Sep 2, 2024
 *      Author: kylel
 */

#ifndef CREATEMATRIX_H_
#define CREATEMATRIX_H_
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

class CreateMatrix {
public:
    CreateMatrix();  // Constructor
    ~CreateMatrix(); // Destructor

    void setMatrixSize(int r, int c); // Sets the size of the matrix
    void generateRandomMatrix(); // Fills the matrix with random values
    void createCustomMatrix();
    void printMatrix(); // Prints the matrix
    void getSolutionsVector(); // the last integer of each row
    int** getMatrix();
    int getRows();
    int getColumns();

private:
    int rows; // Number of rows in the matrix
    int columns; // Number of columns in the matrix
    int** matrix; // Pointer to a 2D array (matrix)

    void deallocateMatrix(); // Helper function to deallocate memory
    void checkIfNull();
};



#endif /* CREATEMATRIX_H_ */
