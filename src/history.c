#include <stdio.h>
#include <string.h>

#define MAX_HISTORY 100

static char history[MAX_HISTORY][256];
static int count = 0;

void add_history(const char *command)
{
    if (count < MAX_HISTORY)
    {
        strcpy(history[count++], command);
    }
}

void show_history(void)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, history[i]);
    }
}