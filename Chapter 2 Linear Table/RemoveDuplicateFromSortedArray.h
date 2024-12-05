#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;

/*
* 
* Given a sorted array, remove the duplicates in place such that each element appear only once
* and return the new length.
* Do not allocate extra space for another array, you must do this in place with constant memory.
* For example, Given input array A = [1,1,2],
* Your function should return length = 2, and A is now [1,2].
* 
*/

class RemoveDuplicateFromSortedArray
{
public:
	int mySolution(vector<int>& num);
	int refSolution1(vector<int>& num);
	int refSolution2(vector<int>& num);
	int refSolution3(vector<int>& num);
	void test();
};