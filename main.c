#include "GL/gl.h"
#include "GL/glut.h"

double angle = 0.0;
double inc = .5;

void Animer()
{
	angle += inc;
	if(angle > 360) angle = 0;
	if(angle < 0) angle = 360;

	glutPostRedisplay();
}

void GererClavier(unsigned char touche, int x, int y)
{
	if(touche == 'a') inc = -inc;
}

void trace_cube()
{
	glBegin(GL_QUADS);

	//Face avant
	glColor3f(1.0,0.0,0.0);
	glVertex3f(0,4,0);
	glVertex3f(8,4,0);
	glVertex3f(8,4,4);
	glVertex3f(0,4,4);

	//Face arriere
	glColor3f(0.0,1.0,0.0);
	glVertex3f(0,0,0);
	glVertex3f(8,0,0);
	glVertex3f(8,0,4);
	glVertex3f(0,0,4);

	//Face gauche
	glColor3f(0.0,0.0,1.0);
	glVertex3f(0,4,0);
	glVertex3f(0,0,0);
	glVertex3f(0,0,4);
	glVertex3f(0,4,4);

	//Face droite
	glColor3f(1.0,1.0,0.0);
	glVertex3f(8,4,0);
	glVertex3f(8,0,0);
	glVertex3f(8,0,4);
	glVertex3f(8,4,4);

	//Face haut
	glColor3f(1.0,0.0,1.0);
	glVertex3f(0,4,4);
	glVertex3f(8,4,4);
	glVertex3f(8,0,4);
	glVertex3f(0,0,4);

	//Face bas
	glColor3f(0.0,1.0,1.0);
	glVertex3f(0,4,0);
	glVertex3f(8,4,0);
	glVertex3f(8,0,0);
	glVertex3f(0,0,0);


	//Toit gauche
	glColor3f(0.0,1.0,1.0);
	glVertex3f(0,0,4);
	glVertex3f(0,4,4);
	glVertex3f(2,2,6);
	glVertex3f(2,2,6);

	//Toit droite
	glColor3f(0.0,1.0,0.0);
	glVertex3f(8,0,4);
	glVertex3f(8,4,4);
	glVertex3f(6,2,6);
	glVertex3f(6,2,6);


	//Toit Avant
	glColor3f(1.0,0.0,0.0);
	glVertex3f(0,4,4);
	glVertex3f(8,4,4);
	glVertex3f(6,2,6);
	glVertex3f(2,2,6);

	//Toit Arriere
	glColor3f(1.0,1.0,0.0);
	glVertex3f(0,0,4);
	glVertex3f(8,0,4);
	glVertex3f(6,2,6);
	glVertex3f(2,2,6);

	glEnd();
	glutSwapBuffers();
}

void affichage()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-2,2,2,-2,5,300);
	gluLookAt(20,20,20,0,0,0,20,20,0);

	glRotatef(angle,0,0,1);

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
  	glutIdleFunc(Animer);
  	glutKeyboardFunc(GererClavier);

  	glutMainLoop();
  	return 0;
}
