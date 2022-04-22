#include "std_lib_facilities.h"

template <typename m1, typename m2>
void print(const map<m1,m2>& map)
{
    for(const auto& p : map)
    {
        cout << p.first << ' ' << p.second << '\n';
    }
}

void read(map<string,int>& map)
{
    string text;
    int number;

    cin >> text >> number;

    map.insert(pair<string,int>(text,number));
}

int main()
{
    map<string, int> msi;

    msi["lecture"] = 21;
    msi["lecture2"] = 12;
    msi["lecture5"] = 32;
    msi["lecture3"] = 23;
    msi["lecture7"] = 43;
    msi["lecture9"] = 34;
    msi["lecture8"] = 54;
    msi["lecture1"] = 45;
    msi["lecture4"] = 65;
    msi["lecture6"] = 56;

    print(msi);

    cout << "Erasing...\n";
    msi.erase(msi.begin(),msi.end());
    print(msi);
    cout << '\n';
    cout << "Erase done!\n";

    cout << "Insert 5 pairs:\n";

    for(int i = 0; i < 5; i++)
    {
        cout << i+1 << ". pár: ";
        read(msi);
    }
    cout << '\n';

    print(msi);

    int sum = accumulate(msi.begin(),msi.end(),0, [](auto prev_sum, auto &msi_entry){return prev_sum+msi_entry.second;});
    cout << "Sum: " << sum << '\n';

    map<int,string> mis;

    for(auto& mapentry: msi)
    {
        mis[mapentry.second] = mapentry.first;
    }

    print(mis);

    return 0;
}

/*
Now try a map :
    1. Define a map<string,int> called msi .
    2. Insert ten (name,value) pairs into it, e.g., msi["lecture"]=21 .
    3. Output the (name,value) pairs to cout in some format of your choice.
    4. Erase the (name,value) pairs from msi .
    5. Write a function that reads value pairs from cin and places them in msi .
    6. Read ten pairs from input and enter them into msi .
    7. Write the elements of msi to cout .
    8. Output the sum of the (integer) values in msi .
    9. Define a map<int,string> called mis .
    10. Enter the values from msi into mis ; that is, if msi has an element ( " lecture",21 ), mis should have an element ( 21,"lecture" ).
    11. Output the elements of mis to cout .
*/