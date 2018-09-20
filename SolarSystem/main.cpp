#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable:4996)

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




GLuint LoadTexture(const char * filename)
{

	GLuint texture;

	int width, height;

	unsigned char * data;

	FILE * file;

	file = fopen(filename, "rb");

	if (file == NULL) return 0;
	width = 1024;
	height = 512;
	data = (unsigned char *)malloc(width * height * 3);
	//int size = fseek(file,);
	fread(data, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i)
	{
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;

	}


	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);


	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);

	return texture;
}

void initialize(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}
/*
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);


	Image* img = loadBMP("sky.bmp");
	_textureId = loadTextureFromImage(img);
	delete img;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	sphere = gluNewQuadric();
	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluQuadricTexture(sphere, GL_TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);
}
*/

void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();  

	glRotatef((GLfloat) year, 0.0, 1.0, 0.0);
	glColor3f(3.0, 3.0, 1.0); //rgb
	glutSolidSphere(0.7, 20, 15); //Sun

	glRotatef((GLfloat) mercuryYear, 0.0, 1.0, 0.0);
	glTranslatef(0.9, 0.0, 0.0);
	glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
	glutSolidSphere(0.08, 10, 8); //Mercury

	glPopMatrix();
	glPushMatrix();

	glRotatef((GLfloat)venusYear, 0.0, 1.0, 0.0);
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
	glutSolidSphere(0.1, 10, 8); //Venus

	glPopMatrix();
	glPushMatrix();
	
	GLuint texture = LoadTexture("earthmap.bmp");
	glRotatef((GLfloat) year, 0.0, 1.0, 0.0);
	glTranslatef(3.0, 0.0, 0.0);
	glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
	glutSolidSphere(0.2, 10, 8); //Earth

	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat) month, 0.0, 1.0, 0.0);
	glutSolidSphere(0.07, 10, 5); //Moon

	glPopMatrix();
	glPushMatrix();

	glRotatef((GLfloat) marsYear, 0.0, 1.0, 0.0);
	glTranslatef(6.0, 0.0, 0.0);
	glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
	glutSolidSphere(0.16, 10, 8); //Mars

	glTranslatef(0.6, 0.0, 0.0);
	glRotatef((GLfloat) month, 0.0, 1.0, 0.0);
	glutSolidSphere(0.05, 10, 5); //Deimos

	glPopMatrix();
	glPushMatrix();

	glRotatef((GLfloat) jupiterYear, 0.0, 1.0, 0.0);
	glTranslatef(8.0, 0.0, 0.0);
	glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
	glutSolidSphere(0.4, 10, 8); //Jupiter

	glTranslatef(0.6, 0.0, 0.0);
	glRotatef((GLfloat)month, 0.3, 1.0, 0.0);
	glutSolidSphere(0.05, 10, 5); //Ganimedes

	glPopMatrix();
	glPushMatrix();

	glRotatef((GLfloat) saturnYear, 0.0, 1.0, 0.0);
	glTranslatef(10.0, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glutSolidSphere(0.3, 10, 8); //Saturn

	glPopMatrix();
	glPushMatrix();

	glRotatef((GLfloat) uranusYear, 0.0, 1.0, 0.0);
	glTranslatef(11.6, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glutSolidSphere(0.2, 10, 8); //Uranus

	glPopMatrix();
	glPushMatrix();

	glRotatef((GLfloat)saturnYear, 0.0, 1.0, 0.0);
	glTranslatef(12.5, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glutSolidSphere(0.2, 10, 8); //Neptune

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	gluPerspective(50.0, w / (GLfloat)h, 3.0, 90.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(2.0, 4.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //observerPosition
}


void timer(int iUnused)
{
	
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
	glutTimerFunc(50, timer, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(2000, 1500);
	glutInitWindowPosition(0, 0);


	//init window
	glutCreateWindow("Solar System");
	initialize();


	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	timer(0);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}