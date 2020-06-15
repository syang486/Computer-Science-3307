//File Name: fileManager.cpp
//Student Name: Shulan Yang
//Student Number: 250976767
//Date: Oct 3rd, 2019

#include "fileManager.h"
#include <string.h>


    //Constructor
    fileManager::fileManager(char *arg){
	fileName = arg;
	fileSize = status.st_size;
	fileBlock = status.st_blksize;
        fileManager_Expand();
	fileError = 0;
	permission = {0};
    };

    //Return file name
    string fileManager::getName1(void){
	return fileName;
    };

    //Return block size of file
    blksize_t fileManager::getBlock1(void){
	return fileBlock;
    };

    //Return size of file
    off_t fileManager::getSize1(void){
	return fileSize;
    };

    //Return return the child of dictory
    vector<char*> fileManager::getChild1(void){
	return fileChildren;
    };



    //Output the name of file
    void fileManager::getName(void){
	printf("File: %s\n", fileName);
    };

    //Output the type of file
    void fileManager::getType(void){
	struct stat status;
	stat(fileName,&status);
	printf("Type : ");
	switch (status.st_mode & S_IFMT) {
	case S_IFDIR:  printf("directory\n");     	 break;
	case S_IFCHR:  printf("character device\n");     break;
	case S_IFIFO:  printf("FIFO/pipe\n");            break;
	case S_IFLNK:  printf("symlink\n");              break;
	case S_IFREG:  printf("regular file\n");         break;
	case S_IFSOCK: printf("socket\n");               break;
	case S_IFBLK:  printf("block device\n");         break;
	default:       printf("unknown?\n");    	 break;
	};
    };

    //Output the size of file
    void fileManager::getSize(void){
	struct stat status;
	stat(fileName,&status);
	printf("Size: %lld\n", (long long) status.st_size);
    };

    //Output the owner ID of file
    void fileManager::getOwnerID(void){
	struct stat status;
	stat(fileName,&status);
	printf("OwnerID: %u\n", status.st_uid);
    };

    //Output the owner name of file
    void fileManager::getOwnerName(void){
	struct stat status;
	stat(fileName,&status);
	struct passwd *owner;
	owner = getpwuid(status.st_uid);
	printf("%s", owner->pw_name);
    };

    //Output the group ID of file
    void fileManager::getGroupID(void){
	struct stat status;
	stat(fileName,&status);
	printf("GroupID: %u\n", status.st_gid);
    };

    //Output the group name of file
    void fileManager::getGroupName(void){
	struct stat status;
	stat(fileName,&status);
	struct group *group;
	group = getgrgid(status.st_gid);
	printf("%s", group->gr_name);
    };

    //Output the permission of file
    void fileManager::getPermission(void){
	struct stat status;
	stat(fileName,&status);
	if ((status.st_mode & S_IFMT) == S_IFDIR) {
	    a = 'd';
	    permission.push_back(a);
	}else if ((status.st_mode & S_IFMT) == S_IFCHR) {
	    a = 'c';
	    permission.push_back(a);
	}else if ((status.st_mode & S_IFMT) == S_IFIFO) {
	    a = 'p';
	    permission.push_back(a);
	}else if ((status.st_mode & S_IFMT) == S_IFLNK) {
	    a = 'l';
	    permission.push_back(a);
	}else if ((status.st_mode & S_IFMT) == S_IFREG) {
	    a = '-';
	    permission.push_back(a);
	}else if ((status.st_mode & S_IFMT) == S_IFSOCK) {
	    a = 's';
	    permission.push_back(a);
	}else if ((status.st_mode & S_IFMT) == S_IFBLK) {
	    a = 'b';
	    permission.push_back(a);
	}else{
	    a = '?';
	    permission.push_back(a);
	};

	if (status.st_mode & S_IRUSR) {
	    a = 'r';
	    permission.push_back(a);
	}else {
	    a = '-';
	    permission.push_back(a);
	};
	if (status.st_mode & S_IWUSR) {
	    a = 'w';
	    permission.push_back(a);
	}else {
	    a = '-';
	    permission.push_back(a);
	};
	if (status.st_mode & S_IXUSR) {
	    a = 'x';
	    permission.push_back(a);
	}else {
	    a = '-';
	    permission.push_back(a);
	};
	if (status.st_mode & S_IRGRP) {
	    a = 'r';
	    permission.push_back(a);
	}else {
	    a = '-';
	    permission.push_back(a);
	};
	if (status.st_mode & S_IWGRP) {
	    a = 'w';
	    permission.push_back(a);
	}else {
	    a = '-';
	    permission.push_back(a);
	};
	if (status.st_mode & S_IXGRP) {
	    a = 'x';
	    permission.push_back(a);
	}else {
	    a = '-';
	    permission.push_back(a);
	};
	if (status.st_mode & S_IROTH) {
	    a = 'r';
	    permission.push_back(a);
	}else {
	    a = '-';
	    permission.push_back(a);
	};
	if (status.st_mode & S_IWOTH) {
	    a = 'w';
	    permission.push_back(a);
	}else {
	    a = '-';
	    permission.push_back(a);
	};
	if (status.st_mode & S_IXOTH) {
	    a = 'x';
	    permission.push_back(a);
	}else {
	    a = '-';
	    permission.push_back(a);
	};
	printf("%o (", status.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
	for (int i = 0; i< 11; i++){
	    cout << permission[i] ;
	};
	printf(")");
    };


    //Output the access time of file
    void fileManager::getAccess(void){
	struct stat status;
	stat(fileName,&status);
	printf("Access Time: %s", ctime(&status.st_atime));
    };

    //Output the modify time of file
    void fileManager::getMod(void){
	struct stat status;
	stat(fileName,&status);
	printf("%s", ctime(&status.st_mtime));
    };

    //Output the change time of file
    void fileManager::getChange(void){
	struct stat status;
	stat(fileName,&status);
	printf("Change Time :%s", ctime(&status.st_ctime));
    };

    //Output the block size of file
    void fileManager::getBlock(void){
	struct stat status;
	stat(fileName,&status);
	printf("Block Size: %ld\n", (long) status.st_blksize);
    };

    //Output the child of directory
    void fileManager::getChild(void){
	int size = fileChildren.size();
	for(int i = 0; i < size;i++){
	    cout << fileChildren[i] << "\t";
	};
	printf("\n");
    };

    //Output the link of file
    void fileManager::getLink(void){
	struct stat status;
	stat(fileName,&status);
	printf("%d", status.st_nlink);
    };

    //Destructor
    fileManager::~fileManager(){};

    //Dump function: take a file stream as a parameter and
    //dump the contents of the named file to that file stream
    int fileManager::fileManager_Dump(fstream& other){
	struct stat status;
	if (stat(fileName, &status) == -1){
	    perror("stat");
	    exit(EXIT_FAILURE);
	};
	if ((status.st_mode & S_IFMT) == S_IFREG){
	    string line;
	    unsigned int size;
	    unsigned int block;
	    ifstream myfile(fileName);
	    while (getline (myfile,line, '.')){
		size = (unsigned int)line.size();
		block = (unsigned int)status.st_blksize;
		//compare block size of two file, and the smaller block size
		//will determine the amount of data to be read form the file and
		//written to the file stream at a time
		while (size > block){
		    other << line.substr(0, status.st_blksize) << "\n";
		    cout << line << "\n";
		    line = line.substr(status.st_blksize);
		    size = (unsigned int)line.size();
		};
		other << line << "\n";
		cout << line << "\n";
	    };
	    myfile.close();
	    other.close();
	    fileError = 0;
	};
	if ((status.st_mode & S_IFMT) != S_IFREG){
	    fileError = -1;
	    printf("file is not regular.\n");
	};
	return fileError;
    };

    //Rename function: changes the name of file from its existing name to
    //the new name provided as a parameter to this function using rename()
    //system function
    int fileManager::fileManager_Rename(char *newName){
	int sign = rename(fileName, newName);
	if (sign == 0)printf("the rename operation is complete\n");
	if (sign == -1)printf("the rename operation is fail\n");
	return sign;
    };

    //Remove function: removes the file from the file system using unlink()
    //system function
    int fileManager::fileManager_Remove(){
	int sign = unlink(fileName);
	if (sign == 0)printf("the remove operation is complete\n");
	if (sign == -1)printf("the remove operation is fail\n");
	return sign;
    };

    //Compare function: takes another one of the file objects as a
    //parameter and will compare the contents of the file object
    //this function was invoked upon to this other file object
    int fileManager::fileManager_Compare(fileManager other){
	ifstream myfile(fileName);
	ifstream otherfile(other.getName1());
	string line1;
	string line2;
	if (!myfile.is_open() | !otherfile.is_open()){
	    fileError = -1;
	    cout << "the file cannot open.\n";
	    return fileError;
	};

	while (getline(myfile, line1)){
	    getline(otherfile, line2);
	    if (line2.empty()){
		fileError = -1;
		printf("the two file are different\n");
		return fileError;
	    };
	    if (line1 != line2){
		fileError = -1;
		printf("the two file are different\n");
		return fileError;
	    };
	};
	myfile.close();
	otherfile.close();
	printf("the two file are the same\n");
	return fileError;

    };


    //Expand function: operates on directories only and is used to fill
    //in the children of the file object this function was invoked upon.
    int fileManager::fileManager_Expand(void){
	if (stat(fileName, &status) == -1){
	    perror("stat");
	    exit(EXIT_FAILURE);
	};
	DIR *directory;
	directory = opendir(fileName);
	if (directory){
	    while ((dir = readdir(directory)) != NULL){
		fileChildren.push_back(dir->d_name);
	    };//find the child of directory and store them in to the vector
	    closedir(directory);
	};
	return fileError;
    };
