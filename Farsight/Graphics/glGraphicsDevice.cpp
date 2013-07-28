#if defined(WIN32)
#include <glut.h>
#elif defined(UNIX)
#include <GL/glut.h>
#endif

#include "glGraphicsDevice.h"

namespace Farsight
{
	 glGraphicsDevice::glGraphicsDevice()
		 : Params()
	 { }

	 bool glGraphicsDevice::Initialize(int argc, char** argv)
	 {
		 glutInit(&argc, argv);
		 glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
		 glutInitWindowPosition(200, 200);

		 glutInitWindowSize(Params.BackBufferWidth, Params.BackBufferHeight);
		 glutCreateWindow("Farsight");

		 return true;
	 }

	 void glGraphicsDevice::DrawBuffer(const VertexBuffer &buffer)
	 {
		 glCallList(buffer.GetId());
	 }

	 void glGraphicsDevice::Clear()
	 {
		 glClear(GL_COLOR_BUFFER_BIT);
	 }
};