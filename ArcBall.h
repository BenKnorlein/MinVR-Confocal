//  ----------------------------------
//  Copyright � 2017, Brown University, Providence, RI.
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
//  PROVIDED �AS IS�, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
//  FOR ANY PARTICULAR PURPOSE.  IN NO EVENT SHALL BROWN UNIVERSITY BE LIABLE FOR ANY 
//  SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR FOR ANY DAMAGES WHATSOEVER RESULTING 
//  FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR 
//  OTHER TORTIOUS ACTION, OR ANY OTHER LEGAL THEORY, ARISING OUT OF OR IN CONNECTION 
//  WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 
//  ----------------------------------
//  
///\file ArcBall.h
///\author Benjamin Knorlein
///\date 10/17/2019

#ifndef ARCBALL_H
#define ARCBALL_H

#include <glm/glm.hpp>
#include <string>

/** Adds a HeadMatrix to the RenderState that gets updated repeatedly based
    upon head tracking events.
 */
class ArcBall {
	public:

		ArcBall();
	    
		virtual ~ArcBall();

		void mouse_pressed(int button, bool isDown);
		void mouseMove(float x, float y);
		glm::mat4 &getViewmatrix()
		{
			updateCameraMatrix();
			return viewmatrix;
		}
	protected:
		void Rotate(float dTheta, float dPhi);
		void Zoom(float distance);
		void Pan(float dx, float dy);
		void updateCameraMatrix();
			
		float m_radius;
		glm::vec3 m_target;
		glm::vec3 m_up;
		glm::vec3 m_eye;

		glm::mat4 viewmatrix;
		bool m_mouse_left_pressed;
		bool m_mouse_right_pressed;
	
		float last_x, last_y;
		float m_PanFactor;
		float m_RotateFactor;
		float m_cameraScrollFactor;
			

};

#endif

