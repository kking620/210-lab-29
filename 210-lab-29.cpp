//Including the necessary headers for file handling, data structures, etc.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <string>
#include <algorithm>
#include <array>

using namespace std;

//Defining function that will be used to simulate environmental changes over time
void holiday_rush(map<string, airportDetails>&);
void weather_event(map<string, airportDetails>&);
void new_airport_opening(map<string, airportDetails>&);

//Defining the structure of the airports that we will be obtaining from our input files
struct airportValues {
    int nPeople;
    int nDelays;
    double avgReviews;
};

//Parameters for the map of the airports, as well as defining the array with the three different values we will be obtaining
using airportDetails = array<list<airportValues>, 3>;
using airportMap = map<string, airportDetails>;

//Defining the main function
int main() {
    //Initializing a map to store airport information, which is associated with an array for
    //the number of people, the number of delays, and the average reviews
    airportMap LAX;
    airportMap JFK;
    airportMap DCA;

    //Open an external file
    


}