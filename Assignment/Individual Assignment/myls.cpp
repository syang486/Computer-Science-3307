//File Name: fileManager.cpp
//Student Name: Shulan Yang
//Student Number: 250976767
//Date: Oct 3rd, 2019

#include <string>
#include <iostream>
#include <dirent.h>
#include "fileManager.h"

using namespace std;

//format output for the information of files
void output(char* child){
	fileManager childfile = fileManager(child);
	struct stat status;
	stat(child,&status);
	childfile.getPermission();
	printf(" ");
	childfile.getLink();
	printf(" ");
	childfile.getOwnerName();
	printf(" ");
	childfile.getGroupName();
	printf(" ");
	cout << childfile.getSize1() << " ";
	childfile.getMod();
	cout << child << "\n";
};

// List the contents of the directory and othe types of files and show the file name
// If "-l" command occurs, display the information of directory or files as well.
int main(int argc, char* argv[]){
	//consider the situation of "ls" command and execute it
	if (argc == 1 && argv[1] == NULL){
		char currentDir[255];
		getcwd(currentDir,255);
		fileManager file = fileManager(currentDir);
		file.getChild();
		return 0;
	};
	
	//consider the situation of "ls filename","ls filename1 filename2...",
	//"ls dirname","ls dirname1 dirname2..." command 
	if (argc >1 && memcmp(argv[1], "-l", 2) != 0){
		struct stat status;
		for (int i = 1; i <argc;i++){
			if (stat(argv[i], &status) == -1){
				perror("stat");
				exit(EXIT_FAILURE);
			};
		};
		if((status.st_mode & S_IFMT) == S_IFREG){
			for(int i = 1; i<argc;i++){
				 printf("%s\n", argv[i]);
			 };
			 return 0;
		};
		if((status.st_mode & S_IFMT) == S_IFDIR){
			if(argc >2){
				for (int i = 1; i<argc;i++){
					printf("%s\n",argv[i]);
					fileManager file = fileManager(argv[i]);
					file.getChild();	
				};
				return 0;
			}else{
				fileManager file = fileManager(argv[1]);
				file.getChild();
				return 0;
			};
		};
	};
	
	//consider "ls -l" command and execute it
	if (argc == 2 && memcmp(argv[1], "-l", 2) == 0){
		char currentDir[255];
		getcwd(currentDir, 255);
		
		fileManager file = fileManager(currentDir);
		vector<char*> child = file.getChild1();
		int childSize = file.getChild1().size();
		int i = 0;
		while(i < childSize){
			fileManager childfile = fileManager(child[i]);
			struct stat status;
			stat(child[i], &status);
			if ((status.st_mode & S_IFMT) == S_IFREG){
				output(child[i]);
			};
			if ((status.st_mode & S_IFMT) == S_IFDIR){
				output(child[i]);
			};
			i = i + 1;
		};
	};
	//consider the situation of "ls -l filename","ls -l filename1 filename2...",
	//"ls -l dirname", "ls -l dirname1 dirname2..." command
	if (argc > 2 && memcmp(argv[1], "-l", 2) == 0){
		struct stat status;
		for (int i = 2; i <argc;i++){
			if (stat(argv[i], &status) == -1){
				perror("stat");
				exit(EXIT_FAILURE);
			};
		};
		if((status.st_mode & S_IFMT) == S_IFREG){
			for(int i = 2; i<argc;i++){
				 output(argv[i]);
			 };
			 return 0;
		};
		if((status.st_mode & S_IFMT) == S_IFDIR){
			for(int i = 2; i<argc;i++){
				fileManager file = fileManager(argv[i]);
				int num = file.getChild1().size();
				for (int i = 0; i < num ; i ++ ){
					output(file.getChild1()[i]);
				};
			};
			return 0;
		};
	};
	return 0;	
};
