#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

#include <string>
#include <iostream>

using namespace std;

/*
 * Judget the path is a folder or not.
 * 
 * Return 1 if is a folder, otherwise return 0
 * */
int IsFolder(const char *path);

/*
 * Copy file from src_path to dest_path
 *
 * Return 1 if succeed, otherwise return 0
 * */
int FileCopy(const char *src, const char *dest);

/*
 * Copy file to a folder.
 *
 * Return 1 if copy succeed, otherwise return 0.
 * */
int FileCopyToFolder(const char *file, const char* folder);

/*
 *  * Create a folder
 *   *
 *    * Return 1 if succeed, otherwise return 0.
 *     * */
int CreateFolder(const char *path);

/*
 * Copy folder to directory immediately.
 *
 * Return 1 if succeed, otherwise return 0.
 * */
int FolderCopy(const char *src, const char *dest);

/*
 * Copy directory to directory.
 *
 * Return 1 if succeed, otherwise return 0.
 * */
int FolderCopyToFolder(const char *src, const char *dest);

void listDir(char *path) {
	DIR             *pDir;
	struct dirent   *ent;
	int             i = 0;
	char            childpath[512];

	pDir = opendir(path);   
	memset(childpath, 0, sizeof(childpath));

	while((ent =readdir(pDir)) != NULL) {
		if(ent->d_type & DT_DIR) {

			if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") ==0 )
				continue;

			sprintf(childpath, "%s/%s", path, ent->d_name);
			printf("path:%s\n", childpath);

			listDir(childpath);
		}
		else
			cout<< ent->d_name << endl;
	}

}

int main(int argc, char *argv[]) {
	DIR *fp;
	struct dirent *ent;
	char path[512] = {0};
	fp = opendir(argv[1]);
	if (!fp)
		return 0;
	while((ent = readdir(fp)) != NULL) {
		if (ent->d_type & DT_DIR) {
			if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
				continue;
			sprintf(path, "%s/%s", argv[1], ent->d_name);
			if (access(path, F_OK) == 0) {
				if (IsFolder(path)) {
					FolderCopytoFolder(path, argv[2]);
				} else {
					FileCopy(path, argv[2]);
				}
			}
		}
	}
	return 0;
}

int IsFolder(const char *path) {
	DIR *dp;
	if ((dp = opendir(path)) == NULL)
		return 0;
	else {
		closedir(dp);
		return 1;
	}
}

int FileCopy(const char *src, const char *dest) {
	FILE *input, *output;
	char ch;
	if ((input = fopen(src, "r")) == NULL) {
		printf("The file %s is not exist!!\n", src);
		return -1;
	}
	if ((output = fopen(dest, "w")) == NULL) {
		fclose(input);
		printf("The output file %s Permmission denied!!", dest);
		return -2;
	}

	ch = fgetc(input);
	while(!feof(input)) {
		fputc(ch, output);
		ch = fgetc(input);
	}

	fclose(input);
	fclose(output);
	return 0;
}

int FileCopyToFolder(const char *src, const char *folder) {
	char fileName[500]; // src file name
	char fileDest[500]; // dest directory
	int i;
	int Length = strlen(file); // length of file name
	for(i = Length-1; i >= 0; i--)
	{
		if(file[i] == '/')
		{
			get the file name
				strncpy(fileName, file+i+1, Length-i);
			break;
		}
	}
	if(i <= -1) strcpy(fileName, file);
	// construct src complete path
	strcpy(fileDest, folder);
	strcat(fileDest, "/");
	strcat(fileDest, fileName);
	return FileCopy(file, fileDest);
}

int CreateFolder(const char *folder) {
	char folderPath[500];
	int i;
	int len;
	strcpy(folderPath, folder);
	len = strlen(folderPath);

	if (folderPath[len - 1] != '/') {
		strcat(folderPath, "/");
		len++;
	}

	for (i = 1; i < len; i++) {
		if (folderPath[i] == '/') {
			folderPath[i] = '\0';
			if (access(folderPath, F_OK) < 0) {
				if (mdkir(folderPath, 0755)) {
					printf("mkdir %s failed!", folderPath);
					return -1;
				}
			} else if (!IsFolder(folderPath)) {
				printf("%s is exists!");
				return -2;
			}
			folderPath[i] = '/';
		}
	}

	return 0;
}

int FolderCopy(const char *src, const char *dest) {
	DIR *dp;
	struct dirent *entry;
	char srcInside[500];
	char desInside[500];
	if((dp = opendir(src))  ==  NULL) {
		printf("%s is not a folder!\n", src);
		return -1;
	}

	if(CreateFolder(dest) != 0)
		return -2;
	while((entry = readdir(dp)) != NULL) {
		strcpy(srcInside, src);
		strcpy(desInside, dest);
		strcat(srcInside, "/");
		strcat(desInside, "/");
		strcat(srcInside, entry->d_name);
		strcat(desInside, entry->d_name);

		if(IsFolder(srcInside)) {
			if(!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
				continue;
			FolderCopy(srcInside, desInside);
		} else {
			FileCopy(srcInside, desInside);
		}
	}

	return 0;
}

int FolderCopytoFolder(const char *src, const char *dest) {
	DIR *dp;
	struct dirent *entry;
	char srcInside[500];
	char desInside[500];
	if((dp = opendir(src))  ==  NULL) {
		printf("%s is not a folder!\n", src);
		return -1;
	}

	if(CreateFolder(dest) != 0) return -2;
	while((entry = readdir(dp)) != NULL) {
		strcpy(srcInside, src);
		strcpy(desInside, dest);
		strcat(srcInside, "/");
		strcat(desInside, "/");
		strcat(srcInside, entry->d_name);
		strcat(desInside, entry->d_name);

		if(IsFolder(srcInside)) {
			if(!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
				continue;
			FolderCopy(srcInside, desInside);
		}
		else {
			FileCopy(srcInside, desInside);
		}
	}

	return 0;
}
