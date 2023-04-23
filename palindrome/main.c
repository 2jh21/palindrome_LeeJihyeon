#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAX_SIZE 100

typedef struct {
	char data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, char item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack Full!\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

char pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty!\n");
		return '\0';
	}
	else return s->data[(s->top)--];
}

char peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty!\n");
		return '\0';
	}
	else return s->data[(s->top)];
}

char Change(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c + 32;
	}
	else {
		return c;
	}
}

int Alpha(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(void) {
	StackType s;
	char str[MAX_SIZE];
	char answer[MAX_SIZE];
	int len, i, palindrome = 1;

	while (1) {
		printf("���ڿ��� �Է��Ͻÿ�: ");
		fgets(str, MAX_SIZE, stdin);

		len = strlen(str);
		init_stack(&s);

		for (i = 0; i < len; i++) {
			if (Alpha(str[i])) {
				push(&s, Change(str[i]));
			}
		}

		for (i = 0; i < len; i++) {
			if (Alpha(str[i])) {
				if (Change(str[i]) != pop(&s)) {
					palindrome = 0;
					break;
				}
			}
		}

		if (palindrome == 0) {
			printf("ȸ���� �ƴմϴ�.\n");
		}
		else {
			printf("ȸ���Դϴ�.\n");
		}

		while (1) {
			printf("\n��� �Է��Ͻðڽ��ϱ�?(Yes/No): ");
			scanf_s("%s", answer, MAX_SIZE);
			if ((answer[0] == 'y' || answer[0] == 'Y') && (answer[1] == 'e' || answer[1] == 'E') && (answer[2] == 's' || answer[2] == 'S')) {
				break;
			}
			else if ((answer[0] == 'n' || answer[0] == 'N') && (answer[1] == 'o' || answer[1] == 'O')) {
				break;
			}
			else {
				printf("\n�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
				continue;
			}
		}
		if ((answer[0] == 'n' || answer[0] == 'N') && (answer[1] == 'o' || answer[1] == 'O')) {
			break;
		}
		printf("\n");

		while (getchar() != '\n');
	}
	return 0;
}
