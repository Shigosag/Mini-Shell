#include <stdio.h>
#include <time.h>

void log_command(const char *command)
{
    FILE *file = fopen("logs/shell.log", "a");

    if (!file)
        return;

    time_t now = time(NULL);

    fprintf(
        file,
        "[%lld] %s\n",
        (long long) now,
        command
    );

    fclose(file);
}