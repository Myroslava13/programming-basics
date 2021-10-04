#include "iostream"
 
using std::cout;
using std::endl;
 
template<typename T>
class Vector
{
private:
    int current;
    int* m;
    int size;
public:
    Vector<T>();
    Vector<T>(int);
    void showarray();
    void addtoend(T);
    void allocarray(int);
    ~Vector()
    {
        cout << "Destroying m....." << endl;
    }
 
 
};
 
template<typename T>
inline Vector<T>::Vector()
{
    size = 0;
    current = 0;
    m = nullptr;
}
 
 
template <typename T>
Vector<T>::Vector(int _size)
{
    size = _size;
    current = 0;
    m = new T[size];//
    cout << "running constructor for " << size << " elements" << endl;
    for (int i = 0; i < size; i++)
    {
        m[i] = i;
    }
 
}
 
template <typename T> 
void Vector<T>::showarray()
{
    cout << "Current array:" << endl;
    for (int i = 0; i < this->size; i++)
    {
        cout << this->m[i] << " ";
    }
    cout << endl;
}
 
template <typename T>
void Vector<T>::allocarray(int n)
{
    cout << "allocarray" << endl;
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
        if (i < this->size) temp[i] = this->m[i];
        else temp[i] = 0;
    delete[]this->m;
    this->m = temp;
    this->size = n;
}
 
template <typename T>
void Vector<T>::addtoend(T tmp)
{
    cout << "adding element to the end of array" << endl;
    this->size++;
    allocarray(this->size);
    this->m[this->size - 1] = tmp;
}
