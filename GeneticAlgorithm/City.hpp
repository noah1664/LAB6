#pragma once
#include <cmath>
#include <iostream>
class City {
private:
	string name;
	int x_coordinate;
	int y_coordinate;
public:
	inline string getName() {
		return name;
	}
	inline int getXcoordinate() {
		return x_coordinate;
	}
	inline int getYcoordinate() {
		return y_coordinate;
	}
	City() {

	}
	static double get_distance_between_cities(City a, City b) {
		return sqrt(pow((double)(a.x_coordinate - b.x_coordinate), 2.0)
			+ pow((double)(a.y_coordinate - b.y_coordinate), 2.0));
	}
	~City() {

	};
	
};