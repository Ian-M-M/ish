#include "liner.h"

int readLine(char * line){
    if (fgets(line, ISH_MAX_STR_SIZE, stdin) == NULL){
        return -1;
    }
    return 0;
}