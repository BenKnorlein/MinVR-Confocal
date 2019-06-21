﻿//  ----------------------------------
//  Copyright © 2015, Brown University, Providence, RI.
//  
//  All Rights Reserved
//   
//  Use of the software is provided under the terms of the GNU General Public License version 3 
//  as published by the Free Software Foundation at http://www.gnu.org/licenses/gpl-3.0.html, provided 
//  that this copyright notice appear in all copies and that the name of Brown University not be used in 
//  advertising or publicity pertaining to the use or distribution of the software without specific written 
//  prior permission from Brown University.
//  
//  See license.txt for further information.
//  
//  BROWN UNIVERSITY DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE WHICH IS 
//  PROVIDED “AS IS”, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
//  FOR ANY PARTICULAR PURPOSE.  IN NO EVENT SHALL BROWN UNIVERSITY BE LIABLE FOR ANY 
//  SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR FOR ANY DAMAGES WHATSOEVER RESULTING 
//  FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR 
//  OTHER TORTIOUS ACTION, OR ANY OTHER LEGAL THEORY, ARISING OUT OF OR IN CONNECTION 
//  WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 
//  ----------------------------------
//  
///\file DepthTexture.h
///\author Benjamin Knorlein
///\date 6/14/2019

#pragma once

#ifndef DEPTHTEXTURE_H
#define DEPTHTEXTURE_H

class DepthTexture
{
public:
	DepthTexture();
	~DepthTexture();

	void copyDepthbuffer();

	unsigned int depth_texture()
	{
		return m_depth_texture;
	};

	const unsigned& width() const
	{
		return m_width;
	}

	const unsigned& height() const
	{
		return m_height;
	}

private:
	void create();

	unsigned int m_width;
	unsigned int m_height;
	int m_pReadBuffer;
	int m_pDrawBuffer;

	unsigned int m_depth_texture;

	bool m_isInitialized;
};

#endif // DEPTHTEXTURE_H