#include <stdio.h>

#define SUM 'a'+'z' //or 'b'+'y' or 'c'+'x'

int main(void)
{
    char input[5];

    scanf("%c%c%c%c%c", &input[0],
                        &input[1],
                        &input[2],
                        &input[3],
                        &input[4]);

    printf("%c%c%c%c%c\n", SUM-input[0],
                           SUM-input[1],
                           SUM-input[2],
                           SUM-input[3],
                           SUM-input[4]);

    return 0;
}
