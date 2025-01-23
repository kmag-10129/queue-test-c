#include "pch.h"
#include <string>

extern "C" {
#include "../queue-c/Queue.h"
	queue queue_test;
}

using namespace std;

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

	// next test is to return the first element of the queue
	// MODIFIED TEST TO USE REFACTORED ELEM FUNCTION
	TEST(QueueAdd, t_ReturnFirstElement) {
		EXPECT_EQ(queue_add(&queue_test, "apple"), Q_SUCCESS);
		string test = (char*)queue_getelem(&queue_test, 'f'); // requires the type cast to turn the raw pointer info to a char array into a string for comparison
		EXPECT_EQ("apple", test); // slightly modified test because a direct compare will compare pointer info which will be different.
	}

	// next test is to return the LAST element in the queue
	// MODIFIED TEST TO USE REFACTORED ELEM FUNCTION
	TEST(QueueAdd, t_ReturnLastElement) {
		EXPECT_EQ(queue_add(&queue_test, "banana"), Q_SUCCESS);
		string test = (char*)queue_getelem(&queue_test, 'l'); // requires the type cast to turn the raw pointer info to a char array into a string for comparison
		EXPECT_EQ("banana", test); // slightly modified test because a direct compare will compare pointer info which will be different.
	}
}
