//
// Created by 12854 on 2019-09-26.
//

#ifndef GROUP_PROJECT_FILEMANAGER_H
#define GROUP_PROJECT_FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
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
fstream myFile;
fileManager(string arg1);
struct stat status;
struct passwd {
    char   *pw_name;       /* username */
    char   *pw_passwd;     /* user password */
    uid_t   pw_uid;        /* user ID */
    gid_t   pw_gid;        /* group ID */
    char   *pw_gecos;      /* user information */
    char   *pw_dir;        /* home directory */
    char   *pw_shell;      /* shell program */
};
struct group {
    char   *gr_name;        /* group name */
    char   *gr_passwd;      /* group password */
    gid_t   gr_gid;         /* group ID */
    char  **gr_mem;         /* NULL-terminated array of pointers
                               to names of group members */
};
struct dirent *dir;


#endif //GROUP_PROJECT_FILEMANAGER_H
