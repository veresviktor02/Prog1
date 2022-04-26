#include <stdio.h>

void f(char p[], int x)
{
    printf("p: %s, x: %d\n", p, x);
}

int main()
{
    printf("Hello, World!\n");

    char p1[] = "Hello";
    char p2[] = "World!";

    printf("%s, %s\n", p1, p2);

    f("foo", 7);

    return 0;
}

/*
    1. Write a “Hello, World!” program in C, compile it, and run it.
    2. Define two variables holding “Hello” and “World!” respectively; concatenate them with a space in between; and output them as Hello World! .
    3. Define a C function that takes a char* parameter p and an int parameter x and print out their values in this format: p is "foo" and x is 7 .
Call it with a few argument pairs.
*/