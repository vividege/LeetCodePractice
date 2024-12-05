#include "RemoveDuplicatesFromSortedArrayII.h"

int RemoveDuplicatesFromSortedArrayII::removeDuplicatesMy(vector<int> &nums)
{
	if (nums.size() < 3)
		return nums.size();
	int counter = 1;
	int index = 0;
	int MAX = 2;
	for (int mover = 1; mover < nums.size(); mover++)
	{
		if (nums[index] != nums[mover])
		{
			nums[++index] = nums[mover];
			counter = 1;
		}
		else
		{
			if (++counter <= MAX)
			{
				nums[++index] = nums[mover];
			}
		}
	}

	return index+1;
}

int RemoveDuplicatesFromSortedArrayII::removeDuplicatesRef1(vector<int>& num)
{
	if (num.size() <= 2)
		return num.size();

	int index = 2; //
	for (int i = 2; i < num.size(); i++)
	{
		//如果第i个元素和index往前数2个元素不同，那么index向后移动，
		if (num[i] != num[index - 2])
		{
			num[index++] = num[i];
		}
	}
	return index;
}

int RemoveDuplicatesFromSortedArrayII::removeDuplicatesRef2(vector<int>& num)
{
	/*
	// 除去第一个元素和最后一个元素，看中间的每一个元素是否和它前后的元素相同，相同的话就不做任何操作，
	// 不同的话就把当前元素赋给Index位置
	*/

	int index = 0;
	for (int i = 0; i < num.size(); i++)
	{
		if (i > 0 && i < num.size() - 1 && num[i] == num[i - 1] && num[i] == num[i + 1])
			continue;
		num[index++] = num[i];
	}
	return index;
}

void RemoveDuplicatesFromSortedArrayII::test()
{
	vector<int> num1 = { 1,2,2,2,2,2 };
	vector<int> num2 = { 1,2,3 };
	vector<int> num3 = { 1 };
	vector<int> num4 = { };
	vector<int> num5 = { 1,1,1,1,2,2 };
	vector<int> num6 = { 1,2,3,3,3,3,4 };
	vector<int> num7 = { 1,1,3,3,3,4,4,5,5};
	vector<vector<int>> testData = { num1, num2, num3, num4, num5, num6,num7 };

	vector<int> expectedResult = { 3,3,1,0,4,5,8 };
	for (int i = 0; i < testData.size(); i++)
	{
		//int actual = removeDuplicatesMy(testData[i]);
		//int actual = removeDuplicatesRef1(testData[i]);
		int actual = removeDuplicatesRef2(testData[i]);
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