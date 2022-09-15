#include <stdio.h>

int main(void)
{
    //[0] for input 'a' <-> 'z'
    //[1] for input 'b' <-> 'y'
    //...
    char mapping[26] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q',
                        'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g',
                        'f', 'e', 'd', 'c', 'b', 'a'};
    char input[6];//one for '\0'

    scanf("%s", input);

    printf("%c%c%c%c%c\n", mapping[(input[0]-'a')],
                           mapping[(input[1]-'a')],
                           mapping[(input[2]-'a')],
                           mapping[(input[3]-'a')],
                           mapping[(input[4]-'a')]);

    return 0;
}
