/*
 * matrixOperations.h
 *
 *  Created on: Sep 28, 2024
 *      Author: kylel
 */

class MatrixOperations {

public:

	float determinant(float** matrix, int rows, int columns);
	float** adjoint(float** matrix, int rows, int columns);
	float** inverse(float** matrix, int rows, int columns);
	float** transpose(float** matrix, int rows, int columns);

private:


};

