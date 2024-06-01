#pragma once

#include "UnitTestFramework.h"
#include "CircularList.h"

TEST_CASE("CircularList", CircularList_DefaultConstructor)
{
	const CircularList<int> list;
	Assert::IsTrue(list.empty());
}

TEST_CASE("CircularList", CircularList_PushBack)
{
	CircularList<int> list;
	list.push_back(1);

	CircularList<int>::iterator iter = list.begin();
	Assert::IsTrue(list.size() == 1 && *iter == 1);
}

TEST_CASE("CircularList", CircularList_CopyConstructor)
{
	CircularList<int> list;
	for (int i = 1; i <= 10; ++i)
	{
		list.push_back(i);
	}

	int current = 1;

	const CircularList<int> copy = list;
	Assert::AreEqual(list.size(), copy.size());

	CircularList<int>::const_iterator iter = copy.begin(), end = iter;
	do
	{
		Assert::AreEqual(*iter, current);
		++iter;
		++current;
	} 
	while (iter != end);
}

TEST_CASE("CircularList", CircularList_Insert)
{
	CircularList<int> list;

	CircularList<int>::iterator iter = list.begin();
	list.insert(iter, 1);

	Assert::AreEqual(list.size(), 1);
	
	iter = list.begin();
	
	list.insert(iter, 0);
	Assert::AreEqual(list.size(), 2);

	iter = list.begin();
	Assert::AreEqual(*iter, 0);
}

TEST_CASE("CircularList", CircularList_FindElement)
{
	CircularList<int> list;
	Assert::IsFalse(find(list, 1));

	for (int i = 1; i <= 10; ++i)
	{
		list.push_back(i);
	}

	Assert::IsTrue(find(list, 3));
	Assert::IsFalse(find(list, 11));
}

TEST_CASE("CircularList", CircularList_EraseAllEqualTo)
{
	CircularList<int> list;

	for (int i = 1; i <= 10; ++i)
	{
		list.push_back(3);
	}

	eraseAllEqualTo(list, 3);
	Assert::IsTrue(list.empty());

	for (int i = 1; i <= 5; ++i)
	{
		list.push_back(i);
		list.push_back(i);
	}

	eraseAllEqualTo(list, 3);
	Assert::IsFalse(find(list, 3));
}
