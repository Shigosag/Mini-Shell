#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../include/colors.h"
#include "../include/command.h"

#define BUFFER_SIZE 1024

// ------------------------------
// TYPEWRITER EFFECT
// ------------------------------
void type_text(const char *text, int speed)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        putchar(text[i]);
        fflush(stdout);
        usleep(speed);
    }
}

// ------------------------------
// BRANDING BANNER
// ------------------------------
void show_banner(void)
{
    printf("\033[H\033[J"); // clear screen

    printf(HOT_PINK);

    type_text("========================================\n", 5000);
    type_text("  __  __ _       _   ____  _          _ _ \n", 2000);
    type_text(" |  \\/  (_)_ __ (_) / ___|| |__   ___| | |\n", 2000);
    type_text(" | |\\/| | | '_ \\| | \\___ \\| '_ \\ / _ \\ | |\n", 2000);
    type_text(" | |  | | | | | | |  ___) | | | |  __/ | |\n", 2000);
    type_text(" |_|  |_|_|_| |_|_| |____/|_| |_|\\___|_|_|\n", 2000);
    type_text("========================================\n", 5000);

    printf(RESET);

    printf("\n");
    printf(PINK "   MINI SHELL BY SHIGOSAG\n" RESET);
    printf(CYAN "   Lightweight C Terminal Engine\n" RESET);
    printf(GREEN "   Type 'help' | 'exit' to quit\n\n" RESET);
}

// ------------------------------
// SHELL LOOP
// ------------------------------
void start_shell(void)
{
    char input[BUFFER_SIZE];

    show_banner();

    while (1)
    {
        printf(
            HOT_PINK "shigosag-shell > " RESET
        );

        if (!fgets(input, sizeof(input), stdin))
        {
            continue;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
        {
            printf(GREEN "Goodbye 👋\n" RESET);
            break;
        }

        if (strcmp(input, "clear") == 0)
        {
            printf("\033[H\033[J");
            continue;
        }

        execute_command(input);
    }
}