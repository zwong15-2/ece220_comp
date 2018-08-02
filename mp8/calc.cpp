/*
 * this program is a calculator that is capable of adding, subtracting, multiplying and dividing
 * complex, real, and rational numbers. The program will first ask the user to select which operation they 
 * would like to perform in a list of 12 options. The user will then be prompted to input numbers depending on the 
 * operation they selected.
 */

#include <cmath>
#include "calc.h"
using namespace std;


// RealNumber, ComplexNumber and RationalNumber inherit from base Number class.


//==============NUMBER===============//
Number::Number(){}

Number::~Number(){}

double Number::magnitude(){return 0.0;}

void Number::print(){}

Number Number::operator + (const Number& arg)
{
    Number result;
    return result;
}

Number Number::operator - (const Number& arg)
{
    Number result;
    return result;
}

Number Number::operator * (const Number& arg)
{
    Number result;
    return result;
}

Number Number::operator / (const Number& arg)
{
    Number result;
    return result;
}

void Number::set_value(double rval){}

void Number::set_value(double rval, double ival){}



//=============real=====================//
//constructors for real number
RealNumber::RealNumber()
{
    realComponent = 0.0;
}

RealNumber::RealNumber(double rval)
{
    realComponent = rval;
}

//return the magnitiude of the real number
double RealNumber::magnitude()
{
    return abs(realComponent);
}

//print real number out
void RealNumber::print(){
    cout << "RealNumber: " << realComponent << "\n" << endl;
}

//real + real
RealNumber RealNumber::operator + (const RealNumber& arg)
{
    RealNumber result;      //declare new RealNumber to store sum 
    result.realComponent = this->realComponent + arg.realComponent;//add together real components of two realNumbers
    return result;
}

//real - real
RealNumber RealNumber::operator - (const RealNumber& arg)
{
    RealNumber result;      //declare new RealNumber to store sum                                          
    result.realComponent = this->realComponent - arg.realComponent; //subtract real components of two realNumbers
    return result;
}

//real * real
RealNumber RealNumber::operator * (const RealNumber& arg)
{
    RealNumber result;      //declare new RealNumber to store sum 
    result.realComponent = this->realComponent * arg.realComponent; //multiply real components of two realNumbers
    return result;
}

//real/real
RealNumber RealNumber::operator / (const RealNumber& arg)
{
    RealNumber result;      //declare new RealNumber to store sum 
    result.realComponent = this->realComponent / arg.realComponent; //divide real components of two realNumbers
    return result;
}

//set the value for real number
void RealNumber::set_value (double rval)
{
    realComponent = rval; //set real component equal to rval
}



//=============complex================//

ComplexNumber::ComplexNumber()
{
    imagComponent = 0.0;
}

ComplexNumber::ComplexNumber(double rval, double ival)
{
    realComponent = rval;     //set private variables equal to inputted values
    imagComponent = ival;
}

//return the magnitude of the complex number
double ComplexNumber::magnitude(){
    double mag = sqrt(((realComponent) * (realComponent)) + ((imagComponent) * (imagComponent))); //calculate magnitude
    return mag; //return value
}
//print the complexnumber
void ComplexNumber::print(){
    cout << "ComplexNumber: " << realComponent << " + " << imagComponent << "i"<< "\n" << endl; //output value of calculated output to monitor
}

//imag + imag
ComplexNumber ComplexNumber::operator + (const ComplexNumber& arg)
{
    ComplexNumber result;                                             //create new Complex number object
    result.imagComponent = this->imagComponent + arg.imagComponent;   //calculate real coponent of result
    result.realComponent = this->realComponent + arg.realComponent;
    return result;
}

//imag - imag
ComplexNumber ComplexNumber::operator - (const ComplexNumber& arg)
{
    ComplexNumber result;                                             //create new Complex number object
    result.imagComponent = this->imagComponent - arg.imagComponent;   //calculate real coponent of result
    result.realComponent = this->realComponent - arg.realComponent;   //calculate imaginary component of result
    return result;
}

//imag * imag
ComplexNumber ComplexNumber::operator * (const ComplexNumber& arg)
{
    ComplexNumber result;                                             //create new Complex number object
    result.realComponent = ((this->realComponent)*(arg.realComponent)) - ((this->imagComponent)*(arg.imagComponent)); //calculate real component of result
    result.imagComponent = (this->realComponent)*(arg.imagComponent) + (this->imagComponent)*(arg.realComponent);     //calculate imaginary component of result
    return result;
}

