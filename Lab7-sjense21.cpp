// Lab7-sjense21.cpp : Defines the entry point for the console application.
// Sidney Jensen
// Lab 7
// 11/12/18

#include "stdafx.h"
#include "Lab7-sjense21.h"
#include "winTimer.h"
#include<algorithm>
#include<iostream>


using namespace std;

int main()
{
	Timer time;
	vector<short> bubble, insertion, selection,
		merge, quick, sorted;
	int temp = 0;

	cout << "enter size of vector for bubble sort: ";
	cin >> temp;
	add_numbers(bubble, temp);
	time.start();
	bubble_sort(bubble.begin(), bubble.end());
	time.stop();
	cout << "Time it took to sort: " << time() << endl;
	//cout << "Sorted list: " << endl;
	//print(bubble);
	cout << endl;

	Timer time1;
	cout << "enter size of vector for insertion sort: ";
	cin >> temp;
	add_numbers(insertion, temp);
	time1.start();
	insertion_sort(insertion.begin(), insertion.end());
	time1.stop();
	cout << "Time it took to sort: " << time1() << endl;
	//cout << "Sorted list: " << endl;
	//print(insertion);
	cout << endl;

	Timer time2;
	cout << "enter size of vector for selection sort: ";
	cin >> temp;
	add_numbers(selection, temp);
	time2.start();
	selection_sort(selection.begin(), selection.end());
	time2.stop();
	cout << "Time it took to sort: " << time2() << endl;
	//cout << "Sorted list: " << endl;
	//print(selection);
	cout << endl;

	Timer time3;
	cout << "enter size of vector for merge sort: ";
	cin >> temp;
	add_numbers(merge, temp);
	time3.start();
	mergesort(merge.begin(), merge.end());
	time3.stop();
	cout << "Time it took to sort: " << time3() << endl;
	//cout << "Sorted list: " << endl;
	//print(merge);
	cout << endl;

	Timer time4;
	cout << "enter size of vector for quick sort: ";
	cin >> temp;
	add_numbers(quick, temp);
	time4.start();
	quicksort(quick.begin(), quick.end());
	time4.stop();
	cout << "Time it took to sort: " << time4() << endl;
	//cout << "Sorted list: " << endl;
	//print(quick);
	cout << endl;

	Timer time5;
	cout << "enter size of vector for STL::sort: ";
	cin >> temp;
	add_numbers(sorted, temp);
	time5.start();
	sort(sorted.begin(), sorted.end());
	time5.stop();
	cout << "Time it took to sort: " << time5() << endl;
	//cout << "Sorted list: " << endl;
	//print(sorted);
	cout << endl;

	return 0;
}

