#include "mathe.h"
#include <string>
#include <iostream>
#include <ctime>



Number::~Number()
{
    delete value;
    delete name;
}

void diesIstEinTest()
{
    std::cout << "ERFOLG ^^" << std::endl;
}
Number::Number(double v)
{
    value = new double;
    *value = v;
}

Number Number::operator+(Number &number)
{
    return Number(*(this->value) + number.getValue());
}

void Number::operator<<(Number &number)
{
    *(this->value) += number.getValue();
}

Number::Number(bool randomNumber)
{
    if(randomNumber == 0)
    {
        *value = 0;
    }
    else
    {
        int zahl1 = clock();
        for(int i=0; i<9999999; i++)
        {}
        int zahl2 = clock();
        int zahl3 = zahl2 + zahl1;
        *value = ((zahl3 + zahl2 + zahl1)*999) % 100;
    }
}
void Number::setValue(double v)
{
    *(this->value) = v;
}

void Number::changeValue(double v)
{
    *(this->value) += v;
}

double Number::getSquare()const
{
    return (*value)*(*value);
}

double Number::getRoot()const
{
    double x = *value;
    double y = 1;
    for(int i=0; i<9999; i++) // HERON VERFAHREN
    {
        x = (x+y)/2;
        y = (*value)/x;
    }
    return (x+y)/2;
}

void Number::setName(std::string n)
{
    *name = n;
}

std::string Number::getName()const
{
    return *name;
}
int Number::getInvert()const
{
    int x1 = int(*value)%10;
    int x2 = int(*value)/10;
    return int((*value)-(x2-x1)*9);
}

double Number::getValue()const
{
    return *value;
}

void Number::doSquare()
{
    *value = (*value)*(*value);
}

void Number::doRoot()
{
    double x = *value;
    double y = 1;
    for(int i=0; i<9999; i++) // HERON VERFAHREN
    {
        x = (x+y)/2;
        y = (*value)/x;
    }
    *value = (x+y)/2;
}

void Number::doInvert()
{
    int x1 = int(*value)%10;
    int x2 = int(*value)/10;
    *value = (*value)-(x2-x1)*9;
}
Circle::~Circle()
{
    delete radius;
    delete diameter;
    delete circumference;
    delete area;
    delete name;
}

Circle::Circle(double value, std::string mode)
{
    if(mode == "R")
    {
        name = new std::string;
        radius = new double;
        diameter = new double;
        circumference = new double;
        area = new double;

        *name = "Unnamed";
        *area = value*value*MATHE_PI;
        *radius = value;
        *diameter = value*2;
        *circumference = value*2*MATHE_PI;
    }
    else if(mode == "C")
    {
        name = new std::string;
        radius = new double;
        diameter = new double;
        circumference = new double;
        area = new double;

        *name = "Unnamed";
        *circumference = value;
        *radius = value/(MATHE_PI*2);
        *diameter = 2*(value/(MATHE_PI*2));
        *area = (*radius)*(*radius)*MATHE_PI;
    }
    else if(mode == "D")
    {
        name = new std::string;
        diameter = new double;
        radius = new double;
        circumference = new double;
        area = new double;

        *name = "Unnamed";
        *area = value*value*(MATHE_PI/4);
        *diameter = value;
        *radius = (value)/2;
        *circumference = ((value)/2)*2*MATHE_PI;
    }
    else if(mode == "A")
    {
        name = new std::string;
        diameter = new double;
        radius = new double;
        circumference = new double;
        area = new double;
        Number nvalue = (4*value)/MATHE_PI;

        *name = "Unnamed";
        *diameter = nvalue.getRoot();
        *radius = *diameter/2;
        *area = value;
        *circumference = (*radius)*2*MATHE_PI;
    }
    else
    {
        std::cout << "Error, no mode called " << mode << "!" << std::endl;
        diameter = new double;
        radius = new double;
        circumference = new double;
        area = new double;
        name = new std::string;

        *name = "Failed:Unnamed";
        *diameter = 0;
        *radius = 0;
        *circumference = 0;
        *area = 0;
    }
}

Circle::Circle(double value, std::string mode, std::string n)
{
    if(mode == "R")
    {
        name = new std::string;
        radius = new double;
        diameter = new double;
        circumference = new double;
        area = new double;

        *area = value*value*MATHE_PI;
        *radius = value;
        *diameter = value*2;
        *circumference = value*2*MATHE_PI;
        *name = n;
    }
    else if(mode == "C")
    {
        name = new std::string;
        radius = new double;
        diameter = new double;
        circumference = new double;
        area = new double;

        *circumference = value;
        *radius = value/(MATHE_PI*2);
        *diameter = 2*(value/(MATHE_PI*2));
        *area = (*radius)*(*radius)*MATHE_PI;
        *name = n;
    }
    else if(mode == "D")
    {
        name = new std::string;
        diameter = new double;
        radius = new double;
        circumference = new double;
        area = new double;

        *area = value*value*(MATHE_PI/4);
        *diameter = value;
        *radius = (value)/2;
        *circumference = ((value)/2)*2*MATHE_PI;
        *name = n;
    }
    else if(mode == "A")
    {
        name = new std::string;
        diameter = new double;
        radius = new double;
        circumference = new double;
        area = new double;
        Number nvalue = (4*value)/MATHE_PI;
        *diameter = nvalue.getRoot();
        *radius = *diameter/2;
        *area = value;
        *circumference = (*radius)*2*MATHE_PI;
        *name = n;
    }
    else
    {
        name = new std::string;
        std::cout << "Error, no mode called " << mode << "!" << std::endl;
        diameter = new double;
        radius = new double;
        circumference = new double;
        area = new double;

        *diameter = 0;
        *radius = 0;
        *circumference = 0;
        *area = 0;
        *name = "Failed:Unnamed";
    }
}

void Circle::setRadius(double value)
{
    *radius = value;
    *diameter = value/2;
    *circumference = value*2*MATHE_PI;
    *area = value*value*MATHE_PI;
}

void Circle::setCircumference(double value)
{
    *circumference = value;
    *radius = value/((MATHE_PI)*2);
    *diameter = 2*(value/(MATHE_PI*2));
    *area = (*radius)*(*radius)*MATHE_PI;
}

void Circle::setDiameter(double value)
{
    *diameter = value;
    *radius = value/2;
    *circumference = (value/2)*2*MATHE_PI;
    *area = (*radius)*(*radius)*MATHE_PI;
}

double Circle::getRadius()const
{
    return *radius;
}

std::string Circle::getName()const
{
    return *name;
}

void Circle::setName(std::string n)
{
    *name = n;
}

double Circle::getCircumference()const
{
    return *circumference;
}

double Circle::getDiameter()const
{
    return *diameter;
}

double Circle::getArea()const
{
    return *area;
}

void Circle::setArea(double value)
{
    Number nvalue = value/MATHE_PI;
    *area = value;
    *radius = nvalue.getRoot();
    *diameter = 2*(*radius);
    *circumference = 2*(*radius);
}

/*squareFc::squareFc(double vp, double vq)          COMMING SOON!!
{
    p = vp;3.14159265359
    q = vq;
}

double squareFc::getpX()
{
    Number value((p/2)-q, 0);
    return -(p/2)+value.getRoot();
}

void squareFc::dopX(Number number)
{
    Number value((p/2)*(p/2)-q, 0);
    number.setValue((-(p/2))-value.getRoot());
    return;
}

double squareFc::getP()
{
    return p;
}
double squareFc::getQ()
{
    return q;
}

void squareFc::printFc()
{
    std::cout << "x^2+" << p << "x+" << q << "=0" << std::endl;
}*/
