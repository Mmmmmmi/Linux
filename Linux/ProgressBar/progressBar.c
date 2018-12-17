#include <stdio.h>
#include <unistd.h>
void Print()
{
    char bar[101] = {0};
    for (int i = 0; i < 100; i++) {
        bar[i] = '#';
        printf("\r");
        printf("\033[1;34m[%-100s] [%3d%%]\033[0m", bar, i + 1);
        fflush(stdout);
        usleep(50000);
    }
    printf("\n");
}


int main()
{

    Print();
    return 0;
}

