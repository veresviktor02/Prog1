#include <iostream>
using namespace std;

struct B2
{
    virtual void pvf() = 0; //pure because of '= 0'
};

struct B1 : B2 //It should be a class but it makes unorthodox bugs
{
    void f()
    {std::cout << "B1::f()\n";}

    virtual void vf()
    {std::cout << "B1::vf()\n";}

    void pvf()
    {std::cout << "B1::pvf()\n";}
};

struct D1 : B1
{
    virtual void vf()
    {std::cout << "actually D1::vf()\n";}
    void f()
    {std::cout << "new f()\n";}
};
//make a D1 object and call vf() and f()

struct D2 : D1
{
    virtual void pvf()
    {std::cout << "I am D2. R2D2\n";}
};

struct D21 : B1
{
    string szoveg = "Nem bírom tovább\n";
    virtual void pvf()
    {std::cout << szoveg;}
};

struct D22 : B1
{
    int szam = 49;
    virtual void pvf()
    {std::cout << szam << '\n';}
};

void f(B1& b1)
{
    b1.f();
    b1.vf();
    b1.pvf();
    //takes a B2& argument and calls pvf() for its argument. Call f() with a D21 and a D22.
}

int main()
{
    B1 b1; //creating a B1 object
    D1 d1; //creating a D1 object
    D2 d2;
    D21 d21;
    D22 d22;

    std::cout << '\n';
    std::cout << "b1's functions: [f(), vf()]\n";
    b1.f();
    b1.vf();

    std::cout << '\n';
    std::cout << "d1's functions: [f(), vf()]\n";
    d1.f();
    d1.vf(); //override to d1
    //b1.vf(); //goes back to normal b1

    B1& bref = d1; //B1 reference on d1
    std::cout << '\n';
    std::cout << "B1's reference on d1 functions: [f(), vf()]\n";
    bref.f(); //it's gonna run B1's f(), not D1's
    bref.vf(); //it's gonna run D1's vf(), because it overrides the other

    std::cout << '\n';
    std::cout << "d2's functions: [f(), vf(), pvf()]\n";
    d2.f();
    d2.vf();
    d2.pvf();

    std::cout << '\n';
    std::cout << "calling b1 with f() function\n";

    f(b1);

    std::cout << '\n';
    std::cout << "calling d21 with f() function\n";

    f(d21);

    std::cout << '\n';
    std::cout << "calling d22 with f() function\n";

    f(d22);

    std::cout << '\n';
}
/*
1. Define a class B1 with a virtual function vf() and a non-virtual function f(). Define both of these functions within class
B1. Implement each function to output its name (e.g., B1::vf()). Make the functions public. Make a B1 object and call
each function.
2. Derive a class D1 from B1 and override vf(). Make a D1 object and call vf() and f() for it.
3. Define a reference to B1 (a B1&) and initialize that to the D1 object you just defined. Call vf() and f() for that reference.
4. Now define a function called f() for D1 and repeat 1–3. Explain the results.
5. Add a pure virtual function called pvf() to B1 and try to repeat 1–4. Explain the result.
6. Define a class D2 derived from D1 and override pvf() in D2. Make an object of class D2 and invoke f(), vf(), and
pvf() for it.
7. Define a class B2 with a pure virtual function pvf(). Define a class D21 with a string data member and a member
function that overrides pvf(); D21::pvf() should output the value of the string. Define a class D22 that is just like D21
except that its data member is an int. Define a function f() that takes a B2& argument and calls pvf() for its argument.
Call f() with a D21 and a D22.
*/