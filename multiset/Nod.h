#include <iostream>

using namespace std;

template <typename T>
class Nod
{
    T info;
    Nod *urm;

public:
    Nod();
    ~Nod();
    Nod(const Nod &);

    T get_info() const;
    void set_info(T);

    Nod *get_urm() const;
    void set_urm(Nod *);

    Nod &operator=(Nod &);
    bool operator==(Nod &);
};

template <typename T>
Nod<T>::Nod()
{
    urm = NULL;
}

template <typename T>
Nod<T>::~Nod()
{
}

template <typename T>
Nod<T>::Nod(const Nod &x)
{
    info = x.info;
    urm = x.urm;
}

template <typename T>
T Nod<T>::get_info() const
{
    return info;
}

template <typename T>
void Nod<T>::set_info(T x)
{
    info = x;
}

template <typename T>
Nod<T> *Nod<T>::get_urm() const
{
    return urm;
}

template <typename T>
void Nod<T>::set_urm(Nod *x)
{
    urm = x;
}

template <typename T>
Nod<T> &Nod<T>::operator=(Nod &x)
{
    info = x.get_info();
    urm = x.get_urm();
    return *this;
}

template <typename T>
bool Nod<T>::operator==(Nod &x)
{
    return info == x.get_info();
}
