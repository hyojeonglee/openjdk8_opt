#!/bin/bash

gcc -Wall -c -fPIC swpness.c

cp swpness.o ~/jdk_1.8_source/openjdk-8u40-src-b25-10_feb_2015/openjdk/build/linux-x86_64-normal-server-slowdebug/hotspot/linux_amd64_compiler2/debug/
