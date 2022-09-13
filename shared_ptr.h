#pragma once
#include <cstddef>

namespace re
{
    
template<typename T>
class shared_ptr
{
public:
    shared_ptr();
    ~shared_ptr();
    explicit shared_ptr(T*);
    shared_ptr(const shared_ptr&);
    shared_ptr<T>& operator= (const shared_ptr&);

    T& operator*() const;
    T* operator->() const;

    explicit operator bool() const;

    bool unique();
    void reset();
    void reset(T*);
    void reset(T&);


private:
    T* ptr_;
    size_t* count_;
};


template<typename T>
shared_ptr<T>::shared_ptr() : ptr_(nullptr), count_(new size_t(1))
{
}

template<typename T>
shared_ptr<T>::~shared_ptr()
{
    if(--(*count_) == 0)
    {
        delete ptr_;
        ptr_ = nullptr; /*如果不将指针置为nullptr，
                        此时ptr_仍然指向原来的内存地址，可能会产生野指针问题*/
                        
        delete count_;
        count_ = nullptr;
    }
}

template<typename T>
shared_ptr<T>::shared_ptr(T* p): ptr_(p), count_(new size_t(1))
{
}

template<typename T>
shared_ptr<T>::shared_ptr(const shared_ptr& rhs): ptr_(rhs.ptr_), count_(rhs.count_)
{
    ++(*count_);
}




template<typename T>
shared_ptr<T>& shared_ptr<T>::operator= (const shared_ptr<T>& rhs)
{
    ptr_ = rhs.ptr_;
    count_ = rhs.count_;
    ++(*count_);
    return *this;
}

template<typename T>
T* shared_ptr<T>::operator->() const
{
    return ptr_;
}

template<typename T>
T& shared_ptr<T>::operator*() const
{
    return *ptr_;
}

template<typename T>
shared_ptr<T>::operator bool() const
{
    return ptr_ != nullptr;
}

} // namespace re