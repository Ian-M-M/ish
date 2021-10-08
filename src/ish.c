#include "liner.h"
#include "parser.h"
#include "ish.h"

int main() {
        
	/**
	* infinite loop
	* 	read command line
	*	parse line read into the following:
	*		- found multiple commands
	*		- acknowledge the differents pipe communications
	*		- execute the commands
	*/
	char line [ISH_MAX_STR_SIZE];
	clearScreen();

	while (1){
		if (readLine(line) != 0) continue;
		printf("%s\n", line);
		// parseLine(line);
		// pipeline();
		// execute();
	}

	return 0;

}
