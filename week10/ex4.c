#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h> 
#include <dirent.h>
#include <sys/stat.h>

int main(){
	DIR *directory = opendir("tmp");
	if(directory == NULL) {
		return 1;
	}
	char name[100];
	struct stat st;
	struct dirent *dir;
	strcpy(name, "tmp/");
	while((dir = readdir(directory))!=NULL){
		stat(name,&st);
		strcat(name,dir->d_name);
		if(st.st_nlink > 1){
			printf("%s There is a link. Founded linkes:\n",dir->d_name);
			struct dirent *link;
			DIR *dir2 = opendir("tmp");
			while((link = readdir(dir2)) != NULL){
				if((link->d_ino == dir->d_ino) &(strcmp(link->d_name,dir->d_name)!=0)){
					printf("%s ",link->d_name);
				}
			}
			printf("\n");
		}
		else printf("%s no links\n", dir->d_name);
		strcpy(name,"tmp/");
	}
	return 0;
}

