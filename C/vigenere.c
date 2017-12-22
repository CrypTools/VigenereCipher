#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 500
#define MAX_SIZE 20
#define DO_NOTHING 2
#define ENCODE 1
#define DECODE 0
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void vCipher(char* string, char* keyword, int action);
int keywordFix(char* string);

int main(int argc, char* argv[]) {

	char process[MAX_SIZE];
	char keyword[MAX_SIZE];
	int i;
	int action = DO_NOTHING;
	int retval = EXIT_SUCCESS;

	printf("Would you like to decode or encode text?\n");
	scanf("%s", &process);
	for (i = 0 ; process[i] ; i++) {
		process[i] = tolower(process[i]);
	}
	if (strcmp(process, "encode") == 0) {
		action = ENCODE;
	} else if (strcmp(process, "decode") == 0) {
		action = DECODE;
	} else {
		printf("Improper process.\nExiting...\n");
		retval =  EXIT_FAILURE;
	}
	if (retval == EXIT_SUCCESS) {
		printf("What is the keyword?\n");
		scanf("%s", &keyword);
		if ( keywordFix(keyword) ) {
			char text[MAX_STRING_SIZE];
			printf("Keyword read is %s\n", keyword);
			printf("What string would you like me to %s? The maximum size is %d characters.\n", process, MAX_STRING_SIZE);
			while (fgets(text, MAX_STRING_SIZE, stdin) != NULL);
			vCipher(text, keyword, action);
			fputs(text, stdout);
		} else {
			printf("Improper Keyword.\nExiting...\n");
			retval = EXIT_FAILURE;
		}
	}

	return retval;
}

int keywordFix(char* string) {
	char* i = string;
	char* j = string;
	while (*j != '\0') {
		*i = *j++;
		// Any non-alphabet characters will be overwritten by the next alphabet character.
		// lower case letters switches to capital. Keywords look cooler when all capped
		if ( ( *i >= 'a' ) && ( *i <= 'z' ) ) {
			*i = toupper(*i);
			i++;
		} else if ( ( *i >= 'A' ) && ( *i <= 'Z' ) ) {
			i++;
		}
	}
	*i = '\0';
	if (string[0] != '\0') {
		return 1;
	} else {
		return 0;
	}
}

// If just letters, *cipherText = [(*text-'A') + (*keyword-'A')] % 26 + 'A'   <---- We use this one.
// If all possible characters, range is ASCII CODE 32 ~ 126
// In that case, *cipherText = [(*text-' ') + (*keyword-'A')] % 95 + ' '
void vCipher(char* string, char* keyword, int action) {

	int i = 0;
	int len = strlen(keyword);
	char* str = string;
	char* key = keyword;
	if ( action == ENCODE) {
		while (*str != '\n' && *str != '\0') {
			//*str = ( (*str-' ')+(keyword[i%len]-'A') )%95 + ' ';
			if ( (*str >= 'a') && (*str <= 'z') ) {
				*str = ( (*str-'a')+(keyword[i%len]-'A') )%26 + 'a';
				i++;
			} else if ( (*str >= 'A') && (*str <= 'Z') ) {
				*str = ( (*str-'A')+(keyword[i%len]-'A') )%26 + 'A';
				i++;
			}
			str++;
		}
	} else if (action == DECODE) {
		while (*str != '\n' && *str != '\0') {
			if ( (*str >= 'a') && (*str <= 'z') ) {
				if ( *str-tolower(keyword[i%len]) >= 0 ) {
					*str = (*str-tolower(keyword[i%len]))+'a';
				} else {
					*str = 'z' + (*str-tolower(keyword[i%len])) + 1;
				}
				i++;
			} else if ( (*str >= 'A') && (*str <= 'Z') ) {
				if ( *str-keyword[i%len] >= 0 ) {
					*str = (*str-keyword[i%len])+'A';
				} else {
					*str = 'Z' + (*str-keyword[i%len]) + 1;
				}
				i++;
			}
			str++;

		}
	}

}




