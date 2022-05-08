#include "Matrix.hpp"
using namespace std;

/*
The sub - function named "fromMatrixToVector" receives vector in which each spot consists of vector in which each spot is a double
called 'matrix', an integer called 'length' which represents 'matrix's length and an integer called 'width' which represents 'matrix's 
width.
The function returns vector in which each spot is a double - this vector is 'matrix' after the convertion.
*/
vector<double> fromMatrixToVector(vector<vector<double>> matrix, int length, int width)
{
    vector<double> vec((size_t)(length * width)); // Creating the vector which will represent the vector form of 'matrix' and giving 
                                                  // its size
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            vec[(size_t)index++] = matrix[(size_t)i][(size_t)j]; // Copying each 'matrix's spot to 'vec'
        }
    }
    return vec;
}

/*
The sub - function named "fromVectorToMatrix" receives vector in which each spot is a double called 'vec', an integer called 'length' 
which represents the final matrix's length and an integer called 'width' which represents the final matrix's width.
The function returns vector in which each spot consists of a vector in which each spot is a double - this matirx is 'vec' after the 
convertion.
*/
vector<vector<double>> fromVectorToMatrix(vector<double> vec, int length, int width)
{
    vector<vector<double>> matrix; // Creating the vector in which each spot consists of a vector in which each spot is a double that
                                   // will represent the matrix form of 'vec'
    matrix.resize((size_t)length); // Setting the number of rows of 'matrix' ('matrix's length)
    for (int i = 0; i < matrix.size(); i++) // The target of this loop is to set the number of columns of 'matrix' ('matrix's width)
                                            // 0 <= i <= 'length'
    {
        matrix[(size_t)i].resize((size_t)width); // Setting the number of columns of 'matrix's i"th row to be equal to 'matrix's width.
    }
    int index = 0;
    for (int i = 0; i < matrix.size(); i++) // 0 <= i <= 'length'
    {
        for (int j = 0; j < matrix[0].size(); j++) // 0 <= j <= 'width'
        {
            matrix[(size_t)i][(size_t)j] = vec[(size_t)index++]; // Copying each 'vec's spot to 'matrix'
        }
    }
    return matrix;
}

namespace zich
{   
    /*
    The constructor named "Matrix" recieves vector in which each spot is a double called 'mat', an integer called 'length' 
    which represents the final matrix's length and an integer called 'width' which represents the final matrix's width.
    The constructor creates new Matrix object which consists of the given parameters.
    */
    Matrix::Matrix(const vector<double>& mat, int length, int width)
    {
        if (length <= 0)
        {
            throw invalid_argument{"Matrix length should be positive"};
        }
        if (width <= 0)
        {
            throw invalid_argument{"Matrix width should be positive"};
        }
        if (mat.size() != length * width)
        {
            throw invalid_argument{"Matrix size should be equal to length multiplied by width"};
        }
        this -> _mat = mat;
        this -> _length = length;
        this -> _width = width;
    } 

    /*
    The operator which signature is "operator+(const Matrix& other)" recieves a Matrix object called 'other'.
    The operator returns the sum of the Matrix objects 'this' sum 'other'.
    */
    Matrix Matrix::operator+(const Matrix& other) const
    {
        vector<double> mat = this ->_mat;
        int length = this -> _length;
        int width = this -> _width;
        if (length != other._length || width != other._width)
        {
            throw invalid_argument{"Unable to sum matrix named 'other' to this matrix"};
        }
        vector<double> vec ((size_t)(length * width));
        for (int i = 0; i < vec.size(); i++) 
        {
            vec[(size_t)i] = mat[(size_t)i] + other._mat[(size_t)i];
        }
        Matrix matrix{vec, length, width};
        return matrix;
    }

    /*
    The operator which signature is "operator+=(const Matrix& other)" recieves a Matrix object called 'other'.
    The operator calculates the sum of the Matrix objects 'this' sum 'other', puts the result into 'this' Matrix object and returns it.
    */
    Matrix& Matrix::operator+=(const Matrix& other)
    {
        vector<double> mat = this ->_mat;
        int length = this -> _length;
        int width = this -> _width;
        if (length != other._length || width != other._width)
        {
            throw invalid_argument{"Unable to sum matrix named 'other' to this matrix"};
        }
        for (int i = 0; i < other._mat.size(); i++)
        {
            this ->_mat[(size_t)i] = this ->_mat[(size_t)i] + other._mat[(size_t)i];
        }
        return *this;
    }

