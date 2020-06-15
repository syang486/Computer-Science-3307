//
// Created by 12854 on 2019-09-26.
//

#include "fileManager.h"
using namespace std;

class fileManager {

public:
    string fileName;
    unsigned int fileType;
    long long int fileSize;
    long int fileOwnerID;
    string fileOwnerName;
    long int fileGroupID;
    string fileGroupName;
    char *fileGroupName;
    unsigned int filePermission;
    string fileAccess;
    string fileChange;
    string fileModify;
    long digit fileBlcok;
    vector<string> fileChildren;
    int fileError;

    void fileManager(string arg1);
    void fileManager_Destructor(void);
    void fileManager_Dump(fstream fs);
    int fileManager_Rename(const char* newName);
    int fileManager_Remove(void);
    int fileManager_Compare(fstream other);
    int fileManager_Expand(void);
}

    void fileManager::fileManager(string arg1){
        fileName = arg1;
        if(status(fileName, &status) == -1){
            perror("stat");
            exit(EXIT_FAILURE);
        };
        fileType = status.st_mode;
        fileSize = status.st_size;
        fileOwnerID = status.st_uid;
        pwd owner = &getpwuid(status.st_uid);
        fileOwnerName = owner.pw_name;
        fileGroupID = status.st_gid;
        pwd group = &getgrgid(status.st_gid);
        fileGroupName = group.gr_name;
        filePermission = status.st_mode;
        fileAccess = ctime(&status.st_atime);
        fileModify = ctime(&status.st_mtime);
        fileChange = ctime(&status.st_ctime);
        fileBlock = status.st_blksize;
        DIR *d;
        d = opendir(".");
        if (d){
            while ((dir = readdir(d)) != NULL){
                fileChildren.push_back(dir->d_name);
            }
            closedir(d);
        }
        fileError = 0;

    }

    void fileManager::fileManager_Destructor(void) {
        ~fileManager();
}
    void fileManager::fileManager_Dump(fstream fs){

    }

    int fileManager::fileManager_Rename(const char *newName){
        fileName = newName;
    }

    int fileManager::fileManager_Remove(void){
        int a;
        fileManager_Destructor(void);
        a = unlink(fileName);
        return a;
    }

    int fileManager::fileManager_Compare(fileManager other){
        long int otherBlock = other.fileBlcok;
        if (otherBlock != fileBlcok) return 1;
        else return 0;
    }

    int fileManager::fileManager_Expand(void){

    }


}


