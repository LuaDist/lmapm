# Copyright (C) 2007-2012 LuaDist.
# Created by Peter Kapec
# Redistribution and use of this file is allowed according to the terms of the MIT license.
# For details see the COPYRIGHT file distributed with LuaDist.
# Please note that the package source code is licensed under its own license.

project ( lmapm C )
cmake_minimum_required ( VERSION 2.8 )
include ( cmake/dist.cmake )
include ( lua )

# Find Mapm library
find_package ( MAPM REQUIRED )
include_directories ( ${MAPM_INCLUDE_DIRS} )

install_lua_module ( mapm lmapm.c mapm.def LINK ${MAPM_LIBRARIES} )
install_data ( README )
install_test ( test.lua )
