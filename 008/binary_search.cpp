#include <iostream>
#include <random>
#include <math.h>
#include "timing.cpp"

int size_of_array = 1000000;
std::random_device rd;
std::mt19937 eng(rd());

void print_array(int* array){
	std::cout << "[ ";
	for (int i = 0; i < size_of_array; i++){
		std::cout << array[i];
		if (i < size_of_array-1){
			std::cout << ", ";
		}
	}
	std::cout << " ]" << std::endl;
}

// Creates a 'sorted' random array
int* generate_random_array(int* array){
	std::uniform_int_distribution<>distr(0, 100);
	int start = distr(eng);
	for (int i = 0; i < size_of_array; i++){
		array[i] = start;
		start += distr(eng);
	}
	return array;
}

int random_pick(int* array){
	std::uniform_int_distribution<>distr(0, size_of_array);
	return array[distr(eng)];
}

// Searching algorithms

// Naive implementation - worst case O(n) linear runtime
int naive_search(int* array, int search){
	for (int i = 0; i < size_of_array; i++){
		if (search == array[i]){
			//std::cout << "Found at " << i << "th loop" << std::endl;
			return i;
		}
	}
	// lol
	return -1;
}

// Binary search - worst case O(log n) logarithmic runtime
int binary_search(int* array, int search){
	int left = 0;
	int right = size_of_array-1;
	int searches = 0;
	while (true){
		searches++;
		if (left > right){
			return -1;
		}
		int mid = std::floor((left+right)/2);
		if (array[mid] == search){
			//std::cout << "Found at " << searches << " searches" << std::endl;
			return mid;
		} else if (array[mid] < search){
			left = mid + 1;
		} else if (array[mid] > search){
			right = mid - 1;
		}
	}
}

int main(int argc, char *argv[]){
	int unsorted_array[size_of_array];
	int *sorted_array = generate_random_array(unsorted_array);

	double startTime, endTime;

	int testing_its = 100;
	std::cout << "Array of " << size_of_array << " items" << std::endl;
	startTime = getRealTime();
	for (int i = 0; i < testing_its; i++){
		int search_item = random_pick(sorted_array);
		naive_search(sorted_array, search_item);
	}
	endTime = getRealTime();
	std::cout << "Naive search for " << testing_its << " items: " << (endTime - startTime) << std::endl;

	startTime = getRealTime();
	for (int i = 0; i < testing_its; i++){
		int search_item = random_pick(sorted_array);
		binary_search(sorted_array, search_item);
	}
	endTime = getRealTime();
	std::cout << "Binary search for " << testing_its << " items: " << (endTime - startTime) << std::endl;




}