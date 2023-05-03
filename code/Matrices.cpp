#include "Matrices.h"


namespace Matrices
{
    Matrix::Matrix(int _rows, int _cols)
    {
        rows = _rows;
        cols = _cols;
        // Resize the vector and initialize elements to 0
        // a's type: vector<vector<double>>
        a.resize(rows, vector<double>(cols, 0));
    }


    Matrix operator+(const Matrix& a, const Matrix& b)
    {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
        {
            throw runtime_error("Error: dimensions must agree");
        }

        Matrix c(a.getRows(), a.getCols());
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
                c(i, j) = a(i, j) + b(i, j);
            }
        }

        return c;
    }


    Matrix operator*(const Matrix& a, const Matrix& b)
    {
        if (a.getCols() != b.getRows())
        {
            throw runtime_error("Error: Cannot multiply, dimensions must agree");
        }

        Matrix c(a.getRows(), b.getCols());

        // a(i,j) b(j,k)
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int k = 0; k < b.getCols(); k++)
            {
                for (int j = 0; j < a.getCols(); j++)
                {
                    c(i, k) += a(i, j) * b(j, k);
                }
            }
        }

        return c;
    }


    bool operator==(const Matrix& a, const Matrix& b)
    {
        bool equal = true;

        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
        {
            equal = false;
        }

        for (int i = 0; i < a.getRows() && equal; i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
                if (a(i, j) != b(i, j))
                {
                    equal = false;
                    break;
                }
            }
        }

        return equal;
    }


    bool operator!=(const Matrix& a, const Matrix& b)
    {
        return !(a == b);
    }


    ostream& operator<<(ostream& os, const Matrix& a)
    {
        //int sizes[a.getRows()];

        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
                os << a(i, j) << " ";
            }
            os << endl;
        }
        return os;
    }

    RotationMatrix(double theta) : Matrix(2,2)
    {
        this->(0, 0) = cos(theta);
        this->(0, 1) = -sin(theta);
        this->(1, 0) = sin(theta);
        this->(1, 1) = cos(theta);
    }

    ScalingMatrix(double scale) : Matrix(2, 2)
    {
        this->(0, 0) = scale;
        this->(0, 1) = 0;
        this->(1, 0) = scale;
        this->(1, 1) = 0;
    }

    TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2,nCols)
    {
        for (int i = 0; i < nCols; i++)
        {
            this->(0, i) = xShift;
            this->(1, i) = yShift;
        }
    }

} // End namespace Matrices