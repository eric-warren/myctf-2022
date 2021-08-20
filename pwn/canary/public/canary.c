#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

__attribute__((constructor))
void setup() {
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
}

int main() {
    char name[32];
    char rating[32];
    printf("I need your name before I can tell a joke\n");
    fgets(name, sizeof(name), stdin);
    printf("Thanks, ");
    printf(name);
    printf("\n");

    printf("\nWhat’s a hacker’s favorite season? ... Phishing season.\nPlease rate my joke\n");
    gets(rating);
    printf("That's great!\n");
}

void dont_look_at_me() {
    execve("/bin/sh", NULL, NULL);
}