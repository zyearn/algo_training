#!/bin/sh

argc=$#
#echo "Number of argc = $argc"

file=""

while true;do
    if [ $1 ];then
        file=$file$1
        shift
    else
        break
    fi
done

if [ -f $file.cpp ]
then
    echo "file exist"
    exit
fi
pbpaste > $file.cpp
vim $file.cpp
