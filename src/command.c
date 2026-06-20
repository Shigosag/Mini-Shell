#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd
#else
#include <unistd.h>
#endif

#include "../include/history.h"
#include "../include/logger.h"
#include "../include/parser.h"

void execute_command(char *input)
{
    // -------------------------
    // BUILT-IN COMMANDS
    // -------------------------
    if (strcmp(input, "exit") == 0)
    {
        exit(0);
    }

    if (strcmp(input, "help") == 0)
    {
        printf("\nCommands:\n");
        printf("help     - Show commands\n");
        printf("pwd      - Current directory\n");
        printf("cd PATH  - Change directory\n");
        printf("history  - Show history\n");
        printf("clear    - Clear screen\n");
        printf("exit     - Quit shell\n\n");
        return;
    }

    if (strcmp(input, "history") == 0)
    {
        show_history();
        return;
    }

    if (strcmp(input, "pwd") == 0)
    {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)))
        {
            printf("%s\n", cwd);
        }
        return;
    }

    if (strncmp(input, "cd ", 3) == 0)
    {
        chdir(input + 3);
        return;
    }

    if (strcmp(input, "clear") == 0)
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        return;
    }

    // -------------------------
    // PARSER LAYER (FUTURE UPGRADE READY)
    // -------------------------
    Command cmd = parse_input(input);

    // NOTE:
    // Real pipe/redirection execution will come later (fork/exec version)
    // For now we still execute raw command safely via system()

    (void)cmd; // prevents unused warning

    system(input);

    // -------------------------
    // LOGGING
    // -------------------------
    add_history(input);
    log_command(input);
}