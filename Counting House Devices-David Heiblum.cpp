//
//  main.cpp
//  House Devices Power Plan
//
//  Created by David Heiblum on 9/25/23.
//

#include <iostream>
#include <fstream>
using namespace std;

struct House_Devices {
    string Room_name;
    int Devices_number;
    int Power_strip_number;
};

int main() {
    int room_number;
    char user_choice;
    cout << "Do you want to enter the number of rooms in your house via keyboard input or file input? (k/f): ";
    cin >> user_choice;
    if (user_choice == 'k') {
        cout << "Please enter the number of rooms in your house: ";
        cin >> room_number;
        cout << "To make sure that we got the entered information correctly, you told us that you have " << room_number << " rooms in your house.\n";
    } else if (user_choice == 'f') {
        string file_name;
        cout << "Please enter the name of the file: ";
        cin >> file_name;
        ifstream file(file_name);
        if (!file) {
            cout << "Failed to open the file. Exiting." << endl;
            return 1;
        }
        file >> room_number;
        cout << "To make sure that we got the information from your input file correctly, you told us that you have " << room_number << " rooms in your house.\n";
        file.close();
    } else {
        cout << "Invalid choice. Exiting." << endl;
        return 1;
    }

    House_Devices *devices = new House_Devices[room_number];

    ofstream roomOutputFile("Room Calculations Results.txt", ios::app);
    if (!roomOutputFile) {
        cout << "Failed to open the room output file. Exiting." << endl;
        delete[] devices;
        return 1;
    }

    for (int i = 0; i < room_number; i++) {
        House_Devices device;
        cout << "Room " << (i + 1) << endl;

        char input_choice;
        cout << "Do you want to enter the room name and number of devices in that room via keyboard input or file input? (k/f): ";
        cin >> input_choice;

        if (input_choice == 'k') {
            cout << "Please enter the room name: ";
            cin >> device.Room_name;
            cout << "Please enter the number of pluggable devices in the mentioned room: ";
            cin >> device.Devices_number;
            cout << "To make sure that we got that correct, you entered the following information: Your room: " << device.Room_name << " has " << device.Devices_number << " devices.\n";
        } else if (input_choice == 'f') {
            string file_name;
            cout << "Please enter the name of the file that you want to input the information from: ";
            cin >> file_name;
            ifstream file(file_name);

            if (!file) {
                cout << "Failed to open the file. Exiting." << endl;
                roomOutputFile.close();
                delete[] devices;
                return 1;
            }

            file >> device.Room_name;
            file >> device.Devices_number;
            cout << "To make sure that the information from your input file is correct, your room name is " << device.Room_name << " and in that room, you have " << device.Devices_number << " devices.\n";
            file.close();
        } else {
            cout << "Invalid choice. Exiting.\n";
            roomOutputFile.close();
            delete[] devices;
            return 1;
        }

        device.Power_strip_number = device.Devices_number / 5;
        int remainder = device.Devices_number % 5;
        if (remainder > 0) {
            device.Power_strip_number += 1;
        }

        cout << "Your room name is " << device.Room_name << " and the number of 5 plug-in outlet power strips you need to power off all " << device.Devices_number << " devices in the room is " << device.Power_strip_number << endl;

        cout << "Do you want to save the room calculation results for later use? (y/n)";
        char output_choice;
        cin >> output_choice;
        if (output_choice == 'y') {
            roomOutputFile << "Your room name is " << device.Room_name << " and the number of pluggable devices that you have in that room is " << device.Devices_number << ". That means that you need " << device.Power_strip_number << " power strips for that room.\n";
            cout << "Calculation results have been saved to Room Calculation Results.txt." << endl;
        } else if (output_choice == 'n') {
            cout << "Oh ok. Next room is....\n";
        } else {
            cout << "Invalid choice. Exiting now." << endl;
            roomOutputFile.close();
            delete[] devices;
            return 1;
        }

        devices[i] = device;
    }

    roomOutputFile.close();

    int total_power_strips = 0;
    for (int i = 0; i < room_number; i++) {
        if (devices[i].Power_strip_number > 0) {
            total_power_strips += devices[i].Power_strip_number;
        }
    }
    cout << "If you want to save all of the power you continually use in the whole house, then the number of power strips you need for the entire house is " << total_power_strips << endl;

    cout << "Do you want to save the calculation results for later use? (y/n)";
    char output_choice;
    cin >> output_choice;
    if (output_choice == 'y') {
        ofstream outputFile("Results.txt", ios::app);
        if (outputFile.is_open()) {
            outputFile << "The total number of power strips needed to turn off all of the pluggable devices in the whole house is " << total_power_strips << endl;
            outputFile.close();
            cout << "Calculation results have been saved to Results.txt." << endl;
        } else {
            cout << "Failed to open the output file. Exiting." << endl;
            delete[] devices;
            return 1;
        }
    } else if (output_choice == 'n') {
        cout << "Oh ok. As a friendly reminder, the total number of power strips needed to turn off all devices in your house is still " << total_power_strips << endl;
    } else {
        cout << "Invalid choice. Exiting now." << endl;
        delete[] devices;
        return 1;
    }

    delete[] devices;
    return 0;
}
