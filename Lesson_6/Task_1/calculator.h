#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();
private slots:
    void addNumber();
    void clearNumbers();
    void operation();
    void calculateResult();

private:
    char tens = 0;
    int64_t currentNumber = 0;
    int64_t storedNumber = 0;
    QString storedOperation = "";
    Ui::Calculator *ui;

    void updateNumber(int number);
};
#endif // CALCULATOR_H
