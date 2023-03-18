

//DIACONESCU ALEXANDRA GRUPA 144



#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Pereche
{
    int max;
    int pozitie;
};

class IntVector
{
private:
    int *v;
    int size;

public:
    IntVector(int size) : v(new int[size]), size(size) {}
    IntVector() : v(NULL), size(0) {}
    IntVector(const IntVector &other) : v(new int[other.size]), size(other.size)
    {
        for (int i = 0; i < size; i++)
        {
            v[i] = other.v[i];
        }
    }
    ~IntVector()
    {
        delete[] v;
    }

    // supraincarcarea =
    IntVector &operator=(const IntVector &vector2)
    {
        if (this != &vector2)
        {
            int *new_v = new int[vector2.size];
            for (int i = 0; i < vector2.size; i++)
            {
                new_v[i] = vector2.v[i];
            }
            delete[] v;
            v = new_v;
            size = vector2.size;
        }
        return *this;
    }

    // Setter
    void Setsize(int size) { this->size = size; }
    void SetVector(const int *vec)
    {
        if (v)
        {
            delete[] v;
        }
        v = new int[size];
        for (int i = 0; i < size; i++)
        {
            v[i] = vec[i];
        }
    }

    // Getter
    int GetSize() const { return size; }
    int *GetVector() const { return v; }

    // supraincarcarea << si >>
    friend ostream &operator<<(ostream &os, const IntVector &intvector)
    {
        os << "IntVector(" << intvector.size << "): [";
        for (int i = 0; i < intvector.size; i++)
        {
            os << intvector.v[i];
            if (i != intvector.size - 1)
            {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    friend istream &operator>>(istream &is, IntVector &intvector)
    {
        is >> intvector.size;
        delete[] intvector.v;
        intvector.v = new int[intvector.size];

        for (int i = 0; i < intvector.size; i++)
        {
            is >> intvector.v[i];
        }

        return is;
    }

    // reactualizarea numarului de componente
    void reactualizare(int newSize, int initValue)
    {
        int *newV = new int[newSize];
        for (int i = 0; i < newSize; i++)
        {
            if (i < size)
            {
                newV[i] = v[i];
            }
            else
            {
                newV[i] = initValue;
            }
        }
        delete[] v;
        v = newV;
        size = newSize;
    }

    // suma elementelor
    int suma() const
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += v[i];
        }

        return sum;
    }

    Pereche maxim() const
    {
        int max = v[0];
        int pozitie = 0;
        for (int i = 0; i < size; i++)
        {
            if (v[i] >= max)
            {
                max = v[i];
                pozitie = i;
            }
        }

        Pereche p = {max, pozitie};
        return p;
    }

    // metoda publica pentru sortarea crescatoare a vectorului

    void sortare()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (v[j] < v[i])
                {
                    int aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
            }
        }
    }
};

// functie pentru memorarea a n obiecte
std::vector<IntVector> memorareIntVectors(int n)
{
    std::vector<IntVector> objects;

    for (int i = 0; i < n; i++)
    {
        IntVector obj = IntVector();

        objects.push_back(obj);
    }

    return objects;
}

// functie pentru citirea a n obiecte
void citireIntVectors(int n, std::vector<IntVector> &objects)
{
    for (int i = 0; i < n; i++)
    {
        IntVector obj;
        std::cin >> obj;
        objects.push_back(obj);
    }
}

// functie pentru afisarea a n obiecte
void afisareIntVectors(const std::vector<IntVector> &objects)
{
    for (int i = 0; i < objects.size(); i++)
    {
        std::cout << "Object " << i << ": " << std::endl;
        std::cout << objects[i];
    }
}

// testare

void TestGetterAndSetter()
{
    IntVector vec;

    int a[] = {1, 2, 3, 4, 5};

    vec.Setsize(5);
    vec.SetVector(a);

    std::cout << "Size: " << vec.GetSize() << std::endl;
    std::cout << "Vector: ";
    int *ptr = vec.GetVector();
    for (int i = 0; i < vec.GetSize(); i++)
    {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;
}

void TestConstructorInit()
{
    IntVector vec;
    int a[] = {1, 2, 3, 4, 5};
    vec.Setsize(5);
    vec.SetVector(a);
    std::cout << "Default constructor: ";
    for (int i = 0; i < vec.GetSize(); i++)
    {
        std::cout << vec.GetVector()[i] << " ";
    }
    std::cout << std::endl;
}

void TestConstructorCuParametru()
{
    IntVector vec(5);
    int a[] = {1, 2, 3, 4, 5};
    vec.SetVector(a);

    std::cout << "Constructor cu parametru: ";
    for (int i = 0; i < vec.GetSize(); i++)
    {
        std::cout << vec.GetVector()[i] << " ";
    }
    std::cout << std::endl;
}

void TestCopyConstructor()
{
    IntVector vec(3);
    int values[] = {1, 2, 3};
    vec.SetVector(values);

    // folosind copy constructor se creeaza un obiect nou
    IntVector vec_copy(vec);

    std::cout << "Vectorul original: ";
    for (int i = 0; i < vec.GetSize(); i++)
    {
        std::cout << vec.GetVector()[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Vectorul copiat: ";
    for (int i = 0; i < vec_copy.GetSize(); i++)
    {
        std::cout << vec_copy.GetVector()[i] << " ";
    }
    std::cout << std::endl;
}

void TestOperatorEgal()
{
    IntVector v1(3), v2(4);
    int arr[4] = {0, 0, 0, 0};
    v2.SetVector(arr);
    v1 = v2;
    std::cout << v1.GetSize() << std::endl;
    std::cout << v2.GetVector()[0] << std::endl;
}

void TestOperatorAfisare()
{
    IntVector v(3);
    int valori[] = {1, 2, 3};
    v.SetVector(valori);
    std::cout << v << std::endl;
}

void TestOperatorCitire()
{
    IntVector vec;
    std::istringstream input("5 1 2 3 4 5");
    input >> vec;
    std::cout << vec << std::endl;
}

void TestReactualizare()
{
    IntVector vec(5);
    int valori[] = {1, 2, 3, 4, 5};
    vec.SetVector(valori);

    std::cout << "Inainte de reactualizare: " << vec << std::endl;

    vec.reactualizare(8, 0);

    std::cout << "Dupa reactualizare: " << vec << std::endl;
}

void TestSuma()
{
    IntVector vec(3);
    int valori[] = {4, 5, 6};
    vec.SetVector(valori);
    int sum = vec.suma();
    std::cout << "Suma: " << sum << std::endl;
}

void TestMax()
{
    IntVector v(5);
    int valori[] = {1, 2, 10, 2, 3};
    v.SetVector(valori);
    Pereche p = v.maxim();
    std::cout << "Maximul este: " << p.max << ", pe pozitia: " << p.pozitie << std::endl;
}

void TestSort()
{
    IntVector vec(4);
    int valori[] = {7, 1, 12, 13};
    vec.SetVector(valori);
    vec.sortare();

    std::cout << "Vector sortat: " << vec << std::endl;
}

int main()
{
    // TestGetterAndSetter();
    // TestConstructorInit();
    // TestConstructorCuParametru();
    // TestCopyConstructor();
    // TestOperatorEgal();
    // TestOperatorAfisare();
    // TestOperatorCitire();
    // TestReactualizare();
    // TestSuma();
    // TestMax();
    // TestSort();

    return 0;
}