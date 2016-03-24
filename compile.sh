#!/bin/bash

if [ ! $1 ];then
    exit
fi

clang++ -g -std=c++11 -stdlib=libc++ $1
