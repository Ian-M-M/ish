#ifndef ISH_LINER
#define ISH_LINER

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// COLORS //
#define ISH_Black       "\033[0;30m"
#define ISH_Red         "\033[0;31m"
#define ISH_Green       "\033[0;32m"
#define ISH_Yellow      "\033[0;33m"
#define ISH_Blue        "\033[0;34m"
#define ISH_Purple      "\033[0;35m"
#define ISH_Cyan        "\033[0;36m"
#define ISH_White       "\033[0;37m"
#define ISH_COLOR_RESET "\033[0m"

#define ISH_MAX_STR_SIZE 100

#define USER getenv("USER")

/************************************
* @return: line read by command line*
*************************************/
int readLine(line);
#endif //ISH_LINER