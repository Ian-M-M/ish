#include "parser.h"

void parseCommands(char * line, char ** cmds){
    char * delim = "|";
    char * newCmd = (char *) malloc(sizeof(char) * ISH_MAX_STR_SIZE);
    newCmd = strtok(line, delim);
    *cmds = line;
    if (newCmd != NULL){
        int index = 1;
        while( (newCmd = strtok(NULL, delim)) != NULL){
            *(cmds + (ISH_MAX_STR_SIZE * index)) = newCmd;
            index++;
        }
    }
    

}

/**
 * < : input redirection
 * > : output redirection
 * | : connect output from first command with input of the second command
 */
int parseLine(char * line, char ** cmds){
    if (sizeof(line)/sizeof(char) <= 0){
        printf("[ERROR]: parsing line, size of cmd not enough");
        return -1;
    }
    
    char * delimiters = "|>";
    parseCommands(line, cmds);
}