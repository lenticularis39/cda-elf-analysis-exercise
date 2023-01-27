#include <stdio.h>
#include <string.h>

char correct_password[] = "C80@6qIVufh#";

int main() {
	char password[20];
	printf("Enter password: ");
	scanf("%20s", password);
	int result = strncmp(correct_password, password, sizeof(correct_password));
	if (result) {
		printf("Password is incorrect\n");
	} else {
		printf("Password is correct\n");
	}
}
