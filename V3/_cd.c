#include "ss_head.h"
/**
 * _cd - custom cd built-in, allows end-user to change directories
 * @input: the input line recieved
 *
 * Return: void
 */

void _cd(sll *head)
{
    char *user_dir = getenv("HOME"), *prev_dir = getenv("OLDPWD");
    char cur_dir[_BUFSIZ];
    size_t size = _BUFSIZ;

    if (_strcmp(head->str, "cd") == 0 && !head->next)
    {
        if (access(user_dir, F_OK) == 0)
            chdir(user_dir);
    }
    else if (_strcmp(head->next->str, "-") == 0)
    {
        chdir(prev_dir);
    }
    else if (_strcmp(head->next->str, ".") == 0)
    {
        getcwd(cur_dir, size);
        chdir(cur_dir);
    }
    else
    {
        getcwd(cur_dir, size);
        user_dir = _strcat(cur_dir, head->next->str);
        
        if (access(user_dir, F_OK) == 0)
        {
            chdir(user_dir);

            if (chdir(user_dir) == -1)
                perror("Error: ");
        }
        else if (access(user_dir, F_OK) == -1)
        {
            perror("Error: ");
        }
    }
}
