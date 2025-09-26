#include "vector.hpp"

namespace dsa
{
    // capacity
    template <typename T>
    int Vector<T>::capacity() const
    {
        return cap;
    }

    // elements stored
    template <typename T>
    int Vector<T>::size() const
    {
        return sz;
    }

    // True is empty
    template <typename T>
    bool Vector<T>::empty() const
    {
        return (sz == 0);
    }

    // element at index when vector is const
    template <typename T>
    const T &Vector<T>::operator[](int i) const
    {
        return data[i];
    }

    // element at index when vector is non-const
    template <typename T>
    T &Vector<T>::operator[](int i)
    {
        return data[i];
    }

    // at function for const
    template <typename T>
    const T &Vector<T>::at(int i) const
    {
        if (i < 0 || i >= sz)
        {
            throw "out of bounds error"; // use std error?
        }
        return data[i];
    }

    // at function for non const]
    template <typename T>
    T &Vector<T>::at(int i)
    {
        if (i < 0 || i >= sz)
        {
            throw "out of bounds error";
        }
        return data[i];
    }

    // first element
    template <typename T>
    const T &Vector<T>::front() const
    {
        return data[0];
    }

    // first element
    template <typename T>
    T &Vector<T>::front()
    {
        return data[0];
    }

    // last element
    template <typename T>
    const T &Vector<T>::back() const
    {
        return data[sz - 1];
    }

    // last element
    template <typename T>
    T &Vector<T>::back()
    {
        return data[sz - 1];
    }

    // insert at end
    template <typename T>
    void Vector<T>::push_back(const T &elem)
    {
        if (sz == cap)
        {
            Vector::reserve(std::max(1, 2 * cap)); // inc cap
        }
        data[sz] = elem;
        sz++;
    }

    // remove from end
    template <typename T>
    void Vector<T>::pop_back()
    {
        sz--;
        Vector::shrink(); // call SHRINK() //but doesnt this reduce cap by half?
    }

    // insert at index
    template <typename T>
    void Vector<T>::insert(int i, const T &elem)
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
    template <typename T>
    void Vector<T>::erase(int i)
    {
        for (int k = i + 1; k < sz; k++)
        {
            data[k - 1] = data[k]; // shifts elements over left
        }
        sz--;
        Vector::shrink();
    }

    // capacity >= minimum
    template <typename T>
    void Vector<T>::reserve(int minimum)
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
    template <typename T>
    void Vector<T>::reallocate(int new_cap)
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
    template <typename T>
    void Vector<T>::shrink()
    {
        if (cap > 0 && sz <= cap / 4) {
            int new_cap = std::max(1, cap/2);
            reallocate(new_cap);
        }
    }

    // explicitly reduce the cap to sz and keep at least 1 slot
    template <typename T>
    void Vector<T>::shrink_to_fit()
    {
        if (cap > sz) {
            int new_cap = std::max(1, sz);
            reallocate(new_cap);
        }
    }

}