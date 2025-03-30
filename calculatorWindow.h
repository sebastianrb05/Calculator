#pragma once
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"

class CalculatorWindow : public TDT4102::AnimationWindow {
public:
    CalculatorWindow(int x, int y, int width, int height, const std::string& title);

private:
    TDT4102::TextInput textField;

    void setupButtons();
    void setupCallbacks();

    // Buttons
    TDT4102::Button button1, button2, button3;
    TDT4102::Button button4, button5, button6;
    TDT4102::Button button7, button8, button9;
    TDT4102::Button button0, buttonEqual, buttonC;
    TDT4102::Button buttonPlus, buttonMinus, buttonMultiply, buttonDivide;
    TDT4102::Button buttonHistory, buttonClearHist;
};
