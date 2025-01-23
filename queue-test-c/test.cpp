#include "pch.h"

extern "C" {
#include "../queue-c/Queue.h"
	queue queue_test;
}

namespace CQueue {
	
	// test to create a queue
	TEST(QueueCreate, t_SimpleQueueCreate) {
		EXPECT_EQ(queue_create(&queue_test), Q_SUCCESS);
	}

}
