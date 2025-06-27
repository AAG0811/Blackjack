#include <stdio.h>
#include <unistd.h>

int main() {
    char values[] = {'/', '-', '\\', '|'};
    int index = 0;
    while (1) {
        printf("%c\r", values[index % 4]);
        fflush(stdout);
        usleep(100000);
        index++;
    }
}