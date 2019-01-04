#pragma once

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include "TypeRedefinitions.h"

real_t Mean(real_set_t& rs) {
    real_t sum = 0.0;
	for(auto d : rs)
		sum += d;
	sum /= rs.size();
	return sum;
}

real_t Max(real_set_t& data) {
	return *std::max_element(std::begin(data), std::end(data));
}

real_t Min(real_set_t& data) {
	return *std::min_element(std::begin(data), std::end(data));
}

real_t Median(real_set_t& data) {
	real_set_t tmp = data;
	std::sort(tmp.begin(), tmp.end());
	return tmp[(tmp.size()+1)/2]; // take into account 0-indexing
}

real_t Range(real_set_t& data) {
	return Max(data) - Min(data);
}

void Magnitude(real_set_t& data) { // abs() on every element
	for(auto& d : data)
		if(d < 0.0)
			d *= -1.0;
}

real_t Sum(real_set_t& data) {
	real_t sum = 0.0;
	for(auto d : data)
		sum += d;
	return sum;
}

real_t Product(real_set_t& data) {
	real_t product = 1.0;
	for(auto d : data)
		product *= d;
	return product;
}

void Clamp(real_set_t& data, real_t max, real_t min) {
	for(auto& d : data) {
		if(d < min)
			d = min;
		else if(d > max)
			d = max;
	}

}

void Shuffle(real_set_t& data) {
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(data.begin(), data.end(), std::default_random_engine(seed));
}

void Sort(real_set_t& data, const int sm) {
	switch(sm) {
		case SortMethod::increasing:
			std::sort(data.begin(), data.end());
			return;
		case SortMethod::decreasing:
			std::sort(data.begin(), data.end(), std::greater<real_t>());
			return;
		default:
			throw std::runtime_error("Sort -> unknown sorting algorithm");
	}
}

void Fill(real_set_t& data, int size, real_t fill_value) {
	data.clear();
	for(int i = 0; i < size; i++)
		data.push_back(fill_value);
}

void Zeros(real_set_t& data, int size) {
	Fill(data, size, 0.0);
}

void Ones(real_set_t& data, int size) {
	Fill(data, size, 1.0);
}

void FillRandom(real_set_t& data, int size = -1) {
	if(size == -1) {
		size = data.size();
	}
	
	data.clear();

	// seed the random number generator
	std::srand(std::time(NULL));

	for(int i = 0; i < size; i++) {
		data.push_back(((real_t)rand() / RAND_MAX));
	}
}

void Scale(real_set_t& data, real_t r) {
	// some small optimizations
	if(r == 0.0) {
		for(auto& d : data)
			d = 0.0;
		return;
	}

	if(r == 1.0)
		return; // dont need to do anything

	for(auto& d : data)
		d *= r;
}
