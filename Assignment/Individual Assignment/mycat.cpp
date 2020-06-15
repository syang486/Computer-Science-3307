//File Name: fileManager.cpp
//Student Name: Shulan Yang
//Student Number: 250976767
//Date: Oct 3rd, 2019

#include <string>
#include <iostream>
#include "fileManager.h"

using namespace std;

// Display the contents of all of the file given as parameter to the 
// command in terminal
int main(int argc, char* argv[]){
	fstream other;
	for (int i = 1; i < argc ; i++){
		fileManager file = fileManager(argv[i]);
		file.fileManager_Dump(other);
	};
	return 0;
};
