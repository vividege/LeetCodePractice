#include "SearchInRotatedSortedArray.h"


int SearchInRotatedSortedArray::searchInRotatedSortedArray(vector<int>& nums, int target)
{
	int size = nums.size();
	int left = 0, right = size - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (target == nums[mid]) return mid;
		if (nums[left] <= nums[mid]) //左边为有序列
		{
			if (target >= nums[left] && target < nums[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		else //右边为有序数列
		{
			if (target > nums[mid] && target <= nums[right])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
	}
	return -1;
}


//利用递归的方法来实现
//定义一个helper先
int SearchInRotatedSortedArray::searchRecursiveHelper(vector<int>& nums, int left, int right, int target) 
{
	if (left > right) return -1;
	int mid = left + (right - left) / 2;
	int leftValue = nums[left];
	int midValue = nums[mid];
	int rightValue = nums[right];

	if (target == leftValue) return left;
	if (target == midValue) return mid;
	if (target == rightValue) return right;

	//如果左边为有序数列
	if (leftValue < midValue)
	{
		if (target > leftValue && target < midValue)
			return searchRecursiveHelper(nums, left+1, mid - 1, target);
		else
			return searchRecursiveHelper(nums, mid + 1, right-1, target);
	}
	else//如果右边为有序数列
	{
		if (target > midValue && target < rightValue)
			return searchRecursiveHelper(nums, mid+1, right-1, target);
		else
			return searchRecursiveHelper(nums, left+1, mid-1, target);
	}
}
int SearchInRotatedSortedArray::searchInRotatedSortedArrayRecursive(vector<int>& nums, int target)
{
	return searchRecursiveHelper(nums, 0, nums.size()-1, target);
}


void SearchInRotatedSortedArray::test()
{
	vector<int> num1 = { 1,2,3,4,5,6,7 };
	vector<int> num2 = { 4,5,6,7,1,2,3 };
	vector<int> num3 = { 2,3,4,5,6,7,1 };
	vector<int> num4 = { 7,1,2,3,4,5,6 };
	vector<vector<int>> testData = { num1, num1, num2, num2, num3, num3, num4, num4};
	vector<int> targets = {2,8,1,8,3,8,2,8};

	vector<int> expectedResult = { 1,-1,4,-1,1,-1,2,-1 };
	for (int i = 0; i < testData.size(); i++)
	{
		//int actual = searchInRotatedSortedArray(testData[i], targets[i]);
		int actual = searchInRotatedSortedArrayRecursive(testData[i], targets[i]);
		int expect = expectedResult[i];
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