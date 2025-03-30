#pragma once
#include <string>
#include <vector>
#include "widgets/TextInput.h"


void writeToHistory(const std::string& file, std::string message);
std::string getLastEquation(TDT4102::TextInput& textField, const std::string& file);
void clearHistory(const std::string& file);
