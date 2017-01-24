#pragma once
#include <iterator>

template<typename T>
class CMyIter : public std::iterator<std::random_access_iterator_tag, T>
{
public:
	CMyIter() : m_ptr(nullptr)
	{ // construct with null pointer
	};

	CMyIter(T* p) : m_ptr(p)
	{ // construct with pointer p
	};

	T& operator*() const
	{ // return designated object
		return *m_ptr;
	}

	T* operator->() const
	{ // return pointer to class object
		return (m_ptr);
	}

	CMyIter& operator++()
	{ // preincrement
		++m_ptr;
		return *this;
	}

	CMyIter operator++(int)
	{ // postincrement
		CMyIter tmp = *this;
		++*this;
		return tmp;
	}

	CMyIter& operator--()
	{ // predecrement
		--m_ptr;
		return *this;
	}

	CMyIter operator--(int)
	{ // postdecrement
		CMyIter tmp = *this;
		--*this;
		return tmp;
	}

	CMyIter& operator+=(ptrdiff_t off)
	{ // increment by integer
		m_ptr += off;
		return *this;
	}

	CMyIter operator+(ptrdiff_t off) const
	{ // return this + integer
		CMyIter tmp = *this;
		return tmp += off;
	}

	CMyIter& operator-=(ptrdiff_t off)
	{ // decrement by integer
		return *this += -off;
	}

	CMyIter operator-(ptrdiff_t off) const
	{ // return this - integer
		CMyIter tmp = *this;
		return tmp -= off;
	}

	ptrdiff_t operator-(const CMyIter& right) const
	{ // return difference of iterators
		return m_ptr - right.m_ptr;
	}

	T& operator[](ptrdiff_t off) const
	{	// subscript
		return *(*this + off);
	}

	bool operator==(const CMyIter& right) const
	{	// test for iterator equality
		return m_ptr == right.m_ptr;
	}

	bool operator!=(const CMyIter& right) const
	{	// test for iterator inequality
		return !(*this == right);
	}

	bool operator<(const CMyIter& right) const
	{	// test if this < right
		return m_ptr < right.m_ptr;
	}

	bool operator>(const CMyIter& right) const
	{	// test if this > right
		return right < *this;
	}

	bool operator<=(const CMyIter& right) const
	{	// test if this <= right
		return !(right < *this);
	}

	bool operator>=(const CMyIter& right) const
	{	// test if this >= right
		return !(*this < right);
	}
private:
	T* m_ptr;
};