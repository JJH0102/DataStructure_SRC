// 임의의 데이터를 큐에 저장할 수 있는 포괄형 프로그램

#include <stdio.h>
#include "queue.h"

int main(void)
{
	Queue q1, q2;
	int i;
	int re;
	double re2;
	double d;
	
	initQueue(&q1, 10, sizeof(int));			// queue1은 int형을 저장
	initQueue(&q2, 100, sizeof(double));	// queue2은 double형을 저장

	i = 100;			push(&q1, &i);
	i = 200;			push(&q1, &i);
	i = 300;			push(&q1, &i);	

	pop(&q1, &re);		printf("q1 1st pop() : %d\n", re);
	pop(&q1, &re);		printf("q1 2nd pop() : %d\n", re);
	pop(&q1, &re);		printf("q1 3rd pop() : %d\n", re);

	d = 1.1;			push(&q2, &d);
	d = 2.2;			push(&q2, &d);
	d = 3.3;			push(&q2, &d);	

	pop(&q2, &re2);			printf("q2 1st pop() : %f\n", re2);
	pop(&q2, &re2);			printf("q2 2nd pop() : %f\n", re2);
	pop(&q2, &re2);			printf("q2 3rd pop() : %f\n", re2);

	cleanupQueue(&q1);
	cleanupQueue(&q2);
	return 0;
}

