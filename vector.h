#ifndef HEADER
#define HEADER
#include <iostream>

template <typename T>
class Vector {
    public:
        Vector() : m_capacity {4}, m_size {0}, m_ptr{new int[m_capacity]} {}
        
        Vector(const Vector& other) {
            this->m_capacity = other.m_capacity;
            this->m_size = other.m_size;
            this->m_ptr = new T[this -> m_capacity];
            for (int i = 0; i < m_size; ++i) {
                this -> m_ptr[i] = other.m_ptr[i];
            }
        }

        Vector(Vector&& t) {
            this->m_cap = t.m_capacity;
            this->m_size = t.m_size;
            this->m_ptr = t.m_ptr;
            t.m_ptr = nullptr;
            t.m_size = 0;
            t.m_capacity = 0;
        }

        void resize(int m_capacity) {
                m_capacity *= 2;
                int* tmp = new T[m_capacity];
                for (int i = 0; i < m_size; ++i) {
                    tmp[i] = m_ptr[i];
                }
                delete[] m_ptr;
                m_ptr = tmp;
        }
        void push_back(int element) {
            if (m_size == m_capacity) {
                resize(m_capacity);
            }
                m_ptr[m_size] = element;
                m_size += 1;
        }

        void push_front(T element) {
            if (m_size == m_capacity) {
                m_capacity *= 2;
                T* tmp = new T[m_capacity];
                for (int i = 0; i < m_size; ++i) {
                    tmp[i + 1] = m_ptr[i];
                }
                delete[] m_ptr;
                m_ptr = tmp;
            }
            else {
                for (int i = m_size - 1; i >= 0; --i) {
                    m_ptr[i + 1] = m_ptr[i];
                }
            }
            m_ptr[0] = element;
            m_size += 1;
        }

        void pop_back() {
            if (m_size > 0) {
                m_size -= 1;
            }   
            else {
                throw std::out_of_range("Vector is empty.");
            }
        }

        int& operator[](int index) {
            if (index < 0 || index >= m_size) {
                throw std::out_of_range("Index is out of bounds");
            }
            return m_ptr[index];
        }

        Vector& operator=(const Vector& other) {
            if(this == &other) {
                return *this;
            }
            delete[] m_ptr;
            m_capacity = other.m_capacity;
            m_size = other.m_size;
            m_ptr = new int[m_capacity];
            for (int i = 0; i < m_size; ++i) {
                m_ptr[i] = other.m_ptr[i];
            } 
            return *this;
        }

        Vector& operator=(Vector&& other) {
            if (this == &other) {
                return *this;
            }
            delete[] m_ptr;
            this->m_capacity = other.m_capacity;
            this->m_size = other.m_size;
            this->m_ptr = other.m_ptr;
            other.m_capacity = 0;
            other.m_ptr = nullptr;
            other.m_size = 0;
            return *this;
        }

        ~Vector() {
            delete[] m_ptr;
        }
    private:
        int m_capacity;
        int m_size;
        T* m_ptr;
};

#endif