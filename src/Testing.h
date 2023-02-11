#include <genesis.h>

int assert(int condition, char *message)
{
    if (!condition)
    {
        //Crash program
       SYS_die("Game Over");
    }
}
