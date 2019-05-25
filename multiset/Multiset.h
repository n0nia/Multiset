#include "Nod.h"

template <class T>
class MultiSet
{
    int nr_distincte;
    const int dim;
    Nod<T> **mset;

public:
    MultiSet();
    MultiSet(const MultiSet &);
    int cheie(T);
    ~MultiSet();

    MultiSet &operator=(const MultiSet &);
    template <typename X>
    friend ostream &operator<<(ostream &, const MultiSet<X> &);

    int dimensiune() const;
    void adaugare_element(T);
    void stergere_element(T);
    int nr_aparitii(T);
    bool cautare(T);
    int elemente_distincte();
    void sterge_toate_aparitiile(T);
};

template <typename T>
MultiSet<T>::MultiSet() : dim(666013)
{
    nr_distincte = 0;
    mset = new Nod<T> *[dim];

    for (int i = 0; i < dim; i++)
    {
        mset[i] = NULL;
    }
}

template <typename T>
MultiSet<T>::MultiSet(const MultiSet &m) : dim(666013)
{
    nr_distincte = m.nr_distincte;
    mset = new Nod<T> *[dim];

    for (int i = 0; i < dim; i++)
        mset[i] = NULL;

    for (int i = 0; i < dim; i++)
    {
        Nod<T> *t = m.mset[i];
        while (t != NULL)
        {
            Nod<T> *aux = mset[i];
            if (aux == NULL)
            {
                aux = new Nod<T>;
                aux->set_info(t->get_info());
                aux->set_urm(NULL);
                mset[i] = aux;
            }
            else
            {
                while (aux->get_urm() != NULL)
                    aux = aux->get_urm();

                Nod<T> *temp = new Nod<T>;
                temp->set_info(t->get_info());
                temp->set_urm(NULL);

                aux->set_urm(temp);
            }
            t = t->get_urm();
        }
    }
}

template <typename T>
int MultiSet<T>::cheie(T x)
{
    return (static_cast<int>(hash<T>()(x) % dim));
}

template <typename T>
MultiSet<T>::~MultiSet()
{
    nr_distincte = 0;
    for (int i = 0; i < dim; i++)
    {
        Nod<T> *temp = mset[i];

        while (temp != NULL)
        {
            Nod<T> *aux = temp;
            temp = temp->get_urm();
            delete aux;
        }
    }
    delete[] mset;
}

template <typename T>
MultiSet<T> &MultiSet<T>::operator=(const MultiSet &m)
{
    // eliberez memoria
    nr_distincte = 0;

    for (int i = 0; i < dim; i++)
    {
        Nod<T> *temp = mset[i];

        while (temp != NULL)
        {
            Nod<T> *aux = temp;
            temp = temp->get_urm();
            delete aux;
        }
    }

    delete[] mset;

    // aloc din nou memorie
    nr_distincte = m.nr_distincte;

    mset = new Nod<T> *[dim];
    for (int i = 0; i < dim; i++)
        mset[i] = NULL;

    for (int i = 0; i < dim; i++)
    {
        Nod<T> *t = m.mset[i];

        while (t != NULL)
        {
            Nod<T> *aux = mset[i];
            if (aux == NULL)
            {
                aux = new Nod<T>;
                aux->set_info(t->get_info());
                aux->set_urm(NULL);
                mset[i] = aux;
            }
            else
            {
                while (aux->get_urm() != NULL)
                    aux = aux->get_urm();
                Nod<T> *temp = new Nod<T>;
                temp->set_info(t->get_info());
                temp->set_urm(NULL);

                aux->set_urm(temp);
            }
            t = t->get_urm();
        }
    }
}

template <typename T>
ostream &operator<<(ostream &out, const MultiSet<T> &x)
{

    int dim = x.dimensiune();
    for (int i = 0; i < dim; i++)
    {
        Nod<T> *aux = x.mset[i];
        while (aux != NULL)
        {
            out << aux->get_info() << " ";
            aux = aux->get_urm();
        }
    }
    return out;
}

template <typename T>
int MultiSet<T>::dimensiune() const
{
    return dim;
}

template <typename T>
void MultiSet<T>::adaugare_element(T x)
{
    int k = cheie(x);

    if (cautare(x) == false)
    {
        nr_distincte++;
    }

    Nod<T> *temp = new Nod<T>;
    temp->set_info(x);
    temp->set_urm(mset[k]);
    mset[k] = temp;
}

template <typename T>
void MultiSet<T>::stergere_element(T x)
{
    int k = cheie(x);

    if (cautare(x) == false)
    {
        throw "Valoarea nu se gaseste\n";
    }

    Nod<T> *sterg = new Nod<T>;

    if (mset[k]->get_info() == x)
    {
        sterg = mset[k];
        mset[k] = mset[k]->get_urm();
    }
    else
    {
        Nod<T> *temp = new Nod<T>;
        temp = mset[k];
        while (temp->get_urm() != NULL)
        {
            if (temp->get_urm()->get_info() == x)
            {
                break;
            }
            temp = temp->get_urm();
        }

        sterg = temp->get_urm();
        temp->set_urm(temp->get_urm()->get_urm());
    }

    delete sterg;

    if (cautare(x) == 0)
    {
        nr_distincte--;
    }
}

template <typename T>
int MultiSet<T>::nr_aparitii(T x)
{
    int nr = 0;
    int k = cheie(x);

    if (cautare(x) == false)
    {
        return 0;
    }

    Nod<T> *temp = new Nod<T>;
    temp = mset[k];

    while (temp != NULL)
    {
        if (temp->get_info() == x)
        {
            nr++;
        }
        temp = temp->get_urm();
    }

    return nr;
}

template <class T>
bool MultiSet<T>::cautare(T x)
{
    bool gasit = false;
    int k = cheie(x);

    Nod<T> *temp = new Nod<T>;
    temp = mset[k];

    while (temp != NULL)
    {
        if (temp->get_info() == x)
        {
            gasit = true;
            break;
        }
        temp = temp->get_urm();
    }

    return gasit;
}

template <typename T>
void MultiSet<T>::sterge_toate_aparitiile(T x)
{
    while (cautare(x) == true)
    {
        try
        {
            stergere_element(x);
        }
        catch (const char *msg)
        {
            cout << msg;
        }
    }
}

template <typename T>
int MultiSet<T>::elemente_distincte()
{
    return nr_distincte;
}
