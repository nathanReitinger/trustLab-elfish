/** called before main
 */
 
#include <stdio.h>

__attribute__((constructor)) void function(void) 
{
    puts ("Penguin");
}

int main(int argc, char**argv)
{
    puts("Main");
    return 0;
}