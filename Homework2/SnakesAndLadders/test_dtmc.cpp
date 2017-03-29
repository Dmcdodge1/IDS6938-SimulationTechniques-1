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


// Hint: Set N - number of simulations low until you have it working
//       Then set it much much higher, and run in release mode so its faster


//Helped by Sarah***** I think she was helped by others as well. May be pretty similar
//Cited: http://www.datagenetics.com/blog/november12011/

int main() {

	SetTransitionMatrix();

	// Print Results to File
	std::ofstream myfile;
	myfile.open("markov_results.txt");

	int start = 0;

	//simulate discrete time Markov Chain
	unsigned int N = 50;
	std::map<int, int> hist;
	std::vector<int> discreteMC;
	for (unsigned int i = 0; i < N; ++i) {
		
		//TODO 
		discreteMC = DTMC(TransitionMatrix, 10, start);

		++hist[std::round(discreteMC.back())];

		for (auto elem : discreteMC) {

			std::cout << elem << ", ";
			myfile << elem << ", ";
		}
		std::cout << std::endl;
		myfile << std::endl;
	}
	//Returns an array discreteMC with the states at each step of the discrete-time Markov Chain
	//The number of transitions is given by steps. The initial state is given by start 
	//(the states are indexed from 0 to n-1 where n is the number of arrays in transMatrix).
	//hist is the histogram 


	// (double)p.second / N    - (decimal) percentage.
	for (auto p : hist) {
		std::cout << p.first << "\t" << (double)p.second / N << std::endl;
	}

	myfile.close();

	return 1;
}