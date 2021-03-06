//===============================================================================
// Copyright:	Copyright (c) 2013-2015 Made to Order Software Corp.
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

#include "LogOutput.h"

#include <QApplication>

LogOutput::pointer_t LogOutput::f_instance;

LogOutput::LogOutput()
	: f_logLevel(wpkg_output::level_info)
{
	set_program_name(QApplication::applicationName().toStdString());
    //set_exception_on_error(); // Cause the log to thrown an exception when the error flag is incremented.
}


LogOutput::pointer_t LogOutput::Instance()
{
    if( !f_instance )
    {
        f_instance.reset( new LogOutput );
    }
    return f_instance;
}

void LogOutput::Release()
{
    f_instance.reset();
}


void LogOutput::log_message( const wpkg_output::message_t& msg ) const
{
	QMutexLocker locker( &f_mutex );
	if( compare_levels(msg.get_level(), f_logLevel) >= 0 )
	{
		f_messageFifo.push_back( msg );
	}
    //
	if( msg.get_debug_flags() & wpkg_output::debug_flags::debug_progress )
	{
        AddProcessMessage( msg.get_raw_message().c_str() );
	}
}


wpkg_output::level_t LogOutput::get_level() const
{
	return f_logLevel;
}


bool LogOutput::pending_messages() const
{
	QMutexLocker locker( &f_mutex );
	return !f_messageFifo.isEmpty();
}


wpkg_output::message_t LogOutput::pop_next_message()
{
	QMutexLocker locker( &f_mutex );
	const wpkg_output::message_t message( f_messageFifo.first() );
	f_messageFifo.pop_front();
	return message;
}


void LogOutput::set_level( wpkg_output::level_t level )
{
	QMutexLocker locker( &f_mutex );
	f_logLevel = level;
}


void LogOutput::clear()
{
	QMutexLocker locker( &f_mutex );
    f_messageFifo.clear();
}


void LogOutput::OutputToLog( wpkg_output::level_t level, const QString& msg )
{
    wpkg_output::message_t msg_obj;
    msg_obj.set_level( level );
    msg_obj.set_raw_message( msg.toStdString() );
    try
    {
        log( msg_obj );
    }
    catch( const std::exception& x )
    {
        qCritical() << "Log error exception caught! x='" << x.what() << "'!";
    }
}


void LogOutput::OutputToLog( wpkg_output::level_t level, const wpkg_output::message_t& msg_obj )
{
    try
    {
        log( msg_obj );
    }
    catch( const std::exception& x )
    {
        qCritical() << "exception caught! x='" << x.what() << "'!";
    }
}


// vim: ts=4 sw=4 noet
