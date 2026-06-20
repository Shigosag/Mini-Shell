#ifndef PARSER_H
#define PARSER_H

#define MAX_ARGS 64

typedef struct {
    char *argv[MAX_ARGS];
    char *input_file;
    char *output_file;
    int pipe_index;
    int has_pipe;
} Command;

Command parse_input(char *line);

#endif