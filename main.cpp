#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFont>

class Calculator : public QWidget {
    Q_OBJECT

private:
    QLineEdit* display;
    QString currentValue;
    QString storedValue;
    QString currentOperator;
    bool newInput;

public:
    Calculator(QWidget* parent = nullptr) : QWidget(parent) {
        currentValue = "0";
        storedValue = "";
        currentOperator = "";
        newInput = true;

        setWindowTitle("Calculator");
        setFixedSize(320, 400);

        QGridLayout* layout = new QGridLayout(this);
        layout->setSpacing(5);

        // Display
        display = new QLineEdit("0");
        display->setReadOnly(true);
        display->setAlignment(Qt::AlignRight);
        display->setFont(QFont("Arial", 20));
        display->setStyleSheet("QLineEdit { padding: 10px; background-color: #f0f0f0; }");
        layout->addWidget(display, 0, 0, 1, 4);

        // Button labels
        QStringList buttons = {
            "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "0", ".", "=", "+"
        };

        // Create buttons
        int row = 1, col = 0;
        for (const QString& label : buttons) {
            QPushButton* btn = new QPushButton(label);
            btn->setFont(QFont("Arial", 16));
            btn->setMinimumSize(70, 70);

            if (label == "=" || label == "+" || label == "-" || label == "*" || label == "/") {
                btn->setStyleSheet("QPushButton { background-color: #ff9500; color: white; } "
                                   "QPushButton:pressed { background-color: #cc7700; }");
            } else {
                btn->setStyleSheet("QPushButton { background-color: #e0e0e0; } "
                                   "QPushButton:pressed { background-color: #c0c0c0; }");
            }

            connect(btn, &QPushButton::clicked, this, [this, label]() { handleButton(label); });
            layout->addWidget(btn, row, col);

            col++;
            if (col > 3) {
                col = 0;
                row++;
            }
        }

        // Clear button
        QPushButton* clearBtn = new QPushButton("C");
        clearBtn->setFont(QFont("Arial", 16));
        clearBtn->setMinimumSize(70, 70);
        clearBtn->setStyleSheet("QPushButton { background-color: #ff3b30; color: white; } "
                                "QPushButton:pressed { background-color: #cc2f26; }");
        connect(clearBtn, &QPushButton::clicked, this, &Calculator::clear);
        layout->addWidget(clearBtn, 5, 0, 1, 4);
    }

private slots:
    void handleButton(const QString& label) {
        if (label >= "0" && label <= "9") {
            if (newInput) {
                currentValue = label;
                newInput = false;
            } else {
                if (currentValue == "0") {
                    currentValue = label;
                } else {
                    currentValue += label;
                }
            }
            display->setText(currentValue);
        }
        else if (label == ".") {
            if (!currentValue.contains(".")) {
                currentValue += ".";
                display->setText(currentValue);
            }
        }
        else if (label == "=") {
            calculate();
        }
        else { // Operator
            if (!currentOperator.isEmpty() && !newInput) {
                calculate();
            }
            storedValue = currentValue;
            currentOperator = label;
            newInput = true;
        }
    }

    void calculate() {
        if (currentOperator.isEmpty() || storedValue.isEmpty()) {
            return;
        }

        double num1 = storedValue.toDouble();
        double num2 = currentValue.toDouble();
        double result = 0;

        if (currentOperator == "+") {
            result = num1 + num2;
        } else if (currentOperator == "-") {
            result = num1 - num2;
        } else if (currentOperator == "*") {
            result = num1 * num2;
        } else if (currentOperator == "/") {
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                display->setText("Error");
                clear();
                return;
            }
        }

        currentValue = QString::number(result);
        display->setText(currentValue);
        currentOperator = "";
        storedValue = "";
        newInput = true;
    }

    void clear() {
        currentValue = "0";
        storedValue = "";
        currentOperator = "";
        newInput = true;
        display->setText("0");
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Calculator calc;
    calc.show();
    return app.exec();
}

#include "main.moc"
