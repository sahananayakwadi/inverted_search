#include <stdio.h>
#include "types.h"

int get_index(char ch)
{
    if(ch >= 'a' && ch <= 'z')
    {
        return ch - 'a';
    }

    if(ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A';
    }

    return 26;
}