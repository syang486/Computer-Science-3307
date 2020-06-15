//File Name: fileManager.cpp
//Student Name: Shulan Yang
//Student Number: 250976767
//Date: Oct 3rd, 2019

#include <string>
#include <iostream>
#include "fileManager.h"

using namespace std;

// Compares two files named as parameters to this command with one another
// and reports if they are the same or different.
int main(int argc, char* argv[]){
	fileManager firstFile = fileManager(argv[1]);
	fileManager secondFile = fileManager(argv[2]);
	firstFile.fileManager_Compare(secondFile);
	return 0;
};
