#!/bin/bash

JDK7_DIR=/usr/lib/jvm/java-7-openjdk-amd64

bash ./configure --with-target-bits=64 --with-boot-jdk=$JDK7_DIR --with-debug-level=slowdebug --enable-debug-symbols ZIP_DEBUGINFO_FILES=0
