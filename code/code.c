#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

typedef struct customer {
	char name;
	int num;
}cus;

cus* cusdata;
void pop(char* x, int num, int re);

char a[100] = { NULL, };
char b[100] = { NULL, };
char c[100] = { NULL, };


int a_label = 0;
int b_label = 1;
int c_label = 2;

void main() {
	cusdata = (cus*)malloc(sizeof(cus));
	int cusnum;
	int goods;
	int i;
	int j;
	int k;

	printf("고객 수를 입력해주세요 : ");
	scanf_s("%d", &cusnum);

	for (i = 0; i < cusnum; i++) {
		cusdata[i].name = 97 + i;
		printf("\n%c 고객의 물건 수를 입력해주세요 : ", cusdata[i].name);
		scanf_s("%d", &goods);
		cusdata[i].num = goods;
		if (i == 0) {
			for (j = 0; j < cusdata[i].num; j++) {
				a[j] = cusdata[i].name;
			}
		}
		if (i == 1) {
			for (j = 0; j < cusdata[i].num; j++) {
				b[j] = cusdata[i].name;
			}
		}
		if (i == 2) {
			for (j = 0; j < cusdata[i].num; j++) {
				c[j] = cusdata[i].name;
			}
		}
	}

	int num;
	for (num = 0; num < cusnum; num++) {
		if (num == 0) {
			printf("\n\n");
			for (k = 0; k < cusdata[num].num; k++) {
				printf("%c ", a[k]);
			}
		}
		if (num == 1) {
			printf("\n\n");
			for (k = 0; k < cusdata[num].num; k++) {
				printf("%c ", b[k]);
			}
		}
		if (num == 2) {
			printf("\n\n");
			for (k = 0; k < cusdata[num].num; k++) {
				printf("%c ", c[k]);
			}
			printf("\n\n");
		}
	}
	
	int count = 0;
	int wait = 3;
	int a_num = cusdata[a_label].num;
	int b_num = cusdata[b_label].num;
	int c_num = cusdata[c_label].num;

	while (1) {
		a_num = cusdata[a_label].num; 
		b_num = cusdata[b_label].num; 
		c_num = cusdata[c_label].num;

		printf("\n\n");
		pop(a, a_label, a_num);
		pop(b, b_label, b_num);
		pop(c, c_label, c_num);

		count++;

		Sleep(200);

		if (a[0] == NULL || b[0] == NULL || c[0] == NULL) {
			if (a[0] == NULL) {
				if (wait < cusnum) {
					for (j = 0; j < cusdata[wait].num; j++) {
						a[j] = cusdata[wait].name;
					}
					a_label = wait;
					wait++;
				}
				else
					a[0] = NULL;
			}
			if (b[0] == NULL) {
				if (wait < cusnum) {
					for (j = 0; j < cusdata[wait].num; j++) {
						b[j] = cusdata[wait].name;
					}
					b_label = wait;
					wait++;
				}
				else
					b[0] = NULL;
			}
			if (c[0] == NULL) {
				if (wait < cusnum) {
					for (j = 0; j < cusdata[wait].num; j++) {
						c[j] = cusdata[wait].name;
					}
					c_label = wait;
					wait++;
				}
				else
					c[0] = NULL;
			}
			if (a[0] == NULL && b[0] == NULL) {
				if (wait < cusnum) {
					for (j = 0; j < cusdata[wait].num; j++) {
						a[j] = cusdata[wait].name;
					}
					a_label = wait;
					wait++;
				}
				else
					a[0] = NULL;
				if (wait < cusnum) {
					for (j = 0; j < cusdata[wait].num; j++) {
						b[j] = cusdata[wait].name;
					}
					b_label = wait;
					wait++;
				}
				else
					b[0] = NULL;
			}
			if (b[0] == NULL && c[0] == NULL) {
				if (wait < cusnum) {
					for (j = 0; j < cusdata[wait].num; j++) {
						b[j] = cusdata[wait].name;
					}
					b_label = wait;
					wait++;
				}
				else
					b[0] = NULL;
				if (wait < cusnum) {
					for (j = 0; j < cusdata[wait].num; j++) {
						c[j] = cusdata[wait].name;
					}
					c_label = wait;
					wait++;
				}
				else
					c[0] = NULL;
			}
			if (a[0] == NULL && c[0] == NULL) {
				if (wait < cusnum) {
					for (j = 0; j < cusdata[wait].num; j++) {
						a[j] = cusdata[wait].name;
					}
					a_label = wait;
					wait++;
				}
				else
					a[0] = NULL;
				if (wait < cusnum) {
					for (j = 0; j < cusdata[wait].num; j++) {
						c[j] = cusdata[wait].name;
					}
					c_label = wait;
					wait++;
				}
				else
					c[0] = NULL;
			}
			printf("\n\n");
			for (k = 0; k < cusdata[a_label].num; k++) {
				printf("%c ", a[k]);
			}
			printf("\n\n");
			for (k = 0; k < cusdata[b_label].num; k++) {
				printf("%c ", b[k]);
			}
			printf("\n\n");
			for (k = 0; k < cusdata[c_label].num; k++) {
				printf("%c ", c[k]);
			}
			printf("\n\n");

		} 
		if (a[0] == NULL && b[0] == NULL && c[0] == NULL) {
			if (wait >= cusnum) {
				printf(":: 계산 종료, 총 계산시간 %d분 ::", count);
				exit(1);
				break;
			}
			else if (wait < cusnum) {
				for (j = 0; j < cusdata[wait].num; j++) {
					a[j] = cusdata[wait].name;
				}
				a_label = wait;
				wait++;
				if (wait < cusnum) {
					for (j = 0; j < cusdata[wait].num; j++) {
						b[j] = cusdata[wait].name;
					}
					b_label = wait;
					wait++;
				}
				else
					b[0] = NULL;
				if (wait < cusnum) {
					for (j = 0; j < cusdata[wait].num; j++) {
						c[j] = cusdata[wait].name;
					}
					c_label = wait;
					wait++;
				}
				else
					c[0] = NULL;
			}
		}
	}
		
}
	



void pop(char* x, int num, int re) {
	int i;
	int k;

	for (i = 0; i < re; i++) {
		x[i] = x[i + 1];
	}
	for (k = 0; k < re - 1; k++) {
		printf("%c ", x[k]);
	}
	printf("\n\n");
	cusdata[num].num--;
}