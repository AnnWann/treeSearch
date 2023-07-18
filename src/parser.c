/*
This file implements parser.h. 
created by: Uaná Gasparim / https://github.com/AnnWann
*/

#include "..\lib\parser.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

//helpers:

void cpySection(char ***parsedPath, char *path, uint8_t limit, uint8_t start, uint8_t parsedPathIndex);

char **swap(char** ptrOfPtr, uint8_t pos1, uint8_t pos2);

void swapHeadAndTail(char ***ptrOfPtr, uint8_t lastPosition);

//functions:

char **parsePath(char** parsedPath, char *path){

    #define remainder (uint8_t)(strlen(path) - index - 1)
    const char *defaultExtension = "000"; 
    uint8_t index = 0, parsedPathIndex = 0, lastBreak = 0;

    for(index; index < (uint8_t)(strlen(path)); index++)
    {
        switch(path[index]){
            case '\\':
                cpySection(&parsedPath, path, index, lastBreak, parsedPathIndex); //add content before the "\"
                lastBreak = index + 1;
                parsedPathIndex++;
                break;
            case ':':
                cpySection(&parsedPath, path, index, lastBreak, parsedPathIndex); //add content before the ":"
                lastBreak = index + 1;
                parsedPathIndex++;
                break;
            case '.':
                cpySection(&parsedPath, path, index, lastBreak, parsedPathIndex); //add content before the "."
                parsedPathIndex++;
                cpySection(&parsedPath, path, index+remainder+1, index+1, parsedPathIndex); //add content after the "."

                //switch places between first and last item
                swapHeadAndTail(&parsedPath, parsedPathIndex);     
                goto exitLoop;
        }
    }

    cpySection(&parsedPath, path, index, lastBreak, parsedPathIndex); //add remaining content
    parsedPathIndex++;
    cpySection(&parsedPath, defaultExtension, 2, 0, parsedPathIndex); //add default 

    //switch places between first and last item
    swapHeadAndTail(&parsedPath, parsedPathIndex);

    exitLoop:

    return parsedPath;
}

char *buildPathAbstraction(char** parsedPath, uint8_t lastIndex){

    _Bool type = strcmp(parsedPath[0], "000") == 0 ? 0 : 1; //check if it is file or directory
    size_t totalLength = 0;

    for (uint8_t i = 0; i <= lastIndex; i++) {
        totalLength += strlen(parsedPath[i]);
    }
    totalLength += lastIndex; // Account for separators
    totalLength++; // Account for null terminator

    char *str = malloc(totalLength * sizeof(char));
    if (str == NULL) {return NULL;}

    //build string
    switch(type){
        case 0:
            str[0] = '0';
            for(uint8_t i = 0; i < lastIndex; i++) strcat(str, parsedPath[i]);
            break;
        case 1:
            str[0] = '1';
            for(uint8_t i = 0; i < lastIndex; i++) strcat(str, parsedPath[i]);
            break;
    }

    return str;
}

void cpySection(char ***parsedPath, char *path, uint8_t limit, uint8_t start, uint8_t parsedPathIndex) {
    char *section = malloc(sizeof(char) * (limit - start));
    memcpy(section, path + start, limit - start);
    section[limit - start] = '\0';
    *parsedPath = realloc(*parsedPath, (limit + 2) * sizeof(char *));
    (*parsedPath)[parsedPathIndex] = section;
}

char **swap(char** ptrOfPtr, uint8_t pos1, uint8_t pos2){
    char *temp = malloc(
        sizeof(pos1 >= pos2 ? pos1 : pos2)
        );
    memcpy(temp, ptrOfPtr[pos1], strlen(ptrOfPtr[pos1]));
    temp[strlen(ptrOfPtr[pos1])] = '\0';
    memcpy(ptrOfPtr[pos1], ptrOfPtr[pos2], strlen(ptrOfPtr[pos2]));
    ptrOfPtr[pos1][strlen(ptrOfPtr[pos2])] = '\0';
    memcpy(ptrOfPtr[pos2], temp, strlen(temp));
    ptrOfPtr[pos2][strlen(temp)] = '\0';     
    return ptrOfPtr;                
}

void swapHeadAndTail(char ***ptrOfPtr, uint8_t lastPosition){
    swap(*ptrOfPtr, 0, lastPosition);
    for(int i = 1; i < lastPosition; i++){
        *ptrOfPtr = swap(*ptrOfPtr, i, lastPosition);
    }
}