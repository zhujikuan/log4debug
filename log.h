#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define LOG_FILE_PATH "./hello.log"
#define LOG_OPEN_REDIRECT()                                            \
    do {                                                               \
        int log_fd = open(LOG_FILE_PATH, O_RDWR | O_CREAT | O_APPEND); \
        if (log_fd == -1) {                                            \
            printf("can not open the file\n");                         \
            return 1;                                                  \
        }                                                              \
        dup2(log_fd, 1);                                               \
        dup2(log_fd, 2);                                               \
    } while (0);

#define LOG_FPRINTF_TO_FILE(format, ...)             \
    do {                                             \
        FILE *log_file = fopen(LOG_FILE_PATH, "a+"); \
        fprintf(log_file, format, ##__VA_ARGS__);    \
        fclose(log_file);                            \
    } while (0);
