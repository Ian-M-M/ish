#ifndef ISH_DEBUG
#define ISH_DEBUG

#define DEBUG_ON

#ifdef DEBUG_ON

#define DPRINTF(data) do{                               \
    debug_ish(data);                                      \
} while (0);

#else //!DEBUG_ON

#define DPRINTF(data) do{} while (0)

#endif //DEBUG_ON

#include <stdio.h>
void debug_ish(char * data){
    if (data != NULL){
        printf("[DEBUG] %s\n", data);
    }
}

#endif //ISH_DEBUG