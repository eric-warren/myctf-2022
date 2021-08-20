#include <stdbool.h>
#include <stdio.h>


int inc(int x) {
	return x + 1;
}

bool check(char *password) {
	if (inc(password[0]) != 'x') {
		return false;
	}
	if (inc(password[1]) != 'f') {
		return false;
	}
	if (inc(password[2]) != 'b') {
		return false;
	}
	if (inc(password[3]) != 'l') {
		return false;
	}
	if (inc(password[4]) != 'q') {
		return false;
	}
	if (inc(password[5]) != 'b') {
		return false;
	}
	if (inc(password[6]) != 't') {
		return false;
	}
	if (inc(password[7]) != 't') {
		return false;
	}
	return true;
}

int main(void)
{
	puts("plz enter password plz:");
	char buf[100];
	fgets(buf, sizeof(buf), stdin);
	if (check(buf)) {
		puts("good job kthxbye");
	} else {
		puts("lolno");
	}
}