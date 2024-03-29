/*
 This file is tasked with the parsing of file to 
string and vice-versa. 
created by: Uaná Gasparim / https://github.com/AnnWann
*/

/*
    PARSING PRINCIPLE:

    format: 
        type of data + extension + Driver name + first letter first directory ... n directory
        + first letter of file.
        
        all of these are converted into a 4 bits hash based on their full name.
        Except for type of data, which is single bit to identify if the path is a directory (0) or 
        a file (1).
        in case of directory, extension gets replaced by 000.

    from:
        Driver:directory/Sdirectory2/Tdirectory3/file.extension
    to: 
        1extensionDriverdstf (not hashed)
    
    if two or more direct
    ories and or files inside the same directory start with the same letter:
        first letter will be followed by a number representative of that letters alphabetical order
        related to the others

    example
        in this folder of path <C:folder\:
            myFile.txt
            myOtherFolder
            masterClass
            mt.a

        each will be converted into:
            1txtCfm3
            0000Cfm4
            0000Cfm1
            0000Cfm2        
*/

#pragma once

#define success 1
#define error 0

#include <stdint.h>
#include <stdbool.h>

char **parsePath(char** parsedPath, char *path);

/*
    parsePath: 
    receives a disk path and a pointer of pointers to a char;
    parses the path into its atomic parts and stores it into the pointer of pointers;
        ex: C:Path\file.exe -> {C, Path, file, exe}
    reorders it so extension goes to the start of the array;
        ex: {C, Path, file, exe} -> {exe, C, Path, file}
    if no extension: Adds the no extension default number at start (000);
    returns the pointer of pointers it received.
*/

char *buildPathAbstraction(char** parsedPath, uint8_t lastIndex);

/* 
    buildPathAbstration: 
    receives a pointer of pointers to a char;
    checks if the first item is equal to '000';
    if true: 
        builds a string starting with 0 and the rest of the string as a 4 bit hash;
    if false: 
        builds a string starting with 1 and the rest of the string as a 4 bit hash;
    returns a pointer to a char.
*/

_Bool isFile(char* path);

_Bool isDir(char* path);