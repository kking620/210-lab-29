//Including the necessary headers for file handling, data structures, etc.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <array>

using namespace std;

//Defining function that will be used to simulate environmental changes over time
void holiday_rush(map<string, array<list<int>, 3>>&);
void weather_event(map<string, array<list<int>, 3>>&);
void new_airport_opening(map<string, array<list<int>, 3>>&);

//Defining the main function
int main() {
    //Parameters for the map of the airports, as well as defining the array with the three different values we will be obtaining
    using airportDetails = array<list<int>, 3>;

    //Initializing a map to store airport information, which is associated with an array for
    //the number of people, the number of delays, and the average reviews
    map<string, airportDetails> airports;

    //Open an external file to read the initial data about the airports to populate the map
        //If the file does not open, print an error message and exit

    //Read the data from the file and populate the map
        //For each line, extract the name of the airport and the details of the airport
        //Insert the approrpiate airport details into the map

    //Close the file

    //Begin a time-based simulation for the typical changes in the data for the airport

        //for 26 time intervals
            //Iterate through each airport in the map
                //for each airport, simulate the changes that you will see
                    //randomly decide if a computer error occurs, plane arrives early,
                    //and a very low chance for a plane crash

                    //depending on the random occurence, update the amount of people, delays, and reviews
                        //For a computer error, increase nPeople, increase nDelays, and decrease avgReviews
                        //For an early arrival, decrease nPeople, decrease nDealys, and increase avgReviews
                        //For a plane crash, decrease nPeople, decrease nDelays, and keep avgReviews the same

                    //print the changes in the values of the airport for the current time interval
                        //e.g. "{nPeople} are now at the airport, there are {nDelays} reported, and "
    


}


//Defining the prototype functions that were initialized earlier in the code
void holiday_rush(map<string, array<list<int>, 3>>&) {
    
}

void weather_event(map<string, array<list<int>, 3>>&) {

}

void new_airport_opening(map<string, array<list<int>, 3>>&) {

}