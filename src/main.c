#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "../lib/parser.h"
#include "../lib/treeOfFiles.h"
#include "../lib/scan.h"
#include "../lib/search.h"

int main(void)
{
    char* root = NULL, *path = NULL, *searchResult = NULL, *command;
    uint8_t answer = 0;
    if(hasFileTree()){
        appLoop:
        FILE *fileTree = getFileTree();
        
        if(root == NULL || strlen(root) == 0) getRoot(fileTree, &root);

        while(1){
            printf("root: %s\nDo you want to search on this root?\n1: Yes\n2: No\n0: Quit\n", root);
            scanf("%hhu", &answer);

            switch(answer){
                case 1:
                    printf("Enter the file/directory you want to find: ");
                    path = malloc(256 * sizeof(char));
                    scanf("%255s", path);
                    search(&path,  fileTree, &searchResult);
                    free(path);
                    if(searchResult == NULL || strlen(searchResult) == 0){
                        printf("There is no such path");
                    }else{
                        command = malloc(sizeof(searchResult));
                        sprintf(command, "start \"%s\"", searchResult);
                        system(command);
                        free(command);
                        free(searchResult);
                    }
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
        createFileTree(root);
        goto appLoop;
    }

    return 0;
}
