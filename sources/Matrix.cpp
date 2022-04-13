#include "Matrix.hpp"
using namespace std;

vector<double> fromMatrixToVector(vector<vector<double>> matrix, int length, int width)
{
    vector<double> vec((size_t)(length * width));
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            vec[(size_t)index++] = matrix[(size_t)i][(size_t)j];
        }
    }
    return vec;
}

vector<vector<double>> fromVectorToMatrix(vector<double> vec, int length, int width)
{
    vector<vector<double>> matrix;
    matrix.resize((size_t)length);
    for (int i = 0; i < matrix.size(); i++)
    {
        matrix[(size_t)i].resize((size_t)width);
    }
    int index = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            matrix[(size_t)i][(size_t)j] = vec[(size_t)index++];
        }
    }
    return matrix;
}

namespace zich
{   
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

    Matrix Matrix::operator+() const
    {
        Matrix matrix{this -> _mat, this -> _length, this -> _width};
        return matrix;
    }

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

    Matrix operator*(Matrix& matrix, double number)
    {
        Matrix answer = number * matrix;
        return answer;
    }

    Matrix operator*(double number, Matrix& matrix)
    {
        Matrix mat{matrix._mat, matrix._length, matrix._width};
        for (int i = 0; i < mat._mat.size(); i++)
        {
            mat._mat[(size_t)i] = mat._mat[(size_t)i] * number;
        }
        return mat;
    }

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

    Matrix& Matrix::operator*=(double number)
    {
        for (int i = 0; i < this ->_mat.size(); i++)
        {
            this ->_mat[(size_t)i] = this ->_mat[(size_t)i] * number;
        }
        return *this;
    }

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

    Matrix& Matrix::operator++()
    {
        for (int i = 0; i < this -> _mat.size(); i++)
        {
            this -> _mat[(size_t)i]++;
        }
        return *this;
    }

    Matrix& Matrix::operator--()
    {
        for (int i = 0; i < this -> _mat.size(); i++)
        {
            this -> _mat[(size_t)i]--;
        }
        return *this;
    }

    Matrix Matrix::operator++(int number)
    {
        Matrix matrix{this -> _mat, this -> _length, this -> _width};
        for (int i = 0; i < this -> _mat.size(); i++)
        {
            this -> _mat[(size_t)i]++;
        }
        return matrix;
    }

    Matrix Matrix::operator--(int number)
    {
        Matrix matrix{this -> _mat, this -> _length, this -> _width};
        for (int i = 0; i < this -> _mat.size(); i++)
        {
            this -> _mat[(size_t)i]--;
        }
        return matrix;
    }

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