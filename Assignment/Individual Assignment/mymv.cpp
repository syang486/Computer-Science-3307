//File Name: fileManager.cpp
//Student Name: Shulan Yang
//Student Number: 250976767
//Date: Oct 3rd, 2019

#include <string>
#include <iostream>
#include "fileManager.h"

using namespace std;

// Move and rename files around
int main(int argc, char* argv[2]){
	if (argc < 2){
		fprintf(stderr, "not file name or directory: %s \n", argv[0]);
		exit(EXIT_FAILURE);
	};
	struct stat status1;
	struct stat status2;
	stat(argv[1], &status1);
	stat(argv[2], &status2);
	//if two files are regualr files, then rename the old file
	if ((status1.st_mode & S_IFMT) == S_IFREG){
		if ((status2.st_mode & S_IFMT) == S_IFREG){
			fileManager oldFile = fileManager(argv[1]);
			oldFile.fileManager_Rename(argv[2]);
		};
	};
	//if two files are directories, then rename the old directory and delete 
	// the original old directory 
	if ((status1.st_mode & S_IFMT) == S_IFDIR) {
		if ((status2.st_mode & S_IFMT) == S_IFDIR){
			fileManager oldFile = fileManager(argv[1]);
			fileManager deleteFile = fileManager(argv[1]);
			oldFile.fileManager_Rename(argv[2]);
			deleteFile.fileManager_Remove();
		};
	};
	return 0;
};
