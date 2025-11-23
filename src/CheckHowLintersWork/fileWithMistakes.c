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
    size_t bytes_read = 0;
    const char* home_dir = NULL;

    // Обработка аргументов командной строки
    if (argc == 2) {
        strncpy(dir, argv[1], sizeof(dir) - 1);
        dir[sizeof(dir) - 1] = '\0'; // Гарантируем нуль-терминацию
    } else {
        home_dir = getenv("HOME");
        if (home_dir != NULL) {
            strncpy(dir, home_dir, sizeof(dir) - 1);
            dir[sizeof(dir) - 1] = '\0';
        } else {
            strncpy(dir, "/", sizeof(dir) - 1);
        }
    }
    snprintf(cmd, sizeof(cmd), "ls \"%s\"", dir);

    fp = popen(cmd, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to invoke: %s\n", cmd);
        return -1;
    }
    while ((bytes_read = fread(buff, 1, sizeof(buff) - 1, fp)) > 0) {
        buff[bytes_read] = '\0';
        printf("%s", buff);
    }

    if (ferror(fp)) {
        fprintf(stderr, "Error reading from command\n");
        pclose(fp);
        return -1;
    }

    pclose(fp);
    return 0;
}