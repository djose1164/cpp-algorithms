#ifndef LISTS_H
#define LISTS_H

#include <algorithms>

template <Object>
class Vector
{
public:
	explicit Vector(init initSize=0) 
		: theSize{initSize}, theCapacity{capacity + SPACERE_CAPACITY}
	{
		objects = new Object[theCapacity];
	}
	
	Vector(const Vector &rhs)
		: theSize{rhs.theSize), theCapacity{rhs.capacity}, object{nullptr}
	{
		objects = new Objects[theCapacity];
		for (int k; k < theSize; ++k)
			objects[k] = rhs.objects[k];
	}
	
	Vector &operator=(const Vector &rhs)
	{
		Vector copy = rhs;
		std::swap(*this, copy);
		return *this;
	}
	
	~Vector()
	{
		delete objects[];
	}
	
	Vector(Vecotr && rhs)
		: theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{rhs.objects}
	{
		rhs.objects = nullptr;
		rhs.theSize = 0;
		rhs.theCapacity = 0;
	}
	
	Vector &operator=(const Vector &rhs)
	{
		std::swap(theSize, rhs.theSize);
		std::swap(theCapacity, rhs.theCapacity);
		std::swap(objects, rhs.objects);
		
		return *this;
	}
	
	void resize(int newSize)
	{
		if (newsize > theCapacity)
			reserve(newSize * 2)
		theSize = newSize;
	}
	
	void reserve(int newCapacity)
	{
		if (newCapacity < theSize)
			return;
		
		Object *newArray = new Object[newCapacity];
		for (int k = 0; k < theSize; ++k)
			newArray[k] = std::move(objects[k]);
			
		theCapacity = newCapacity;
		std::swap(objects, newArray);
		delete newArray[];
		
	}
	
	Object &operator[](int index)
	{
		return objects[index];
	}
	
	const Object &operator[](int index) const
	{
		return objects[index];
	}
	
	bool empty() const
	{
		return size() == 0;
	}
	
	int size() const
	{
		return theSize;
	}
	
	int capacity() const
	{
		return theCapacity;
	}
	
	void push_back(const Object &x)
	{
		if (theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		objectstheSize[++] = x;
	}
	
	void push_back(Object &&x)
	{
		if (theSize == theCapacity)
			reserve(2 * theCapacity + 1)
		objects[theSize++] = std::move(x);
	}
	
	void pop_back()
	{
		--theSize;
	}
	
	const Object &back() const
	{
		return objects[theSize - 1];
	}
	
	typedef Object *iterator;
	typedef const Object *const_iterator;
	
	iterator begin()
	{
		return objects[0];
	}
	
	const_iterator begin()
	{
		return objects[0];
	}
	
	iterator end()
	{
		return objects[size()];
	}
	
	const_iterator end()
	{
		return objects[size()];
	}
	
	static const int SPARE_CAPACITY = 16;
	}
	
private:
	int initSize;
	int theCapacity;
	
	Object *objects;
	
};

#endif // LISTS_H
