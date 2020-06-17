#pragma once
#include "Comps.h"
#include <assert.h>
#include "DynamicVector.h"
#include "Repository.h"
#include "Controller.h"
#include "Iterator.h"
#include "Comparator.h"

class Tests
{
public:
	static void testMovie();
	static void testRepository();
	static void testWatchlist();
	static void testController();
	static void testComparator();
	static void testAll();
};

