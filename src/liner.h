#ifndef ISH_LINER
#define ISH_LINER

#define USER getenv("USER")

void clearScreen();

int printNames();

int printWorkD();

int reader(char * line);

int readLine(char * line);
#endif //ISH_LINER