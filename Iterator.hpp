template<typename ObjectType>
class Iterator
{
    using ValueType = typename ObjectType::ValueType;
    using PointerType = ValueType*;
    using RerenceType = ValueType&;
    
    private:
    PointerType m_ptr;
    
    public:
    Iterator(PointerType ptr):m_ptr(ptr)
    {
    }
    
    RerenceType operator[](int index)
    {
        return *(m_ptr + index);
    }
    
    Iterator& operator=(Iterator<ObjectType> & other)
    {
        this->m_ptr = other.m_ptr;
        return *this;
    }
    
    Iterator& operator++()
    {
        ++m_ptr;
        return *this;
    }
    
    Iterator& operator++(int)
    {
        Iterator temp = *this;
        
        ++(*this);
        return temp;
    }
    
    Iterator& operator--()
    {
        --m_ptr;
        return *this;
    }
    
    Iterator& operator--(int)
    {
        Iterator temp = *this;
        
        --(*this);
        return temp;
    }
    
    bool operator==(Iterator<ObjectType>& other)
    {
        return this->m_ptr == other.m_ptr;
    }
    
   bool operator!=(Iterator<ObjectType> other)
    {
        return this->m_ptr != other.m_ptr;
    }
    
    RerenceType operator*()
    {
        return *m_ptr;
    }
    
};