#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"
#include <iostream>
#include "buttonAction.h"
#include "globals.h"
#include "history.h"
#include "calculatorWindow.h"

int main() {
    CalculatorWindow win{100, 100, 400, 600, "Calculator"};
    win.wait_for_close();
    return 0;
}
