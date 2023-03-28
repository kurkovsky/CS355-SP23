/*
A very basic implementation of ls:
list the names of all directory entries

Pseudocode:
    open directory
    while not end of directory
        read directory entry
        display entry info
    close directory
 */

#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

void mode_to_string(int mode, char str[]){
    strcpy(str,"----------");
    if(S_ISDIR(mode)) str[0]='d';
    if(S_ISCHR(mode)) str[0]='c';
    if(S_ISBLK(mode)) str[0]='b';
    if(S_ISLNK(mode)) str[0]='l';

    if(mode & S_IRUSR) str[1]='r';
    if(mode & S_IWUSR) str[2]='w';
    if(mode & S_IXUSR) str[3]='x';

    if(mode & S_IRGRP) str[4]='r';
    if(mode & S_IWGRP) str[5]='w';
    if(mode & S_IXGRP) str[6]='x';

    if(mode & S_IROTH) str[7]='r';
    if(mode & S_IWOTH) str[8]='w';
    if(mode & S_IXOTH) str[9]='x';
}

void show_dir_entry(char *dir_entry_name, struct stat *info){
    char modestring[11];
    mode_to_string(info->st_mode, modestring);
    printf("%s ", modestring);
    printf("%4d ", (int)info->st_nlink);
    printf("%8d ", (int) info->st_size);
    printf("%.20s ", ctime(&info->st_ctim.tv_sec));
    printf("%s\n", dir_entry_name);
}

void do_stat(char *dir_entry_name){
    struct stat info;
    if(stat(dir_entry_name, &info)==-1)
        perror(dir_entry_name);
    else
        //printf("stat: %s %d bytes\n", dir_entry_name, (int) info.st_size);
        show_dir_entry(dir_entry_name, &info);
}

// lists all entries of the given directory
void do_ls(char *dir_name) {
    DIR *dir_ptr;               // pointer to a directory structure
    struct dirent *dirent_ptr;  // pointer to the current directory entry
    dir_ptr = opendir(dir_name);
    // The line below if equivalent to this:
    // if(!dir_ptr) {
    if(dir_ptr==0) {            // opendir could fail, possibly because
        perror(dir_name);       // the directory does not exist
    }
    else {                      // iterate over all directory entries
        while((dirent_ptr=readdir(dir_ptr)) != 0) {
            //printf("Directrory entry: %s\n", dirent_ptr->d_name);
            do_stat(dirent_ptr->d_name);
        }
        closedir(dir_ptr);
    }
}

int main() {
    do_ls(".");                 // list the contents of the current directory
    return 0;
}
