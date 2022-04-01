#include "std_lib_facilities.h"

template<typename T> struct S
{
    public:
        S() : val(T()) {}
        S(T type) { val = type; }

        void operator= (const T&);

        void read_val(T& v);

        T& get();
        const T& get() const;

        void set(const T& vv);

    private:
        T val;
};

template<typename T> T& S<T>::get()
{
    return val;
};

template<typename T> const T& S<T>::get() const
{
    return val;
};

template<typename T> void S<T>::set(const T& vv)
{
    val = vv;
};

template<typename T> void S<T>::operator=(const T& type)
{
    val = type;
};

template<typename T> void read_val(T& v)
{
    cin >> v;
};

int main()
{
    
    S<int> s_int(3);
    S<char> s_char('a');
    S<double> s_double(6.9); 
    S<string> s_string("alma");

    vector<int> my_vector;
    
    for(int i = 0; i < 5; i++)
    {
        my_vector.push_back(i * 2);
    }

    S<vector<int>> s_vectorint();

    cout << s_int.get() << '\n';
    cout << s_char.get() << '\n'; 
    cout << s_double.get() << '\n'; 
    cout << s_string.get() << '\n';

    for(int i = 0; i < 5; i++)
    {
        cout << my_vector[i] << ' ';
    }
    cout << '\n';

    cout << "Changing values..." << '\n';
        
    s_int = 4;
    s_char = 'b';
    s_double = 4.20;
    s_string = "reszelt alma";

    cout << s_int.get() << '\n';
    cout << s_char.get() << '\n'; 
    cout << s_double.get() << '\n'; 
    cout << s_string.get() << '\n';


    int s_int_2;
	char s_char_2;
	double s_double_2;
	string s_string_2;

    cout << "Adj meg új értékeket! (int, char, double string)\n";

	read_val(s_int_2);
	s_int.set(s_int_2);
	read_val(s_char_2);
	s_char.set(s_char_2);
	read_val(s_double_2);
	s_double.set(s_double_2);
	read_val(s_string_2);
	s_string.set(s_string_2);

	cout << s_int.get() << '\n';
    cout << s_char.get() << '\n'; 
    cout << s_double.get() << '\n'; 
    cout << s_string.get() << '\n';
    
    return 0;
}