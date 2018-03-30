#include "GL/gl.h"
#include "GL/glut.h"

void trace_cube()
{
	glBegin(GL_QUADS);

	//Face avant
	glColor3f(1.0,0.0,0.0);
	glVertex3f(0,0,0);
	glVertex3f(0,1000,0);
	glVertex3f(1000,1000,0);
	glVertex3f(0,1000,0);

	glEnd();
	glutSwapBuffers();
}

void affichage()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1,1,1,-1,5,1000);
	gluLookAt(0,0,20,500,500,0,0,0,1);

	trace_cube();

	glFlush();
}

int main(int argc, char *argv[])
{
  	glutInit(&argc, argv);
  	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  	glutInitWindowSize(800,600);
  	glutInitWindowPosition(50,50);
  	glutCreateWindow("Fenetre");
  	glEnable(GL_DEPTH_TEST);
  	glutDisplayFunc(affichage);

  	glutMainLoop();
  	return 0;
}
