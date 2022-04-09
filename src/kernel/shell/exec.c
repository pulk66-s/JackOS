#include "exec.h"

/**
 * @brief function that must execute all commands that the user input in the shell
 * 
 * @param cmd : the command to be executed
 */
void exec(const char *cmd)
{
    char **args = split(cmd, " ");
    char *cmd_name = args[0];
    args++;

    if (strcmp(cmd_name, "setxkbmap")) {
        setxkbmap(args);
        kprint_at(COMMAND_EXECUTED, 0, ++shell.y, SET_COLOR(WHITE, BLACK));
    } else {
        kprint_at(UNKNOWN_CMD, 0, ++shell.y, SET_COLOR(WHITE, BLACK));
    }
}