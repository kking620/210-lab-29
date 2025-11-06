//Including the necessary headers for file handling, data structures, etc.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <algorithm>
#include <array>
#include <chrono>
#include <thread>

using namespace std;

//Defining function that will be used to simulate environmental changes over time
void plane_crash(map<string, array<list<double>, 3>>&);
void weather_event(map<string, array<list<double>, 3>>&);
void new_airport_opening(map<string, array<list<double>, 3>>&);
void computer_error(map<string, array<list<double>, 3>>&);
void early_arrival(map<string, array<list<double>, 3>>&);
void holiday_event(map<string, array<list<double>, 3>>&);

//Defining the main function
int main() {
    srand(time(0));
    //Parameters for the map of the airports, as well as defining the array with the three different values we will be obtaining
    using airportDetails = array<list<double>, 3>;

    //Initializing a map to store airport information, which is associated with an array for
    //the number of people, the number of delays, and the average reviews
    map<string, airportDetails> airports;

    //Open an external file to read the initial data about the airports to populate the map
        //If the file does not open, print an error message and exit
    ifstream fin("testvalue.txt");
    if (!fin.is_open()) {
        cout << "This file could not be found.\n";
        return 1;
    }

    //Read the data from the file and populate the map
        //For each line, extract the name of the airport and the details of the airport
        //Insert the approrpiate airport details into the map
        string apName;
        double nPeople, nDelays, avgReviews;

        while(fin >> apName) {
            fin >> nPeople;
            airports[apName][0].push_back(nPeople);

            fin >> nDelays;
            airports[apName][1].push_back(nDelays);

            fin >> avgReviews;
            airports[apName][2].push_back(avgReviews);
        }
    //Close the file
    fin.close();

    //Begin a time-based simulation for the typical changes in the data for the airport
    for (int timeInterval = 0; timeInterval < 26; timeInterval++) {
        //for 26 time intervals
            //Iterate through each airport in the map
            for (auto &pair : airports) {
                string cAPName = pair.first;
                airportDetails& cAPData = pair.second;
            //for each airport, simulate the changes that you will see
                //randomly decide if a computer error occurs, plane arrives early,
                //and a very low chance for a plane crash
                //depending on the random occurence, update the amount of people, delays, and reviews
                //for this code, dummy values have been placed in the eventOccurs section, but will be randomized during actual program
                    //Common occurences that will be randomly generated:
                    //For a computer error, increase nPeople, increase nDelays, and decrease avgReviews
                    int eventOccurs = 60;
                    if (eventOccurs <= 60)
                    computer_error(airports);
                    //For an early arrival, decrease nPeople, decrease nDelays, and increase avgReviews
                    int eventOccurs = 40;
                    if (eventOccurs <= 40)
                    early_arrival(airports);
                    //For a holiday, increase nPeople significantly, increase nDelays drastically, and decrease avgReviews
                    int eventOccurs = 35;
                    if (eventOccurs <= 35)
                    holiday_event(airports);

                    //Rarer occurences that will randomly be generated:
                    //For the opening of other nearby airports, decrease nPeople, keep nDelays the same, and increase avgReviews slightly
                    int eventOccurs = 15;
                    if (eventOccurs <= 15)
                    new_airport_opening(airports);
                    //For extreme weather events, increase nPeople, drastically increase nDelays, and drastically decrease avgReviews
                    int eventOccurs = 10;
                    if (eventOccurs <= 10)
                    new_airport_opening(airports);
                    //For a plane crash. drastically decrease nPeople, drastically increase nDealys, and keep avgReviews the same
                    int eventOccurs = 1;
                    if (eventOccurs <= 1)
                    new_airport_opening(airports);

                //print the changes in the values of the airport for the current time interval
                    //e.g. "For {airport name}: {nPeople} are now present, there are {nDelays} reported, and the average reviews are {avgReviews}"
                cout << fixed << setprecision(0);
                cout << "For " << cAPName << ":";
                cout << cAPData[0].back() << " people are now present, ";
                cout << cAPData[1].back() << " delays reported, ";
                cout << "And the average reviews are " << cAPData[2].back() << endl; 
            }
        //Wait or pause briefly to simulate the passage of "two weeks" between time intervals
        this_thread::sleep_for(chrono::seconds(1));
    }
    //End the main function
    return 0;
}


//Defining the prototype functions that were initialized earlier in the code
void plane_crash(map<string, array<list<double>, 3>>& a) {
    //For a plane crash. drastically decrease nPeople, drastically increase nDelays, and keep avgReviews the same
    for (auto& [name, details] : a) {
       double currentPeople = details[0].back() * 0.5;
       double currentDelays = details[1].back() * 2.0;
    }
}

void weather_event(map<string, array<list<double>, 3>>& a) {
    //For extreme weather events, increase nPeople, drastically increase nDelays, and drastically decrease avgReviews
     for (auto& [name, details] : a) {
       double currentPeople = details[0].back() * 1.25;
       double currentDelays = details[1].back() * 1.5;
       double currentReviews = details[2].back() * 0.7;
    }
}

void new_airport_opening(map<string, array<list<double>, 3>>& a) {
    //For the opening of other nearby airports, decrease nPeople, keep nDelays the same, and increase avgReviews slightly
     for (auto& [name, details] : a) {
       double currentPeople = details[0].back() * 0.8;
       double currentReviews = details[2].back() * 1.2;
    }
}

void computer_error(map<string, array<list<double>, 3>>& a) {
    //For a computer error, increase nPeople, increase nDelays, and decrease avgReviews
     for (auto& [name, details] : a) {
       double currentPeople = details[0].back() * 1.1;
       double currentDelays = details[1].back() * 1.15;
       double currentReviews = details[2].back() * 0.85;
    }
}

void early_arrival(map<string, array<list<double>, 3>>& a) {
    //For an early arrival, decrease nPeople, decrease nDelays, and increase avgReviews
     for (auto& [name, details] : a) {
       double currentPeople = details[0].back() * 0.9;
       double currentDelays = details[1].back() * 0.9;
       double currentReviews = details[2].back() * 1.25;
    }
}

void holiday_event(map<string, array<list<double>, 3>>& a) {
    //For a holiday, increase nPeople significantly, increase nDelays drastically, and decrease avgReviews
     for (auto& [name, details] : a) {
       double currentPeople = details[0].back() * 1.5;
       double currentDelays = details[1].back() * 1.3;
       double currentReviews = details[2].back() * 0.75;
    }
}