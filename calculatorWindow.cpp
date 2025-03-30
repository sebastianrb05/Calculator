#include "calculatorWindow.h"
#include "buttonAction.h"
#include "globals.h"
#include "history.h"

using namespace TDT4102;

CalculatorWindow::CalculatorWindow(int x, int y, int width, int height, const std::string& title)
    : AnimationWindow{x, y, width, height, title},
      textField{{0, 0}, 300, 90, ""},
      button1{{20, 100}, 60, 60, "1"},
      button2{{90, 100}, 60, 60, "2"},
      button3{{160, 100}, 60, 60, "3"},
      button4{{20, 170}, 60, 60, "4"},
      button5{{90, 170}, 60, 60, "5"},
      button6{{160, 170}, 60, 60, "6"},
      button7{{20, 240}, 60, 60, "7"},
      button8{{90, 240}, 60, 60, "8"},
      button9{{160, 240}, 60, 60, "9"},
      buttonC{{20, 310}, 60, 60, "C"},
      button0{{90, 310}, 60, 60, "0"},
      buttonEqual{{160, 310}, 60, 60, "="},
      buttonPlus{{230, 100}, 60, 60, "+"},
      buttonMinus{{230, 170}, 60, 60, "-"},
      buttonMultiply{{230, 240}, 60, 60, "*"},
      buttonDivide{{230, 310}, 60, 60, "/"},
      buttonHistory{{20, 400}, 270, 60, "History"},
      buttonClearHist{{20, 470}, 270, 60, "Clear History"}
{
    setupCallbacks();

    // Add all widgets
    add(textField);

    add(button1); add(button2); add(button3);
    add(button4); add(button5); add(button6);
    add(button7); add(button8); add(button9);
    add(button0); add(buttonEqual); add(buttonC);

    add(buttonPlus); add(buttonMinus);
    add(buttonMultiply); add(buttonDivide);

    add(buttonHistory); add(buttonClearHist);
}

void CalculatorWindow::setupCallbacks() {
    button1.setCallback([this]() { button1Pressed(textField); });
    button2.setCallback([this]() { button2Pressed(textField); });
    button3.setCallback([this]() { button3Pressed(textField); });
    button4.setCallback([this]() { button4Pressed(textField); });
    button5.setCallback([this]() { button5Pressed(textField); });
    button6.setCallback([this]() { button6Pressed(textField); });
    button7.setCallback([this]() { button7Pressed(textField); });
    button8.setCallback([this]() { button8Pressed(textField); });
    button9.setCallback([this]() { button9Pressed(textField); });
    button0.setCallback([this]() { button0Pressed(textField); });
    buttonPlus.setCallback([this]() { buttonPlusPressed(textField); });
    buttonMinus.setCallback([this]() { buttonMinusPressed(textField); });
    buttonMultiply.setCallback([this]() { buttonMultiplyPressed(textField); });
    buttonDivide.setCallback([this]() { buttonDividePressed(textField); });
    buttonEqual.setCallback([this]() { buttonEqualPressed(textField); });
    buttonC.setCallback([this]() { buttonClearPressed(textField); });
    buttonHistory.setCallback([this]() { getLastEquation(textField, historyFilePath); });
    buttonClearHist.setCallback([]() { clearHistory(historyFilePath); });
}
