#pragma once
#include "City.hpp"
#include <vector>
using namespace std;
static const int CITIES_IN_TOUR = 30;
class Tour {

private:
	double fitness;
	vector<City*> permutations;
public:
	Tour();
	friend void shuffle_cities(Tour& perm);
	friend double get_tour_distance(Tour city_list);
	int determine_fitness(Tour* population, int population_size);
	void swap_cities(int index_one, int index_two, vector<City>& perm);
	friend Tour& crossover(Tour& parents);
	friend void mutate(Tour* population);
    friend bool contains_city(Tour& candidate_tour, int length, City& candidate_city);
	~Tour();
	Tour& operator=(Tour& m);
	void swap(Tour& t1, Tour& t2);
};