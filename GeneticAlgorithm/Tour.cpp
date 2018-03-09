#include "Tour.hpp"
#include "Population.hpp"
#include "City.hpp"
#include <cmath>
#include <vector>
#include <iostream>

static const int SHUFFLES = 32;
static const int FITNESS_SCALER = 10000;
static const int NUMBER_OF_ELITES = 1;
static const double MUTATION_RATE = 0.15;

using namespace std;
double get_tour_distance(Tour city_list) {
	double distance = 0;
	for (int i = 0; i < CITIES_IN_TOUR; i++) {
		distance += City::get_distance_between_cities(*city_list.permutations[i], *city_list.permutations[(i + 1) % CITIES_IN_TOUR]);
	}
	return distance;
};
void swap_cities(int index_one, int index_two, vector<City*>& perm) {
	City& temp = *perm[index_one];
	perm[index_one] = perm[index_two];
	*perm[index_two] = temp;
};
void shuffle_cities(Tour& perm) {
	int i = 0;
	for (int i = 0; i < SHUFFLES; ++i) {
		int index_one = rand() % CITIES_IN_TOUR;
		int index_two = rand() % CITIES_IN_TOUR;

		swap_cities(index_one, index_two, perm.permutations);
	}
};
int determine_fitness(Tour* population, int population_size) {
	double shortest_tour_in_population = (double) RAND_MAX;
	int index_of_shortest_tour = 0;
	double candidate_distance = 0.0;
	for (int i = 0; i < population_size; ++i) {
		candidate_distance = get_tour_distance(population[i]);
		population[i].determine_fitness = FITNESS_SCALER / candidate_distance;
		if (candidate_distance <= shortest_tour_in_population) {
			index_of_shortest_tour = i;
			shortest_tour_in_population = candidate_distance;
		}
	}
	return index_of_shortest_tour;
};

Tour& crossover(Tour& parents) {
	int i = 0;
	Tour child{};
	int boundary_index = rand() % CITIES_IN_TOUR;
	child.fitness = 0;
	for (i = 0; i < boundary_index; i++) {
		child.permutations[i] = parents.permutations[i];
	}
	for (i = boundary_index; i < CITIES_IN_TOUR; i++) {
		if (contains_city(child, i, *parents.permutations[i])) {
			shuffle_cities(parents);
			i--;
		}
		else {
			child.permutations[i] = parents.permutations[i];
		}
		}
	return child;
}
void mutate(Tour* population) {
	int i = 0, j =0 , k=0;
	double mutates = 0.0;
	for (i = 0 + NUMBER_OF_ELITES; i < POPULATION_SIZE; ++i) {
		for (j = 0; j < CITIES_IN_TOUR; ++j) {
			mutates = (double)rand() / (double)RAND_MAX;
			if (mutates <= MUTATION_RATE) {
				k = rand() % CITIES_IN_TOUR;
				swap_cities(j, k, (population + i)->permutations);
			}
		}
	}
}
bool contains_city(Tour& candidate_tour, int length, City& candidate_city) {
	for (int i = 0; i < length; ++i) {
		if (candidate_tour.permutations[i]->getName() == candidate_city.getName()
			&& candidate_tour.permutations[i]->getXcoordinate() == candidate_city.getXcoordinate()
			&& candidate_tour.permutations[i]->getYcoordinate() == candidate_city.getYcoordinate()) {
			return true;
		}
	}
	return false;
}
Tour::Tour() {

};
Tour::~Tour() {

}
void Tour::swap(Tour& t1, Tour& t2) {
	using std::swap;
	swap(t1.fitness, t2.fitness);
	swap(t1.permutations, t2.permutations);
}
Tour& Tour::operator=(Tour& t) {
	swap(*this, t);
	return *this;
}
int main() {
	system("pause");
}