//imag/imag
ComplexNumber ComplexNumber::operator / (const ComplexNumber& arg)
{
    //code here
    ComplexNumber result;  //create new Complex number object                                                                                     
    result.realComponent = ((this->realComponent)*(arg.realComponent) + (this->imagComponent)*(arg.imagComponent))/(((arg.realComponent) * (arg.realComponent)) + ((arg.imagComponent)* (arg.imagComponent)));  //calculate real component of result
    result.imagComponent = ((this->imagComponent)*(arg.realComponent) - (this->realComponent)*(arg.imagComponent))/(((arg.realComponent) * (arg.realComponent)) + ((arg.imagComponent) * (arg.imagComponent))); //calculate imaginary component of result
    return result;
}

//set the complexnumber value
void ComplexNumber::set_value (double rval, double ival)
{
    realComponent = rval;   //set private variables equal to inputted variables
    imagComponent = ival;
}







//=============rational================//

RationalNumber::RationalNumber()
{
    numerator = 0;
    denominator = 1;
}

RationalNumber::RationalNumber(int numer, int denom)
{
    RationalNumber::set_value(numer, denom);
}

//return the magnitude of the rational number
double RationalNumber::magnitude(){
    double result = abs(numerator / denominator);   //return absolute value of fraction
    return result;
}

//print the rational number
void RationalNumber::print(){
    //code here
    cout << "RationalNumber: " << numerator << " / " << denominator << "\n" << endl;  //print calculated result to monitor
}

//rational + rational
RationalNumber RationalNumber::operator + (const RationalNumber& arg)
{
    RationalNumber result;
    double numer = (this->numerator)*(arg.denominator) + (this->denominator)*(arg.numerator); //add together fractions
    double denom = (this->denominator)*(arg.denominator);
    
    int divisor = gcd(numer, denom);            //find gcd of numerator and denominator
    result.numerator = abs(numer / divisor);    //divide numerator and denominator by gcd and store absolute value in memory
    result.denominator = abs(denom / divisor);
    if(numer < 0 || denom < 0){                 //if calculated numerator/denominator is negative, make numerator negative
      result.numerator = 0 - result.numerator;
    }
    return result;    //return tesult object
}

//rational - rational
RationalNumber RationalNumber::operator - (const RationalNumber& arg)
{
    RationalNumber result;    //make new result object
    double numer = (this->numerator)*(arg.denominator) - (this->denominator)*(arg.numerator); //subtract fractions
    double denom = (this->denominator)*(arg.denominator);
  
    int divisor = gcd(numer, denom);                                                          //find gcd of numerator and denominator
    result.numerator = abs(numer / divisor);                                                  //divide numerator and denominator by gcd and store absolute value in memory        
    result.denominator = abs(denom / divisor);
    if(numer < 0 || denom < 0){
      result.numerator = 0 - result.numerator;                                                //if calculated numerator/denominator is negative, make numerator negative
    }
    return result;    //return result object
}

//rational * rational
RationalNumber RationalNumber::operator * (const RationalNumber& arg)
{
  RationalNumber result;                                    //make result object to store result RationalNumber
  double numer = (this->numerator)*(arg.numerator);         //multiply fractions
  double denom = (this->denominator)*(arg.denominator);
  
  int divisor = gcd(numer, denom);                          //find gcd of numerator and denominator
  result.numerator = abs(numer / divisor);                  //divide numerator and denominator by gcd and store absolute value in memory        
  result.denominator = abs(denom / divisor);
  if(numer < 0 || denom < 0){
    result.numerator = 0 - result.numerator;                //if calculated numerator/denominator is negative, make numerator negative
  }
  return result;  //return result object
}

//rational/rational
RationalNumber RationalNumber::operator / (const RationalNumber& arg)
{
  RationalNumber result;                                    //make result object to store result RationalNumber
  double numer = (this->numerator)*(arg.denominator);       //multiply fractions
  double denom = (this->denominator)*(arg.numerator);
  
  int divisor = gcd(numer, denom);                          //find gcd of numerator and denominator
  result.numerator = abs(numer / divisor);                  //divide numerator and denominator by gcd and store absolute value in memory        
  result.denominator = abs(denom / divisor);
  if(numer < 0 || denom < 0){
    result.numerator = 0 - result.numerator;                //if calculated numerator/denominator is negative, make numerator negative
  }
  return result;  //return result object
}

//set the rational number value
void RationalNumber::set_value (int numer, int denom)
{

    int divisor = gcd(numer, denom);          //find gcd of input variables
    numerator = abs(numer / divisor);         //set private variables equal to the absolute value of the input variable divided by the gcd
    denominator = abs(denom / divisor);
    
    if((numer < 0) || (denom < 0)){           //if calculated numerator/denominator is negative, make numerator negative
      numerator = 0 - numerator;
    }
}


// helper function
int RationalNumber::gcd(int a, int b)
{
  //calculate greatest common divisor of the two inputted variables
    int c;
  
    while(b != 0){
      c = a % b;
      a = b;
      b = c;
    }
    return a;
}
