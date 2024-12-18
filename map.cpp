#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Create a map to store state names and populations
    map<string, int> populationMap;

    // Insert some sample data
    populationMap["Maharashtra"] = 7026357;
    populationMap["Rajasthan"] = 6578936;
    populationMap["Karnataka"] = 6678993;
    populationMap["Punjab"] = 5789032;
    populationMap["West Bengal"] = 6676291;

    // Display message and get user input
    cout << "======== Population of States in India ==========\n";
    cout << "Enter the name of a state: ";
    string state_name;
    getline(cin, state_name);  // Using getline to read full state name

    // Check if the state exists and print the population
    if (populationMap.count(state_name)) {
        cout << state_name << "'s population is " << populationMap[state_name] << endl;
    } else {
        cout << "State not found in the map.\n";
    }

    return 0;
}

