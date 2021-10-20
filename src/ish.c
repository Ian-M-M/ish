#include "debug.h"
#include "liner.h"
#include "parser.h"
#include "ish.h"


int main(int argc, char *argv[]) {
	/**
	* infinite loop
	* 	read command line
	*	parse line read into the following:
	*		- found multiple commands
	*		- acknowledge the differents pipe communications
	*		- execute the commands
	*/
	int i, j;
	char *  line = (char * ) malloc(sizeof(char) * ISH_MAX_STR_SIZE + 1);
	if (line == NULL){
		printf("[ERROR] can't allocate a line.\n");
		return -1;
	}
	for (i = 0; i < ISH_MAX_STR_SIZE; i++){
		*(line + i) = '0';
	}
	*(line + i) = '\0';
	sprintf(debugMsg, "%s: line size (%zu), line: \n%s", __func__, strlen(line), line);
	DPRINTF(debugMsg);
	char ** cmds = (char **) malloc(sizeof(char) * ISH_MAX_CMD_SIZE * ISH_MAX_STR_SIZE + 1);
	if (cmds == NULL){
		printf("[ERROR] can't allocate cmds.\n");
		return -1;
	}
	DPRINTF("cmds created");
	for (i = 0; i < ISH_MAX_CMD_SIZE; i++){
		for (j = 0; j < ISH_MAX_STR_SIZE; j++){
			*(cmds + (i * ISH_MAX_CMD_SIZE) + j) = "0";
			// printf("[DEBUG]: 4 i[%d] j[%d] pointer [%d]\n", i, j, (i * ISH_MAX_CMD_SIZE) + j);
		}
		*(cmds + (i * ISH_MAX_CMD_SIZE) + j) = '\0';
	}
	DPRINTF("cmds filled");	
	#ifndef DEBUG_ON
		clearScreen();
	#endif

	while (1){
		if (readLine(line) != 0) continue;
		sprintf(debugMsg, "readed line %s", line);
		DPRINTF(debugMsg);	
		if (parseLine(line, cmds) != 0) continue;
		printf("[PARSE LINE]:\n");
		for (i = 0; i < ISH_MAX_CMD_SIZE; i++){
			for (j = 0; j < ISH_MAX_STR_SIZE; j++){
				printf("[%d] %s\n", i, *(cmds + (i * ISH_MAX_CMD_SIZE) + j));
				if (*(cmds + (i * ISH_MAX_CMD_SIZE) + j) == "0") break;
			}
		}
		// pipeline();
		// execute();
	}
	return 0;

}
