#pragma once
#include "stdafx.h"
#include "MyIter.h"

template <typename T>
class CMyArray
{
	typedef CMyIter<T> iterator;
	typedef CMyIter<const T> const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
public:
	CMyArray() = default;

	CMyArray(const CMyArray& arr)
	{
		const auto size = arr.GetSize();
		if (size != 0)
		{
			m_begin = RawAlloc(size);
			try
			{
				CopyItems(arr.m_begin, arr.m_end, m_begin, m_end);
				m_endOfCapacity = m_end;
			}
			catch (...)
			{
				DeleteItems(m_begin, m_end);
				throw;
			}
		}
	}

	CMyArray(CMyArray&& arr)
		: m_begin(arr.m_begin)
		, m_end(arr.m_end)
		, m_endOfCapacity(arr.m_endOfCapacity)
	{
		arr.m_begin = nullptr;
		arr.m_end = nullptr;
		arr.m_endOfCapacity = nullptr;
	}

	void Append(const T& value)
	{
		if (m_end == m_endOfCapacity) // no free space
		{
			size_t newCapacity = max(size_t(1), GetCapacity() * 2);

			Reserve(newCapacity);
		}
		// Конструируем копию value по адресу newItemLocation
		new (m_end) T(value);
		++m_end;
	}

	void Resize(size_t newSize)
	{
		if (newSize < GetSize())
		{
			PopBackN(GetSize() - newSize)
		}
		else if (GetSize() < newSize)
		{
			CMyArray temp;
			temp.Reserve(newSize);

			for (size_t i = 0; i < GetSize(); ++i)
			{
				temp.Append(*(m_begin + i));
			}
			for (size_t i = GetSize(); i < newSize; ++i)
			{
				temp.Append(T());
			}

			*this = std::move(temp);
		}
	}

	void PopBackN(size_t count)
	{
		T* ptr = m_end - count;
		DeleteItems(ptr, m_end);
		m_end = ptr;
	}

	void Reserve(size_t count)
	{
		if (GetCapacity() < count)
		{
			auto newBegin = RawAlloc(count);
			T *newEnd = newBegin;
			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}
			DeleteItems(m_begin, m_end);

			// Переключаемся на использование нового хранилища элементов
			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + count;
		}
	}

	void Clear()
	{
		DeleteItems(m_begin, m_end);
		m_end = m_begin;
		m_endOfCapacity = m_begin;
	}

	T& GetBack()
	{
		assert(GetSize() != 0u);
		return m_end[-1];
	}

	const T& GetBack()const
	{
		assert(GetSize() != 0u);
		return m_end[-1];
	}

	size_t GetSize()const
	{
		return m_end - m_begin;
	}

	size_t GetCapacity()const
	{
		return m_endOfCapacity - m_begin;
	}

	bool IsEmpty() const
	{
		return (m_begin == m_end);
	}

	const T& operator[](size_t position) const
	{
		if (GetCapacity() <= position)
		{
			throw std::out_of_range("MyArray subscript out of range");
		}
		return *(m_begin + position);
	}

	T& operator[](size_t position)
	{
		if (GetCapacity() <= position)
		{
			throw std::out_of_range("MyArray subscript out of range");
		}
		return *(m_begin + position);
	}

	CMyArray& operator=(CMyArray const& right)
	{
		if (this != &right)
		{
			if (right.IsEmpty())
			{
				Clear();
			}
			else
			{
				CMyArray temp(right);
				std::swap(m_begin, temp.m_begin);
				std::swap(m_end, temp.m_end);
				std::swap(m_endOfCapacity, temp.m_endOfCapacity);
			}
		}
		return *this;
	}

	CMyArray& operator=(CMyArray && right)
	{
		if (this != &right)
		{
			Clear();
			m_begin = right.m_begin;
			m_end = right.m_end;
			m_endOfCapacity = right.m_endOfCapacity;

			right.Clear();
			/*right.m_begin = nullptr;
			right.m_end = nullptr;
			right.m_endOfCapacity = nullptr;*/
		}
		return *this;
	}
	iterator begin()
	{
		return iterator(m_begin);
	}

	const_iterator begin() const
	{
		return const_iterator(m_begin);
	}

	iterator end()
	{
		return iterator(m_end);
	}

	const_iterator end() const
	{
		return const_iterator(m_end);
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(end());
	}

	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(end());
	}

	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}

	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(begin());
	}

	~CMyArray()
	{
		DeleteItems(m_begin, m_end);
	}
private:
	static void DeleteItems(T *begin, T *end)
	{
		// Разрушаем старые элементы
		DestroyItems(begin, end);
		// Освобождаем область памяти для их хранения
		RawDealloc(begin);
	}

	// Копирует элементы из текущего вектора в to, возвращает newEnd
	static void CopyItems(const T *srcBegin, T *srcEnd, T * const dstBegin, T * & dstEnd)
	{
		for (dstEnd = dstBegin; srcBegin != srcEnd; ++srcBegin, ++dstEnd)
		{
			// Construct "T" at "dstEnd" as a copy of "*begin"
			new (dstEnd)T(*srcBegin);
		}
	}

	static void DestroyItems(T *from, T *to)
	{
		// dst - адрес объект, при конструирование которого было выброшено исключение
		// to - первый скорнструированный объект
		while (to != from)
		{
			--to;
			// явно вызываем деструктор для шаблонного типа T
			to->~T();
		}
	}

	static T *RawAlloc(size_t n)
	{
		size_t memSize = n * sizeof(T);
		T *p = static_cast<T*>(malloc(memSize));
		if (!p)
		{
			throw std::bad_alloc();
		}
		return p;
	}

	static void RawDealloc(T *p)
	{
		free(p);
	}

private:
	T *m_begin = nullptr;
	T *m_end = nullptr;
	T *m_endOfCapacity = nullptr;
};