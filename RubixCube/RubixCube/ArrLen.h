//extremely simple class meant for passing arrays between functions, so that length can be stored along with it.
#ifndef __ArrLen__
#define __ArrLen__

template<typename T>
class ArrLen
{
public:
	T* arr;
	size_t len;

	T& operator[](size_t i);
};

#endif