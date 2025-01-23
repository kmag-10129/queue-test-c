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

	// next test is to check the size of the queue
	// note this is when it is empty
	TEST(QueueSize, t_CheckQueueSize) {
		EXPECT_EQ(queue_size(&queue_test), 0);
	}


	// next test is to add an element to the end of the queue
	TEST(QueueAdd, t_AddOneElementToQueue) {
		EXPECT_EQ(queue_add(&queue_test, "apple"), Q_SUCCESS);
	}

}
