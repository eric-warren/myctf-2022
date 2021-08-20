#include <stdio.h>
#include <string.h>
#include <stdlib.h>


const char *jokes[] = {
  "What’s a hacker’s favorite season? ... Phishing season.",
  "What do you call a turtle that surfs the dark web? ... A TORtoise",
  "How did the vegetable farmer sell his produce on the dark web? ... He used onion routing.",
  "What did the moderator say to kick off the IT speed dating session? ... Singles, sign on!",
  "Did you hear about the computer that kept rebooting? ... It was terminal.",
  "What’s a programmer’s least favorite Pixar movie? ... A Bug’s Life.",
  "How do programmers like their brownies? ... GUI",
};

int main(void)
{
  srand(time(0));
  int checker= 0;
  long joke_index = rand() % (sizeof(jokes) / sizeof(char *));
  char rating[32];
  
  setbuf(stdout, NULL);
  setbuf(stdin, NULL);
  setbuf(stderr, NULL);

  puts(jokes[joke_index]);
  puts("How was that joke? Could you give it a rating of 1-10?");

  gets(rating);

  if(checker == 0xEFBEADDE) {
    system("/bin/sh");
  }
}