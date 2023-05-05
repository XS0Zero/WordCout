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
	if (strcmp(argv[2], "-c") == 0) { // 统计字符数
		char c;
		while ((c = fgetc(fp)) != EOF) {
			count++;
		}
	} else if (strcmp(argv[2], "-w") == 0) { // 统计单词数
		char c;
		int state = 0; // 0表示空白状态，1表示有单词
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
		if (state == 1) { // 检查最后一个单词
			count++;
		}
	} else {
		printf("Invalid command!\n");
		return -1;
	}

	fclose(fp); // 关闭文件指针
	printf("%d\n", count); // 输出结果
	return 0;
}
