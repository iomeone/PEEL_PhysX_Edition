///////////////////////////////////////////////////////////////////////////////
/*
 *	PEEL - Physics Engine Evaluation Lab
 *	Copyright (C) 2012 Pierre Terdiman
 *	Homepage: http://www.codercorner.com/blog.htm
 */
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ScreenQuad.h"
#include "Camera.h"

///////////////////////////////////////////////////////////////////////////////

ScreenQuadMode::ScreenQuadMode()
{
}

ScreenQuadMode::~ScreenQuadMode()
{
}

///////////////////////////////////////////////////////////////////////////////

ShaderBasedScreenQuad::ShaderBasedScreenQuad()
{
}

ShaderBasedScreenQuad::~ShaderBasedScreenQuad()
{
	ReleaseProgram(mProgram);
}

///////////////////////////////////////////////////////////////////////////////

void Draw2DScreenQuad(udword screen_width, udword screen_height)
{
	const Point p0b(-1.0f, -1.0f, 0.0f);
	const Point p1b(-1.0f,  1.0f, 0.0f);
	const Point p2b( 1.0f,  1.0f, 0.0f);
	const Point p3b( 1.0f, -1.0f, 0.0f);

	const Point c0 = ComputeWorldRay(0, screen_height-1);
	const Point c1 = ComputeWorldRay(0, 0);
	const Point c2 = ComputeWorldRay(screen_width-1, 0);
	const Point c3 = ComputeWorldRay(screen_width-1, screen_height-1);

	glBegin(GL_TRIANGLES);
		glNormal3f(c0.x, c0.y, c0.z);
		glVertex3f(p0b.x, p0b.y, p0b.z);

		glNormal3f(c1.x, c1.y, c1.z);
		glVertex3f(p1b.x, p1b.y, p1b.z);

		glNormal3f(c2.x, c2.y, c2.z);
		glVertex3f(p2b.x, p2b.y, p2b.z);

		glNormal3f(c0.x, c0.y, c0.z);
		glVertex3f(p0b.x, p0b.y, p0b.z);

		glNormal3f(c3.x, c3.y, c3.z);
		glVertex3f(p3b.x, p3b.y, p3b.z);

		glNormal3f(c2.x, c2.y, c2.z);
		glVertex3f(p2b.x, p2b.y, p2b.z);
	glEnd();
}

///////////////////////////////////////////////////////////////////////////////