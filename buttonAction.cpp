#include "std_lib_facilities.h"
#include "buttonAction.h"
#include "widgets/TextInput.h"
#include "calculator.h"
#include "history.h"
#include "globals.h"


// Each function corresponds to a button press and updates the text field accordingly

void button1Pressed(TDT4102::TextInput& textField) {
    textField.setText(textField.getText() + "1");
}

void button2Pressed(TDT4102::TextInput& textField) {    
    textField.setText(textField.getText() + "2");
}

void button3Pressed(TDT4102::TextInput& textField) {
    textField.setText(textField.getText() + "3");
}

void button4Pressed(TDT4102::TextInput& textField) {
    textField.setText(textField.getText() + "4");
}

void button5Pressed(TDT4102::TextInput& textField) {
    textField.setText(textField.getText() + "5");
}

void button6Pressed(TDT4102::TextInput& textField) {
    textField.setText(textField.getText() + "6");
}

void button7Pressed(TDT4102::TextInput& textField) {
    textField.setText(textField.getText() + "7");
}

void button8Pressed(TDT4102::TextInput& textField) {
    textField.setText(textField.getText() + "8");
}

void button9Pressed(TDT4102::TextInput& textField) {
    textField.setText(textField.getText() + "9");
}

void button0Pressed(TDT4102::TextInput& textField) {
    textField.setText(textField.getText() + "0");
}

void buttonPlusPressed(TDT4102::TextInput& textField) {
    textField.setText(textField.getText() + "+");
}

void buttonMinusPressed(TDT4102::TextInput& textField) {
    textField.setText(textField.getText() + "-");
}

void buttonMultiplyPressed(TDT4102::TextInput& textField) {
    textField.setText(textField.getText() + "*");
}

void buttonDividePressed(TDT4102::TextInput& textField) {
    textField.setText(textField.getText() + "/");
}

void buttonEqualPressed(TDT4102::TextInput& textField) {
    try{
        std::string equation = textField.getText();
        textField.setText(textField.getText() + "=" + std::to_string(calculate(equation)));
        std::string result = textField.getText();
        writeToHistory(historyFilePath, result);

    }
    catch (exception& e){
        cout << "ERROR: " << e.what() << endl;
    }
}

void buttonClearPressed(TDT4102::TextInput& textField) {
    textField.setText("");
}


