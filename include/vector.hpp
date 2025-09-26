#pragma once
#include <iostream>
#include <algorithm>  //for std::max
#include <stdexcept>  //for throwing out of bounds exception

namespace dsa{

template <typename T>
class Vector {

private:
    int cap{0};
    int sz{0};
    T* data{nullptr};

public:
    //empty
    Vector() = default;
    // capacity
    int capacity() const
    {
        return cap;
    }

    // elements stored
    int size() const
    {
        return sz;
    }

    // True is empty
    bool empty() const
    {
        return (sz == 0);
    }

    // element at index when vector is const
    const T& operator[](int i) const
    {
        return data[i];
    }

    // element at index when vector is non-const
    T& operator[](int i)
    {
        return data[i];
    }

    // at function for const
    const T& at(int i) const
    {
        if (i < 0 || i >= sz)
        {
            throw std::out_of_range("out of bounds error");
        }
        return data[i];
    }

    // at function for non const]
    T& at(int i)
    {
        if (i < 0 || i >= sz)
        {
            throw std::out_of_range("out of bounds error");
        }
        return data[i];
    }

    // first element
    const T& front() const
    {
        return data[0];
    }

    // first element
    T& front()
    {
        return data[0];
    }

    // last element
    const T& back() const
    {
        return data[sz - 1];
    }

    // last element
    T& back()
    {
        return data[sz - 1];
    }

    // insert at end
    void push_back(const T &elem)
    {
        if (sz == cap)
        {
            reserve(std::max(1, 2 * cap)); // inc cap
        }
        data[sz] = elem;
        sz++;
    }

    // remove from end
    void pop_back()
    {
        sz--;
        Vector::shrink(); // call SHRINK() //but doesnt this reduce cap by half?
    }

    // insert at index
    void insert(int i, const T &elem)
    {
        if (sz == cap)
        {
            reserve(std::max(1, 2 * cap)); // inc cap
        }

        for (int k = sz - 1; k >= i; k--)
        { // from the right, move left until i. shift elements right
            data[k + 1] = data[k];
        }

        data[i] = elem;
        sz++;
    }

    // removes at index
    void erase(int i)
    {
        for (int k = i + 1; k < sz; k++)
        {
            data[k - 1] = data[k]; // shifts elements over left
        }
        sz--;
        shrink();
    }

    // capacity >= minimum
    void reserve(int minimum)
    {
        if (cap < minimum)
        {
            T *new_array = new T[minimum];
            for (int k = 0; k < sz; k++)
            {
                new_array[k] = data[k];
            }
            delete[] data;
            data = new_array;
            cap = minimum;
        }
    }

    // helper function for shrink - increases the capacity
    void reallocate(int new_cap)
    {
        if (new_cap == cap) {
            return;
        }
        T *temp = new T[new_cap];

        for (int k = 0; k < sz; k++) {
            temp[k] = data[k];
        }
        
        delete[] data;
        data = temp;
        cap  = new_cap;
    }

    // called by other functions to reduce cap by half
    // when sz <= cap/4
    void shrink()
    {
        if (cap > 0 && sz <= cap / 4) {
            int new_cap = std::max(1, cap/2);
            reallocate(new_cap);
        }
    }

    // explicitly reduce the cap to sz and keep at least 1 slot
    void shrink_to_fit()
    {
        if (cap > sz) {
            int new_cap = std::max(1, sz);
            reallocate(new_cap);
        }
    }

}; //end class Vector
}//end namespace dsa

