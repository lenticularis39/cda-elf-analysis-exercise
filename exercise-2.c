#include <stdio.h>
#include <string.h>

struct __attribute__((__packed__)) {
	char junk[6];
	char correct[12];
	char junk2[7];
} passwords __attribute__((section(".secretsection"))) = {
	.junk = "O6f84^",
	.correct = "40Vb9%FX59BO",
	.junk2 = "Wkne4G",
};

int main() {
	char password[20];
	printf("Enter password: ");
	scanf("%20s", password);
	int result = strncmp(passwords.correct, password, sizeof(passwords.correct));
	if (result) {
		printf("Password is incorrect\n");
	} else {
		printf("Password is correct\n");
	}
}
