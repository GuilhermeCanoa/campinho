/*

	Trabalho final - Computação gráfica
	Dupla: Mariana Fantini e Gabriele Benato
	Unesp - Rio Claro
	
	Uso: gcc -o saida.out TrabalhoFinal.c -lGL -lGLU -lglut -lm
*/

#define PONTOS 10
#define RAIO 3
#define PI 3.14159

#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>

void arquibancada();
void base();
void chao();
void pilarTrave();
void chapeu();
void pilarCil();
void display();
void reshape (int w, int h);
void iniciaIluminacao();
void keyboard (unsigned char key, int a, int b);


static float circ1[10][2];
static float circ2[10][2];

static int anguloRX, anguloRY, anguloRZ;
static int anguloCX, anguloCY, anguloCZ;
static float eyeX = 0, eyeY = -2.9, eyeZ = 16;
GLfloat x, y, z = 0, z2 = 1;
GLint view_w, view_h;
float auxX = 0.1, auxZ = 0.1, auxY = 0.1;
int chutou;

int main(int argc, char** argv) {
	
    // Inicializando o GLUT

	chutou = 0;

    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 500);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("Campo de Futebol");
    iniciaIluminacao();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}



void arquibancada(){

int xLargura = 10;
int yAltura = -4;

	glBegin (GL_POLYGON);
		glVertex3f (xLargura, -4.4, 10);
		glVertex3f (xLargura, -4, 10);
		glVertex3f (xLargura, -4, -5);
		glVertex3f (xLargura, -4.4, -5);
	glEnd ();

	//banco
	glBegin (GL_POLYGON);
		glVertex3f (xLargura,       yAltura,10);
		glVertex3f (xLargura + 0.5, yAltura,10);
		glVertex3f (xLargura + 0.5, yAltura, -5);
		glVertex3f (xLargura,       yAltura, -5);
	glEnd ();
	


//arquibancada
	glBegin (GL_POLYGON);
		glVertex3f (10.5, -4, 10);
		glVertex3f (10.5, -3.6, 10);
		glVertex3f (10.5, -3.6, -5);
		glVertex3f (10.5, -4, -5);
	glEnd ();

//banco
	glBegin (GL_POLYGON);
		glVertex3f (10.5, -3.6,10);
		glVertex3f (11, -3.6,10);
		glVertex3f (11, -3.6, -5);
		glVertex3f (10.5, -3.6, -5);
	glEnd ();


	//arquibancada (altura)
	glBegin (GL_POLYGON);
		glVertex3f (11, -3.6, 10);
		glVertex3f (11, -3.2, 10);
		glVertex3f (11, -3.2, -5);
		glVertex3f (11, -3.6, -5);
	glEnd ();

//banco
	glBegin (GL_POLYGON);
		glVertex3f (11, -3.2,10);
		glVertex3f (11.5, -3.2,10);
		glVertex3f (11.5, -3.2, -5);
		glVertex3f (11, -3.2, -5);
	glEnd ();


		//arquibancada (altura)
	glBegin (GL_POLYGON);
		glVertex3f (11.5, -3.2, 10);
		glVertex3f (11.5, -2.8, 10);
		glVertex3f (11.5, -2.8, -5);
		glVertex3f (11.5, -3.2, -5);
	glEnd ();

//banco
	glBegin (GL_POLYGON);
		glVertex3f (11.5, -2.8,10);
		glVertex3f (12, -2.8,10);
		glVertex3f (12, -2.8, -5);
		glVertex3f (11.5, -2.8, -5);
	glEnd ();


}


