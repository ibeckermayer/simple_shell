#include "ss_head.h"

void _cd(char *input)
{
    char *user_dir = getenv("HOME"), *prev_dir = getenv("OLDPWD");
    char cur_dir[_BUFSIZ];
    size_t size = _BUFSIZ;

    if (input[2] == '\0' || (input[2] == ' ' && !input[3]))
    {
        if (access(user_dir, F_OK) == 0)
            chdir(user_dir);
    }
    else if (_strcmp(input, "cd -") == 0)
    {
        chdir(prev_dir);
    }
    else if (_strcmp(input, "cd .") == 0)
    {
        getcwd(cur_dir, size);
        chdir(cur_dir);
    }
    else
    {
        getcwd(cur_dir, size);
        user_dir = _strcat(cur_dir, cut_off(input, 3));

        if (access(user_dir, F_OK) == 0)
        {
            chdir(user_dir);

            if (chdir(user_dir) == -1)
                printf("(chdir) Error: %s\n", strerror(errno));
        }
        else if (access(user_dir, F_OK) == -1)
        {
            printf("(access) Error: %s\n", strerror(errno));
        }
    }
}
