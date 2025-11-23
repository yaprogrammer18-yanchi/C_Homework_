#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char dir[1024] = { 0 };
    char cmd[1200] = { 0 };
    char buff[1024] = { 0 };
    FILE* fp = NULL;
    size_t bytesRead = 0;
    const char* homeDir = NULL;

    if (argc == 2) {
        snprintf(dir, sizeof(dir), "%s", argv[1]);
    } else {
        homeDir = getenv("HOME");
        if (homeDir != NULL) {
            snprintf(dir, sizeof(dir), "%s", homeDir);
        } else {
            snprintf(dir, sizeof(dir), "%s", "/");
        }
    }

    snprintf(cmd, sizeof(cmd), "ls \"%s\"", dir);

    fp = popen(cmd, "r");
    if (fp == NULL) {
        fputs("Failed to invoke command\n", stderr);
        return -1;
    }

    while ((bytesRead = fread(buff, 1, sizeof(buff) - 1, fp)) > 0) {
        buff[bytesRead] = '\0';
        printf("%s", buff);
    }

    if (ferror(fp)) {
        fputs("Error reading from command\n", stderr);
        pclose(fp);
        return -1;
    }

    pclose(fp);
    return 0;
}
}