#pragma once
#include "Tour.hpp"
#include "Population.hpp"
#include "City.hpp"
static const int PARENT_POOL_SIZE = 5;
static const int ITERATIONS = 1000;
static const int MAP_BOUNDARY = 1000;
int main() {
	int i = 0;
	int j = 0;
	int iterations = 0;
	int index_of_shortest_tour = 0;
	double best_distance = 0;
	double best_iteration_distance = 0;
	double improvement_factor = 0;
	Population population{};
	Tour crosses{};
	Tour temp_tour{};
	City* cities_to_visit{};

}