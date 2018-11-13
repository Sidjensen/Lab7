#pragma once
// Lab7-sjense21.cpp
// Sidney Jensen
// Lab 7
// 11/12/18

#ifndef LAB7_H
#define LAB7_H

typedef unsigned long ulong;
#include "stdafx.h"
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>
#include<iostream>

using namespace std;

void add_numbers(vector<short> &data, int length) {
	for (ulong i = 1; i <= length; i++) // loops through ten times
	{
		data.push_back(rand()); // adds a random number
	}
};

void print(const vector<short> &data) {
	if (data.empty()) {
		cout << "<empty>";
	}
	else {
		cout << "<" << data.at(0);
		for (ulong i = 1; i<data.size(); i++) {
			cout << ", " << data.at(i);
		}
		cout << ">";
	}
};

template <typename RandomAccessIterator>
void bubble_sort(RandomAccessIterator begin, RandomAccessIterator end) {
	bool swapped = true;
	while (begin != end-- && swapped) {
		swapped = false;
		for (auto i = begin; i != end; ++i) {
			if (*(i + 1) < *i) {
				std::iter_swap(i, i + 1);
				swapped = true;
			}
		}
	}
};

template <typename RandomAccessIterator, typename Predicate>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end,
	Predicate p) {
	for (auto i = begin; i != end; ++i) {
		std::rotate(std::upper_bound(begin, i, *i, p), i, i + 1);
	}
};

template <typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end) {
	insertion_sort(
		begin, end,
		std::less<
		typename std::iterator_traits<RandomAccessIterator>::value_type>());
};

template<typename ForwardIterator> void selection_sort(ForwardIterator begin,
	ForwardIterator end) {
	for (auto i = begin; i != end; ++i) {
		std::iter_swap(i, std::min_element(i, end));
	}
};

template<typename RandomAccessIterator, typename Order>
void mergesort(RandomAccessIterator first, RandomAccessIterator last, Order order)
{
	if (last - first > 1)
	{
		RandomAccessIterator middle = first + (last - first) / 2;
		mergesort(first, middle, order);
		mergesort(middle, last, order);
		std::inplace_merge(first, middle, last, order);
	}
};

template<typename RandomAccessIterator>
void mergesort(RandomAccessIterator first, RandomAccessIterator last)
{
	mergesort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
};

template<typename RandomAccessIterator,
	typename Order>
	void quicksort(RandomAccessIterator first, RandomAccessIterator last, Order order)
{
	if (last - first > 1)
	{
		RandomAccessIterator split = std::partition(first + 1, last, std::bind2nd(order, *first));
		std::iter_swap(first, split - 1);
		quicksort(first, split - 1, order);
		quicksort(split, last, order);
	}
};

template<typename RandomAccessIterator>
void quicksort(RandomAccessIterator first, RandomAccessIterator last)
{
	quicksort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
};
//vector<short> quickSort(vector<short> vec) // from http://rosettacode.org/wiki/Sorting_algorithms/Quicksort
//{
//	if (vec.size() > 1)
//	{
//		int left = vec.front(), right = vec.back();
//		int temp;
//		int pivot = vec[(left + right) / 2];
//		while (left <= right) {
//			while (vec[left] < pivot)
//			{
//				left++;
//			}
//			while (vec[right] > pivot)
//			{
//				right--;
//			}
//			if (left <= right)
//			{
//				temp = vec[left];
//				vec[left] = vec[right];
//				vec[right] = vec[left];
//			}
//		}
//		quickSort(vec.front() to vec[right]);
//		quickSort(vec[left] to vec.back())
//	}
//}


#endif 