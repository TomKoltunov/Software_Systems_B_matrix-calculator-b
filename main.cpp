/**
 * @file main.cpp
 * @author Tom Koltunov
 * @brief Checking program for 3rd assignment in Software_Systems_B course
 * @date 2022-04
 */

#include "Matrix.hpp"
using namespace std;
using namespace zich;

int main()
{
    vector<double> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> vec2 = {0, 0, 0, 0};
    Matrix mat1(vec1, 3, 3);
    Matrix mat2(vec1, 3, 3);
    Matrix mat3(vec2, 2, 2);

    try
    {
        cout << mat1 + mat2;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    catch(exception& e)
    {
        cerr << "Exception has been caught: " << e.what() << endl;
        cout << endl;
        cout << endl;
    }

    try
    {
        cout << mat1 + mat3;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    catch(exception& e)
    {
        cerr << "Exception has been caught: " << e.what() << endl;
        cout << endl;
        cout << endl;
    }
    
    try
    {
        cout << mat1 - mat2;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    catch(exception& e)
    {
        cerr << "Exception has been caught: " << e.what() << endl;
        cout << endl;
        cout << endl;
    }

    try
    {
        cout << mat1 - mat3;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    catch(exception& e)
    {
        cerr << "Exception has been caught: " << e.what() << endl;
        cout << endl;
        cout << endl;
    }

    try
    {
        cout << +mat1;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    catch(exception& e)
    {
        cerr << "Exception has been caught: " << e.what() << endl;
        cout << endl;
        cout << endl;
    }

    try
    {
        cout << -mat1;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    catch(exception& e)
    {
        cerr << "Exception has been caught: " << e.what() << endl;
        cout << endl;
        cout << endl;
    }

    try
    {
        cout << mat1 * mat2;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    catch(exception& e)
    {
        cerr << "Exception has been caught: " << e.what() << endl;
        cout << endl;
        cout << endl;
    }

    try
    {
        cout << mat1 * mat3;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    catch(exception& e)
    {
        cerr << "Exception has been caught: " << e.what() << endl;
        cout << endl;
        cout << endl;
    }

    try
    {
        cout << mat1++;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    catch(exception& e)
    {
        cerr << "Exception has been caught: " << e.what() << endl;
        cout << endl;
        cout << endl;
    }

    try
    {
        cout << mat1--;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    catch(exception& e)
    {
        cerr << "Exception has been caught: " << e.what() << endl;
        cout << endl;
        cout << endl;
    }
}