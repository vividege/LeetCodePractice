#include "MedianOfTwoSortedArray.h"

double MedianOfTwoSortedArray::findMedianSortedArray(vector<int>& nums1, vector<int>& nums2)
{
	/*
	* nums1: 1,2,3,4, ... ... i-1 | i ... ... m-1
	* nums2: 1,2,3,4,...j-1 | j .... .... .... ....n-1
	* 0 < m < n
	* 思路：
	*	> 假设 m<n，如果m>n，那么调换m和n
	*	> 两个排序数组，总能找到一条线分别在两组元素的i和j的位置，使得
	*		>> 这条线左边的所有元素都是不大于右边元素的
	*		>> 如果m+n是偶数，中位数=线左边所有数的最大值+线右边所有数的最小值/2.0
	*		>> 如果m+n是奇数，中位数 = 线左边所有数的最大值
	*	> 假设线在数组1的位置为i， 0<i<m, 那么j的位置为
	*   > j = (m+n)/2-i (m+n为偶数)
	*   > j = (m+n+1)/2 -i (m+n为奇数，并且令左边元素多一个)
	*	> 根据计算机整除的性质，j=(m+n+1)/2-i
	*	> 找到了i就找到了中位数
	*/
	int m = nums1.size(), n = nums2.size();
	if (m > n) {
		return findMedianSortedArray(nums2, nums1);
	}
	int left = 0, right = m;
	int leftMax = 0, rightMin = 0;
	while (left <= right) {
		int i = left + (right - left) / 2;
		int j = (m + n + 1) / 2 - i;
		int nums1_i_1	= i > 0 ? nums1[i - 1]	: INT_MIN;
		int nums1_i		= i < m ? nums1[i]		: INT_MAX;
		int nums2_j_1	= j > 0 ? nums2[j - 1]	: INT_MIN;
		int nums2_j		= j < n ? nums2[j]		: INT_MAX;

		//判断条件
		bool condition1 = nums1_i_1 <= nums2_j;
		bool condition2 = nums2_j_1 <= nums1_i;

		if (condition1 && condition2) { //已经找到了i, 只需要再找到线左边的最大值和右边的最小值
			leftMax = max(nums1_i_1, nums2_j_1);
			rightMin = min(nums1_i, nums2_j);
			break;
		}
		if (condition1) { 
			/*说明条件2不满足，那就是数组2的j元素太大，
				j应该变小，根据i, j的关系，i就应该变大，
				在i的右边去找，所以left应该向右移动
			*/
			left = i + 1;
		}
		else {
			right = i - 1; //在i的左边去找
		}
	}
	return (m + n) % 2 == 0 ? (leftMax + rightMin) / 2.0 : double(leftMax);
}

void MedianOfTwoSortedArray::test() {
	vector<int> num1 = { 1,2,3,7 };
	vector<int> num2 = { 4,5,6,8 };
	vector<int> num3 = { 2,3,4 };
	vector<int> num4 = { 5,6 };

	vector<vector<int>> testData1 = { num1, num1,num1, num2, num2,num3};
	vector<vector<int>> testData2 = { num2, num3,num4, num3, num4,num4 };
	vector<double> expetced = { 4.5,3.0, 4.0, 4.0, 5.5, 4.0};

	for (int i = 0; i < testData1.size(); i++) {
		double actual = findMedianSortedArray(testData1[i], testData2[i]);
		double expect = expetced[i];
		if (abs(actual - expect) < 0.001) {
			cout << "Test [" << i << "] PASSED" << endl;
		}
		else
		{
			cout << "Test [" << i << "] FAILED: "<<actual <<" - "<<expect <<" != "<<abs(actual - expect) << endl;
		}
	}
}
