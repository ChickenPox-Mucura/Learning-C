#include <stdio.h>
#include <stdlib.h>
int strindex(char s[], char t[]);
/* Exercício 4-1 */

int main(void)
{
	char pat[4] = "old";
	char string[25] = "i am old but not cold";
	int index;

	index = strindex(string, pat);
	printf("%d\n", index);

	return EXIT_SUCCESS;
		
}

int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; ++i) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
			;
		if (s[j] != '\0')
			;
		else if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
