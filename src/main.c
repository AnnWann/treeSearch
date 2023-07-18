#include <stdio.h>
#include <stdlib.h>
#include "../lib/parser.h"
#include "../lib/treeOfFiles.h"
#include "../lib/scan.h"
#include "../lib/search.h"

int main(void)
{
    char* root = NULL, path = NULL, searchResult = NULL;
    uint8_t answer = 0;
    if(hasFileTree()){
        FILE *fileTree = getFileTree();
        root = getRoot(fileTree);
        appLoop:
        while(1){
            printf("root: %s\nDo you want to search on this root?\n1: Yes\n2: No\n0: Quit\n", root);
            scanf("%hhu", &answer);
            switch(answer){
                case 1:
                    printf("Enter the file/directory you want to find: ");
                    scanf("%255s", path);
                    searchResult = search(path,  fileTree);
                    if(searchResult == NULL || searchResult == ""){
                        printf("There is no such path");
                    }else openPath(searchResult);
                    break;
                case 2: 
                    goto enterRoot;
                case 0:
                    printf("Program terminated :D");
                    return 0;
                default:
                    printf("Invalid value");
            }
        }
    }else{
        enterRoot:
        printf("Please enter the root of your search: ");
        scanf("%255s", root);
        createFileTree();
        goto appLoop;
    }

    return 0;
}
