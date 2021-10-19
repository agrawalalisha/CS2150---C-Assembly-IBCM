// Alisha Agrawal
// aa3se
// 05/04/2021
// traveling.cpp

// This program uses the skeleton code provided for the Lab 11 in-lab

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

/**
 *@brief main function for traveling salesman algorithm
 *
 *@param argc count of the command line arguments
 *@param argv vector of command line arguments
 *@return returns 0
 * Function creates a Middle-Earth and finds the shortest cycle through cities
 */
int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE
    // sort the dests vector
    sort(dests.begin() + 1, dests.end());
    string first = dests[0];
    // shortest distance stored in min
    float min = computeDistance(me, first, dests);
    float curr = 0.0;
    vector<string> itin = dests;

    // permute through dests
    while(next_permutation(dests.begin() + 1, dests.end())) {
      curr = computeDistance(me, first, dests);
      if(curr < min) {
	itin = dests;
	min = curr; 
      }
    }

    // print out the shortest distance and route
    first = itin[0];
    cout << "Minimum path has distance: " << min << ": ";
    printRoute(first, itin);
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.

/**
 *@brief computes distance of a cycle of cities
 *@author Alisha Agrawal
 *@param me Middle Earth instance
 *@param start starting city
 *@param dests vector of cities
 * use Middle Earth instance and vector of cities and starting city to compute full distance of travel
 */
float computeDistance(MiddleEarth me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  float dist = 0.0; // distance
  string s = start;
  // add distnace from one city to another
  for(int i=0; i < dests.size(); i++) {
    dist += me.getDistance(s, dests[i]);
    s = dests.at(i);
  }

  // add the distance from the start to end
  dist += me.getDistance(dests[0], dests[dests.size()-1]);
  return dist;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor

/**
 *@brief prints city route
 *@author Alisha Agrawal
 *@param start the start city
 *@param dests the vector of cities
 * take the start city and vector of city and prints the entire route 
 * from start through cities and back to start
 */
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  // loop through dests and print each city
  for(int i=0; i<dests.size(); i++) {
    cout << dests[i] << " -> ";
  }
  // print starting city
  cout<<start<< endl;
}
