//File Name: fileManager.cpp
//Student Name: Shulan Yang
//Student Number: 250976767
//Date: Oct 3rd, 2019

#include <string>
#include <iostream>
#include "fileManager.h"

using namespace std;

// This is used to make a copy of a file from a source to a destination 
// named as parameters to the command, and the dump method from above 
//should work nicely for this on its own.
int main(int argc, char* argv[2]){
	if (argc < 2){
		fprintf(stderr, "not file name or directory: %s \n", argv[0]);
		exit(EXIT_FAILURE);
	};
	int result = -1;
	struct stat status1;
	struct stat status2;
	stat(argv[1], &status1);
	stat(argv[2], &status2);
	//in order to copy the content of file to another file,
	//make sure two parameters are regular file
	if ((status1.st_mode & S_IFMT) == S_IFREG){
		if ((status2.st_mode & S_IFMT) == S_IFREG){
			fileManager oldFile = fileManager(argv[1]);
			fileManager newFile = fileManager(argv[2]);
			fstream other;
			other.open(newFile.getName1());
			result = oldFile.fileManager_Dump(other);
		};
	};
	if (result == -1){
		printf("the copy operation is fail\n");
		exit(EXIT_FAILURE);
	};
	if (result == 0){
		printf("the copy operation is completed\n");
	};
	return 0;
};
