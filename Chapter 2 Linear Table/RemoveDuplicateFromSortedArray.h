#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;

class RemoveDuplicateFromSortedArray
{
public:
	int mySolution(vector<int>& num);
	int refSolution1(vector<int>& num);
	int refSolution2(vector<int>& num);
	int refSolution3(vector<int>& num);
	void test();
};