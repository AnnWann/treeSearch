/*
this file implements treeOfFiles.h.
Made by: Uaná Gasparim GitHub: https://github.com/AnnWann
*/

#include <stdlib.h>
#include <stdio.h>
#include "..\lib\treeOfFiles.h"

//Helpers

//

FILE* getFileTree(void);

void getRoot(FILE* fileTree, char** root);

void createFileTree(char* root);

bool hasFileTree(void){
    const char *fname = "./fileTree.txt";
    FILE *fp = fopen(fname, "r");
    bool exists;
    return exists = (!fp) ? false : true;
    
}

