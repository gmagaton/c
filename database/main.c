#include <stdio.h>

const char *getfield(char *line, int num)
{
    const char *tok;
    for (tok = strtok(line, ";");
         tok && *tok;
         tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int main()
{
    FILE *file = fopen("FILE.csv", "r");
    if (file == NULL)
    {
        perror("FILE.csv does not exists");
        exit(1);
    }

    int campo = 3;
    char line[1024];
    int linei = 1;
    while (fgets(line, sizeof(line), file))
    {

        char *tmp = strdup(line);
        printf("Campo %i da linha %i: %s - Linha: %s\n", campo, linei, getfield(tmp, 3), line);
        free(tmp);
        linei++;
    }

    free(file);
}