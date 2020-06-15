//File Name: fileManager.h
//Student Name: Shulan Yang
//Student Number: 250976767
//Date: Oct 3rd, 2019

#ifndef GROUP_PROJECT_FILEMANAGER_H
#define GROUP_PROJECT_FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <grp.h>
#include <dirent.h>
#include <errno.h>
using namespace std;


class fileManager{
    public:

			struct stat status;
			struct passwd *owner;
			struct group *grp;
			struct dirent *dir;
	//Initialize variable

	//Initialize function
	fileManager(char *fileName);
	string getName1(void);
	blksize_t getBlock1(void);
	off_t getSize1(void);
	vector<char*> getChild1(void);

	void getName(void);
	void getType(void);
	void getSize(void);
	void getOwnerID(void);
	void getOwnerName(void);
	void getGroupID(void);
	void getGroupName(void);
	void getPermission(void);
	void getAccess(void);
	void getMod(void);
	void getChange(void);
	void getBlock(void);
	void getChild(void);
	void getLink(void);

	~fileManager();
	int fileManager_Dump(fstream& other);
	int fileManager_Rename(char *newName);
	int fileManager_Remove(void);
	int fileManager_Compare(fileManager other);
	int fileManager_Expand(void);

private:
	char *fileName;
	off_t fileSize;
	mode_t filePermission;
	blksize_t fileBlock;
	int fileError;
	vector<char*> fileChildren;
	vector<char> permission;
	char a;


};

#endif //GROUP_PROJECT_FILEMANAGER_H
