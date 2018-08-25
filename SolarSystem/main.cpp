#include <GL/glut.h>
#include <stdlib.h>
static int	day = 0,
			month = 0,
			year = 0,
			marsYear = year + 1,
			venusYear = year + 1,
			jupiterYear = year + 1,
			saturnYear = year + 1,
			uranusYear = year + 1,
			neptuneYear = year + 1,
			mercuryYear = year + 1;
void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();  

	glRotatef((GLfloat) year, 0.0, 1.0, 0.0);
	glColor3f(3.0, 3.0, 1.0); //rgb
	glutWireSphere(0.7, 20, 15); //Sun

	glRotatef((GLfloat) mercuryYear, 0.0, 1.0, 0.0);
	glTranslatef(0.9, 0.0, 0.0);
	glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
	glutWireSphere(0.08, 10, 8); //Mercury

	glPopMatrix();
	glPushMatrix();

	glRotatef((GLfloat)venusYear, 0.0, 1.0, 0.0);
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
	glutWireSphere(0.1, 10, 8); //Venus

	glPopMatrix();
	glPushMatrix();
	
	
	glRotatef((GLfloat) year, 0.0, 1.0, 0.0);
	glTranslatef(3.0, 0.0, 0.0);
	glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
	glutWireSphere(0.2, 10, 8); //Earth

	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat) month, 0.0, 1.0, 0.0);
	glutWireSphere(0.07, 10, 5); //Moon

	glPopMatrix();
	glPushMatrix();

	glRotatef((GLfloat) marsYear, 0.0, 1.0, 0.0);
	glTranslatef(6.0, 0.0, 0.0);
	glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
	glutWireSphere(0.16, 10, 8); //Mars

	glTranslatef(0.6, 0.0, 0.0);
	glRotatef((GLfloat) month, 0.0, 1.0, 0.0);
	glutWireSphere(0.05, 10, 5); //Deimos

	glPopMatrix();
	glPushMatrix();

	glRotatef((GLfloat) jupiterYear, 0.0, 1.0, 0.0);
	glTranslatef(8.0, 0.0, 0.0);
	glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
	glutWireSphere(0.4, 10, 8); //Jupiter

	glTranslatef(0.6, 0.0, 0.0);
	glRotatef((GLfloat)month, 0.3, 1.0, 0.0);
	glutWireSphere(0.05, 10, 5); //Ganimedes

	glPopMatrix();
	glPushMatrix();

	glRotatef((GLfloat) saturnYear, 0.0, 1.0, 0.0);
	glTranslatef(10.0, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glutWireSphere(0.3, 10, 8); //Saturn

	glPopMatrix();
	glPushMatrix();

	glRotatef((GLfloat) uranusYear, 0.0, 1.0, 0.0);
	glTranslatef(11.6, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glutWireSphere(0.2, 10, 8); //Uranus

	glPopMatrix();
	glPushMatrix();

	glRotatef((GLfloat)saturnYear, 0.0, 1.0, 0.0);
	glTranslatef(12.5, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glutWireSphere(0.2, 10, 8); //Neptune

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	gluPerspective(50.0, w / (GLfloat)h, 3.0, 90.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(2.0, 4.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //observerPosition
}

void pushbutton(unsigned char button, int x, int y) {

	switch (button) {
	case 'a':
		year = (year + 6) % 360;
		day = (day + 10) % 360;
		month = (month + 30) % 360;
		marsYear = (marsYear + 5) % 360;
		jupiterYear = (jupiterYear + 4) % 360;
		saturnYear = (saturnYear + 3) % 360;
		uranusYear = (uranusYear + 2) % 360;
		neptuneYear = (neptuneYear + 1) % 360;
		venusYear = (venusYear + 7) % 360;
		mercuryYear = (mercuryYear + 8) % 360;

		glutPostRedisplay();
		break;
	default:
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1280, 800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Solar System");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(pushbutton);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}