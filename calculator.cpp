#include "calculator.h"
#include <vector>
#include <iostream>
#include <string>
#include <cctype> 


// Calculator function that does the calculation based on the input string
double calculate(const std::string& equation) {
    std::vector<int> nums;
    std::vector<char> ops;
    size_t n = equation.length();
    size_t i = 0;

    while (i < n) {
        // Read the first number
        int num = 0;
        while (i < n && std::isdigit(equation[i])) {
            num = num * 10 + (equation[i] - '0');
            i++;
        }

        // Check for * and / before pushing to nums
        while (!ops.empty() && (ops.back() == '*' || ops.back() == '/')) {
            char op = ops.back();
            ops.pop_back();
            int prev = nums.back();
            nums.pop_back();
            if (op == '*') { 
                num = prev * num;
            } else {
                if (num == 0) {
                    std::cerr << "Division by zero error" << std::endl;
                    return 0; // Handle division by zero
                }
                num = prev / num;
            }
        }

        nums.push_back(num);

        // Read operator
        if (i < n && (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/')) {
            ops.push_back(equation[i]);
            i++;
        }
    }

    // Checking for to make sure the equation is valid (not to many operators)
    if (nums.size() != ops.size() + 1) {
        std::cerr << "Invalid equation" << std::endl;
        return 0;
    }

    // Handle + and -
    int result = nums[0];
    size_t index = 1;

    for (char op : ops) {
        if (op == '+') {
            result += nums[index];
        } else {
            result -= nums[index];
        }
        index++;
    }
    
    return result; // Ensure the function always returns a value
}