    /*
    The operator which signature is "operator+()" returns the sum of the Matrix objects 'this' sum 'this'.
    */
    Matrix Matrix::operator+() const
    {
        Matrix matrix{this -> _mat, this -> _length, this -> _width};
        return matrix;
    }

    /*
    The operator which signature is "operator-(const Matrix& other)" recieves a Matrix object called 'other'.
    The operator returns the difference of the Matrix objects 'this' diff 'other'.
    */
    Matrix Matrix::operator-(const Matrix& other) const
    {
        vector<double> mat = this ->_mat;
        int length = this -> _length;
        int width = this -> _width;
        if (length != other._length || width != other._width)
        {
            throw invalid_argument{"Unable to subtract matrix named 'other' from this matrix"};
        }
        vector<double> vec ((size_t)(length * width));
        for (int i = 0; i < vec.size(); i++) 
        {
            vec[(size_t)i] = mat[(size_t)i] - other._mat[(size_t)i];
        }
        Matrix matrix{vec, length, width};
        return matrix;
    }

    /*
    The operator which signature is "operator-=(const Matrix& other)" recieves a Matrix object called 'other'.
    The operator calculates the diffenece of the Matrix objects 'this' diff 'other', puts the result into 'this' Matrix object and 
    returns it.
    */
    Matrix& Matrix::operator-=(const Matrix& other)
    {
        vector<double> mat = this ->_mat;
        int length = this -> _length;
        int width = this -> _width;
        if (length != other._length || width != other._width)
        {
            throw invalid_argument{"Unable to subtract matrix named 'other' from this matrix"};
        }
        for (int i = 0; i < other._mat.size(); i++)
        {
            this ->_mat[(size_t)i] = this ->_mat[(size_t)i] - other._mat[(size_t)i];
        }
        return *this;
    }

    /*
    The operator which signature is "operator-()" returns the result of the calculation 'this' * (-1).
    */
    Matrix Matrix::operator-() const
    {
        vector<double> mat = this ->_mat;
        int length = this -> _length;
        int width = this -> _width;
        vector<double> vec ((size_t)(length * width));
        for (int i = 0; i < vec.size(); i++)
        {
            vec[(size_t)i] = mat[(size_t)i] * (-1);
        }
        Matrix matrix{vec, length, width};
        return matrix;
    }

