#pragma once
#include <vector>
#include <iostream>
using namespace std;

/*
* 
* Follow up for ”Remove Duplicates”: What if duplicates are allowed at most twice?
* For example, Given sorted array A = [1,1,1,2,2,3],
* Your function should return length = 5, and A is now [1,1,2,2,3]
* 
*/

class RemoveDuplicatesFromSortedArrayII
{
public:
	int removeDuplicatesMy(vector<int>& nums);
	int removeDuplicatesRef1(vector<int>& nums);
	int removeDuplicatesRef2(vector<int>& nums);
	void test();
};

