//Including the necessary headers for file handling, data structures, etc.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
#include <array>
#include <chrono>
#include <thread>

using namespace std;

//Defining function that will be used to simulate environmental changes over time
void plane_crash(map<string, array<list<double>, 3>>&, string);
void weather_event(map<string, array<list<double>, 3>>&, string);
void new_airport_opening(map<string, array<list<double>, 3>>&, string);
void computer_error(map<string, array<list<double>, 3>>&, string);
void early_arrival(map<string, array<list<double>, 3>>&, string);
void holiday_event(map<string, array<list<double>, 3>>&, string);
double list_average(list<double>&);
bool load_data(map<string, array<list<double>, 3>>&, string);

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
    if (load_data(airports, "testvalue.txt") == false)
        return 1;
    //Close the file
    fin.close();

    //Begin a time-based simulation for the typical changes in the data for the airport
    for (int timeInterval = 0; timeInterval < 26; timeInterval++) {
        //for 26 time intervals
        cout << "Time Period " << timeInterval + 1 << endl;
            //Iterate through each airport in the map
            for (auto &pair : airports) {
            //for each airport, simulate the changes that you will see
                //randomly decide if a computer error occurs, plane arrives early,
                //and a very low chance for a plane crash
                //depending on the random occurence, update the amount of people, delays, and reviews
                //for this code, dummy values have been placed in the eventOccurs section, but will be randomized during actual program
                    //Common occurences that will be randomly generated:
                    //For a computer error, increase nPeople, increase nDelays, and decrease avgReviews
                    int commonOccurrence = rand() % 100 + 1;
                    if (commonOccurrence <= 70) {
                        int e1 = rand() % 100 + 1;
                        if (e1 <= 40)
                        computer_error(airports, pair.first);
                        //For an early arrival, decrease nPeople, decrease nDelays, and increase avgReviews
                        int e2 = rand() % 100 + 1;
                        if (e2 <= 30)
                        early_arrival(airports, pair.first);
                        //For a holiday, increase nPeople significantly, increase nDelays drastically, and decrease avgReviews
                        int e3 = rand() % 100 + 1;
                        if (e3 <= 20)
                        holiday_event(airports, pair.first);
                    }
                    //Rarer occurences that will randomly be generated:
                    //For the opening of other nearby airports, decrease nPeople, keep nDelays the same, and increase avgReviews slightly
                    int rareOccurrence = rand() % 100 + 1;
                    if (rareOccurrence >= 90) {
                        int e4 = rand() % 100 + 1;
                        if (e4 <= 10)
                        new_airport_opening(airports, pair.first);
                        //For extreme weather events, increase nPeople, drastically increase nDelays, and drastically decrease avgReviews
                        int e5 = rand() % 100 + 1;
                        if (e5 <= 5)
                        weather_event(airports, pair.first);
                        //For a plane crash. drastically decrease nPeople, drastically increase nDealys, and keep avgReviews the same
                        int e6 = rand() % 100 + 1;
                        if (e6 <= 1)
                        plane_crash(airports, pair.first);
                    }
                    cout << endl;
            }
            //print the changes in the values of the airport for the current time interval
            //e.g. "For {airport name}: {nPeople} are now present, there are {nDelays} reported, and the average reviews are {avgReviews}"
            for ( auto& [name, details] : airports) {
                cout << fixed << setprecision(0);
                cout << "For " << name << ":";

                double pwAvg = list_average(details[0]);
                double dwAvg = list_average(details[1]);
                double rwAvg = list_average(details[2]);
                

                cout << pwAvg << " people are now present, ";
                cout << dwAvg << " delays reported, ";
                cout << fixed << setprecision(2);
                cout << "and the average reviews are " << rwAvg << endl; 
            }
        //Wait or pause briefly to simulate the passage of "two weeks" between time intervals
        cout << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << endl;
    cout << "Biweekly Summary From the Airports: \n";
    for ( auto& [name, details] : airports) {
        cout << fixed << setprecision(0);
        cout << "For " << name << ":";

            double pyAvg = list_average(details[0]);
            double dyAvg = list_average(details[1]);
            double ryAvg = list_average(details[2]);

        cout << pyAvg << " people were present, ";
        cout << dyAvg << " delays were reported, ";
        cout << fixed << setprecision(2);
        cout << "and the average reviews are " << ryAvg << " every two weeks!" << endl; 
    }

    //End the main function
    return 0;
}

