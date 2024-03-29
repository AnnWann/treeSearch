/*
This file is tasked with building the graph tree responsible with
mapping the disk. 
Made by: Uaná Gasparim GitHub: https://github.com/AnnWann
*/

#include <stdio.h>
#include <stdbool.h>

FILE* getFileTree(void);

void getRoot(FILE* fileTree, char** root);

void createFileTree(char* root);

bool hasFileTree(void);