// gcc man.c -lglut -lGL -lGLU -lm -o man && ./man

#include <GL/glut.h>
#include <stdio.h>
// Rotation
static GLfloat yRot = 0.0f;
static GLfloat xRot = 0.0f;
static GLfloat zRot = 0.0f;
static GLfloat zoom = -5.0f;
float angulo1=0.0;
float angulo2=0.0;
float angulo3 = 0.0;
int aux = 0;
// Change viewing volume and viewport. Called when window is resized
void ChangeSize(int w, int h)
{
    GLfloat fAspect;

    // Prevent a divide by zero
    if (h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w / (GLfloat)h;

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Produce the perspective projection
    gluPerspective(35.0f, fAspect, 1.0, 40.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// This function does any needed initialization on the rendering context. Here it sets up and initializes the lighting for the scene.
void SetupRC()
{

    // Light values and coordinates
    GLfloat whiteLight[] = {0.05f, 0.05f, 0.05f, 1.0f};
    GLfloat sourceLight[] = {0.20f, 0.25f, 0.25f, 1.0f};
    GLfloat lightPos[] = {-10.f, 5.0f, 5.0f, 1.0f};

    glEnable(GL_DEPTH_TEST); // Hidden surface removal
    glFrontFace(GL_CCW);     // Counter clock-wise polygons face out
    glEnable(GL_CULL_FACE);  // Do not calculate inside

    // Enable lighting
    glEnable(GL_LIGHTING);  
  
    // Setup and enable light 0  
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);  
    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);  
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);  
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);  
    glEnable(GL_LIGHT0);
     
    // Enable color tracking  
    glEnable(GL_COLOR_MATERIAL);  

    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Black blue background
    glClearColor(0.67f, 1.00f, 0.54f, 1.0f);
}


void MouseFunc(int button, int sate, int x, int y){
	
	if(button == 3){
		zoom += 0.5f;
	}
	if(button == 4){
		zoom -= 0.5f;
	}

	glutPostRedisplay();
}

// Respond to arrow keys (rotate snowman)
void SpecialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_UP){
        xRot -= 5.0f;
    }

    if (key == GLUT_KEY_DOWN){
        xRot += 5.0f;
    }

    if (key == GLUT_KEY_LEFT){
        yRot -= 5.0f;
    }

    if (key == GLUT_KEY_RIGHT){
        yRot += 5.0f;
    }

    yRot = (GLfloat)((const int)yRot % 360);
    xRot = (GLfloat)((const int)xRot % 360);
    // Refresh the Window
    glutPostRedisplay();
}

// Called to draw scene
void RenderScene(void)
{

    GLUquadricObj *pObj; // Quadric Object

    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Save the matrix state and do the rotations
    glPushMatrix();

    // Move object back and do in place rotation
    glTranslatef(0.0f, 0.5f, zoom);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);

    // Draw something
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    // white
     

    // bonecoBrabo

	
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	// tronco
	glPushMatrix();
		glTranslatef(0.0f,-1.0f, 0.0f);
		glScaled(1.2,1.5,0.5);
		glutSolidCube(1.0);
		// Cabeça
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glPushMatrix();
			glTranslatef(0.0f,0.75f, 0.0f);
			glScaled(0.9,0.7,1.75);
			glutSolidCube(0.8);

		glPopMatrix();
		
		glColor4f(1.00f, 0.73f, 0.73f, 1.0f); 
		glPushMatrix();		//Ombros
			glTranslatef(-0.65f,0.35f, 0.0f);
			glRotatef(angulo1,0,0,1);
			glScaled(0.75,0.7,2.5);
			
			glutSolidCube(0.48);
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			glPushMatrix();			//Braços
				glTranslatef(-0.01f,-0.70f, 0.0f);
				glScaled(0.35,1.0,0.35);
				glutSolidCube(1.0);

				glColor4f(1.00f, 0.73f, 0.73f, 1.0f); 
				glPushMatrix();// punhos
					glTranslatef(-0.01f,-0.39f, 0.0f);
												glRotatef(angulo2,0,0,1);


					glScaled(1.25,0.35,1.25);
					glutSolidCube(0.90);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		glColor4f(1.00f, 0.73f, 0.73f, 1.0f); 
		glPushMatrix();//Ombros
			glTranslatef(0.65f,0.35f, 0.0f);
			glScaled(0.75,0.7,2.5);
			glutSolidCube(0.48);

			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			glPushMatrix();		//Braços
				glTranslatef(0.01f,-0.70f, 0.0f);
				glScaled(0.35,1.0,0.35);
				glutSolidCube(1.0);

				glColor4f(1.00f, 0.73f, 0.73f, 1.0f); 
				glPushMatrix();// punhos
					glTranslatef(0.01f,-0.39f, 0.0f);

					glScaled(1.25,0.35,1.25);
					glutSolidCube(0.90);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	
		glPushMatrix();// Pernas 1/2
			glTranslatef(0.25f,-0.60f, 0.0f);
			glScaled(0.40,0.40,0.85);
			glutSolidCube(1.0);

			glColor4f(1.00f, 0.73f, 0.73f, 1.0f);
			glPushMatrix();//Joelho
				glTranslatef(0.0f,-0.65f, 0.0f);
				glScaled(1.1,0.45,1.1);
				glutSolidCube(1.0);

				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
				glPushMatrix();//canela
					glTranslatef(0.0f,-1.0f, 0.0f);
					glScaled(0.9,2.7,0.9);
					glutSolidCube(1.0);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
			
		glPushMatrix();// Pernas 2/2
			glTranslatef(-0.25f,-0.60f, 0.0f);
			glScaled(0.40,0.40,0.85);
			glutSolidCube(1.0);   	 
			glPushMatrix();//Joelho
			glColor4f(1.00f, 0.73f, 0.73f, 1.0f);
				glTranslatef(0.0f,-0.65f, 0.0f);
				glScaled(1.1,0.45,1.1);
				glutSolidCube(1.0);
				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
				glPushMatrix();//canela
					glTranslatef(0.0f,-1.0f, 0.0f);
					glScaled(0.9,2.7,0.9);
					glutSolidCube(1.0);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	
	if(angulo1 !=-170 || angulo1 == 0.0){
		angulo1 = angulo1 -1;

	}




	if(angulo1 == -170 && angulo2 < 10 && aux == 0){
	angulo2 = angulo2 +1;
	}
	if((angulo2 == 10 || aux == 1) && (angulo1==-170)){
			
		angulo2 = angulo2-1;
		aux =1;
		
	}
	if (angulo2 == -10 && angulo1!=0.0){
		angulo1 = angulo1+1;
		aux =2;
	}






	

	glutPostRedisplay();

			
    // Restore the matrix state
    glPopMatrix();

    // Buffer swap
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Man");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);

    SetupRC();
    glutMainLoop();

    return 0;
}
