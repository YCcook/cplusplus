#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <functional>
#include <iterator>

using namespace std;


template<typename _Iterator>
#if _cplusplus <201103L
inline typename reverse_iterator<_Iterator>::difference_type
    operator-(const reverse_iterator<_Iterator>&_x,
            const reverse_iterator<_Iterator>&_y)
#else
inline auto
operator-(const reverse_iterator<_Iterator>&_x,
          const reverse_iterator<_Iterator>&_y)
->decltype(_x.base(),_y.base())
#endif
{return _y.base() - _x.base();}

class c
{public:
    explicit c(const string &s)
    :mystr(s){}
    friend  ostream &operator<<(ostream &os)
    {
        return os<<mystr<<endl;
    }
private:
    string mystr;
}

int main()
{
    auto i=42;

    auto ll1=[](int x)->int{return x+10};

    function<int(int x)>ll=[](int x)->int {return x+10};

    cout<<ll1(10);

    list<int> l{1,2,3};
    list<int>::iterator  iterator;
    iterator =find(l.begin(),l.end(),10);

    auto ite=find(l.begin(),l.end(),11);

    vector<int>vec;

    for(auto &s:vec)
    {
        cout<<s<<endl;
    }

    for(auto _pos=l.begin(),_end=l.end();_pos!=_end;++_pos)
    {
        cout<<*_pos;
    }
    endl;

    vector<string>vs{"hello","world"};

    vecot<bool>v{true};

    auto var=v.at(0);


    return 0; 
}

