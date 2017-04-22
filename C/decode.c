#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char* decode(char** code, int h, int w);
void filter(char* code, int length, char* fwords[], int num_of_fwords);
int main() {
	int height = 0, width = 0, num_of_fwords;
	scanf("%d%d", &height, &width); getchar();
	char **code = (char **)malloc(sizeof(char *) * height);
	for (int n = 0; n < height; n++) {
		code[n] = (char *)malloc(sizeof(char) * width);
	}
	for (int a = 0; a < height; a++) {
		for (int b = 0; b < width; b++) {
			char temp = getchar();
			if (temp != '\n')
				code[a][b] = temp;
			else
				scanf("%c", &code[a][b]);
		}
	}
	scanf("%d", &num_of_fwords);
	char* fwords[10];
	for (int a = 0; a < num_of_fwords; a++) {
		fwords[a] = (char*)malloc(sizeof(char) * 30);
		scanf("%s", fwords[a]);
	}
	char *_decode = decode(code, height, width);
	int length = width * height;
	filter(_decode, length, fwords, num_of_fwords);
	for (int n = 0; n < height; n++)
		free(code[n]);
	free(code);
	for (int n = 0; n < num_of_fwords; n++)
		free(fwords[n]);
	free(_decode);
	return 0;
}

char* decode(char **code, int h, int w) {
	char *_decode = (char *)malloc(w * h);
	int re_h = h, re_w = w, n = -1, i = 0;
	int re_1 = -1, re_2 = 0;
	int j = 0;
	while (1) {
		if (n + 1 == re_h)
			break;
		for (n = n + 1; n < re_h; n++) {
			_decode[j++] = code[n][i];
			printf("%c", code[n][i]);
		}
		n--;
		if (i + 1 == re_w)
			break;
		for (i = i + 1; i < re_w; i++) {
			_decode[j++] = code[n][i];
			printf("%c", code[n][i]);
		}
		i--;
		if (n - 1 == re_1)
			break;
		for (n = n - 1; n > re_1; n--) {
			_decode[j++] = code[n][i];
			printf("%c", code[n][i]);
		}
		n++;
		if (i - 1 == re_2)
			break;
		for (i = i - 1; i > re_2; i--) {
			_decode[j++] = code[n][i];
			printf("%c", code[n][i]);
		}
		i++;
		re_h--;
		re_w--;
		re_1++;
		re_2++;
	}
	printf("\n");
	return _decode;
}
void filter(char* code, int length, char* fwords[], int num_of_fwords) {
	for (int n = 0; n < length; n++) {
		for (int i = 0; i < num_of_fwords; i++) {
			int j = 0, r = n;
			while (code[r] == fwords[i][j]) {
				r++;
				j++;
				if (j == strlen(fwords[i]))
					break;
			}
			if (j == strlen(fwords[i])) {
				for (int i = n + 1; i < r; i++)
					code[i] = '*';
				n = r - 1;
				break;
			}
		}
	}
	for (int n = 0; n < length; n++)
		printf("%c", code[n]);
	printf("\n");
}