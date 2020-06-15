//File Name: fileManager.cpp
//Student Name: Shulan Yang
//Student Number: 250976767
//Date: Oct 3rd, 2019

#include <string>
#include <iostream>
#include "fileManager.h"

using namespace std;

// Outputs all of the information on the file named as a parameter 
// to this command.
int main(int argc, char* argv[]){
	struct stat status;
	if (argc < 2){
		fprintf(stderr, "not file name or directory: %s \n", argv[0]);
		exit(EXIT_FAILURE);
	};
	for (int i = 1; i < argc ; i++){
		if (stat(argv[i], &status) == -1){
			perror("stat");
			exit(EXIT_FAILURE);
		};
		fileManager file(argv[i]);
		//Output the informations
		file.getName();
		file.getType();
		file.getSize();
		file.getOwnerID();
		printf("OwnerName: ");
		file.getOwnerName();
		printf("\n");
		file.getGroupID();
		printf("GroupName: ");
		file.getGroupName();
		printf("\n");
		printf("Permission: "); 
		file.getPermission();
		printf("\n");
		file.getAccess();
		printf("Modify Time: ");
		file.getMod();
		file.getChange();
		file.getBlock();
		cout << "\n";
	};
	return 0;
};
