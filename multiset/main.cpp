#include <iostream>
#include <assert.h>
#include "Multiset.h"

using namespace std;

void testeAssertInt()
{
    MultiSet<int> multiset;
    multiset.adaugare_element(10);
    multiset.adaugare_element(10);
    multiset.adaugare_element(20);
    multiset.adaugare_element(30);

    cout << multiset << "\n";

    MultiSet<int> multiset2 = multiset;
    cout << "Test copy constructor\n";
    cout << multiset2 << "\n";

    MultiSet<int> multiset3;
    multiset3 = multiset;
    cout << "Test operator =\n";
    cout << multiset3 << "\n";

    assert(multiset.cautare(10) == true);
    assert(multiset.cautare(40) == false);
    assert(multiset.elemente_distincte() == 3);
    assert(multiset.nr_aparitii(10) == 2);
    try
    {
        multiset.stergere_element(20);
        assert(multiset.nr_aparitii(20) == 0);
    }
    catch (const char *msg)
    {
        cout << msg;
    }

    try
    {
        multiset.sterge_toate_aparitiile(10);
        assert(multiset.nr_aparitii(10) == 0);
    }
    catch (const char *msg)
    {
        cout << msg;
    }
}

void testeAssertString()
{
    MultiSet<string> multiset;
    multiset.adaugare_element("carul");
    multiset.adaugare_element("acesta");
    multiset.adaugare_element("mare");
    multiset.adaugare_element("de tot");

    cout << multiset << "\n";

    MultiSet<string> multiset2 = multiset;
    cout << "Test copy constructor\n";
    cout << multiset2 << "\n";

    MultiSet<string> multiset3;
    multiset3 = multiset;
    cout << "Test operator =\n";
    cout << multiset3 << "\n";

    assert(multiset.cautare("carul") == true);
    assert(multiset.cautare("pisica") == false);
    assert(multiset.elemente_distincte() == 4);
    assert(multiset.nr_aparitii("carul") == 1);

    try
    {
        multiset.stergere_element("carul");
        assert(multiset.nr_aparitii("carul") == 0);
    }
    catch (const char *msg)
    {
        cout << msg;
    }

    try
    {
        multiset.sterge_toate_aparitiile("mare");
        assert(multiset.nr_aparitii("mare") == 0);
    }
    catch (const char *msg)
    {
        cout << msg;
    }
}

void testeAssertFloat()
{
    MultiSet<float> multiset;
    multiset.adaugare_element(10.10);
    multiset.adaugare_element(10.10);
    multiset.adaugare_element(20.20);
    multiset.adaugare_element(30.30);

    cout << multiset << "\n";

    MultiSet<float> multiset2 = multiset;
    cout << "Test copy constructor\n";
    cout << multiset2 << "\n";

    MultiSet<float> multiset3;
    multiset3 = multiset;
    cout << "Test operator =\n";
    cout << multiset3 << "\n";

    assert(multiset.cautare(10.10) == true);
    assert(multiset.cautare(40.40) == false);
    assert(multiset.elemente_distincte() == 3);
    assert(multiset.nr_aparitii(10.10) == 2);
    try
    {
        multiset.stergere_element(20.20);
        assert(multiset.nr_aparitii(20.20) == 0);
    }
    catch (const char *msg)
    {
        cout << msg;
    }

    try
    {
        multiset.sterge_toate_aparitiile(10.10);
        assert(multiset.nr_aparitii(10.10) == 0);
    }
    catch (const char *msg)
    {
        cout << msg;
    }
}

int main()
{
    cout << "Test pe Int:\n\n";
    testeAssertInt();
    cout << "\nTest pe String:\n\n";
    testeAssertString();
    cout << "\nTest pe Float:\n\n";
    testeAssertFloat();
    return 0;
}
