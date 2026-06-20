cmake_minimum_required(VERSION 3.28)

project(
    MiniShell
    VERSION 2.0.0
    LANGUAGES C
)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(
    minishell
    src/main.c
    src/shell.c
    src/command.c
    src/parser.c
    src/executor.c
    src/history.c
    src/logger.c
)