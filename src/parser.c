#include <string.h>
#include <stdlib.h>
#include "parser.h"

Command parse_input(char *line)
{
    Command cmd = {0};

    int i = 0;
    char *token = strtok(line, " ");

    while (token && i < MAX_ARGS - 1)
    {
        if (strcmp(token, ">") == 0)
        {
            token = strtok(NULL, " ");
            cmd.output_file = token;
        }
        else if (strcmp(token, "<") == 0)
        {
            token = strtok(NULL, " ");
            cmd.input_file = token;
        }
        else if (strcmp(token, "|") == 0)
        {
            cmd.has_pipe = 1;
            cmd.pipe_index = i;
        }
        else
        {
            cmd.argv[i++] = token;
        }

        token = strtok(NULL, " ");
    }

    cmd.argv[i] = NULL;
    return cmd;
}