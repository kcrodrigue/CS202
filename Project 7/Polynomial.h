#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

class Polynomial
{
public:
    Polynomial();
    Polynomial(int, int*);
    Polynomial(const Polynomial&);
    ~Polynomial();
    int solve(int);
    void operator=(const Polynomial&);
    bool operator==(const Polynomial&);
    bool operator!=(const Polynomial&);
    Polynomial operator*(const Polynomial&);
    Polynomial operator*(int);
    Polynomial operator+(const Polynomial&);
    friend ostream& operator<<(ostream&, const Polynomial&);
    friend ifstream& operator>>(ifstream&, Polynomial&);

private:
    int* coefficients;
    int max_degree;
};
