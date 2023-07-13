/*
This file implements parser.h. 
created by: Uaná Gasparim / https://github.com/AnnWann
*/

#include "..\lib\parser.h"

void parsePath(char** pathParsed, char *path, bool status)
{
    uint32_t index = 0;
    uint32_t lastBreak = 0;
    for(index; index < (uint32_t)(strlen(path)); index++){
            if(path[index] == '\\'){

                pathParsed[lastBreak] = malloc((index - lastBreak + 1) * sizeof(char));
                memcpy(&pathParsed[lastBreak], &path[lastBreak], sizeof(*pathParsed[lastBreak]));
            }
            lastBreak = index;
        }
}