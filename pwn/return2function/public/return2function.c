#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void super_secret_flag_reading_function_never_call_this()
{
  char flag[0x100] = {0};
  FILE *fp = fopen("./flag.txt", "r");
  if (!fp)
  {
    puts("Flag didnt load contact an admin");
    exit(-1);
  }
  fgets(flag, 0xff, fp);
  puts(flag);
  fclose(fp);
}

int main(void)
{
  char rating[32];

  setbuf(stdout, NULL);
  setbuf(stdin, NULL);
  setbuf(stderr, NULL);

  puts("Why didn’t the company move into the Castle in the Sky?");
  puts("There wasn’t enough cloud storage.");

  gets(rating);
}