#include "liner.h"

void clearScreen(){
    printf("%s", CLEAR_SCREEN_ANSI);
}

int printNames(){
    if (USER == NULL) return -1;
    printf("ish:%s@%s%s~", ISH_Green, USER, ISH_COLOR_RESET);
    return 0;
}

int printWorkD(){

    char wd [ISH_MAX_STR_SIZE];
    if (getcwd(wd, ISH_MAX_STR_SIZE) == NULL) return -1;
    printf("%s%s%s$ ",ISH_Blue, wd, ISH_COLOR_RESET);
    return 0;
}

int reader(char * line){
    // sprintf(debugMsg, "%s: reading new line:\n", __func__);
	// DPRINTF(debugMsg);
    char reader [ISH_MAX_STR_SIZE];
    char * error;
    error = fgets(reader, ISH_MAX_STR_SIZE + 1, stdin);
    if (error == NULL){
        return -1;
    }
    strcpy(line, reader);
    // sprintf(debugMsg, "%s: new line:\n%s", __func__, line);
	// DPRINTF(debugMsg);
    return 0;
} __always_inline

int readLine(char * line){
    if (printNames() != 0) return -1;
    if (printWorkD() != 0) return -2;
    if (reader(line) != 0) return -3;
    printf("[DEBUG LINER] 2\n");
    return 0;
}