#include "std_lib_facilities.h"

struct Person
{
    public:
    Person() : first_name{"Guest"}, last_name{"Human"}, age{-1} {};

    Person(string f_name, string s_name, int age) : first_name{f_name}, last_name{s_name}, age{age} {

    if(first_name.empty() || last_name.empty()){
    error("Meg kell adni egy vezetéknevet és egy keresztnevet!\n");
    }

    if(age == -1)
    {
        error("Meg kell adnod egy életkort!\n");
    }

    const string illegal_chars = ";:\"'[]*&^%$#@!";

    string names = first_name + last_name;

    for (int i = 0; i < names.size(); ++i)
    {

        if(string(illegal_chars).find(f_name[i]) != string::npos)
        {
            error("A név nem tartalmazhatja az alábbi karaktereket: " + illegal_chars + "\n");
        }
    }

    if (age <= 0 || age >= 150)
    {
        error("Az életkornak 0 és 150 között kell lennie!");
    }
};

int get_age() const
{
    return age;
}

string get_name() const
{
    return first_name + " " + last_name;
}

private:
string first_name;
string last_name;
int age;
};

ostream& operator<<( ostream& os, Person& person)
{
    return os << "Név: " << person.get_name() << '\n' << "Életkor: " << person.get_age() << '\n';
}

istream& operator>>(istream& in, Person& p)
{
string first_name, last_name;
int age;

in >> first_name >> last_name >> age;

if(!in)
{
    return in;
}

p = Person(first_name, last_name, age);
return in;
}

Person& operator>>(string& s, Person& p)
{
    istringstream stream_string(s);

    string input;

    string first_name, last_name;
    int age = -1;

    int arg_counter = 0;

    while(getline(stream_string, input, ' '))
    {
        switch(arg_counter)
        {
        case 0:
        first_name = input;
        break;

        case 1:
        last_name = input;
        break;

        case 2:
        age = stoi(input);
        break;

        default:
        break;
        }
    arg_counter++;
    }

return p = Person(first_name, last_name, age);
}


int main()
{
    try
    {

        cout << "2. Feladat:\n";

         Person person_one = Person{"Goofy", "Human", 63};

        cout << person_one;
        cout << '\n';

        cout << "3. feladat:\n";

        Person person_two;

        cout << "Adj meg egy vezeték- és egy keresztnevet, valamint egy életkort, vesszővel elválasztva!\n";

        cin >> person_two;

        cout << '\n';
        cout << "Az alábbi adatokat adtad meg:\n";
        cout << person_two;
        cout << '\n';

        cout << "8. feladat:\n";

        vector<Person> persons;

        Person placeholder = Person();
        string input;

        cout << "Nevek tárolása...\n";
        cout << "Adj meg egy vezeték- és egy keresztnevet, valamint egy életkort, vesszővel elválasztva!\n";
        cout << "Írj 'exit'-et, hogy abbahagyja a nevek tárolását!\n";

        while(getline(cin, input))
        {
            if(input == "exit")
            {
                break;
            }

            if(input.empty())
            {
                continue;
            }

            try
            {
                input >> placeholder;
            }
            catch (runtime_error& e)
            {
                cerr << "Error: " << e.what() << '\n';
                continue;
            }
            catch(...)
            {
                cout << "Az alábbi formátumban add meg az adatokat: Keresztnév, vezetéknév, életkor! (Szólözzel elválasztva)\n";
                continue;
            }

            persons.push_back(placeholder);

            cout << '\n';
            cout << "Megadhatsz egy új nevet! (vagy 'exit'-tel lépj ki!)\n";
        }

        cout << '\n';

        cout << "Az alábbi adatokat adtad meg:\n";

        for (int i = 0; i < persons.size(); ++i)
        {
            cout << "[" + to_string(i+1) + "] " << persons[i] << '\n';
        }

        return 0;

    }
    catch (runtime_error& e)
    {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Valami hiba történt :/.\n";
        return 2;
    }
}

/*
1. Define a struct Person containing a string name and an int age.
2. Define a variable of type Person , initialize it with “Goofy” and 63, and
write it to the screen ( cout ).
3. Define an input ( >> ) and an output ( << ) operator for Person ; read in a
Person from the keyboard ( cin ) and write it out to the screen ( cout ).
4. Give Person a constructor initializing name and age .
5. Make the representation of Person private, and provide const member
functions name() and age() to read the name and age.
6. Modify >> and << to work with the redefined Person .
7. Modify the constructor to check that age is [0:150) and that name doesn’t
contain any of the characters ; : " ' [ ] * & ^ % $ # @ ! . Use error() in case
of error. Test.
8. Read a sequence of Person s from input ( cin ) into a vector<Person> ;
write them out again to the screen ( cout ). Test with correct and errone-
ous input.
9. Change the representation of Person to have first_name and second_name
instead of name . Make it an error not to supply both a first and a second
name. Be sure to fix >> and << also. Test.
*/