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
        strncpy_s(dir, argv[1], sizeof(dir) - 1);
        dir[sizeof(dir) - 1] = '\0';
    } else {
        homeDir = getenv("HOME");
        if (homeDir != NULL) {
            strncpy_s(dir, homeDir, sizeof(dir) - 1);
            dir[sizeof(dir) - 1] = '\0';
        } else {
            strncpy_s(dir, "/", sizeof(dir) - 1);
        }
    }
    snprintf_s(cmd, sizeof(cmd), "ls \"%s\"", dir);

    fp = popen(cmd, "r");
    if (fp == NULL) {
        fprintf_s(stderr, "Failed to invoke: %s\n", cmd);
        return -1;
    }
    while ((bytesRead = fread(buff, 1, sizeof(buff) - 1, fp)) > 0) {
        buff[bytesRead] = '\0';
        printf_s("%s", buff);
    }

    if (ferror(fp)) {
        fprintf_s(stderr, "Error reading from command\n");
        pclose(fp);
        return -1;
    }

    pclose(fp);
    return 0;
}