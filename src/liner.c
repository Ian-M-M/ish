#include "liner.h"
#include "ish.h"

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
    printf("[DEBUG LINER.reader()] 1, line size => %zu\n", strlen(line));
    if (fgets(line, ISH_MAX_STR_SIZE, stdin) == NULL){
        return -1;
    }
    return 0;
} __always_inline

int readLine(char * line){
    if (printNames() != 0) return -1;
    if (printWorkD() != 0) return -2;
    printf("[DEBUG LINER] 1\n");
    if (reader(line) != 0) return -3;
    printf("[DEBUG LINER] 2\n");
    return 0;
}