void chao() {
	
    glColor3f(0, 1, 0);

	glBegin (GL_POLYGON);
		glVertex3f (-5, -4.4, -5);
		glVertex3f (-5, -4.4, 10);
		glVertex3f (10, -4.4, 10);
		glVertex3f (10, -4.4, -5);
	glEnd ();

	
	glColor3f(0.4, 0.4, 0.4);

/*
	glBegin (GL_POLYGON);
		glVertex3f (-5, -4.4, -5);
		glVertex3f (-5, -4, -5);
		glVertex3f (10, -4, -5);
		glVertex3f (10, -4.4, -5);
	glEnd ();

	glBegin (GL_POLYGON);
		glVertex3f (-5, -4.4, -5);
		glVertex3f (-5, -4, -5);
		glVertex3f (-5, -4, 10);
		glVertex3f (-5, -4.4, 10);
	glEnd ();
*/
	glBegin (GL_POLYGON);
		glVertex3f (10, -4.4, 10);
		glVertex3f (10, -4, 10);
		glVertex3f (-5, -4, 10);
		glVertex3f (-5, -4.4, 10);
	glEnd ();

}

void pilarTrave() {
	
	glColor3f(1, 1, 1);
	GLUquadricObj *quadr;
	quadr = gluNewQuadric();

	glPushMatrix();
		glTranslatef(0, 0.6, 0);
		glRotatef(90, 1, 0, 0);
		gluCylinder(quadr, 0.2f, 0.2f, 3.0f, 32, 32);
	glPopMatrix();

}

void pilarTravessao() {
	
	glColor3f(1, 1, 1);
	GLUquadricObj *quadr;
	quadr = gluNewQuadric();

	glPushMatrix();
		glTranslatef(0, 0, 0);
		glRotatef(-180, 1, 0, 1);
		glRotatef(180,0,1,0);
		glTranslatef(0,-0.5,0);
		gluCylinder(quadr, 0.2f, 0.2f, 4.0f, 32, 32);
	glPopMatrix();

}

void pinturaChao(){

		glColor3f(1, 1, 1);
		GLUquadricObj *quadr;
		quadr = gluNewQuadric();

		glPushMatrix();
			glTranslatef(-10, -2.5,7);
			glRotatef(90,0,1,0);
			gluCylinder(quadr, 0.1f, 0.1f, 15.0f, 32, 32);
		glPopMatrix();

}

void bola(){

	glPushMatrix();
		glTranslatef(0,0,-0.6);
		glutSolidSphere(0.5,60,60);

	glPopMatrix();
}


/////////FUNÇÃO DO SITE https://gist.github.com/strife25/803118
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle
	
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)), 
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
////////////////////////////////////////////////////////////////


void pilarCil() { 		//gera trave, travessao
	
	glPushMatrix();
	//primeira trave
		glTranslatef(5, -1.7, -4);
		pilarTrave();
		glTranslatef(-4, 0, 0);
		pilarTrave();
//segunda trave
		glTranslatef(0, 0, 13.8);
		pilarTrave();
		glTranslatef(4, 0, 0);
		pilarTrave();	
//travessao
		glTranslatef(0,0,0);
		pilarTravessao();
		glTranslatef(0,0,-13.8);
		pilarTravessao();

//pintura
		pinturaChao();

//circulo
		glTranslatef(-2,-2.6,6.7);
		glRotatef(90,1,0,0);
		drawFilledCircle(0,0,2);

		//circulo
		glColor3f(0,1,0);
		glTranslatef(0,0,-0.1);
		drawFilledCircle(0,0,1.5);

		//bola
		glColor3f(1,0,0);
		glTranslatef(0,0.1,0);
		bola();

	glPopMatrix();
	
}

void display() {
	
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	chao();

	glPushMatrix();
	arquibancada();
	glPopMatrix();

	glPushMatrix();
		pilarCil();
	glPopMatrix();

	glutSwapBuffers();
}

void reshape (int w, int h) {
	
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	view_w = w;
	//view_y=y
	view_h = h;

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(65.0, (GLfloat) view_w/(GLfloat) view_h, 1.0, 40.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef (0.0, 0.0, -5.0);

	gluLookAt (eyeX, eyeY, eyeZ,	  // onde está a camera
		   0.0, 0.0, 0.0,	  // pra onde a camera está olhando
		   0.0, 1.0, 0.0);	  // pra onde a camera está apontando
}

/* atenção: função baseada em exemplo do professor */
void iniciaIluminacao() {

  	GLfloat luzAmbiente[4]  = {0.4, 0.4, 0.4, 1.0};
	GLfloat luzDifusa[4]    = {0.7, 0.7, 0.7, 1.0};	         
	GLfloat luzEspecular[4] = {0.0, 0.3, 0.3, 1.0};   	     
	GLfloat posicaoLuz[4]   = {0.0, 100.0, 100.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4] = {0.1, 0.1, 0.1, 1.0};
	GLint especMaterial = 10;

 	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS, especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);
}

