#!/bin/bash

if [ ! $1 ];then
    exit
fi

clang++ -std=c++11 -stdlib=libc++ $1
