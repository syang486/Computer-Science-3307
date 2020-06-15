//File Name: fileManager.cpp
//Student Name: Shulan Yang
//Student Number: 250976767
//Date: Oct 3rd, 2019

#include <string>
#include <iostream>
#include "fileManager.h"

using namespace std;

// Rmoves the given files listed as parameters to this command
int main(int argc, char* argv[]){
	for (int i = 1; i < argc ; i++){
		fileManager file = fileManager(argv[i]);
		cout << "sign :" << file.fileManager_Remove() << "\n";
	};
	return 0;
};
