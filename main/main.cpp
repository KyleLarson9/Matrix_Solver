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
	 CreateMatrix matrix;

	 matrix.setMatrixSize(15, 15);
	 matrix.generateRandomMatrix();
	 matrix.printRandomMatrix();


	 return  0;

}

