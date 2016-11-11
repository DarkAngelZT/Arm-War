/*
 * InternalDataStructures.h
 *
 *  Created on: 2016年9月4日
 *      Author: neo
 *  所有内部传参的数据结构定义都在这里了
 */

#ifndef SRC_UTILITIES_INTERNALDATASTRUCTURES_H_
#define SRC_UTILITIES_INTERNALDATASTRUCTURES_H_
#include <map>
#include <irrlicht.h>
#include "NeoData.h"
#include <algorithm>
class NeoData;
/***Physics*****/
class BasicExplosionParams: public NeoData
{
public:
	BasicExplosionParams()
	{
		fRange = 10;
		fImpulse = 1;
		bAttenuateByRange = true;
		nEventID = 3;
	}
	virtual ~BasicExplosionParams()
	{
		aScriptValus.clear();
	}
	BasicExplosionParams& operator=(BasicExplosionParams&another)
	{
		fRange = another.fRange;
		fImpulse = another.fImpulse;
		bAttenuateByRange = another.bAttenuateByRange;
		nEventID = another.nEventID;
		origin = another.origin;
		std::copy(another.aScriptValus.begin(), another.aScriptValus.end(),
				aScriptValus.begin());
		return *this;
	}
	//---lua interface---//
	void PushScriptValue(std::string&value)
	{
		aScriptValus.push_back(value);
	}
	void ClearScriptValues()
	{
		aScriptValus.clear();
	}
	bool SetScriptValueAt(int i,std::string&v)
	{
		if(i<aScriptValus.size())
		{
			aScriptValus[i]=v;
			return true;
		}
		else return false;
	}
	//---------------//
	float fRange;
	float fImpulse;
	bool bAttenuateByRange;
	int nEventID;
	std::vector<std::string> aScriptValus;
	irr::core::vector3df origin;
};

/***Graphics**/
class BasicExplosionEffectParams: public NeoData
{
public:
	BasicExplosionEffectParams()
	{
		fRadius = 10;
		material_name_high_speed = "explosion01.jpg";
		material_name_low_speed = "explosion02.jpg";
		start_color_high_speed = irr::video::SColor(255, 100, 0, 0);
		end_color_high_speed = irr::video::SColor(0, 0, 0, 0);
		start_color_low_speed = irr::video::SColor(200, 0, 0, 0);
		end_color_low_speed = irr::video::SColor(0, 0, 0, 0);
		shock_wave_color = irr::video::SColor(180, 255, 255, 255);
	}
	virtual ~BasicExplosionEffectParams()
	{
	}
	BasicExplosionEffectParams& operator=(BasicExplosionEffectParams&another)
	{
		fRadius = another.fRadius;
		origin = another.origin;
		rotation = another.rotation;
		material_name_high_speed = another.material_name_high_speed;
		material_name_low_speed = another.material_name_low_speed;
		start_color_high_speed = another.start_color_high_speed;
		start_color_low_speed = another.start_color_low_speed;
		end_color_high_speed = another.end_color_high_speed;
		end_color_low_speed = another.end_color_low_speed;
		shock_wave_color = another.shock_wave_color;
		return *this;
	}
	irr::core::vector3df origin;
	irr::core::vector3df rotation;
	float fRadius;
	std::string material_name_high_speed;
	std::string material_name_low_speed;
	irr::video::SColor start_color_high_speed;
	irr::video::SColor end_color_high_speed;
	irr::video::SColor start_color_low_speed;
	irr::video::SColor end_color_low_speed;
	irr::video::SColor shock_wave_color;
};
#endif /* SRC_UTILITIES_INTERNALDATASTRUCTURES_H_ */
