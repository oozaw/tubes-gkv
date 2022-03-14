/* Pemilik	: Wahyu Purnomo Ady
 * NIM		: 24060119120028
 * Tanggal	: 27 Maret 2021
 */
 
 
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void cylinder(float alas,float atas,float tinggi);
double rotAngle = 0; // rotation angle (BEWARE: Global)
double rotAngle1 = 0; // rotation angle (BEWARE: Global)
float angle=0.0, deltaAngle = 0.0, ratio;
float x=10.0f,y=10.0f,z=40.0f; // posisi awal kamera
float lx=0.0f,ly=0.01f,lz=-1.0f;
int deltaMove = 0,h,w;
int bitmapHeight=12;
const double PI = 3.141592653589793;
int i, j, radius, jumlah_titik, x_tengah, y_tengah;
int a = 0; // int
int b = 0;
bool right = true;
bool left = true;


GLfloat xt=0.0,yt=0.0,zt=0.0,xw=0.0;   /* x,y,z translation */
GLfloat tx=295,ty=62;
GLfloat xs=1.0,ys=1.0,zs=1.0;

void Reshape(int w1, int h1) {
	// Fungsi reshape
	if(h1 == 0) h1 = 1;
	w = w1;
	h = h1;
	ratio = 1.0f * w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45,ratio,0.1,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
	x, y, z,
	x + lx,y + ly,z + lz,
	0.0f,1.0f,0.0f);
}

void orientMe(float ang) {
	// Fungsi ini untuk memutar arah kamera (tengok kiri/kanan)
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z,
	x + lx,y + ly,z + lz,
	0.0f,1.0f,0.0f);
}

void moveMeFlat(int i) {
	// Fungsi ini untuk maju mundur kamera
	x = x + i*(lx)*0.1;
	z = z + i*(lz)*0.1;
	glLoadIdentity();
	gluLookAt(x, y, z,
	x + lx,y + ly,z + lz,
	0.0f,1.0f,0.0f);
}

void keyboard(unsigned char k, int x, int y)
{
	// Fungsi ini untuk rotasi kamera
	switch (k)
	{
		case 'q':
			rotAngle += 10; // increase rotation by 10 degrees
			break;
		case 'w':
			rotAngle1 += 10; // increase rotation by 10 degrees
			break;
		case 'e':
			rotAngle1 -= 10; // increase rotation by 10 degrees
			break;
		case 'r':
			rotAngle -= 10; // decrease rotation by 10 degrees
			break;
		case 'a':
			xw+=0.5;
			break;
		case 'd' : 
			xw-=0.5;
			break;
		case (27):
			exit(0); // exit
			
	}
	glutPostRedisplay();
}

void cylinder(float alas,float up,float height)
{
	 float i;
	 glPushMatrix();
	 glTranslatef(1.0,0.0,-alas/8); // perpindahan dari X,Y,Z
	 glutSolidCone(alas,0,32,4);
	 for(i=0;i<=height;i+=alas/24) {
		  glTranslatef(0.0,0.0,alas/24);
		  glutSolidTorus(alas/4,alas-((i*(alas-up))/height),16,16);
	 }
	 glTranslatef(0.0,0.0,alas/4);
	 glutSolidCone(height,0,20,1);
	 glColor3f(0.,0.,0.);
	 glPopMatrix();
}

