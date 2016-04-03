/*
 * NeoTypedData.h
 *
 *  Created on: 2016年2月18日
 *      Author: neo
 */

#ifndef SRC_UTILITIES_NEOTYPEDDATA_H_
#define SRC_UTILITIES_NEOTYPEDDATA_H_

#include "NeoData.h"

/*
 *具体类型数据容器
 */
template<typename T>
class NeoTypedData: virtual public NeoData
{
public:
	NeoTypedData();
	NeoTypedData(T& data);
	virtual ~NeoTypedData();
	T& getData() const;
	void setData(T& data);

private:
	T m_data;
};


#endif /* SRC_UTILITIES_NEOTYPEDDATA_H_ */
