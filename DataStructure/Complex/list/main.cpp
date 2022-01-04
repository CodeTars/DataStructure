#include <stdio.h>
#include <stdlib.h>

struct stu {
	int num;
	int age;
	struct stu *next;
};

stu* creat(int n) {
	stu *head = NULL, *last_one, *cur;
	for (int i = 0; i < n; i++) {
		cur = (stu *) malloc(sizeof(stu));
		scanf("%d %d", &cur->num, &cur->age);
		cur->next = NULL;
		if (i == 0) {
			head = cur;
		} else {
			last_one->next = cur;
		}
		last_one = cur;
	}
	return head;
}

void append(stu *p) {
	while(p->next) p = p->next;
	stu *cur = (stu *) malloc(sizeof(stu));
	

}
void print(stu *p) {
	while(p) {
		printf("num = %d, age = %d\n", p->num, p->age);	
		p = p->next;	
	}
}

void destroy(stu *p) {
	while(p) {
		stu *q = p->next;
		free(p);
		p = q;
	}	
}

int main() {
	stu *head;
	head = creat(3);
	print(head);	
	append(head);
	destroy(head);
	return 0;
}
