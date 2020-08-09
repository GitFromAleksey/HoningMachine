#include "array.hpp"

// ----------------------------------------------------------------------------
//template <typename T>
//cArray<T>::cArray():
//m_ArrayPtr(0),
//m_ArraySize(0),
//m_CurrentItemIndex(0)
//{}
//// ----------------------------------------------------------------------------
//template <typename T>
//cArray<T>::~cArray()
//{
//  delete[] m_ArrayPtr;
//}
// ----------------------------------------------------------------------------
//template <typename T>
//void cArray<T>::AddItem(T *itemPtr)
//{
//  if(m_ArrayPtr == 0)
//  {
//    m_ArraySize = 1;
//    m_ArrayPtr = new T[1];
//    m_ArrayPtr[0] = itemPtr;
//  }
//  else
//  {
//    T *new_array = new T[++m_ArraySize];

//    for(uint16_t i = 0; i < (m_ArraySize-1); ++i)
//    {
//      new_array[i] = m_ArrayPtr[i];
//    }
//    
//    delete[] m_ArrayPtr;
//    
//    new_array[m_ArraySize-1] = itemPtr;
//    m_ArrayPtr = new_array;
//  }
//}
// ----------------------------------------------------------------------------
template <typename T>
T *cArray<T>::GetNextItem()
{
  T *tmp = 0;

  if(m_ArraySize == 0)
    return tmp;
  
  tmp = m_ArrayPtr[m_CurrentItemIndex];

  ++m_CurrentItemIndex;
  if(m_CurrentItemIndex == m_ArraySize)
    m_CurrentItemIndex = 0;
  
  return tmp;
}
// ----------------------------------------------------------------------------
template <typename T>
void cArray<T>::ClearArray()
{
  m_CurrentItemIndex = 0;
  m_ArraySize = 0;
  delete[] m_ArrayPtr;
  m_ArrayPtr = 0;
}
// ----------------------------------------------------------------------------