//boolean function that will return true if the file is appropriately uploaded to the map
bool load_data(map<string, array<list<double>, 3>>& a, string filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << filename << " could not be opened.\n";
        return false;
    }
    else {
         //Read the data from the file and populate the map
        //For each line, extract the name of the airport and the details of the airport
        //Insert the approrpiate airport details into the map
        string line;
        string apName;
        double nPeople, nDelays, avgReviews;

        while(getline(file, line)) {
            stringstream ss(line);
            
            ss >> apName >> nPeople >> nDelays >> avgReviews;

            a[apName][0].push_back(nPeople);
            a[apName][1].push_back(nDelays);
            a[apName][2].push_back(avgReviews);
        }
        return true;
    }
}

double list_average(list<double>& aData) {
    double sum = accumulate(aData.begin(), aData.end(), 0.0);
    double average = sum / aData.size();

    return average;
}

//Defining the prototype functions that were initialized earlier in the code
void plane_crash(map<string, array<list<double>, 3>>& a, string n) {
    //For a plane crash. drastically decrease nPeople, drastically increase nDelays, and keep avgReviews the same
    auto it = a.find(n);
    
    if(it != a.end()) {
        for (double& people_value : it->second[0]) {
            people_value = people_value * 0.5;
        }
        for (double& delay_value : it->second[1]) {
            delay_value = delay_value  + 20;
        }
    }
    
    cout << "Tragically, a plane from " << n << " has crashed.\n";
}

void weather_event(map<string, array<list<double>, 3>>& a, string n) {
    //For extreme weather events, increase nPeople, drastically increase nDelays, and drastically decrease avgReviews
    auto it = a.find(n);
    
    if(it != a.end()) {
        for (double& people_value : it->second[0]) {
            people_value = people_value * 1.1;
        }
        for (double& delay_value : it->second[1]) {
            delay_value = delay_value + 15;
        }
        for (double& reviews : it->second[2]) {
            reviews = reviews * 0.9;
        }
    }  
   
    cout << "Weather events at " << n << " have prevented planes from taking off.\n";
}

void new_airport_opening(map<string, array<list<double>, 3>>& a, string n) {
    //For the opening of other nearby airports, decrease nPeople, keep nDelays the same, and increase avgReviews slightly
    auto it = a.find(n);
    
    if(it != a.end()) {
        for (double& people_value : it->second[0]) {
            people_value = people_value * 0.9;
        }
        for (double& reviews : it->second[2]) {
            reviews = reviews * 1.2;
            if (reviews >= 5.0)
                reviews = 5.0;
        }
    }
    
    cout << "A new airport has opened near  " << n << "!\n";
}

void computer_error(map<string, array<list<double>, 3>>& a, string n) {
    //For a computer error, increase nPeople, increase nDelays, and decrease avgReviews
     auto it = a.find(n);
    
    if(it != a.end()) {
        for (double& people_value : it->second[0]) {
            people_value = people_value * 1.1;
        }
        for (double& delay_value : it->second[1]) {
            delay_value = delay_value + 5;
        }
        for (double& reviews : it->second[2]) {
            reviews = reviews * 0.98;
        }
    }

    cout << "A computer error at " << n << " has delayed the boarding process.\n";
}

void early_arrival(map<string, array<list<double>, 3>>& a, string n) {
    //For an early arrival, decrease nPeople, decrease nDelays, and increase avgReviews
    auto it = a.find(n);
    
    if(it != a.end()) {
        for (double& people_value : it->second[0]) {
            people_value = people_value * 0.95;
        }
        for (double& delay_value : it->second[1]) {
            delay_value = delay_value - 4;
        }
        for (double& reviews : it->second[2]) {
            reviews = reviews * 1.25;
            if (reviews >= 5.0)
                reviews = 5.0;
        }
    }
   cout << "A plane at " << n << " has arrived early!\n";
}

void holiday_event(map<string, array<list<double>, 3>>& a, string n) {
    //For a holiday, increase nPeople significantly, increase nDelays drastically, and decrease avgReviews
    auto it = a.find(n);
    
    if(it != a.end()) {
        for (double& people_value : it->second[0]) {
            people_value = people_value * 1.25;
        }
        for (double& delay_value : it->second[1]) {
            delay_value = delay_value + 20;
        }
        for (double& reviews : it->second[2]) {
            reviews = reviews * 0.95;
        }
    } 
    cout << "The holiday rush at " << n << " has led to very long lines.\n";
}