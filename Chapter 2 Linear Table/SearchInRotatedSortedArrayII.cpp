#include "SearchInRotatedSortedArrayII.h"

bool SearchInRotatedSortedArrayII::searchInRotatedSortedArrayII(vector<int>& nums, int target)
{
	// This is used to solve the sorted array contains duplicate elements. e.g. [4,5,6,1,2,3,4,4,4]
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) return true;
		if (nums[mid] == nums[left]) left++; //遇到重复元素，跳过
		else if (nums[mid] > nums[left]) { //左边为有序
			if (target >= nums[left] && target < nums[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		else {
			if (target > nums[mid] && target <= nums[right]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
	}
	return false;
}

void SearchInRotatedSortedArrayII::test()
{
	vector<int> num1 = { 1,0,1,1,1 };
	vector<int> num2 = { 4,5,6,6,6,7,1,2,3 };
	vector<int> num3 = { 1,1,1,1 };
	vector<int> num4 = { 7,1,2,3,4,5,6 };
	vector<vector<int>> testData = { num1, num1, num2, num2, num3, num3, num4, num4 };
	vector<int> targets = { 0,2,6,8,1,0,2,9 };

	vector<bool> expectedResult = {true, false, true, false, true, false, true, false };
	for (int i = 0; i < testData.size(); i++)
	{
		bool actual = searchInRotatedSortedArrayII(testData[i], targets[i]);
		bool expect = expectedResult[i];
		if (actual == expect) {
			cout << "Test [" << i << "] PASSED" << endl;
		}
		else
		{
			cout << "Test [" << i << "] FAILED:" << actual << " != " << expect << endl;
		}
	}


	cout << "Done" << endl;
}