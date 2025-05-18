#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect(ui->btn0, &QAbstractButton::clicked, this, &Calculator::addNumber);
    connect(ui->btn1, &QAbstractButton::clicked, this, &Calculator::addNumber);
    connect(ui->btn2, &QAbstractButton::clicked, this, &Calculator::addNumber);
    connect(ui->btn3, &QAbstractButton::clicked, this, &Calculator::addNumber);
    connect(ui->btn4, &QAbstractButton::clicked, this, &Calculator::addNumber);
    connect(ui->btn5, &QAbstractButton::clicked, this, &Calculator::addNumber);
    connect(ui->btn6, &QAbstractButton::clicked, this, &Calculator::addNumber);
    connect(ui->btn7, &QAbstractButton::clicked, this, &Calculator::addNumber);
    connect(ui->btn8, &QAbstractButton::clicked, this, &Calculator::addNumber);
    connect(ui->btn9, &QAbstractButton::clicked, this, &Calculator::addNumber);

    connect(ui->btnClear, &QAbstractButton::clicked, this, &Calculator::clearNumbers);

    connect(ui->btnPlus, &QAbstractButton::clicked, this, &Calculator::operation);
    connect(ui->btnSubtract, &QAbstractButton::clicked, this, &Calculator::operation);
    connect(ui->btnMulti, &QAbstractButton::clicked, this, &Calculator::operation);
    connect(ui->btnDivide, &QAbstractButton::clicked, this, &Calculator::operation);
    connect(ui->btnRoot, &QAbstractButton::clicked, this, &Calculator::operation);
    connect(ui->btnPow, &QAbstractButton::clicked, this, &Calculator::operation);

    connect(ui->btnEqual, &QAbstractButton::clicked, this, &Calculator::calculateResult);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::updateNumber(int number)
{
    ui->lcdNumber->display(number);
}

void Calculator::addNumber()
{
    int buttonValue = qobject_cast<QPushButton*>(sender())->text().toInt();
    if(tens < 9){
        currentNumber = currentNumber * 10 + buttonValue;
        tens++;
    }
    updateNumber(currentNumber);
}

void Calculator::clearNumbers()
{
    currentNumber = 0;
    storedNumber = 0;
    tens = 0;
    updateNumber(currentNumber);
}

void Calculator::operation()
{
    storedOperation = qobject_cast<QPushButton*>(sender())->text();
    tens = 0;
    if (storedOperation == "sqrt")
    {
        currentNumber = sqrt(currentNumber);
        updateNumber(currentNumber);
        return;
    }
    storedNumber = currentNumber;
    currentNumber = 0;
    updateNumber(currentNumber);

}

void Calculator::calculateResult()
{
    int64_t result = 0;
    tens = 0;
    if(storedOperation == "+"){
        result = storedNumber + currentNumber;
    } else if (storedOperation == "-"){
        result = storedNumber - currentNumber;
    } else if (storedOperation == "x"){
        result = storedNumber * currentNumber;
    } else if (storedOperation == "/" && currentNumber != 0){
        result = storedNumber / currentNumber;
    } else if (storedOperation == "^"){
        result = pow(storedNumber, currentNumber);
    }
    currentNumber = 0;
    storedNumber = 0;
    storedOperation = "";
    if(result >= pow(10, 10)) result = 999999999;
    updateNumber(result);
}
