#include <stdio.h>
#include <string.h>

#define C(c) { if(password[i++] != c) goto end; }

int main() {
	char password[20];
	printf("Enter password: ");
	scanf("%20s", password);
	if (strnlen(password, 20) != 12) goto end;
	int i = 0;
	/* 9Mu7usiajwTJ */
	C('9') C('M') C('u') C('7') C('u') C('s') C('i') C('a') C('j') C('w') C('T') C('J')
	printf("Password is correct\n");
	return 0;
end:
	printf("Password is incorrect\n");
	return 0;
}
