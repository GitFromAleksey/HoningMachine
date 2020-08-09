#ifndef _ARRAY_H
#define _ARRAY_H

#include <stddef.h>
#include <stdint.h>

template <typename T>
class cArray
{
  public:
    cArray(){}
    ~cArray(){}

    void AddItem(T *itemPtr)
    {
//      if(m_ArrayPtr == 0)
//      {
//        m_ArraySize = 1;
//        m_ArrayPtr = new T[1];
//        m_ArrayPtr[0] = itemPtr;
//      }
//      else
//      {
//        T *new_array = new T[++m_ArraySize];

//        for(uint16_t i = 0; i < (m_ArraySize-1); ++i)
//        {
//          new_array[i] = m_ArrayPtr[i];
//        }
//        
//        delete[] m_ArrayPtr;
//        
//        new_array[m_ArraySize-1] = itemPtr;
//        m_ArrayPtr = new_array;
//      }
    }

    T *GetNextItem();
    void ClearArray();
  
  private:
    T *m_ArrayPtr;
    uint16_t m_ArraySize;
    uint16_t m_CurrentItemIndex;
};

#endif /* _ARRAY_H */
