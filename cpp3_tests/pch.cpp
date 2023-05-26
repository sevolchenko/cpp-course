//
// pch.cpp
//

#include "pch.h"
#include "../cpp3/Queue.h"
#pragma once

TEST(QueueTest, Size) {
	Queue<int> q;
	EXPECT_EQ(q.size(), 0);
	q.push(1);
	EXPECT_EQ(q.size(), 1);
	q.push(2);
	EXPECT_EQ(q.size(), 2);
}

TEST(QueueTest, Back) {
	Queue<int> q;
	q.push(1);
	EXPECT_EQ(q.back(), 1);
	q.push(2);
	EXPECT_EQ(q.back(), 2);
}

TEST(QueueTest, Empty) {
	Queue<int> q;
	EXPECT_TRUE(q.empty());
	q.push(1);
	EXPECT_FALSE(q.empty());
}

TEST(QueueTest, Front) {
	Queue<int> q;
	q.push(1);
	EXPECT_EQ(q.front(), 1);
	q.push(2);
	EXPECT_EQ(q.front(), 1);
}

TEST(QueueTest, Pop) {
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.pop();
	EXPECT_EQ(q.front(), 2);
}

TEST(QueueTest, Push) {
	Queue<int> q;
	q.push(1);
	EXPECT_EQ(q.front(), 1);
	q.push(2);
	EXPECT_EQ(q.back(), 2);
}