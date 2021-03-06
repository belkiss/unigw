//=============================================================================
// Package Explorer -- Package Explorer License Box
// Copyright (C) 2011  Made to Order Software Corp.
// All Rights Reserved.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//=============================================================================
#pragma once

#include "ui_LicenseBox.h"

class LicenseBox : public QDialog, private Ui_LicenseBox
{
	Q_OBJECT

public:
	LicenseBox(QWidget *parent_widget);

private slots:
	void onLinkActivated( const QString& webpage_url );
};


// vim: ts=4 sw=4
