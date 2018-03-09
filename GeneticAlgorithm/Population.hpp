#pragma once
#include "Tour.hpp"
using namespace std;
static const int NUMBER_OF_PARENTS = 2;
static const int POPULATION_SIZE = 30;
class Population {
private:
	vector<Tour*> pop;
public:
	Population * select_parents(Tour* population) {
		Population* parents{};
		Tour parent_pool[5];
		int parent_index = 0;
		int k = 0;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 5; ++j) {
				k = rand() % 30;
				*(parent_pool + j) = *(population + k);
			}
			parent_index = determine_fitness(parent_pool, PARENT_POOL_SIZE);
			parents->pop[i] = (parent_pool + parent_index);


		}
		return parents;
	}
	Population() {

	}
	~Population() {

	}
};