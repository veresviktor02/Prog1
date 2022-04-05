#include "std_lib_facilities.h"

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    while(f1 != e1)
    {
        *f2 = *f1;
        ++f1;
        ++f2;
    }
    return f2;
}

int main()
{

    int a_rray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b_rray[10];
    vector<int> a_vector;
    vector<int> b_vector;
    list<int> a_list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 10; i++) //a_vector elements
    {
        a_vector.push_back(i);
    }

    copy(begin(a_rray), end(a_rray), begin(b_rray));
    
    /////////////////////////////////////////////////////////////////

    cout << "a_rray print:\n";
    for (int i = 0; i < 10; i++) //a_rray print
    {
        cout << a_rray[i] << ' ';
    }
    cout << '\n';

    cout << "a_vector print:\n";
    for (int i = 0; i < 10; i++) //a_vector print
    {
        cout << a_vector[i] << ' ';
    }
    cout << '\n';

    cout << "a_list print:\n";
    for (auto const &i: a_list) //a_list print
    {
        cout << i << ' ';
    }
    cout << '\n';
    
    /////////////////////////////////////////////////////////////////

    for (int i = 0; i < 10; i++) //b_rray = a_rray
    {
        b_rray[i] = a_rray[i];
    }
    
    for (int i = 0; i < 10; i++) //b_vector = a_vector
    {
        b_vector.push_back(a_vector[i]);
    }

    /////////////////////////////////////////////////////////////////

    cout << "b_rray print:\n";
    for (int i = 0; i < 10; i++) //b_rray print
    {
        cout << b_rray[i] << ' ';
    }
    cout << '\n';

    cout << "b_vector print:\n";
    for (int i = 0; i < 10; i++) //b_vector print
    {
        cout << b_vector[i] << ' ';
    }
    cout << '\n';

    cout << "a_list print:\n";
    for (auto const &i: a_list) //a_list print
    {
        cout << i << ' ';
    }
    cout << '\n';

    /////////////////////////////////////////////////////////////////

    for (int i = 0; i < 10; i++)
    {
        b_rray[i] += 2;
    }
    
    for (int i = 0; i < 10; i++)
    {
        b_vector[i] += 3;
    }

    for (int i : a_list)
    {
        i += 5;
    }
    
    

    /////////////////////////////////////////////////////////////////
    
    cout << "b_rray print AFTER CHANGE:\n";
    for (int i = 0; i < 10; i++) //b_rray print AFTER CHANGE
    {
        cout << b_rray[i] << ' ';
    }
    cout << '\n';

    cout << "b_vector print AFTER CHANGE:\n";
    for (int i = 0; i < 10; i++) //b_vector print AFTER CHANGE
    {
        cout << b_vector[i] << ' ';
    }
    cout << '\n';

    cout << "a_list print AFTER CHANGE:\n";
    for (auto const &i: a_list) //a_list print AFTER CHANGE
    {
        cout << i << ' ';
    }
    cout << '\n';




    my_copy(begin(a_list), end(a_list), begin(b_rray));
    
    auto search = find(begin(a_vector), end(a_vector), 3);
    auto search2 = find(begin(a_list), end(a_list), 27);

    if(search != end(a_vector))
    {
        cout << "van benne 3-as, a " << distance(begin(a_vector), search) << " pozícióban.\n";
    }
    else
    {
        cout << "nincs benne 3-as.\n";
    }

    if(search2 != end(a_list))
    {
        cout << "van benne 27-es, a " << distance(begin(a_list), search2) << " pozícióban.\n";
    }
    else
    {
        cout << "nincs benne 27-es.\n";
    }

    return 0;
}