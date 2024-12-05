#include "RemoveDuplicateFromSortedArray.h"

int RemoveDuplicateFromSortedArray::mySolution(vector<int>& num)
{
	if (num.size() <= 1)
		return num.size();

	int insert = 0;
	int mover = 1;
	for (;mover < num.size();mover++)
	{
		if (num[insert] != num[mover])
		{
			if (++insert != mover)
				num[insert] = num[mover];
		}
	}
	return insert+1;
	cout << "Doneoneoneone" << endl;
}

int RemoveDuplicateFromSortedArray::refSolution1(vector<int>& num)
{
	if (num.empty()) return 0;
	int index = 0;
	for (int i = 1; i < num.size(); i++)
	{
		if (num[index] != num[i])
			num[++index] = num[i];
	}
	return index+1;
}


int RemoveDuplicateFromSortedArray::refSolution2(vector<int>& num)
{
	//Utilize std::distance() function and std::unique() function
	//distance(begin, end): find the number of elements in [begin,end)
	//unique() is used to remove duplicates of any element present consecutively in a range[first, last), it returns an iterator
	vector<int>::iterator it = unique(num.begin(), num.end());

	return distance(num.begin(),it);
}


template<typename InIt, typename OutIt>
OutIt removeDuplicates(InIt first, InIt last, OutIt output)
{
	//upper_bound(first, last, value) is a built-in function used to find the first element in a sorted range 
	// that is strictly greater than a given value.

	while (first != last)
	{
		*output++ = *first;
		first = upper_bound(first, last, *first);
	}
	return output;
}
int RemoveDuplicateFromSortedArray::refSolution3(vector<int>& num)
{
	return distance(num.begin(), removeDuplicates(num.begin(), num.end(), num.begin()));
}

void RemoveDuplicateFromSortedArray::test()
{
	vector<int> num1 = { 1,2,2,2,2,2 };
	vector<int> num2 = { 1,2,3 };
	vector<int> num3 = { 1};
	vector<int> num4 = { };
	vector<int> num5 = { 1,1,1,1,2,2 };
	vector<int> num6 = { 1,2,3,3,3,3 };
	vector<vector<int>> testData = { num1, num2, num3, num4, num5, num6 };

	vector<int> expectedResult = { 2,3,1,0,2,3 };
	for(int i = 0; i<testData.size(); i++)
	{
		//int actual = mySolution(testData[i]);
		//int actual = refSolution1(testData[i]);
		int actual = refSolution3(testData[i]);
		int expect = expectedResult[i];
		if ( actual == expect) {
			cout << "Test ["<<i<<"] PASSED" << endl;
		}
		else
		{
			cout << "Test [" << i << "] FAILED:"<<actual<<" != " <<expect << endl;
		}
	}

	cout << "Done" << endl;
}