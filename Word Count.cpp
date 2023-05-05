#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstring>
int main(int argc, const char *argv[]) {
	if (argc != 3) {
		printf("Usage: %s filename (-c | -w)\n", argv[0]);
		return -1;
	}

	FILE *fp;
	if ((fp = fopen(argv[1], "r")) == NULL) {
		printf("Cannot open file %s\n", argv[1]);
		return -1;
	}

	int count = 0;
	if (strcmp(argv[2], "-c") == 0) { // ͳ���ַ���
		char c;
		while ((c = fgetc(fp)) != EOF) {
			count++;
		}
	} else if (strcmp(argv[2], "-w") == 0) { // ͳ�Ƶ�����
		char c;
		int state = 0; // 0��ʾ�հ�״̬��1��ʾ�е���
		while ((c = fgetc(fp)) != EOF) {
			if (isspace(c) || c == ',') {
				if (state == 1) {
					count++;
					state = 0;
				}
			} else {
				state = 1;
			}
		}
		if (state == 1) { // ������һ������
			count++;
		}
	} else {
		printf("Invalid command!\n");
		return -1;
	}

	fclose(fp); // �ر��ļ�ָ��
	printf("%d\n", count); // ������
	return 0;
}
