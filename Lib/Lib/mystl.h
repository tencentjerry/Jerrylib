#pragma once
#include "allocator.h"


namespace MySTL
{


template<typename T>
using default_allocator = Lib::allocator<T>;

template<typename key, typename value, typename compare = std::less<key> >
class map : public std::map<key, value, compare, default_allocator<std::pair<const key, value> > >
{

};

template<typename key, typename compare = std::less<key>>
class set : public std::set<key, compare, Lib::allocator<key> >
{

}; 


template<typename value>
class vector : public std::vector<value, Lib::allocator<value>>
{

};


template<typename value>
class list : public std::list<value, Lib::allocator<value>>
{

};


using string = std::basic_string<char, std::char_traits<char>, Lib::allocator<char> >;



}

