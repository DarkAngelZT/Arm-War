#!/bin/bash
echo start copying...
dest="$1"

mkdir "$dest/libs"
mkdir "$dest/Release"
rsync -av --exclude "*.a" libs/ "$dest/libs/"
rm -r "$dest/libs/win64"

cp Release/NeoGameFrameWork "$dest/Release/NeoGameFrameWork"
cp start_release.sh "$dest/start_game.sh"

cp -a resources "$dest/resources"
cp -a script "$dest/script"

echo "done"
