#define GLOAD_IMPLEMENTATION
#define RGFW_NO_GL_HEADER
#define RGFW_IMPLEMENTATION
#define RGFW_USE_XDL
#include "gload.h"
#include "RGFW.h"

int main(int argc, char** argv){
	RGFW_window* w = RGFW_createWindow("test", RGFW_RECT(0, 0, 300, 300), 0);
	gload_init();
	RGFW_window_makeCurrent(w);
	while(!RGFW_window_shouldClose(w)){
		RGFW_window_checkEvent(w);

		glViewport(0, 0, w->r.w, w->r.h);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-w->r.w / 2, w->r.w / 2, -w->r.h / 2, w->r.h / 2, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glBegin(GL_TRIANGLES);
			glColor3f(1, 0, 0);
			glVertex2f(0, 100);
			glColor3f(0, 1, 0);
			glVertex2f(-100, -100);
			glColor3f(0, 0, 1);
			glVertex2f(100, -100);
		glEnd();

		RGFW_window_swapBuffers(w);
	}
}
