#include <fstream>
#include <iostream>
#include "history.h"
#include "globals.h"
#include "calculator.h"
#include "widgets/TextInput.h"


// Function to write each equation to the history file
void writeToHistory(const std::string& file, std::string message) {
    std::ofstream outFile;
    outFile.open(file, std::ios::app);

    if (outFile.fail())
    {
        std::cout << "Error opening file." << std::endl;
    }

    // Write some new content to the file.  
    outFile << message << std::endl;
    
    // Close the file as we are done working with the file.
    outFile.close();
}

// Function to read the last equation from the history file and set it in the text field
std::string getLastEquation(TDT4102::TextInput& textField,const std::string& file) {
    std::ifstream inFile(file);
    std::string lastEquation;
    std::string line;

    if (inFile.is_open()) {
        while (std::getline(inFile, line)) {
            lastEquation = line; // Store the last line read
        }
        textField.setText(lastEquation); // Set the text field to the last equation
        inFile.close();
    } else {
        std::cout << "Error opening file." << std::endl;
    }

    return lastEquation;
}

// Function to clear the history file
void clearHistory(const std::string& file) {
    std::ofstream outFile(file, std::ios::trunc); // Open file in truncate mode to clear it
    if (outFile.is_open()) {
        outFile.close(); // Close the file immediately to clear its content
    } else {
        std::cout << "Error opening file." << std::endl;
    }
}