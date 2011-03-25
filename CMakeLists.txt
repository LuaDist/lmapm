# Copyright (C) 2007-2009 LuaDist.
# Created by Peter Kapec
# Redistribution and use of this file is allowed according to the terms of the MIT license.
# For details see the COPYRIGHT file distributed with LuaDist.
# Please note that the package source code is licensed under its own license.

PROJECT(lmapm C)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
INCLUDE(dist.cmake)

# Find Mapm library
FIND_PACKAGE(MAPM REQUIRED)
INCLUDE_DIRECTORIES( ${MAPM_INCLUDE_DIRS})

# Build
ADD_LUA_MODULE(mapm lmapm.c mapm.def)
TARGET_LINK_LIBRARIES(mapm ${MAPM_LIBRARIES})

# Install all files and documentation
INSTALL (TARGETS mapm DESTINATION ${INSTALL_CMOD})
INSTALL (FILES README DESTINATION ${INSTALL_DATA})
INSTALL (FILES test.lua DESTINATION ${INSTALL_TEST})
