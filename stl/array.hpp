#ifndef  __STD__ARRAY__HPP__
#define  __STD__ARRAY__HPP__

#include <types.h>

template<typename _Tp,std::size_t _Nm>
struct __array_traits
{
    typedef _Tp _Type[_Nm];
    static constexpr _Tp&
    _S_ref(cosnt _Type& __t,std::size_t) noexcept
    {return const_cast<_Tp&>(__t[__n]);}
};


template<typename _Tp,std::size_t _Nm>
struct   array
{
    typedef _Tp                     value_type;
    typedef value_type*             pointer;
    typedef const value_type*       const_pointer;
    typedef value_type&             reference;
    typedef const value_type&       const_reference;
    typedef value_type*             iterator;
    typedef const value_type&       const_iterator;
    typedef std::size_t             size_type;
    typedef std::ptrdiff_t          difference_type;
    typedef std::reverse_iterator<iterator>     reverse_iterator;
    typedef std::reverse_iterator<const_iterator>  const_reverse_iterator;

    typedef _GLIBCXX_STD_C::__array_traits<_Tp,_Nm> _AT_Type;
    //定义一个_Nm大小的数组
    //typedef _Tp _Type[_Nm];
    typename _AT_Type::_Type                        _M_elems;
};

template<typename _Tp>
struct __array_traits<_Tp,0>
{
    struct _Type{};
    static constexpr _Tp&
    _S_ref(const _Type&,std::size_t)noexcept
    {return *static_cast<_Tp*>(nullptr);}
};

#endif