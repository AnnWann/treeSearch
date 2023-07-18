/*
this file implements treeOfFiles.h.
Made by: Uaná Gasparim GitHub: https://github.com/AnnWann
*/

#include <stdlib.h>
#include <stdio.h>
#include "..\lib\treeOfFiles.h"

const char *fname = "./fileTree.txt";
    
//Helpers

//

FILE* getFileTree(void){
    return fopen(fname, "r");    
}

void getRoot(FILE* fileTree, char** root);

void createFileTree(char* root);

bool hasFileTree(void){
    FILE *fp = fopen(fname, "r");
    bool exists = false;
    return exists = (!fp) ? false : true;    
}

