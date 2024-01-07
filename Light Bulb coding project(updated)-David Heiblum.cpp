//
//  main.cpp
//  lightbulb coding project
//
//  Created by David Heiblum on 1/6/24.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Bulb_Counter {
    string Room_name;
    int Lightbulb_number;
};

int main(int argc, const char * argv[]) {
    cout << "How many light bulbs do you think you will need to address in total?\n";
    int b1;
    cin >> b1;
  
    cout << "You said that you might need to address " << b1 << " light bulbs in total.\n";
    Bulb_Counter bulb[b1]; // Declare an array to hold up to 100 bulbs (adjust as needed)
    cout << "Enter k for keyboard input or f for file input.\n";
    int room_number;
    char user_choice2;
    cin >> user_choice2;
    if (user_choice2 == 'k') {
        cout << "Please enter the number of rooms in your house: ";
        cin >> room_number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore newline character in the buffer
        for (int i = 0; i < room_number; i++) {
            cout << "Please enter the room name: ";
           getline(cin,bulb[i].Room_name);
            cout << "Please enter the number of light bulbs: ";
            cin >> bulb[i].Lightbulb_number;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore newline character in the buffer
            cout << "Your room " << bulb[i].Room_name << " has " << bulb[i].Lightbulb_number << " light bulb(s).\n";
        }
    }
    else if (user_choice2 == 'f') {
        string file_name;
        cout << "Please enter the name of the input file: ";
        cin >> file_name;
        ifstream file(file_name);
        if (!file) {
            cout << "Failed to open the file. Exiting." << endl;
            return 1;
        }
        file >> room_number;
        file.close();
        cout << "To make sure that we got the information from your input file correctly, you told us that you have " << room_number << " rooms in your house.\n";
        
        for (int i = 0; i < room_number; i++) {
            // Read data from the already opened file
            string file_name;
            cout << "Please enter the name of the input file: ";
            cin >> file_name;
            ifstream file(file_name);
            if (!file) {
                cout << "Failed to open the file. Exiting." << endl;
                return 1;
            }
            file >> bulb[i].Room_name;
            file >> bulb[i].Lightbulb_number;
            file.close();   // Close the file after reading from it
            cout << "Your room " << bulb[i].Room_name << " has " << bulb[i].Lightbulb_number << " light bulb(s).\n";
        }
    }
    else {
        cout << "Exiting program now.\n";
        return 1; // Exit with an error code
    }
    
    
    // Now you can safely use room_number in the following loop
    int total_light_bulbs=0;
    for (int i = 0; i < room_number; i++) {
   
       total_light_bulbs += bulb[i].Lightbulb_number;
    }
    cout << "You have " << total_light_bulbs << " light bulbs in your house.\n";
    cout << "Do you want to write the results to a file? Yes or No? Y for Yes and N for No.\n";
    char write_choice;
    cin >> write_choice;
    if (write_choice == 'Y' || write_choice == 'y') {
        string file_name;
        cout << "Please enter the name of the output file: ";
        cin >> file_name;
        cout<<"Writing to file.\n";
        ofstream file(file_name);
        if (!file) {
            cout << "Failed to open the file for writing. Exiting." << endl;
            return 1;
        }
        file << "You have " << total_light_bulbs << " light bulbs in your house.\n";
        file.close();
        cout<<"File written completed successfully. Check your output file on your computer disk.\n";
    }
    else if (write_choice == 'N' || write_choice == 'n') {
        cout << "Oh, okay then. Bye for now.\n";
    }
    
    return 0;
}
