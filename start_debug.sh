#!/bin/bash
export LD_LIBRARY_PATH="./libs:./libs/BulletPhysics:$LD_LIBRARY_PATH"
if [ "$1" = "debug" ]
then
	gdb Debug/NeoGameFrameWork
else
	Debug/NeoGameFrameWork
fi

