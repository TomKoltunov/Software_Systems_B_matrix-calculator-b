/**
 * @file Matrix.hpp
 * @author Tom Koltunov
 * @brief Headers file for 3rd assignment in Software_Systems_B course
 * @date 2022-04
 */

#include <iostream>
#include <vector>

using namespace std;

namespace zich
{
    class Matrix
    {
        private:
            vector<double> _mat;
            int _length;
            int _width;

        public:
            /*
            The constructor named "Matrix" recieves vector in which each spot is a double called 'mat', an integer called 'length' 
            which represents the final matrix's length and an integer called 'width' which represents the final matrix's width.
            The constructor creates new Matrix object which consists of the given parameters.
            */
            Matrix(const vector<double>& mat, int length, int width);

            /*
            The operator which signature is "operator+(const Matrix& other)" recieves a Matrix object called 'other'.
            The operator returns the sum of the Matrix objects 'this' sum 'other'.
            */
            Matrix operator+(const Matrix& other) const; //כשאני רוצה שזה יפעל על אובייקטים קבועים

            /*
            The operator which signature is "operator+=(const Matrix& other)" recieves a Matrix object called 'other'.
            The operator calculates the sum of the Matrix objects 'this' sum 'other', puts the result into 'this' Matrix object and returns it.
            */
            Matrix& operator+=(const Matrix& other);// & כי אני לא מעתיק את כל האובייקר וקונסט כי אני לא רוצה לשנות את האובייקט

            /*
            The operator which signature is "operator+()" returns the sum of the Matrix objects 'this' sum 'this'.
            */
            Matrix operator+() const;

            /*
            The operator which signature is "operator-(const Matrix& other)" recieves a Matrix object called 'other'.
            The operator returns the difference of the Matrix objects 'this' diff 'other'.
            */
            Matrix operator-(const Matrix& other) const;

            /*
            The operator which signature is "operator-=(const Matrix& other)" recieves a Matrix object called 'other'.
            The operator calculates the diffenece of the Matrix objects 'this' diff 'other', puts the result into 'this' Matrix object and 
            returns it.
            */
            Matrix& operator-=(const Matrix& other);

            /*
            The operator which signature is "operator-()" returns the result of the calculation 'this' * (-1).
            */
            Matrix operator-() const;

            /*
            The operator which signature is "operator*(const Matrix& other)" recieves a Matrix object called 'other'.
            The operator returns the multiplication of the Matrix objects 'this' mult 'other'.
            The operator uses the sub - functions named "fromVectorToMatrix" and "fromMatrixToVector" which appear above it outside the 
            namespace.
            */
            Matrix operator*(const Matrix& other) const;

            /*
            The operator which signature is "operator*(Matrix& matrix, double number)" recieves a Matrix object called 'matrix' and a double
            called 'numebr'.
            The operator returns the multiplication of the Matrix object 'matrix' mult number.
            */
            friend Matrix operator*(Matrix& matrix, double number);

            /*
            The operator which signature is "operator*(Matrix& matrix, double number)" recieves a Matrix object called 'matrix' and a double
            called 'numebr'.
            The operator returns the multiplication of number mult the Matrix object 'matrix'.
            */
            friend Matrix operator*(double number, Matrix& matrix); 

            /*
            The operator which signature is "operator*=(const Matrix& other)" recieves a Matrix object called 'other'.
            The operator calculates the multiplication of the Matrix objects 'this' mult 'other', puts the result into 'this' Matrix object and 
            returns it.
            */
            Matrix& operator*=(const Matrix& other);

            /*
            The operator which signature is "operator*=(double number)" recieves a double called 'number'.
            The operator calculates the multiplication of the Matrix object 'this' mult 'number', puts the result into 'this' Matrix object and 
            returns it.
            */
            Matrix& operator*=(double number);

            /*
            The operator which signature is "operator>(const Matrix& matrix)" recieves a Matrix object called 'other'.
            The operator returns "true" if the Matrix object 'this' is bigger than the Matrix object 'other', else it returns "false".
            */
            bool operator>(const Matrix& mat) const;

            /*
            The operator which signature is "operator>=(const Matrix& matrix)" recieves a Matrix object called 'other'.
            The operator returns "true" if the Matrix object 'this' is bigger than or equals to the Matrix object 'other', else it returns 
            "false".
            */
            bool operator>=(const Matrix& mat) const;

            /*
            The operator which signature is "operator<(const Matrix& matrix)" recieves a Matrix object called 'other'.
            The operator returns "true" if the Matrix object 'this' is smaller than the Matrix object 'other', else it returns "false".
            */
            bool operator<(const Matrix& mat) const;

            /*
            The operator which signature is "operator<=(const Matrix& matrix)" recieves a Matrix object called 'other'.
            The operator returns "true" if the Matrix object 'this' is smaller than or equals to the Matrix object 'other', else it returns 
            "false".
            */
            bool operator<=(const Matrix& mat) const;

            /*
            The operator which signature is "operator==(const Matrix& matrix)" recieves a Matrix object called 'other'.
            The operator returns "true" if the Matrix object 'this' is equals to the Matrix object 'other', else it returns "false".
            */
            bool operator==(const Matrix& mat) const;

            /*
            The operator which signature is "operator!=(const Matrix& matrix)" recieves a Matrix object called 'other'.
            The operator returns "true" if the Matrix object 'this' isn't equals to the Matrix object 'other', else it returns "false".
            */
            bool operator!=(const Matrix& mat) const;

            /*
            The operator which signature is "operator++()" first adds 1 to the Matrix object 'this' and then returns 'this'.
            */
            Matrix& operator++();

            /*
            The operator which signature is "operator--()" first takes 1 from the Matrix object 'this' and then returns 'this'.
            */
            Matrix& operator--();

            /*
            The operator which signature is "operator++(int number)" first returns the Matrix object 'this' and then adds 1 to it.
            */
            Matrix operator++(int);

            /*
            The operator which signature is "operator--(int number)" first returns the Matrix object 'this' and then takes 1 from it.
            */
            Matrix operator--(int);

            /*
            The operator which signature is "operator<<(ostream& output, const Matrix& mat)" receives the output device and a Matrix 
            object and it outputs the Matrix object to the given output device.
            */
            friend ostream& operator<<(ostream& output, const Matrix& mat);

            /*
            The operator which signature is "operator>>(istream& input , Matrix& mat)" receives the input device and a Matrix 
            object and it inputs the Matrix object from the given output device.
            */
            friend istream& operator>>(istream& input , Matrix& mat);
    };
}