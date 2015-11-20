//===============================================================================
// Copyright:	Copyright (c) 2015 Made to Order Software Corp.
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

#include "UpdateThread.h"

#include <libdebpackages/wpkg_output.h>
#include <libdebpackages/wpkgar_repository.h>

UpdateThread::UpdateThread( QObject* p )
    : QThread(p)
{
}

void UpdateThread::run()
{
    try
    {
        QMutexLocker locker( &Manager::Instance()->GetMutex() );
        auto manager( Manager::Instance()->GetManager().lock() );
        wpkgar::wpkgar_repository repository( manager.get() );

        repository.update();
    }
    catch( const std::runtime_error& except )
    {
        qCritical() << "std::runtime_error caught! what=" << except.what();
        wpkg_output::log( except.what() ).level( wpkg_output::level_error );
    }

    // Destroy now that we're finished.
    Manager::Release();
}

// vim: ts=4 sw=4 et
