#pragma once
#include <vector>
#include <iostream>

using namespace std;


class SearchInRotatedSortedArray
{
public:
		int searchInRotatedSortedArray(vector<int>& nums, int target);
		int searchInRotatedSortedArrayRecursive(vector<int>& nums, int target);
		void test();
private:
	int searchRecursiveHelper(vector<int>& nums, int left, int right, int target);
};

