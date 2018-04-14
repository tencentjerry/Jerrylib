#pragma once

#include "base.h"

namespace Lib
{

class SysNewAlloc
{
public:
	static void* allocate(size_t size)
	{
		void* p = ::malloc(size);
		if (nullptr == p)
		{
			throw std::bad_alloc();
		}
		return p;
	}

	static void deallocate(void* p)
	{
		::free(p);
	}


};

template<typename Type, typename Malloc = SysNewAlloc>
class allocator
{
public:

	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef Type* pointer;
	typedef const Type* const_pointer;
	typedef Type& reference;
	typedef const Type& const_reference;
	typedef Type value_type;

	template<typename Type1>
	struct rebind
	{
		typedef allocator<Type1> other;
	};

	allocator()
	{

	}

	template<typename Type1>
	allocator(const allocator<Type1>& other)
	{

	}

	~allocator()
	{

	}

	pointer address(reference __x) const
	{
		return &__x;
	}

	const_pointer address(const_reference __x) const
	{
		return &__x;
	}

	pointer allocate(size_type __n, const void* = 0)
	{
		if (__n > this->max_size())
		{
			throw std::bad_alloc();
		}

		return static_cast<Type*>(Malloc::allocate(__n * sizeof(Type)));
	}

	void deallocate(pointer __p, size_type size)
	{
		Malloc::deallocate(__p);
		return;
	}

	size_type max_size() const
	{
		return size_t(-1) / sizeof(Type);
	}

	template<typename _Up, typename... Args>
	void construte(_Up* up, Args&&... args)
	{
		new((void*)up) _Up(std::forward<Args>(args)...);
	}

	template<typename _Up>
	void destroy(_Up* __p)
	{
		__p->~_Up();
	}
};


template<typename _TP>
inline bool operator == (const allocator<_TP>& allocater1, const allocator<_TP>& allocater2)
{
	return true;
}

template<typename _TP>
inline bool operator != (const allocator<_TP>& allocater1, const allocator<_TP>& allocater2)
{
	return false;
}

}
