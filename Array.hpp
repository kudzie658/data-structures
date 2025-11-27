#include<stdlib.h>
#include<initializer_list>
#include"Iterator.hpp"
#ifndef ARRAY_HPP
#define ARRAY_HPP

template < typename T, size_t N >
class Array
{
    public:
    using ValueType = T;
    using Itr = Iterator<Array<T, N>>;
    
    private:
    T m_elements[N];
    int m_length;

    public:
    Array(): m_length(N + 1) {
        for(size_t i = 0; i < N; i++)
        m_elements[i] = 0;
    }
    Array(std::initializer_list < T > elements_list) {
        int index = 0;
        for(auto itr = elements_list.begin(); itr != elements_list.end(); itr++) {
            m_elements[index++] = *itr;
        }

        m_length = index + 1;
    }
    
    Itr begin()
    {
        return Itr(m_elements);
    }
    
    Itr end()
    {
        return Itr(m_elements + m_length-1);
    }

    constexpr size_t size() const
    {
        return N;
    }

    T& operator[](size_t index) {
        boundCheck(index);
        return m_elements[index];
    }

    const T& operator[](int index) const
    {
        boundCheck(index);
        return m_elements[index];
    }

    bool add(T element) {
        if(m_length >= N) {
            return false;
        }

        m_elements[m_length] = element;
    }

    bool remove(T data) {
        for(int i = 0; i <= N; i++) {
            if(m_elements[i] == data) {
                m_elements[i] = 0;
                return true;
            }
        }
        return false;
    }

    bool removeAt(size_t index) {
        boundCheck(index); //catch the exception  and return false
        m_elements[index] = 0;
        return true;
    }

    const T& at(size_t index) const
    {
        return m_elements[index];
    }


    private: void boundCheck(size_t size) {}

};

#endif //ARRAY_HPP