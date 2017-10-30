/*
 * utf8.h
 *
 *  Created on: 2017年10月29日
 *      Author: neo
 */

#ifndef SRC_UTILITIES_UTF8_H_
#define SRC_UTILITIES_UTF8_H_
#include "irrTypes.h"
#include "irrString.h"
namespace irr
{
namespace core
{
void utf8ToWchar(const char *in, wchar_t *out, const u64 len);

void wcharToUtf8(const wchar_t *in, char *out, const u64 len);
}
}

#endif /* SRC_UTILITIES_UTF8_H_ */
