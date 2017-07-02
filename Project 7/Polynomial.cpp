#include "Polynomial.h"

Polynomial::Polynomial()
{
    coefficients = NULL;
    max_degree = 0;
}

Polynomial::Polynomial(int input_max, int* input_coefficients)
{
    max_degree = input_max;
    coefficients = new int[max_degree+1];

    for(int i = 0; i <= max_degree; i++)
    {
        coefficients[i] = input_coefficients[i];
    }

}

Polynomial::Polynomial(const Polynomial& input)
{
    max_degree = input.max_degree;
    coefficients = new int[max_degree+1];

    for(int i = 0; i <= max_degree; i++)
    {
        coefficients[i] = input.coefficients[i];
    }
}

Polynomial::~Polynomial()
{
    if(coefficients != NULL)
    {
        delete [] coefficients;
        coefficients = NULL;
    }
}

int Polynomial::solve(int input)
{
    int solved = 0;
    int temp_num = 0;

    for(int i = 0; i < max_degree; i++)
    {
        temp_num = pow(input, i);
        temp_num *= coefficients[i];

        solved += temp_num;
    }

    return solved;
}

void Polynomial::operator=(const Polynomial& rhs)
{
    delete [] coefficients;
    max_degree = rhs.max_degree;
    coefficients = new int[max_degree+1];

    for(int i = 0; i <= max_degree; i++)
    {
        coefficients[i] = rhs.coefficients[i];
    }
}

bool Polynomial::operator==(const Polynomial& rhs)
{
    bool match = true;

    if(max_degree == rhs.max_degree)
    {
        for(int i = 0; i < max_degree; i++)
        {
            if(coefficients[i] != rhs.coefficients[i])
            {
                match = false;
            }

        }
    }

    else
    {
        match = false;
    }

    return match;
}

bool Polynomial::operator!=(const Polynomial& rhs)
{
    bool differ = false;

    if(max_degree == rhs.max_degree)
    {
        for(int i = 0; i < max_degree; i++)
        {
            if(coefficients[i] != rhs.coefficients[i])
            {
                differ = true;
            }

        }
    }

    else
    {
        differ = true;
    }

    return differ;
}

Polynomial Polynomial::operator*(const Polynomial& rhs)
{
    int new_size = max_degree+rhs.max_degree;
    int* product = new int[new_size+1];

    for(int i = 0; i < new_size; i++)
    {
        product[i] = 0;
    }

    for(int i = 0; i <= max_degree; i++)
    {
        for(int j = 0; j <= rhs.max_degree; j++)
        {
            product[i+j] += coefficients[i]*rhs.coefficients[j];
        }
    }

    Polynomial temp(new_size, product);
    cout << "Temporary polynomial is: " << temp << endl;
    return temp;
}

Polynomial Polynomial::operator*(int input)
{
    for(int i = 0; i < max_degree + 1; i++)
    {
        coefficients[i] *= input;
    }

    return Polynomial(max_degree, coefficients);
}

Polynomial Polynomial::operator+(const Polynomial& rhs)
{
    if(rhs.max_degree > max_degree)
    {
        max_degree = rhs.max_degree;
    }
    int* new_coef = new int[max_degree];

    for(int i = 0; i <= max_degree; i++)
    {
        new_coef[i] = coefficients[i]+rhs.coefficients[i];
    }

    return Polynomial(max_degree, new_coef);
}

ostream& operator<<(ostream& cout, const Polynomial& output)
{
    for(int i = output.max_degree; i >= 0; i--)
    {
        if(i > 0)
        {
            if(i == output.max_degree)
            {
                if(output.coefficients[i] == 1)
                {
                    cout << "x^" << i;
                }
                else if(output.coefficients[i] != 0)
                {
                    cout << output.coefficients[i] << "x^" << i;
                }
            }
            else if(output.coefficients[i] > 1)
            {
                cout << "+" << output.coefficients[i] << "x^" << i;
            }
            else if(output.coefficients[i] == 1)
            {
                cout << "+"  << "x^" << i;
            }
            else if(output.coefficients[i] < -1)
            {
                cout << output.coefficients[i] << "x^" << i;
            }
            else if(output.coefficients[i] == -1)
            {
                cout << "-"  << "x^" << i;
            }
        }
        else if(i == 0)
        {
            if(output.coefficients[i] > 0)
            {
                cout << "+" << output.coefficients[i];
            }
            else if(output.coefficients[i] < 0)
            {
                cout << output.coefficients[i];
            }
        }
    }

    return cout;
}

ifstream& operator>>(ifstream& fin, Polynomial& input)
{
    fin >> input.max_degree;

    input.coefficients = new int[input.max_degree];

    for(int i = input.max_degree; i >= 0; i--)
    {
        fin >> input.coefficients[i];
    }

    return fin;

}