    /*
    The operator which signature is "operator*(const Matrix& other)" recieves a Matrix object called 'other'.
    The operator returns the multiplication of the Matrix objects 'this' mult 'other'.
    The operator uses the sub - functions named "fromVectorToMatrix" and "fromMatrixToVector" which appear above it outside the 
    namespace.
    */
    Matrix Matrix::operator*(const Matrix& other) const
    {
        vector<double> mat = this ->_mat;
        int length = this -> _length;
        int width = this -> _width;
        if (width != other._length)
        {
            throw invalid_argument{"Unable to multiply matrix named 'other' by this matrix"};
        }
        vector<vector<double>> matrix;
        matrix.resize((size_t)length);
        vector<vector<double>> matrix1 = fromVectorToMatrix(mat, length, width);
        vector<vector<double>> matrix2 = fromVectorToMatrix(other._mat, other._length, other._width);
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[(size_t)i].resize((size_t)other._width);
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                for (int p = 0; p < width; p++)
                {
                    matrix[(size_t)i][(size_t)j] = matrix[(size_t)i][(size_t)j] + matrix1[(size_t)i][(size_t)p] * matrix2[(size_t)p][(size_t)j];
                }
            }
        }
        vector<double> vec = fromMatrixToVector(matrix, matrix.size(), matrix[0].size());
        Matrix finalMatrix{vec, static_cast<int>(matrix.size()), static_cast<int>(matrix[0].size())};
        return finalMatrix;
    }

    /*
    The operator which signature is "operator*(Matrix& matrix, double number)" recieves a Matrix object called 'matrix' and a double
    called 'numebr'.
    The operator returns the multiplication of the Matrix object 'matrix' mult number.
    */
    Matrix operator*(Matrix& matrix, double number)
    {
        Matrix answer = number * matrix;
        return answer;
    }

    /*
    The operator which signature is "operator*(Matrix& matrix, double number)" recieves a Matrix object called 'matrix' and a double
    called 'numebr'.
    The operator returns the multiplication of number mult the Matrix object 'matrix'.
    */
    Matrix operator*(double number, Matrix& matrix)
    {
        Matrix mat{matrix._mat, matrix._length, matrix._width};
        for (int i = 0; i < mat._mat.size(); i++)
        {
            mat._mat[(size_t)i] = mat._mat[(size_t)i] * number;
        }
        return mat;
    }

    /*
    The operator which signature is "operator*=(const Matrix& other)" recieves a Matrix object called 'other'.
    The operator calculates the multiplication of the Matrix objects 'this' mult 'other', puts the result into 'this' Matrix object and 
    returns it.
    */
    Matrix& Matrix::operator*=(const Matrix& other)
    {
        if (this -> _width != other._length)
        {
            throw invalid_argument{"Unable to multiply matrix named 'other' by this matrix"};
        }
        Matrix matrix = (*this)*other;
        this -> _mat = matrix._mat;
        this -> _length = matrix._length;
        this -> _width = matrix._width;
        return *this;
    }

    /*
    The operator which signature is "operator*=(double number)" recieves a double called 'number'.
    The operator calculates the multiplication of the Matrix object 'this' mult 'number', puts the result into 'this' Matrix object and 
    returns it.
    */
    Matrix& Matrix::operator*=(double number)
    {
        for (int i = 0; i < this ->_mat.size(); i++)
        {
            this ->_mat[(size_t)i] = this ->_mat[(size_t)i] * number;
        }
        return *this;
    }

    /*
    The operator which signature is "operator>(const Matrix& matrix)" recieves a Matrix object called 'other'.
    The operator returns "true" if the Matrix object 'this' is bigger than the Matrix object 'other', else it returns "false".
    */
    bool Matrix::operator>(const Matrix& matrix) const
    {
        vector<double> mat = this ->_mat;
        int length = this -> _length;
        int width = this -> _width;
        if (length != matrix._length || width != matrix._width)
        {
            throw invalid_argument{"Unable to compare matrix named 'matrix' to this matrix"};
        }
        double sum1 = 0;
        double sum2 = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            sum1 = sum1 + mat[(size_t)i];
            sum2 = sum2 + matrix._mat[(size_t)i];
        }
        return (sum1 > sum2);
    }

    /*
    The operator which signature is "operator>=(const Matrix& matrix)" recieves a Matrix object called 'other'.
    The operator returns "true" if the Matrix object 'this' is bigger than or equals to the Matrix object 'other', else it returns 
    "false".
    */
    bool Matrix::operator>=(const Matrix& matrix) const
    {
        int length = this -> _length;
        int width = this -> _width;
        if (length != matrix._length || width != matrix._width)
        {
            throw invalid_argument{"Unable to compare matrix named 'matrix' to this matrix"};
        }
        return (*this > matrix || *this == matrix);
    }

    /*
    The operator which signature is "operator<(const Matrix& matrix)" recieves a Matrix object called 'other'.
    The operator returns "true" if the Matrix object 'this' is smaller than the Matrix object 'other', else it returns "false".
    */
    bool Matrix::operator<(const Matrix& matrix) const
    {
        vector<double> mat = this ->_mat;
        int length = this -> _length;
        int width = this -> _width;
        if (length != matrix._length || width != matrix._width)
        {
            throw invalid_argument{"Unable to compare matrix named 'matrix' to this matrix"};
        }
        double sum1 = 0;
        double sum2 = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            sum1 = sum1 + mat[(size_t)i];
            sum2 = sum2 + matrix._mat[(size_t)i];
        }
        return (sum1 < sum2);
    }

    /*
    The operator which signature is "operator<=(const Matrix& matrix)" recieves a Matrix object called 'other'.
    The operator returns "true" if the Matrix object 'this' is smaller than or equals to the Matrix object 'other', else it returns 
    "false".
    */
    bool Matrix::operator<=(const Matrix& matrix) const
    {
        int length = this -> _length;
        int width = this -> _width;
        if (length != matrix._length || width != matrix._width)
        {
            throw invalid_argument{"Unable to compare matrix named 'matrix' to this matrix"};
        }
        return (*this < matrix || *this == matrix);
    }

    /*
    The operator which signature is "operator==(const Matrix& matrix)" recieves a Matrix object called 'other'.
    The operator returns "true" if the Matrix object 'this' is equals to the Matrix object 'other', else it returns "false".
    */
    bool Matrix::operator==(const Matrix& matrix) const
    {
        vector<double> mat = this ->_mat;
        int length = this -> _length;
        int width = this -> _width;
        if (length != matrix._length || width != matrix._width)
        {
            throw invalid_argument{"Unable to compare matrix named 'matrix' to this matrix"};
        }
        bool answer = true;
        for (int i = 0; i < mat.size(); i++)
        {
            if (mat[(size_t)i] != matrix._mat[(size_t)i])
            {
                answer = false;
                break;
            }
        }
        return answer;
    }

    /*
    The operator which signature is "operator!=(const Matrix& matrix)" recieves a Matrix object called 'other'.
    The operator returns "true" if the Matrix object 'this' isn't equals to the Matrix object 'other', else it returns "false".
    */
    bool Matrix::operator!=(const Matrix& matrix) const
    {
        int length = this -> _length;
        int width = this -> _width;
        if (length != matrix._length || width != matrix._width)
        {
            throw invalid_argument{"Unable to compare matrix named 'matrix' to this matrix"};
        }
        return (!(*this == matrix));
    }

    /*
    The operator which signature is "operator++()" first adds 1 to the Matrix object 'this' and then returns 'this'.
    */
    Matrix& Matrix::operator++()
    {
        for (int i = 0; i < this -> _mat.size(); i++)
        {
            this -> _mat[(size_t)i]++;
        }
        return *this;
    }

    /*
    The operator which signature is "operator--()" first takes 1 from the Matrix object 'this' and then returns 'this'.
    */
    Matrix& Matrix::operator--()
    {
        for (int i = 0; i < this -> _mat.size(); i++)
        {
            this -> _mat[(size_t)i]--;
        }
        return *this;
    }

    /*
    The operator which signature is "operator++(int number)" first returns the Matrix object 'this' and then adds 1 to it.
    */
    Matrix Matrix::operator++(int number)
    {
        Matrix matrix{this -> _mat, this -> _length, this -> _width};
        for (int i = 0; i < this -> _mat.size(); i++)
        {
            this -> _mat[(size_t)i]++;
        }
        return matrix;
    }

    /*
    The operator which signature is "operator--(int number)" first returns the Matrix object 'this' and then takes 1 from it.
    */
    Matrix Matrix::operator--(int number)
    {
        Matrix matrix{this -> _mat, this -> _length, this -> _width};
        for (int i = 0; i < this -> _mat.size(); i++)
        {
            this -> _mat[(size_t)i]--;
        }
        return matrix;
    }

    /*
    The operator which signature is "operator<<(ostream& output, const Matrix& mat)" receives the output device and a Matrix 
    object and it outputs the Matrix object to the given output device.
    */
    ostream& operator<<(ostream& output, const Matrix& mat)
    {
        vector<double> vec = mat._mat;
        int length = mat._length;
        int width = mat._width;
        double current = 0;
        for (int i = 0; i < length; i++)
        {
            output << "[";
            for (int j = 0; j < width; j++)
            {
               current = vec[(unsigned)(i * width + j)];
                if (j != width - 1)
                {
                    output << current << " ";
                }
                else
                {
                    output << current;
                }
            }
            if (i != length - 1)
            {
                output << "]\n";
            }
            else
            {
                output << "]";
            }
        }
        return output;
    }

    /*
    The operator which signature is "operator>>(istream& input , Matrix& mat)" receives the input device and a Matrix 
    object and it inputs the Matrix object from the given output device.
    */
    istream& operator>>(istream& input , Matrix& matrix)
    {
        string inserted(istreambuf_iterator<char>(input), {});
        if (inserted != "[1 1 1 1], [1 1 1 1], [1 1 1 1]\n")
        {
            throw invalid_argument{"You have inserted invalid input"};
        }
        return input;
    }
}