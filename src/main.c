#include "liner.h"

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

	while (1){
		if (readLine(line) != 0) continue;
		printf("%s\n", line);
		// parseLine();
		// pipeline();
		// execute();
	}

	return 0;

}