void Truk1() {
	// KONTAINER
	
	// body kanan
	glColor3f(0.5f, 0.8f, 0.5f);
	glPushMatrix();
	glTranslatef(0,0,3);
	glBegin(GL_QUADS);
	glVertex3f(-5.0f,0.5f,0.0f); // kiri bawah
	glVertex3f(2.0f,0.5f,0.0f);  // kanan bawah
	glVertex3f(2.0f,3.0f,0.0f);  // kanan atas
	glVertex3f(-5.0f,3.0f,0.0f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(2.0f,1.3f,0.0f); // kiri bawah
	glVertex3f(4.0f,1.3f,0.0f);  // kanan bawah
	glVertex3f(4.0f,3.0f,0.0f);  // kanan atas
	glVertex3f(2.0f,3.0f,0.0f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(3.0f,0.8f,-0.7f); // kiri bawah
	glVertex3f(3.2f,0.8f,-0.7f);  // kanan bawah
	glVertex3f(3.2f,1.3f,-0.7f);  // kanan atas
	glVertex3f(3.0f,1.3f,-0.7f); // kiri atas
	glEnd();
	glPopMatrix();
	
	// body atas
	glColor3f(0.5f, 0.8f, 0.5f);
	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	glTranslatef(0,0,3);
	glBegin(GL_QUADS);
	glVertex3f(-5.0f,-3.0f,0.0f); // kiri bawah
	glVertex3f(4.0f,-3.0f,0.0f);  // kanan bawah
	glVertex3f(4.0f,-1.5f,0.0f);  // kanan atas
	glVertex3f(-5.0f,-1.5f,0.0f); // kiri atas
	glEnd();
	glPopMatrix();
	
	// body kiri
	glPushMatrix();
	glTranslatef(0,0,1.5);
	glBegin(GL_QUADS);
	glVertex3f(-5.0f,0.5f,0.0f); // kiri bawah
	glVertex3f(2.0f,0.5f,0.0f);  // kanan bawah
	glVertex3f(2.0f,3.0f,0.0f);  // kanan atas
	glVertex3f(-5.0f,3.0f,0.0f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(2.0f,1.3f,0.0f); // kiri bawah
	glVertex3f(4.0f,1.3f,0.0f);  // kanan bawah
	glVertex3f(4.0f,3.0f,0.0f);  // kanan atas
	glVertex3f(2.0f,3.0f,0.0f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(3.0f,0.8f,0.6f); // kiri bawah
	glVertex3f(3.2f,0.8f,0.6f);  // kanan bawah
	glVertex3f(3.2f,1.3f,0.6f);  // kanan atas
	glVertex3f(3.0f,1.3f,0.6f); // kiri atas
	glEnd();
	glPopMatrix();
	
	// body bawah
	glColor3f(0.5f, 0.8f, 0.5f);
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslatef(0,0,3);
	glBegin(GL_QUADS);
	glVertex3f(-5.0f,3.0f,-3.5f); // kiri bawah
	glVertex3f(2.0f,3.0f,-3.5f);  // kanan bawah
	glVertex3f(2.0f,1.5f,-3.5f);  // kanan atas
	glVertex3f(-5.0f,1.5f,-3.5f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(2.0f,3.0f,-4.3f); // kiri bawah
	glVertex3f(4.0f,3.0f,-4.3f);  // kanan bawah
	glVertex3f(4.0f,1.5f,-4.3f);  // kanan atas
	glVertex3f(2.0f,1.5f,-4.3f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(3.2f,2.3f,-3.8f); // kiri bawah
	glVertex3f(3.0f,2.3f,-3.8f);  // kanan bawah
	glVertex3f(3.0f,2.1f,-3.8f);  // kanan atas
	glVertex3f(3.2f,2.1f,-3.8f); // kiri atas
	glEnd();
	glPopMatrix();
	
	// body belakang
	glColor3f(0.5f, 0.8f, 0.5f);
	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	glTranslatef(0,0,3);
	glBegin(GL_QUADS);
	glVertex3f(3.0f,0.5f,2.0f); // kiri bawah
	glVertex3f(1.5f,0.5f,2.0f);  // kanan bawah
	glVertex3f(1.5f,3.0f,2.0f);  // kanan atas
	glVertex3f(3.0f,3.0f,2.0f); // kiri atas
	glEnd();
	glPopMatrix();

	// body depan
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslatef(0,0,3);
	glBegin(GL_QUADS);
	glVertex3f(-3.0f,1.3f,1.0f); // kiri bawah
	glVertex3f(-1.5f,1.3f,1.0f);  // kanan bawah
	glVertex3f(-1.5f,3.0f,1.0f);  // kanan atas
	glVertex3f(-3.0f,3.0f,1.0f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-3.0f,0.5f,-1.0f); // kiri bawah
	glVertex3f(-1.5f,0.5f,-1.0f);  // kanan bawah
	glVertex3f(-1.5f,1.3f,-1.0f);  // kanan atas
	glVertex3f(-3.0f,1.3f,-1.0f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-2.3f,0.8f,0.2f); // kiri bawah
	glVertex3f(-2.1f,0.8f,0.2f);  // kanan bawah
	glVertex3f(-2.1f,1.3f,0.2f);  // kanan atas
	glVertex3f(-2.3f,1.3f,0.2f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-2.3f,0.8f,0.0f); // kiri bawah
	glVertex3f(-2.1f,0.8f,0.0f);  // kanan bawah
	glVertex3f(-2.1f,1.3f,0.0f);  // kanan atas
	glVertex3f(-2.3f,1.3f,0.0f); // kiri atas
	glEnd();
	glPopMatrix();
	
	// KEPALA
	
	// kaca kanan
	glPushMatrix();
	glTranslatef(0,0,3);
	glBegin(GL_QUADS);
	glVertex3f(4.9f,1.7f,0.01f); // kiri bawah
	glVertex3f(6.3f,1.7f,0.01f);  // kanan bawah
	glVertex3f(6.3f,2.5f,0.01f);  // kanan atas
	glVertex3f(4.9f,2.5f,0.01f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(6.5f,1.7f,0.01f); // kiri bawah
	glVertex3f(7.2f,1.7f,0.01f);  // kanan bawah
	glVertex3f(7.2f,1.8f,0.01f);  // kanan atas
	glVertex3f(6.5f,2.5f,0.01f); // kiri atas
	glEnd();
	glPopMatrix();
	
	// body kanan
	glColor3f(0.5f, 0.0f, 0.3f);
	glPushMatrix();
	glTranslatef(0,0,3);
	glBegin(GL_QUADS);
	glVertex3f(4.5f,0.5f,0.0f); // kiri bawah
	glVertex3f(6.5f,0.5f,0.0f);  // kanan bawah
	glVertex3f(6.5f,3.0f,0.0f);  // kanan atas
	glVertex3f(4.5f,3.0f,0.0f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(2.5f,0.5f,0.0f); // kiri bawah
	glVertex3f(6.0f,0.5f,0.0f);  // kanan bawah
	glVertex3f(6.0f,1.1f,0.0f);  // kanan atas
	glVertex3f(2.5f,1.1f,0.0f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(4.5f,0.5f,0.0f); // kiri bawah
	glVertex3f(8.5f,0.5f,0.0f);  // kanan bawah
	glVertex3f(8.5f,1.7f,0.0f);  // kanan atas
	glVertex3f(4.5f,1.7f,0.0f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(4.5f,0.5f,0.0f); // kiri bawah
	glVertex3f(8.5f,0.5f,0.0f);  // kanan bawah
	glVertex3f(6.5f,2.6f,0.0f);  // kanan atas
	glVertex3f(4.5f,3.0f,0.0f); // kiri atas
	glEnd();
	glPopMatrix();
	
	// kaca kiri
	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(0,0,1.5);
	glBegin(GL_QUADS);
	glVertex3f(4.9f,1.7f,-0.01f); // kiri bawah
	glVertex3f(6.3f,1.7f,-0.01f);  // kanan bawah
	glVertex3f(6.3f,2.5f,-0.01f);  // kanan atas
	glVertex3f(4.9f,2.5f,-0.01f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(6.5f,1.7f,-0.01f); // kiri bawah
	glVertex3f(7.2f,1.7f,-0.01f);  // kanan bawah
	glVertex3f(7.2f,1.8f,-0.01f);  // kanan atas
	glVertex3f(6.5f,2.5f,-0.01f); // kiri atas
	glEnd();
	glPopMatrix();
	
	// body kiri
	glColor3f(0.5f, 0.0f, 0.3f);
	glPushMatrix();
	glTranslatef(0,0,1.5);
	glBegin(GL_QUADS);
	glVertex3f(4.5f,0.5f,0.0f); // kiri bawah
	glVertex3f(6.5f,0.5f,0.0f);  // kanan bawah
	glVertex3f(6.5f,3.0f,0.0f);  // kanan atas
	glVertex3f(4.5f,3.0f,0.0f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(2.5f,0.5f,0.0f); // kiri bawah
	glVertex3f(6.0f,0.5f,0.0f);  // kanan bawah
	glVertex3f(6.0f,1.1f,0.0f);  // kanan atas
	glVertex3f(2.5f,1.1f,0.0f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(4.5f,0.5f,0.0f); // kiri bawah
	glVertex3f(8.5f,0.5f,0.0f);  // kanan bawah
	glVertex3f(8.5f,1.7f,0.0f);  // kanan atas
	glVertex3f(4.5f,1.7f,0.0f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(4.5f,0.5f,0.0f); // kiri bawah
	glVertex3f(8.5f,0.5f,0.0f);  // kanan bawah
	glVertex3f(6.5f,2.6f,0.0f);  // kanan atas
	glVertex3f(4.5f,3.0f,0.0f); // kiri atas
	glEnd();
	glPopMatrix();
	
	// kaca depan
	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslatef(0,0,3);
	glBegin(GL_QUADS);
	glVertex3f(-3.0f,0.5f,5.5f); // kiri bawah
	glVertex3f(-1.5f,0.5f,5.5f);  // kanan bawah
	glVertex3f(-1.5f,3.0f,3.1f);  // kanan atas
	glVertex3f(-3.0f,3.0f,3.1f); // kiri atas
	glEnd();
	glPopMatrix();
	
	//lampu depan
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslatef(0,0,3);
	glBegin(GL_QUADS);
	glVertex3f(-2.8f,0.7f,5.51f); // kiri bawah
	glVertex3f(-2.5f,0.7f,5.51f);  // kanan bawah
	glVertex3f(-2.5f,1.f,5.51f);  // kanan atas
	glVertex3f(-2.8f,1.f,5.51f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-2.f,0.7f,5.51f); // kiri bawah
	glVertex3f(-1.7f,0.7f,5.51f);  // kanan bawah
	glVertex3f(-1.7f,1.f,5.51f);  // kanan atas
	glVertex3f(-2.f,1.f,5.51f); // kiri atas
	glEnd();
	glPopMatrix();
	
	// body depan
	glColor3f(0.5f, 0.0f, 0.3f);
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslatef(0,0,3);
	glBegin(GL_QUADS);
	glVertex3f(-3.0f,0.5f,5.5f); // kiri bawah
	glVertex3f(-1.5f,0.5f,5.5f);  // kanan bawah
	glVertex3f(-1.5f,1.7f,5.5f);  // kanan atas
	glVertex3f(-3.0f,1.7f,5.5f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-3.0f,0.5f,5.5f); // kiri bawah
	glVertex3f(-1.5f,0.5f,5.5f);  // kanan bawah
	glVertex3f(-1.5f,3.0f,3.1f);  // kanan atas
	glVertex3f(-3.0f,3.0f,3.1f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-3.0f,0.5f,3.5f); // kiri bawah
	glVertex3f(-1.5f,0.5f,3.5f);  // kanan bawah
	glVertex3f(-1.5f,3.0f,3.5f);  // kanan atas
	glVertex3f(-3.0f,3.0f,3.5f); // kiri atas
	glEnd();
	glPopMatrix();
	
	// body belakang
	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	glTranslatef(0,0,3);
	glBegin(GL_QUADS);
	glVertex3f(3.0f,0.5f,-7.5f); // kiri bawah
	glVertex3f(1.5f,0.5f,-7.5f);  // kanan bawah
	glVertex3f(1.5f,3.0f,-7.5f);  // kanan atas
	glVertex3f(3.0f,3.0f,-7.5f); // kiri atas
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(3.0f,0.5f,-5.5f); // kiri bawah
	glVertex3f(1.5f,0.5f,-5.5f);  // kanan bawah
	glVertex3f(1.5f,1.1f,-5.5f);  // kanan atas
	glVertex3f(3.0f,1.1f,-5.5f); // kiri atas
	glEnd();
	glPopMatrix();
	
	// body atas
	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	glTranslatef(0,0,3);
	glBegin(GL_QUADS);
	glVertex3f(4.5f,-3.0f,0.0f); // kiri bawah
	glVertex3f(6.5f,-3.0f,0.0f);  // kanan bawah
	glVertex3f(6.5f,-1.5f,0.0f);  // kanan atas
	glVertex3f(4.5f,-1.5f,0.0f); // kiri atas
//	glEnd();
//	glBegin(GL_QUADS);
	glVertex3f(2.5f,-3.0f,-1.9f); // kiri bawah
	glVertex3f(4.5f,-3.0f,-1.9f);  // kanan bawah
	glVertex3f(4.5f,-1.5f,-1.9f);  // kanan atas
	glVertex3f(2.5f,-1.5f,-1.9f); // kiri atas
//	glEnd();
//	glBegin(GL_QUADS);
	glVertex3f(8.5f,-3.0f,-1.3f); // kiri bawah
	glVertex3f(6.5f,-3.0f,-1.3f); // kanan bawah
	glVertex3f(6.5f,-1.5f,-1.3f); // kanan atas
	glVertex3f(8.5f,-1.5f,-1.3f); // kiri atas
	glEnd();
	glPopMatrix();	
	
	// body bawah
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslatef(0,0,3);
	glBegin(GL_QUADS);
	glVertex3f(8.5f,3.0f,-3.5f); // kiri bawah
	glVertex3f(2.5f,3.0f,-3.5f);  // kanan bawah
	glVertex3f(2.5f,1.5f,-3.5f);  // kanan atas
	glVertex3f(8.5f,1.5f,-3.5f); // kiri atas
	glEnd();
	glPopMatrix();
	
	// RODA
	
	// roda depan kanan
	glPushMatrix();
	glRotatef(180,0,180,0);
	glColor3f(0,0,0);
	glTranslatef(-8.3, 0.5, -3.1);
	cylinder(0.4, 0.4, 0.4);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(180,0,180,0);
	glTranslatef(-5, 0.5, -3.1);
	cylinder(0.4, 0.4, 0.4);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(180,0,180,0);
	glTranslatef(-4, 0.5, -3.1);
	cylinder(0.4, 0.4, 0.4);
	glPopMatrix();
	
	// roda belakang kanan
	glPushMatrix();
	glRotatef(180,0,180,0);
	glTranslatef(2, 0.5, -3.1);
	cylinder(0.4, 0.4, 0.4);
	glPopMatrix();
	
	//roda depan kiri
	glPushMatrix();
	glTranslatef(6.3, 0.5, 1.4);
	cylinder(0.4, 0.4, 0.3);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(2, 0.5, 1.4);
	cylinder(0.4, 0.4, 0.3);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(3, 0.5, 1.4);
	cylinder(0.4, 0.4, 0.3);
	glPopMatrix();
	
	//roda belakang kiri
	glPushMatrix();
	glTranslatef(-4, 0.5, 1.4);
	cylinder(0.4, 0.4, 0.3);
	glPopMatrix();
	
}

void Truk2(){

	/* Kepala */
	
	// Alas Bawah
	glPushMatrix();
		glRotated(270, 1, 0, 0);
		glTranslatef(0,0,0.5);
		glColor3f(0.0,0.5,0.0);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Belakang
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,1);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,2.0f,0.0f);
			glVertex3f(0.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Atas
	glPushMatrix();
		glRotated(270, 1, 0, 0);
		glTranslatef(0,0,4.5);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(3.5f,-2.0f,0.0f);
			glVertex3f(3.5f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Depan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,4);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,0.25f,0.0f);
			glVertex3f(0.0f,0.25f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Kaca Depan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,4.75,4);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-0.25f,-0.5f);
			glVertex3f(0.0f,-0.25f,-0.5f);
		glEnd();
	glPopMatrix();
	
	// Alas Samping Kanan Bawah
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,0.25f,0.0f);
			glVertex3f(1.0f,0.25f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Samping Kanan Atas
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,0.25f,0.0f);
			glVertex3f(4.0f,0.25f,0.0f);
			glVertex3f(3.5f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Samping Kiri Bawah
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,-2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,0.25f,0.0f);
			glVertex3f(1.0f,0.25f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Samping Kiri Atas
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,-2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,0.25f,0.0f);
			glVertex3f(4.0f,0.25f,0.0f);
			glVertex3f(3.5f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();	
	
	// Jendela Kiri
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,2.001);
		glColor3f(0.3,0.4,0.3);
		glBegin(GL_QUADS);
			glVertex3f(2.0f,0.3f,0.0f);
			glVertex3f(3.75f,0.3f,0.0f);
			glVertex3f(3.365f,1.75f,0.0f);
			glVertex3f(2.0f,1.75f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Pintu Kiri
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,2.001);
		glColor3f(0.0,0.4,0.0);
		glBegin(GL_QUADS);
			glVertex3f(2.0f,-1.75f,0.0f);
			glVertex3f(3.75f,-1.75f,0.0f);
			glVertex3f(3.75f,0.25f,0.0f);
			glVertex3f(2.0f,0.25f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Ganggang Kiri
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,2.003);
		glColor3f(0.0,0.2,0.0);
		glBegin(GL_QUADS);
			glVertex3f(2.1f,-0.35f,0.0f);
			glVertex3f(2.6f,-0.35f,0.0f);
			glVertex3f(2.6f,-0.25f,0.0f);
			glVertex3f(2.1f,-0.25f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,2.002);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(2.15f,-0.4f,0.0f);
			glVertex3f(2.55f,-0.4f,0.0f);
			glVertex3f(2.55f,-0.2f,0.0f);
			glVertex3f(2.15f,-0.2f,0.0f);
		glEnd();
	glPopMatrix();
	
//	glPushMatrix();
//		glRotated(0, 0, 1, 0);
//		glTranslatef(0,2.5,2.001);
//		glColor3f(0.0,0.0,0.0);
//		glBegin(GL_QUADS);
//			glVertex3f(2.75f,-1.75f,0.0f);
//			glVertex3f(3.75f,-1.75f,0.0f);
//			glVertex3f(3.75f,-1.15f,0.0f);
//			glVertex3f(2.75f,-1.15f,0.0f);
//		glEnd();
//	glPopMatrix();
	
	// Jendela Kanan
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,-2.001);
		glColor3f(0.3,0.4,0.3);
		glBegin(GL_QUADS);
			glVertex3f(2.0f,0.3f,0.0f);
			glVertex3f(3.75f,0.3f,0.0f);
			glVertex3f(3.365f,1.75f,0.0f);
			glVertex3f(2.0f,1.75f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Pintu Kanan
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,-2.001);
		glColor3f(0.0,0.3,0.0);
		glBegin(GL_QUADS);
			glVertex3f(2.0f,-1.75f,0.0f);
			glVertex3f(3.75f,-1.75f,0.0f);
			glVertex3f(3.75f,0.25f,0.0f);
			glVertex3f(2.0f,0.25f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Ganggang Kanan
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,-2.003);
		glColor3f(0.0,0.2,0.0);
		glBegin(GL_QUADS);
			glVertex3f(2.1f,-0.35f,0.0f);
			glVertex3f(2.6f,-0.35f,0.0f);
			glVertex3f(2.6f,-0.25f,0.0f);
			glVertex3f(2.1f,-0.25f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,-2.002);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(2.15f,-0.4f,0.0f);
			glVertex3f(2.55f,-0.4f,0.0f);
			glVertex3f(2.55f,-0.2f,0.0f);
			glVertex3f(2.15f,-0.2f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Kaca Depan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,4.75,4.005);
		glColor3f(0.3,0.4,0.3);
		glBegin(GL_QUADS);
			glVertex3f(0.25f,-2.0f,0.0f);
			glVertex3f(3.75f,-2.0f,0.0f);
			glVertex3f(3.75f,-0.5f,-0.43f);
			glVertex3f(0.25f,-0.5f,-0.43f);
		glEnd();
	glPopMatrix();
	
	// Hiasan Depan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,4.001);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-1.5f,0.0f);
			glVertex3f(3.0f,-1.5f,0.0f);
			glVertex3f(3.25f,-1.0f,0.0f);
			glVertex3f(0.75f,-1.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,4.001);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0.75f,-0.9f,0.0f);
			glVertex3f(3.25f,-0.9f,0.0f);
			glVertex3f(3.5f,-0.4f,0.0f);
			glVertex3f(0.5f,-0.4f,0.0f);
		glEnd();
	glPopMatrix();
	
//	glPushMatrix();
//		glRotated(90, 0, 1, 0);
//		glTranslatef(-2,2.5,4.001);
//		glColor3f(0.0,0.0,0.0);
//		glBegin(GL_QUADS);
//			glVertex3f(0.0f,-0.15f,0.0f);
//			glVertex3f(4.0f,-0.15f,0.0f);
//			glVertex3f(4.0f,0.0f,0.0f);
//			glVertex3f(0.0f,0.0f,0.0f);
//		glEnd();
//	glPopMatrix();
	
	// Lampu
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,4.001);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-1.5f,0.0f);
			glVertex3f(0.8f,-1.5f,0.0f);
			glVertex3f(0.55f,-1.0f,0.0f);
			glVertex3f(0.0f,-1.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,4.002);
		glColor3f(1.0,1.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0.3f,-1.5f,0.0f);
			glVertex3f(0.8f,-1.5f,0.0f);
			glVertex3f(0.55f,-1.0f,0.0f);
			glVertex3f(0.3f,-1.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,4.001);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(3.2f,-1.5f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(4.0f,-1.0f,0.0f);
			glVertex3f(3.45f,-1.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,4.002);
		glColor3f(1.0,1.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(3.2f,-1.5f,0.0f);
			glVertex3f(3.7f,-1.5f,0.0f);
			glVertex3f(3.7f,-1.0f,0.0f);
			glVertex3f(3.45f,-1.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	/* Alas Muatan Depan *///---------------------------------
	
	// Alas Bawah
	glPushMatrix();
		glRotated(270, 1, 0, 0);
		glTranslatef(0,0,0.5);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Atas
	glPushMatrix();
		glRotated(270, 1, 0, 0);
		glTranslatef(0,0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Kanan
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-1.5f,0.0f);
			glVertex3f(1.0f,-1.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Kiri
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,-2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-1.5f,0.0f);
			glVertex3f(1.0f,-1.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Belakang
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,-7);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(0.0f,-1.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	/* Muatan Depan*/
	
	// Alas Bawah
	glPushMatrix();
		glRotated(270, 1, 0, 0);
		glTranslatef(0,0,1.0);
		glColor3f(0.0,0.5,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0.75f,-2.0f,0.0f);
			glVertex3f(-7.5f,-2.0f,0.0f);
			glVertex3f(-7.5f,2.0f,0.0f);
			glVertex3f(0.75f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Atas
	glPushMatrix();
		glRotated(270, 1, 0, 0);
		glTranslatef(0,0,5.5);
		glBegin(GL_QUADS);
			glVertex3f(0.75f,-2.0f,0.0f);
			glVertex3f(-7.5f,-2.0f,0.0f);
			glVertex3f(-7.5f,2.0f,0.0f);
			glVertex3f(0.75f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Kanan
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,2);
		glBegin(GL_QUADS);
			glVertex3f(0.75f,-1.5f,0.0f);
			glVertex3f(-7.5f,-1.5f,0.0f);
			glVertex3f(-7.5f,3.0f,0.0f);
			glVertex3f(0.75f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Kiri
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(0,2.5,-2);
		glBegin(GL_QUADS);
			glVertex3f(0.75f,-1.5f,0.0f);
			glVertex3f(-7.5f,-1.5f,0.0f);
			glVertex3f(-7.5f,3.0f,0.0f);
			glVertex3f(0.75f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Belakang
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,-7.5);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-1.5f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(4.0f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Depan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,0.75);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-1.5f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(4.0f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	/* Alas Muatan Belakang */
	
	// Alas Bawah
	glPushMatrix();
		glRotated(270, 1, 0, 0);
		glTranslatef(-10.0,0,0.5);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Atas
	glPushMatrix();
		glRotated(270, 1, 0, 0);
		glTranslatef(-10.0,0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,2.0f,0.0f);
			glVertex3f(1.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Kanan
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(-10.0,2.5,2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-1.5f,0.0f);
			glVertex3f(1.0f,-1.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Kiri
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(-10.0,2.5,-2);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-2.0f,0.0f);
			glVertex3f(-7.0f,-1.5f,0.0f);
			glVertex3f(1.0f,-1.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Belakang
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,-17);
//		glColor3f(0.0,0.5,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(0.0f,-1.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Depan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,-9);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-2.0f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(0.0f,-1.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	/* Muatan Belakang*/
	
	// Alas Bawah
	glPushMatrix();
		glRotated(270, 1, 0, 0);
		glTranslatef(-10.0,0,1.0);
		glColor3f(0.0,0.5,0.0);
		glBegin(GL_QUADS);
			glVertex3f(1.25f,-2.0f,0.0f);
			glVertex3f(-7.5f,-2.0f,0.0f);
			glVertex3f(-7.5f,2.0f,0.0f);
			glVertex3f(1.25f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Atas
	glPushMatrix();
		glRotated(270, 1, 0, 0);
		glTranslatef(-10.0,0,5.5);
		glBegin(GL_QUADS);
			glVertex3f(1.25f,-2.0f,0.0f);
			glVertex3f(-7.5f,-2.0f,0.0f);
			glVertex3f(-7.5f,2.0f,0.0f);
			glVertex3f(1.25f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Kanan
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(-10.0,2.5,2);
		glBegin(GL_QUADS);
			glVertex3f(1.25f,-1.5f,0.0f);
			glVertex3f(-7.5f,-1.5f,0.0f);
			glVertex3f(-7.5f,3.0f,0.0f);
			glVertex3f(1.25f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Kiri
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(-10.0,2.5,-2);
		glBegin(GL_QUADS);
			glVertex3f(1.25f,-1.5f,0.0f);
			glVertex3f(-7.5f,-1.5f,0.0f);
			glVertex3f(-7.5f,3.0f,0.0f);
			glVertex3f(1.25f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Belakang
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,-17.5);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-1.5f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(4.0f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Depan
	glPushMatrix();
		glRotated(90, 0, 1, 0);
		glTranslatef(-2,2.5,-8.75);
		glBegin(GL_QUADS);
			glVertex3f(0.0f,-1.5f,0.0f);
			glVertex3f(4.0f,-1.5f,0.0f);
			glVertex3f(4.0f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
		glEnd();
	glPopMatrix();
	
	/* Sambungan Tengah *///------------------------------------------------
	
	// Alas Bawah
	glPushMatrix();
		glRotated(270, 1, 0, 0);
		glTranslatef(-8.0,0,0.6);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-0.5f,0.0f);
			glVertex3f(-1.0f,-0.5f,0.0f);
			glVertex3f(-1.0f,0.5f,0.0f);
			glVertex3f(1.0f,0.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Atas
	glPushMatrix();
		glRotated(270, 1, 0, 0);
		glTranslatef(-8.0,0,0.9);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-0.5f,0.0f);
			glVertex3f(-1.0f,-0.5f,0.0f);
			glVertex3f(-1.0f,0.5f,0.0f);
			glVertex3f(1.0f,0.5f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Kanan
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(-8.0,0.8,0.5);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-0.2f,0.0f);
			glVertex3f(-1.0f,-0.2f,0.0f);
			glVertex3f(-1.0f,0.1f,0.0f);
			glVertex3f(1.0f,0.1f,0.0f);
		glEnd();
	glPopMatrix();
	
	// Alas Kiri
	glPushMatrix();
		glRotated(0, 0, 1, 0);
		glTranslatef(-8.0,0.8,-0.5);
		glBegin(GL_QUADS);
			glVertex3f(1.0f,-0.2f,0.0f);
			glVertex3f(-1.0f,-0.2f,0.0f);
			glVertex3f(-1.0f,0.1f,0.0f);
			glVertex3f(1.0f,0.1f,0.0f);
		glEnd();
	glPopMatrix();

	/* Ban Depan */
	
	// Ban Kanan Depan
	glPushMatrix();
	for(j=0;j<=360;j++){
		glPushMatrix();
		glTranslatef(2,0.6,-1.2);
		glRotated(90,1,0,0);
		glRotated(j,0,1,0);
		glTranslatef(0,3.0,0.6);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0,0,0);
			glVertex3f(0.1,0,0);
			glVertex3f(0.1,0.4,0);
			glVertex3f(0,0.3,0);
		glEnd();
		glPopMatrix();
		}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1,0.6,2.2);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(1,0.6,1.8);
	glRotated(180,1,0,0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	// Ban Kiri Depan
	glPushMatrix();
	for(j=0;j<=360;j++){
		glPushMatrix();
		glTranslatef(2,0.6,-2.2);
		glRotated(90,1,0,0);
		glRotated(j,0,1,0);
		glTranslatef(0,0.0,0.6);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0,0,0);
			glVertex3f(0.1,0,0);
			glVertex3f(0.1,0.4,0);
			glVertex3f(0,0.3,0);
		glEnd();
		glPopMatrix();
		}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1,0.6,-1.8);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(1,0.6,-2.2);
	glRotated(180,1,0,0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	/* Ban Tengah 1 */
	
	// Ban Kanan Depan
	glPushMatrix();
	for(j=0;j<=360;j++){
		glPushMatrix();
		glTranslatef(-5,0.6,-1.2);
		glRotated(90,1,0,0);
		glRotated(j,0,1,0);
		glTranslatef(0,3.0,0.6);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0,0,0);
			glVertex3f(0.1,0,0);
			glVertex3f(0.1,0.4,0);
			glVertex3f(0,0.3,0);
		glEnd();
		glPopMatrix();
		}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6,0.6,2.2);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-6,0.6,1.8);
	glRotated(180,1,0,0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	// Ban Kiri Depan
	glPushMatrix();
	for(j=0;j<=360;j++){
		glPushMatrix();
		glTranslatef(-5,0.6,-2.2);
		glRotated(90,1,0,0);
		glRotated(j,0,1,0);
		glTranslatef(0,0.0,0.6);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0,0,0);
			glVertex3f(0.1,0,0);
			glVertex3f(0.1,0.4,0);
			glVertex3f(0,0.3,0);
		glEnd();
		glPopMatrix();
		}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6,0.6,-1.8);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-6,0.6,-2.2);
	glRotated(180,1,0,0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	/* Ban Tengah 2 */
	
	// Ban Kanan Depan
	glPushMatrix();
	for(j=0;j<=360;j++){
		glPushMatrix();
		glTranslatef(-10.5,0.6,-1.2);
		glRotated(90,1,0,0);
		glRotated(j,0,1,0);
		glTranslatef(0,3.0,0.6);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0,0,0);
			glVertex3f(0.1,0,0);
			glVertex3f(0.1,0.4,0);
			glVertex3f(0,0.3,0);
		glEnd();
		glPopMatrix();
		}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-11.5,0.6,2.2);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-11.5,0.6,1.8);
	glRotated(180,1,0,0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	// Ban Kiri Depan
	glPushMatrix();
	for(j=0;j<=360;j++){
		glPushMatrix();
		glTranslatef(-10.5,0.6,-2.2);
		glRotated(90,1,0,0);
		glRotated(j,0,1,0);
		glTranslatef(0,0.0,0.6);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0,0,0);
			glVertex3f(0.1,0,0);
			glVertex3f(0.1,0.4,0);
			glVertex3f(0,0.3,0);
		glEnd();
		glPopMatrix();
		}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-11.5,0.6,-1.8);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-11.5,0.6,-2.2);
	glRotated(180,1,0,0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	/* Ban Belakang */
	
	// Ban Kanan Depan
	glPushMatrix();
	for(j=0;j<=360;j++){
		glPushMatrix();
		glTranslatef(-15.5,0.6,-1.2);
		glRotated(90,1,0,0);
		glRotated(j,0,1,0);
		glTranslatef(0,3.0,0.6);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0,0,0);
			glVertex3f(0.1,0,0);
			glVertex3f(0.1,0.4,0);
			glVertex3f(0,0.3,0);
		glEnd();
		glPopMatrix();
		}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-16.5,0.6,2.2);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-16.5,0.6,1.8);
	glRotated(180,1,0,0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	// Ban Kiri Depan
	glPushMatrix();
	for(j=0;j<=360;j++){
		glPushMatrix();
		glTranslatef(-15.5,0.6,-2.2);
		glRotated(90,1,0,0);
		glRotated(j,0,1,0);
		glTranslatef(0,0.0,0.6);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3f(0,0,0);
			glVertex3f(0.1,0,0);
			glVertex3f(0.1,0.4,0);
			glVertex3f(0,0.3,0);
		glEnd();
		glPopMatrix();
		}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-16.5,0.6,-1.8);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-16.5,0.6,-2.2);
	glRotated(180,1,0,0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		radius=60;
		jumlah_titik=20;
		x_tengah=100;
		y_tengah=0;
		for (i=0;i<=360;i++){
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
	glEnd();
	glPopMatrix();
}

void city(){
	
	//sky
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.002);
	glBegin(GL_QUADS);
	glColor3ub(135,206,250);
	glVertex2f(-100.0,10.0); //kiri atas
	glVertex2f(100.0,10.0); //kanan atas
	glColor3ub(255,69,0);
	glVertex2f(100.0,-6.2);
	glVertex2f(-100.0,-6.2);
	glEnd();
	glPopMatrix();
	
	//moon
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(1,1,0.7);
	glBegin(GL_POLYGON);
	
	radius = 50;
	jumlah_titik = 100;	
	x_tengah = -0;
	y_tengah = 1;
	
	for (i=0;i<=360;i++){
		float sudut = i * (2*PI/jumlah_titik);
		float x = x_tengah + radius *cos(sudut);
		float y = y_tengah + radius *cos(sudut);
		glVertex2f(x/10,y/10);
	}	
	glEnd();
	glPopMatrix();
	
	//shadow
	glPushMatrix();
	glTranslatef(0, 0, -0.001);
	glBegin(GL_POLYGON);
	glColor3ub(105,105,105);
	glVertex2f(-9.8,-6.0);
	glVertex2f(-9.8,1.0);
	glVertex2f(-4.0,1.0);
	glVertex2f(-4.0,-2.0);
	glVertex2f(3.0,-2.0);
	glVertex2f(2.0,2.0);
	glVertex2f(8.2,-6.0);
	glEnd();
	glPopMatrix();
	
	//building5
	glPushMatrix();
	glTranslatef(-17, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(0,0,0);
	glVertex2f(4.1,-6);
	glVertex2f(4.1,3);
	glVertex2f(7,3);
	glVertex2f(7,-6);
	glEnd();
	glPopMatrix();
	
	//window5
	glPushMatrix();
	glTranslatef(-17, 0, 0.001);
	glBegin(GL_QUADS);
	glColor3ub(255,255,0);
	glVertex2f(5.2,-5.9);
	glVertex2f(5.2,-1.7);
	glVertex2f(5.8,-1.7);
	glVertex2f(5.8,-5.9);
	
	glVertex2f(4.4,-1.4);
	glVertex2f(4.4,2.7);
	glVertex2f(5,2.7);
	glVertex2f(5,-1.4);
	
	glVertex2f(6,-1.4);
	glVertex2f(6,2.7);
	glVertex2f(6.7,2.7);
	glVertex2f(6.7,-1.4);
	
	glVertex2f(5.2,-1.4);
	glVertex2f(5.2,2.7);
	glVertex2f(5.8,2.7);
	glVertex2f(5.8,-1.4);
	
	glVertex2f(4.4,-5.9);
	glVertex2f(4.4,-1.7);
	glVertex2f(5,-1.7);
	glVertex2f(5,-5.9);
	
	glVertex2f(6,-5.9);
	glVertex2f(6,-1.7);
	glVertex2f(6.7,-1.7);
	glVertex2f(6.7,-5.9);
	glEnd();
	glPopMatrix();
	
	//building, dari kiri
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-9.8,-6);
	glVertex2f(-9.8,0);
	glVertex2f(-9.6,0);
	glVertex2f(-9.6,1);
	glVertex2f(-9.2,1);
	glVertex2f(-9.2,1.5);
	glVertex2f(-6.6,1.5);
	glVertex2f(-6.6,1);
	glVertex2f(-6.6,1);
	glVertex2f(-6.2,1);
	glVertex2f(-6.2,0);
	glVertex2f(-6,0);
	glVertex2f(-6,-6);
	glEnd();
	glPopMatrix();
	
	//window
	glPushMatrix();
	glTranslatef(0, 0, 0.001);
	glBegin(GL_QUADS);
	glColor3ub(255,255,0);
	glVertex2f(-9.4,0.8);
	glVertex2f(-6.4,0.8);
	glVertex2f(-6.4,0.2);
	glVertex2f(-9.4,0.2);
	
	glVertex2f(-9.6,-0.2);
	glVertex2f(-6.2,-0.2);
	glVertex2f(-6.2,-5.8);
	glVertex2f(-9.6,-5.8);
	glEnd();
	
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(-7.9,-5.8);
	glVertex2f(-7.9,-0.2);
	
	glVertex2f(-6.2,-3.2);
	glVertex2f(-9.6,-3.2);
	
	glVertex2f(-6.2,-1.7);
	glVertex2f(-9.6,-1.7);
	
	glVertex2f(-6.2,-4.7);
	glVertex2f(-9.6,-4.7);
	
	glVertex2f(-7,-5.8);
	glVertex2f(-7,-0.2);
	
	glVertex2f(-8.8,-5.8);
	glVertex2f(-8.8,-0.2);
	glEnd();
	glPopMatrix();
	
	//building2
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-5.5,-6);
	glVertex2f(-5.5,2);
	glVertex2f(-5.3,2);
	glVertex2f(-5.3,2.2);
	glVertex2f(-5.1,2.2);
	glVertex2f(-5.1,2.7);
	glVertex2f(-3.5,2.7);
	glVertex2f(-3.5,2.2);
	glVertex2f(-3.3,2.2);
	glVertex2f(-3.3,2);
	glVertex2f(-3.1,2);
	glVertex2f(-3.1,-6);
	glEnd();
	glPopMatrix();
	
	//window2
	glPushMatrix();
	glTranslatef(0, 0, 0.001);
	glBegin(GL_QUADS);
	glColor3ub(255,255,0);
	glVertex2f(-4.4,-5.8);
	glVertex2f(-4.4,2.3);
	glVertex2f(-4.1,2.3);
	glVertex2f(-4.1,-5.8);
	
	glVertex2f(-4.7,-5.5);
	glVertex2f(-4.7,1.8);
	glVertex2f(-5.2,1.8);
	glVertex2f(-5.2,-5.5);
	
	glVertex2f(-3.8,-5.5);
	glVertex2f(-3.8,1.8);
	glVertex2f(-3.3,1.8);
	glVertex2f(-3.3,-5.5);
	glEnd();
	glPopMatrix();
	
	//building3
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(0,0,0);
	glVertex2f(-3,-6);
	glVertex2f(-3,-2);
	glVertex2f(-1.1,-2);
	glVertex2f(-1.1,-6);
	glEnd();
	glPopMatrix();
	
	//building4
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(-1,-6);
	glVertex2f(-1,2);
	glVertex2f(0,2);
	glVertex2f(0,3);
	glVertex2f(1,3);
	glVertex2f(1,4.5);
	glVertex2f(2,4.5);
	glVertex2f(3,3);
	glVertex2f(3,2);
	glVertex2f(4,2);
	glVertex2f(4,-6);
	glEnd();
	glPopMatrix();
	
	//window4
	glPushMatrix();
	glTranslatef(0, 0, 0.001);
	glBegin(GL_QUADS);
	glColor3ub(255,255,0);
	glVertex2f(-0.8,1.8);
	glVertex2f(3.8,1.8);
	glVertex2f(3.8,0.8);
	glVertex2f(-0.8,0.8);
	
	glVertex2f(-0.8,-5.2);
	glVertex2f(-0.8,-4.2);
	glVertex2f(3.8,-4.2);
	glVertex2f(3.8,-5.2);
	
	glVertex2f(-0,-2.2);
	glVertex2f(-0,-1.2);
	glVertex2f(3.8,-1.2);
	glVertex2f(3.8,-2.2);
	
	glVertex2f(2.9,0.5);
	glVertex2f(3.8,0.5);
	glVertex2f(3.8,-0.9);
	glVertex2f(2.9,-0.9);
	
	glVertex2f(-0.8,0.5);
	glVertex2f(0.1,0.5);
	glVertex2f(0.1,-0.9);
	glVertex2f(-0.8,-0.9);
	
	glVertex2f(-0.8,-2.5);
	glVertex2f(0.1,-2.5);
	glVertex2f(0.1,-3.8);
	glVertex2f(-0.8,-3.8);
	
	glVertex2f(1.1,0.5);
	glVertex2f(2,0.5);
	glVertex2f(2,-0.9);
	glVertex2f(1.1,-0.9);
	
	glVertex2f(0.0,-5.8);
	glVertex2f(0.0,-5.4);
	glVertex2f(3.8,-5.4);
	glVertex2f(3.8,-5.8);
	glEnd();
	glPopMatrix();
	
	//building5
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(0,0,0);
	glVertex2f(4.1,-6);
	glVertex2f(4.1,3);
	glVertex2f(7,3);
	glVertex2f(7,-6);
	glEnd();
	glPopMatrix();
	
	//window5
	glPushMatrix();
	glTranslatef(0, 0, 0.001);
	glBegin(GL_QUADS);
	glColor3ub(255,255,0);
	glVertex2f(5.2,-5.9);
	glVertex2f(5.2,-1.7);
	glVertex2f(5.8,-1.7);
	glVertex2f(5.8,-5.9);
	
	glVertex2f(4.4,-1.4);
	glVertex2f(4.4,2.7);
	glVertex2f(5,2.7);
	glVertex2f(5,-1.4);
	
	glVertex2f(6,-1.4);
	glVertex2f(6,2.7);
	glVertex2f(6.7,2.7);
	glVertex2f(6.7,-1.4);
	
	glVertex2f(5.2,-1.4);
	glVertex2f(5.2,2.7);
	glVertex2f(5.8,2.7);
	glVertex2f(5.8,-1.4);
	
	glVertex2f(4.4,-5.9);
	glVertex2f(4.4,-1.7);
	glVertex2f(5,-1.7);
	glVertex2f(5,-5.9);
	
	glVertex2f(6,-5.9);
	glVertex2f(6,-1.7);
	glVertex2f(6.7,-1.7);
	glVertex2f(6.7,-5.9);
	glEnd();
	glPopMatrix();
	
	//building6
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(7.5,-6);
	glVertex2f(7.5,0);
	glVertex2f(9,0);
	glVertex2f(9,-2);
	glVertex2f(9.8,-2);
	glVertex2f(9.8,-6);
	glEnd();
	glPopMatrix();
	
	//window6
	glPushMatrix();
	glTranslatef(0, 0, 0.001);
	glBegin(GL_QUADS);
	glColor3ub(255,255,0);
	glVertex2f(7.7,-5.8);
	glVertex2f(7.7,-0.2);
	glVertex2f(8.8,-0.2);
	glVertex2f(8.8,-5.8);
	glEnd();
	glPopMatrix();
	
	glFlush();
}
	
void leftcloud(){
	//cloud
	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);
	radius = 12;
	jumlah_titik = 100;
	x_tengah = -50;
	y_tengah = 50;
	for (i=0;i<=360;i++){
			
		float sudut=i* (2*PI/jumlah_titik);
		float x = x_tengah + radius *cos(sudut);
		float y = y_tengah + radius *sin(sudut);
		glVertex2f(x/10,y/10);				
	}
	radius = 10;
	jumlah_titik = 100;
	x_tengah = -60;
	y_tengah = 50;
	for (i=0;i<=360;i++){
			
		float sudut=i* (2*PI/jumlah_titik);
		float x = x_tengah + radius *cos(sudut);
		float y = y_tengah + radius *sin(sudut);
		glVertex2f(x/10,y/10);
	}
	radius = 10;
	jumlah_titik = 100;
	x_tengah = -40;
	y_tengah = 50;
	for (i=0;i<=360;i++){
			
		float sudut=i*(2*PI/jumlah_titik);
		float x = x_tengah + radius *cos(sudut);
		float y = y_tengah + radius *sin(sudut);
		glVertex2f(x/10,y/10);
	}
	glEnd();

	//cloud2
	glBegin(GL_POLYGON);
	radius = 12;
	jumlah_titik = 100;
	x_tengah = -70;
	y_tengah = 80;
	for (i=0;i<=360;i++){
			
		float sudut=i* (2*PI/jumlah_titik);
		float x = x_tengah + radius *cos(sudut);
		float y = y_tengah + radius *sin(sudut);
		glVertex2f(x/10,y/10);				
	}
	radius = 10;
	jumlah_titik = 100;
	x_tengah = -80;
	y_tengah = 80;
	for (i=0;i<=360;i++){
			
		float sudut=i* (2*PI/jumlah_titik);
		float x = x_tengah + radius *cos(sudut);
		float y = y_tengah + radius *sin(sudut);
		glVertex2f(x/10,y/10);
	}
	radius = 10;
	jumlah_titik = 100;
	x_tengah = -60;
	y_tengah = 80;
	for (i=0;i<=360;i++){
		
		float sudut=i*(2*PI/jumlah_titik);
		float x = x_tengah + radius *cos(sudut);
		float y = y_tengah + radius *sin(sudut);
		glVertex2f(x/10,y/10);
	}
	glEnd();
}

void rightcloud(){
	//cloud
	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);
	radius = 12;
	jumlah_titik = 100;
	x_tengah = 70;
	y_tengah = 80;
	for (i=0;i<=360;i++){
		
		float sudut=i* (2*PI/jumlah_titik);
		float x = x_tengah + radius *cos(sudut);
		float y = y_tengah + radius *sin(sudut);
		glVertex2f(x/10,y/10);				
	}
	radius = 10;
	jumlah_titik = 100;
	x_tengah = 80;
	y_tengah = 80;
	for (i=0;i<=360;i++){
		
		float sudut=i* (2*PI/jumlah_titik);
		float x = x_tengah + radius *cos(sudut);
		float y = y_tengah + radius *sin(sudut);
		glVertex2f(x/10,y/10);
	}
	radius = 10;
	jumlah_titik = 100;
	x_tengah = 60;
	y_tengah = 80;
	for (i=0;i<=360;i++){
		
		float sudut=i*(2*PI/jumlah_titik);
		float x = x_tengah + radius *cos(sudut);
		float y = y_tengah + radius *sin(sudut);
		glVertex2f(x/10,y/10);
	}
	glEnd();

	//cloud2
	glBegin(GL_POLYGON);
	radius = 12;
	jumlah_titik = 100;
	x_tengah = 50;
	y_tengah = 50;
	for (i=0;i<=360;i++){
			
		float sudut=i* (2*PI/jumlah_titik);
		float x = x_tengah + radius *cos(sudut);
		float y = y_tengah + radius *sin(sudut);
		glVertex2f(x/10,y/10);				
	}
	radius = 10;
	jumlah_titik = 100;
	x_tengah = 60;
	y_tengah = 50;
	for (i=0;i<=360;i++){
			
		float sudut=i* (2*PI/jumlah_titik);
		float x = x_tengah + radius *cos(sudut);
		float y = y_tengah + radius *sin(sudut);
		glVertex2f(x/10,y/10);
	}
	radius = 10;
	jumlah_titik = 100;
	x_tengah = 40;
	y_tengah = 50;
	for (i=0;i<=360;i++){
			
		float sudut=i*(2*PI/jumlah_titik);
		float x = x_tengah + radius *cos(sudut);
		float y = y_tengah + radius *sin(sudut);
		glVertex2f(x/10,y/10);
	}
	glEnd();
	glFlush();
}

void Jalan() {
	glBegin(GL_QUADS);
	glPushMatrix();
 	glTranslatef(0,0,0);
 	//belakang
 	glColor3f(0,1,0);
  	glVertex3f(-100,-0.001,-100);
  	glVertex3f(-100,-0.001,0);         //a green surroundings
	glVertex3f(100,-0.001,0);
	glVertex3f(100,-0.001,-100);

	//belakang
  	glColor3f(0.7,0.7,0.7);
  	glVertex3f(-100,0,0);
  	glVertex3f(-100,0,-4);         //a long road
  	glVertex3f(100,0,-4);
  	glVertex3f(100,0,0);

	//garis tengah
  	glColor3f(1.0,0.75,0.0);
  	glVertex3f(-100,0,0);       //a median
  	glVertex3f(-100,0,1);
  	glVertex3f(100,0,1);
	glVertex3f(100,0,0);

	//depan
  	glColor3f(0.7,0.7,0.7);
  	glVertex3f(-100,0,0);
  	glVertex3f(-100,0,5);         //a long road
  	glVertex3f(100,0,5);
  	glVertex3f(100,0,0);

	//depan
  	glColor3f(0,1,0);
  	glVertex3f(-100,-0.001,1);
  	glVertex3f(-100,-0.001,100);         //a green surroundings
  	glVertex3f(100,-0.001,100);
  	glVertex3f(100,-0.001,1);
  	glEnd();
	glPopMatrix();
}

void display() {
	// Kalau move dan angle tidak nol, gerakkan kamera...
	if (deltaMove)
		moveMeFlat(deltaMove);
	if (deltaAngle) {
		angle += deltaAngle;
		orientMe(angle);
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Gambar objek
	
	// Truk 1
	glPushMatrix();
	glRotated(rotAngle, 0, 1, 0); // rotate by rotAngle about y-axis
	glRotated(rotAngle1, 1, 0, 0); // rotate by rotAngle about yaxis
	glRotatef(180, 0, 1, 0);
	glTranslatef(-30, 0, -5);
	Truk1();
	glPopMatrix();
	
	// Truk 2
	glPushMatrix();
	glRotated(rotAngle, 0, 1, 0); // rotate by rotAngle about y-axis
	glRotated(rotAngle1, 1, 0, 0); // rotate by rotAngle about yaxis
	glScalef(0.6, 0.6, 0.6);
	glTranslatef(0.0-xw,0, 5);
	Truk2();
	glPopMatrix();
	
	// Jalan
	glPushMatrix();
	glRotated(rotAngle, 0, 1, 0); // rotate by rotAngle about y-axis
	glRotated(rotAngle1, 1, 0, 0); // rotate by rotAngle about yaxis
	Jalan();
	glPopMatrix();
	
	//city
	glPushMatrix();
	glRotated(rotAngle, 0, 1, 0); // rotate by rotAngle about y-axis
	glRotated(rotAngle1, 1, 0, 0); // rotate by rotAngle about yaxis
	glScalef(2, 2, 2);
	glTranslatef(5,7,1);
	city();
	glPopMatrix();
	
	//leftcloud
	glPushMatrix();
	glRotated(rotAngle, 0, 1, 0); // rotate by rotAngle about y-axis
	glRotated(rotAngle1, 1, 0, 0); // rotate by rotAngle about yaxis
	glScalef(2, 2, 2);
	glTranslatef(a+5,5,1.2);
	leftcloud();
	glPopMatrix();
	
	//rightcloud
	glPushMatrix();
	glRotated(rotAngle, 0, 1, 0); // rotate by rotAngle about y-axis
	glRotated(rotAngle1, 1, 0, 0); // rotate by rotAngle about yaxis
	glScalef(2, 2, 2);
	glTranslatef(b+5,5,1.2);
	rightcloud();
	glPopMatrix();
	
	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
	
}

void pressKey(int key, int x, int y) {
	// Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas
	// Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak
	switch (key) {
		case GLUT_KEY_LEFT : 
			deltaAngle = -0.05f;
			break;
		case GLUT_KEY_RIGHT : 
			deltaAngle = 0.05f;
			break;
		case GLUT_KEY_UP : 
			deltaMove = 4;
			break;
		case GLUT_KEY_DOWN : 
			deltaMove = -4;
			break;
	}
}

void releaseKey(int key, int x, int y) {
	// Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas
	// Saat tombol dilepas, variabel angle dan move diset nol => kamera berhenti
	switch (key) {
		case GLUT_KEY_LEFT :
			if (deltaAngle < 0.0f)
				deltaAngle = 0.0f;
				break;
		case GLUT_KEY_RIGHT : 
			if (deltaAngle > 0.0f)
				deltaAngle = 0.0f;
				break;
		case GLUT_KEY_UP : 
			if (deltaMove > 0)
				deltaMove = 0;
				break;
		case GLUT_KEY_DOWN : 
			if (deltaMove < 0)
				deltaMove = 0;
				break;
	}
}

// Variable untuk pencahayaan
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void lighting() {
	// Fungsi mengaktifkan pencahayaan
	glTranslatef(0.0, 20.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void init(void) {
	glEnable (GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("Truk Saya");
//	glutIgnoreKeyRepeat(1); // Mengabaikan key repeat (saat tombol keyboard dipencet terus)
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutIdleFunc(display); // Fungsi display-nya dipanggil terusmenerus
	glutReshapeFunc(Reshape);
//	lighting();
	init();
	glutMainLoop();
	
	return(0);
}
