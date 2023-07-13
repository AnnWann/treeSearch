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
    
    if two or more directories and or files inside the same directory start with the same letter:
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

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define success 1
#define error 0

void parsePath(char** pathParsed, char *path, bool status);