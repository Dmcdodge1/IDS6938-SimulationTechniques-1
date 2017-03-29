#include <iostream>
#include <functional>   
#include <numeric> 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <Eigen\dense>

#include "markov.h"
#include "TransitionMatrix.h"

int main(){

	SetTransitionMatrix();

	//Output Vector
	v.setZero();
	v(0) = 1.0;

	// Print Results to File
	std::ofstream myfile;
	myfile.open("markov_results.txt");

	for (int j = 0; j < 20; j++) {

   // TODO 
   //Helped by Sarah***** I think she was helped by others as well. May be pretty similar
	//Cited: http://www.datagenetics.com/blog/november12011/

	v = v.transpose() * TransitionMatrix; //got this bad boy online 
		for (int i = 0; i < size; i++) { 

			std::cout << v(i) << ", ";
			myfile << v(i) << ", ";  
		}
	std::cout << std::endl;
	myfile << std::endl;
	}
	myfile.close();

	return 1;
}