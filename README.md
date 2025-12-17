# 🧮 C++ Qt GUI Calculator

A lightweight, functional desktop calculator application built using *C++* and the *Qt Framework*. This project demonstrates the implementation of a graphical user interface (GUI) using Qt Widgets, Signal & Slot mechanisms, and grid layouts.

## 🚀 Features

* *Basic Arithmetic:* Addition, Subtraction, Multiplication, and Division.
* *Floating Point Support:* Handles decimal calculations.
* *Error Handling:* gracefully handles division by zero errors.
* *Responsive UI:* Uses QGridLayout for a clean, resizable interface.
* *Interactive Design:* Custom styling for operator and clear buttons.

## 🛠 Built With

* *Language:* C++
* *Framework:* Qt 6 (compatible with Qt 5)
* *Components:* QApplication, QWidget, QGridLayout, QLineEdit, QPushButton

## 📦 How to Build and Run

Since this is a Qt project, you will need the Qt libraries installed on your system.

### Option 1: Using Qt Creator (Recommended)
1.  Open *Qt Creator*.
2.  Select *File > New Project > Application (Qt Widgets Application)*.
3.  Replace the contents of your main.cpp with the code in this repository.
4.  Click the *Run* (green arrow) button.

### Option 2: Using Command Line (qmake)
If you want to build this manually from the terminal, follow these steps:

1.  *Create a Project File:*
    Create a file named calculator.pro in the same folder as main.cpp and add the following lines:
    qmake
    QT += core gui widgets
    TARGET = CalculatorApp
    TEMPLATE = app
    SOURCES += main.cpp
    

2.  *Build the project:*
    bash
    qmake calculator.pro
    make   # On Linux/macOS
    # OR
    nmake  # On Windows with MSVC
    

3.  *Run the application:*
    * *Linux:* ./CalculatorApp
    * *Windows:* release\CalculatorApp.exe

## 🧩 Code Overview

The project consists of a single Calculator class inheriting from QWidget.

* *Layout:* A QGridLayout organizes the display and buttons.
* *Event Handling:*
    * *Lambdas:* Used to connect number buttons to the handleButton slot to reduce boilerplate code.
    * *Slots:* calculate() performs the math logic, and clear() resets the state.
* *Logic:* The calculator uses a state machine approach (newInput, storedValue, currentOperator) to manage the input flow.

## 👤 Author

*Shahzad Ahmad*
* GitHub: [@shahzadahmaddev]

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).
