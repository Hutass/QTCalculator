#include "calculator.h"

#include <string>

using namespace std;

Calculator::Calculator()
{

}
QString Calculator::Calculate(QString inputExpression)
{
    int maxExpressionLenght = 5;
    double number[maxExpressionLenght];
    for(int i=0;i<maxExpressionLenght;i++)
        number[i] = 0.0;
    char sign[maxExpressionLenght];

    int stringLength = inputExpression.length();
    QByteArray stringArray = inputExpression.toLocal8Bit();
    char* convertedString = stringArray.data();

    QString bufString = "";
    int numberArrayIterator = 0;

    for(int i=0; i<stringLength; i++)
    {
        switch(convertedString[i])
        {
        case '0' ... '9':
        case '.':
            bufString += convertedString[i];
            break;
        case '+': case '-': case '*': case '/': case '%':
            number[numberArrayIterator % maxExpressionLenght] = bufString.toDouble();
            sign[numberArrayIterator % maxExpressionLenght] = convertedString[i];
            bufString = "";
            numberArrayIterator++;
            break;
        }
    }
    number[numberArrayIterator % maxExpressionLenght] = bufString.toDouble();

    if(numberArrayIterator == 0)
        return "Некорректная запись выражения!";

    if(numberArrayIterator < maxExpressionLenght)
    {
        for(int i=0; i<numberArrayIterator;i++)
        {
            switch(sign[i])
            {
            case '+':
                number[i+1] = number[i] + number[i+1];
                break;
            case '-':
                number[i+1] = number[i] - number[i+1];
                break;
            case '*':
                number[i+1] = number[i] * number[i+1];
                break;
            case '/':
                if(number[i+1] != 0.0)
                    number[i+1] = number[i] / number[i+1];
                else
                    return "Деление на ноль!";
                break;
            case '%':
                if(number[i+1] != 0.0)
                {
                    if((int)(number[i] / number[i+1])*number[i+1] <= number[i])
                        number[i+1] = number[i] - (int)(number[i] / number[i+1])*number[i+1];
                        else
                        number[i+1] = number[i] - ((int)(number[i] / number[i+1])-1)*number[i+1];
                }
                else
                    return "Деление на ноль!";
                break;
            }
        }
        return QString::number(number[numberArrayIterator],'g',6);
    }
    else
    {
        return "Превышен предел операций: " + QString::number(maxExpressionLenght) + "!";
    }
}
