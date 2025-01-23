#include "pch.h"
#include <string>

extern "C" {
#include "../queue-c/Queue.h"
	queue queue_test;
}

using namespace std;

namespace CQueue {

	// test to create a queue
	// todo: modify to allow existing data as inputs
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

	// new test added to try adding multiple elements to the end of the queue 
	TEST(QueueAdd, t_AddMultiElementToQueue) {
		EXPECT_EQ(queue_add(&queue_test, "banana"), Q_SUCCESS);
		EXPECT_EQ(queue_add(&queue_test, "cherry"), Q_SUCCESS);
	}

	// next test is to return the first element of the queue
	// MODIFIED TEST TO USE REFACTORED ELEM FUNCTION
	TEST(QueueReturn, t_ReturnFirstElement) {
		queue_add(&queue_test, "apple"), Q_SUCCESS; // fills the queue as a prerequisite for testing
		string test = (char*)queue_getelem(&queue_test, 'f'); // requires the type cast to turn the raw pointer info to a char array into a string for comparison
		EXPECT_EQ("apple", test); // slightly modified test because a direct compare will compare pointer info which will be different.
	}

	// next test is to return the LAST element in the queue
	// MODIFIED TEST TO USE REFACTORED ELEM FUNCTION
	TEST(QueueReturn, t_ReturnLastElement) {
		queue_add(&queue_test, "banana"); // fills the queue as a prerequisite for testing
		queue_add(&queue_test, "cherry");
		string test = (char*)queue_getelem(&queue_test, 'l'); // requires the type cast to turn the raw pointer info to a char array into a string for comparison
		EXPECT_EQ("cherry", test); // slightly modified test because a direct compare will compare pointer info which will be different.
	}

	// next test is to perform the dequeue (remove the FIRST element in the queue)
	TEST(QueueRemove, t_Dequeue) {
		queue_add(&queue_test, "apple"); // fills the queue as a prerequisite for testing
		EXPECT_EQ(queue_remove(&queue_test), Q_SUCCESS); // should pass if we are not trying to remove from an empty queue. 
	}

	// next test is to perform the dequeue (remove the FIRST element in the queue) then check the new first element
	TEST(QueueRemove, t_DequeueAndCheckFirstElement) {
		queue_add(&queue_test, "banana"); // fills the queue as a prerequisite for testing
		queue_add(&queue_test, "cherry");
		EXPECT_EQ(queue_remove(&queue_test), Q_SUCCESS); // should pass if we are not trying to remove from an empty queue. 
		string test = (char*)queue_getelem(&queue_test, 'f'); // requires the type cast to turn the raw pointer info to a char array into a string for comparison
		EXPECT_EQ("cherry", test); // slightly modified test because a direct compare will compare pointer info which will be different.
	}

	// next test is to destroy the queue object
	TEST(QueueExit, t_DestroyQueue) {
		EXPECT_EQ(queue_destroy(&queue_test), Q_SUCCESS);
	}
}
