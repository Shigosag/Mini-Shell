#include <stdlib.h>
#include <string.h>
#include "executor.h"

// -----------------------------
// BUILD COMMAND STRING SAFELY
// -----------------------------
static void build_command(Command cmd, char *buffer, size_t size)
{
    buffer[0] = '\0';

    // rebuild argv into command string
    for (int i = 0; cmd.argv[i] != NULL; i++)
    {
        strcat(buffer, cmd.argv[i]);
        strcat(buffer, " ");
    }

    // input redirection
    if (cmd.input_file)
    {
        strcat(buffer, "< ");
        strcat(buffer, cmd.input_file);
        strcat(buffer, " ");
    }

    // output redirection
    if (cmd.output_file)
    {
        strcat(buffer, "> ");
        strcat(buffer, cmd.output_file);
        strcat(buffer, " ");
    }

    // pipe (basic passthrough)
    if (cmd.has_pipe)
    {
        strcat(buffer, "| ");
        for (int i = cmd.pipe_index + 1; cmd.argv[i] != NULL; i++)
        {
            strcat(buffer, cmd.argv[i]);
            strcat(buffer, " ");
        }
    }
}

// -----------------------------
// EXECUTOR (CROSS PLATFORM SAFE)
// -----------------------------
void execute(Command cmd)
{
    char command[1024];
    build_command(cmd, command, sizeof(command));

    system(command);
}