#include"log.h"
int main() {
    LOG_OPEN_REDIRECT();
    printf("hello\n");
    printf("hello test log\n");
    return 0;
}