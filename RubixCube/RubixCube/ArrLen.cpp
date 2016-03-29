#include "ArrLen.h"


template<typename T>
inline T & ArrLen<T>::operator[](size_t i)
{
	return arr[i];
}