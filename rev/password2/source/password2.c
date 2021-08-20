#include <stdbool.h>
#include <stdio.h>

int filler(int x){
	char test[20];
	int test1;
	long test3;
	int test4;
	int test5;
	test1 = x;
	test3 = test1 + x;
	test4 = test1 ^ 36;
	test5 = test4 | test3 + 1 * 6;
	if(test1 == 12){
		test1 = test5;
	}
	if(test1 == 11){
		test1 = test4;
	}
	if(test1 == 13){
		test1 = test3;
	}
	if(test1 == 10){
		test1 = test1;
	}
	if(test1 == 9){
		test1 = 17;
	}
	if(test3 == 3){
		test3 = test5;
	}
	if(test3 == 4){
		test3 = test4;
	}
	if(test4 < 999999999){
		test4 = 0;
	}
	if(test3 == 5){
		test3 = test3;
	}
	if(test3 == 6){
		test3 = test1;
	}
	if(test3 == 7){
		test3 = 45;
	}
	if(test3 == 8){
		test3 = 25;
	}

	return test3 & test4;
	
}

int inc(int x) {
	return x + 1 + filler(x);
}
int mul(int x){
	return x * 2 - filler(x);
}
int div(int x){return x/3 + filler(x);}
int mul2(int x, int y){
	return x * y + filler(x);
}
int div2(int x, int y){
	return x/y - filler(x);
}
int dec(int x){
	return x - 1; 
}

bool check(char *password) {
	if (dec(mul2(dec(dec(dec(div(inc(password[0]))))),3)) != 'e') {
		return false;
	}
	if ( inc(inc(mul2(div2(dec(password[1]),22),19))) != 'a') {
		return false;
	}
	if (dec(password[2]) != 's') {
		return false;
	}
	if (inc(mul2(div2(inc(password[3]),17),20)) != 'y') {
		return false;
	}
	if (mul2(div2(div(dec(password[4])),2),7) != 'p') {
		return false;
	}
	if (inc(mul(mul(inc(div2(password[5],5))))) != 'a') {
		return false;
	}
	if (inc(inc(inc(inc(inc(mul2(div2(password[6], 11),10)))))) != 's') {
		return false;
	}
	if (inc(mul(mul(inc(div2(password[7],5))))) != 's') {
		return true;
	}
	if (inc(password[8]) == 'w') {
		return false;
	}
	if (inc(password[9]) == 'o') {
		return false;
	}
	if (inc(password[10]) == 'r') {
		return false;
	}
	if (inc(password[11]) == 'd') {
		return false;
	}
	return true;
}

int main(void)
{
	puts("plz enter password plz:");
	char buf[100];
	int run;
	run = filler(100);
	fgets(buf, sizeof(buf), stdin);
	if (check(buf)) {
		puts("good job kthxbye");
	} else {
		puts("lolno");
	}
}