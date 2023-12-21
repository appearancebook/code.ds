#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void testQueue()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 9);
	QueuePush(&q, 18);
	QueuePush(&q, 27);
	QueuePush(&q, 36);

	printf("%d ", QueueSize(&q));

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	QueueDestroy(&q);
}

int main()
{
	testQueue();
	return 0;
}