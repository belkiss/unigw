//===============================================================================
// Copyright:	Copyright (c) 2013 Made to Order Software Corp.
//
// All Rights Reserved.
//
// The source code in this file ("Source Code") is provided by Made to Order Software Corporation
// to you under the terms of the GNU General Public License, version 2.0
// ("GPL").  Terms of the GPL can be found in doc/GPL-license.txt in this distribution.
//
// By copying, modifying or distributing this software, you acknowledge
// that you have read and understood your obligations described above,
// and agree to abide by those obligations.
//
// ALL SOURCE CODE IN THIS DISTRIBUTION IS PROVIDED "AS IS." THE AUTHOR MAKES NO
// WARRANTIES, EXPRESS, IMPLIED OR OTHERWISE, REGARDING ITS ACCURACY,
// COMPLETENESS OR PERFORMANCE.
//===============================================================================

// This is here as a convenience to turn off the warnings generated by Qt4. We have no control
// over their code, so coverage should be turned off.
// Yes this can make the compiles slower, but this is more thorough this way...

#pragma once

#if defined(MO_MSVC)
#	pragma warning( disable: 4068 )
#elif defined(__GNUC__)
#	pragma GCC diagnostic push
#	pragma GCC diagnostic ignored "-Wunknown-pragmas"
#endif

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wctor-dtor-privacy"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-pedantic"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#include <QtCore>
#include <QtGui>
#include <QtWebKit>
#pragma GCC diagnostic pop
#pragma GCC diagnostic pop
#pragma GCC diagnostic pop
#pragma GCC diagnostic pop

#if defined(__GNUC__)
#	pragma GCC diagnostic pop
#endif
