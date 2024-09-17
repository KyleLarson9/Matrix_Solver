/*
 * main.cpp
 *
 *  Created on: Sep 1, 2024
 *      Author: kylel
 */
#include <iostream>
#include "createMatrix.h"

using namespace std;

int main() {

	CreateMatrix createMatrix;

	createMatrix.setMatrixSize(2, 3);
	createMatrix.createCustomMatrix();
	createMatrix.printMatrix();


	return  0;

}

