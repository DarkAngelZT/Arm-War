/*
 * NeoTypedData.cpp
 *
 *  Created on: 2016年2月18日
 *      Author: neo
 */

#include "NeoTypedData.h"


template<typename T>
NeoTypedData<T>::NeoTypedData(T& data)
{
}
template<typename T>
T& NeoTypedData<T>::getData() const
{
	return m_data;
}

template<typename T>
NeoTypedData<T>::NeoTypedData()
{
}

template<typename T>
NeoTypedData<T>::~NeoTypedData()
{
}

template<typename T>
void NeoTypedData<T>::setData(T& data)
{
	m_data = data;
}
