#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>

template <typename Object>
class Vector
{
public:
	explicit Vector(int size = 0)
		: size_{size}
		, capacity_{SPARE_CAPACITY + size_}
	{
		objects_ = new Object[capacity_];
	}

	Vector(const Vector &rhs)
		: size_{rhs.size_}
		, capacity_{rhs.capacity_}
		, objects_{nullptr}
	{
		objects_ = new Object[capacity_];
		for (int i{0}; i < size_; ++i)
			objects_[i] = rhs.objects_[i];
	}

	Vector &operator=(Vector &rhs)
	{
		Vector copy{rhs};
		std::swap(*this, copy);
		return *this;
	}

	~Vector()
	{
		delete[] objects_;
	}

	Vector(Vector &&rhs)
		: size_{rhs.size_}
		, capacity_{rhs.capacity_}
		, objects_{rhs.objects_}
	{
		rhs.size_ = 0;
		rhs.capacity_ = 0;
		rhs.objects_ = nullptr;
	}

	Vector &operator=(Vector &&rhs)
	{
		std::swap(size_, rhs.size_);
		std::swap(capacity_, rhs.capacity_);
		std::swap(objects_, rhs.objects_);

		return *this;
	}

	void resize(int newSize)
	{
		if (newSize > capacity_)
			reserve(newSize*2);
		size_ = newSize;
	}

	void reserve(int newCapacity)
	{
		if (newCapacity < size_)
			return;
		
		auto newArray{new Object[newCapacity]};
		for(int i{0}; i < size_; ++i)
			newArray[i] = std::move(objects_[i]);
		
		capacity_ = newCapacity;
		std::swap(objects_, newArray);
		delete[] newArray;
	}

	Object &operator[](int idx)
	{
		return objects_[idx];
	}

	const Object &operator[](int idx) const
	{
		return objects_[idx];
	}

	bool empty() const
	{
		return size() == 0;
	}

	int size() const
	{
		return size_;
	}

	int capacity() const
	{
		return capacity_;
	}

	void push_back(const Object &x)
	{
		if (size_ == capacity_)
			reserve(2*capacity_ + 1);
		objects_[size_++] = x;
	}

	void push_back(const Object &&x)
	{
		if (size_ == capacity_)
			reserve(2*capacity_ + 1);
		objects_[size_++] = std::move(x);
	}

	void pop_back()
	{
		--size_;
	}

	const Object &back() const
	{
		return objects_[size() - 1];
	}

	typedef Object *iterator;
	typedef const Object *const_iterator;

	iterator begin()
	{
		return &objects_[0];
	}

	const_iterator begin() const
	{
		return &objects_[0];
	}

	iterator end()
	{
		return &objects_[size()];
	}

	const_iterator end() const
	{
		return &objects_[size()];
	}

	static constexpr int SPARE_CAPACITY{16};

private:
	int size_;
	int capacity_;

	Object *objects_;
};

#endif // VECTOR_H