void keyboard (unsigned char key, int a, int b) {
	
    GLfloat liga [] = {1.0, 1.0, 1.0, 1.0};
    GLfloat desliga [] = {0.0, 0.0, 0.0, 0.0};

	switch (key) {
		case 'k':
			anguloRZ += 2;
			break;
		case 'j':
			anguloRZ -= 2;
			break;
		case 'm':
			if (anguloCX < 6) {
				anguloCX += 1;
				anguloCZ += 1;
			} else {
				anguloCX -= 1;
				anguloCZ -= 1;
			}
			anguloCY += 2;
			break;
		case 'n':
			if (anguloCX < 4) {
				anguloCX += 1;
				anguloCZ += 1;
			} else {
				anguloCX -= 1;
				anguloCZ -= 1;
			}
			anguloCY -= 2;
			break;
		case 'z':
			eyeZ += 0.05;
			break;
		case 'x':
			eyeZ -= 0.05;
			break;
		case 'p':
			if ((eyeZ < 0.002) && (eyeZ > -0.002)) {
				auxX = auxX * (-1);
			}
			if ((eyeX < 0.002) && (eyeX > -0.002)) {
				auxZ = auxZ * (-1);
			}
			eyeX += auxX;
			eyeZ += auxZ;
			break;
		case 'o':
			if ((eyeZ < 0.002) && (eyeZ > -0.002)) {
				auxX = auxX * (-1);
			}
			if ((eyeX < 0.002) && (eyeX > -0.002)) {
				auxZ = auxZ * (-1);
			}
			eyeX -= auxX;
			eyeZ -= auxZ;
			break;
		case 'q':
			if (eyeY < 4.5) {
				if (auxY < 0) {
					auxY = auxY * (-1);
				}
				eyeY += auxY;
			}
			break;
		case 'w':
			if (eyeY > -4.5){
				if (auxY > 0) {
					auxY = auxY * (-1);
				}
				eyeY += auxY;
			}printf("\nPosicao: %f", eyeY);
			break;
		case 'r':
			eyeX = 0;
			eyeY = 0;
			eyeZ = 16;
			break;
		case 's':
			// deixa só a luz especular
			glDisable(GL_LIGHT0);
			liga[3] = 0.0;
			glLightfv(GL_LIGHT0, GL_SPECULAR, liga);
			glLightfv(GL_LIGHT0, GL_DIFFUSE, desliga);
			glLightfv(GL_LIGHT0, GL_AMBIENT, desliga);
			glEnable(GL_LIGHT0);
			chutou = 1;
			break;
		case 'd':
			// deixa só a luz difusa
			glDisable(GL_LIGHT0);
			liga[3] = 1.0;
			glLightfv(GL_LIGHT0, GL_SPECULAR, desliga);
			glLightfv(GL_LIGHT0, GL_DIFFUSE, liga);
			glLightfv(GL_LIGHT0, GL_AMBIENT, desliga);
			glEnable(GL_LIGHT0);
			break;
		case 'a':
			// deixa só a luz ambiente
			glDisable(GL_LIGHT0);
			liga[3] = 1.0;
			glLightfv(GL_LIGHT0, GL_SPECULAR, desliga);
			glLightfv(GL_LIGHT0, GL_DIFFUSE, desliga);
			glLightfv(GL_LIGHT0, GL_AMBIENT, liga);
			glEnable(GL_LIGHT0);
			break;
		case 'l':
			if (glIsEnabled(GL_LIGHT0)){
				glDisable(GL_LIGHT0);
			} else {
				glEnable(GL_LIGHT0);
			}
			break;
		// sair da simulação
		case ' ':
			exit(0);
		default:
			break;
	}

	glutPostRedisplay();
	reshape(view_w, view_h);
}

