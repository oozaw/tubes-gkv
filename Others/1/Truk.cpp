// Template untuk mainan objek 3D
// Kamera bisa maju mundur kiri kanan
// Sudah dilengkapi pencahayaan
// Sekarang pake texture

#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float angle=0.0, deltaAngle = 0.0, ratio;
float x=0.0f,y=1.75f,z=15.0f; // posisi awal kamera
float lx=0.0f,ly=0.0f,lz=-1.0f;
int deltaMove = 0,h,w;
int bitmapHeight=12;
const double PI = 3.141592653589793;
int i, j, radius, jumlah_titik, x_tengah, y_tengah;

void Reshape(int w1, int h1){
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
	gluLookAt(x, y, z,
	x + lx,y + ly,z + lz,
	0.0f,1.0f,0.0f);
}

void orientMe(float ang){
	// Fungsi ini untuk memutar arah kamera (tengok kiri/kanan)
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z,
	x + lx,y + ly,z + lz,
	0.0f,1.0f,0.0f);
}

void moveMeFlat(int i){
// Fungsi ini untuk maju mundur kamera
	x = x + i*(lx)*0.1;
	z = z + i*(lz)*0.1;
	glLoadIdentity();
	gluLookAt(x, y, z,
	x + lx,y + ly,z + lz,
	0.0f,1.0f,0.0f);
}

void Grid() {
	// Fungsi untuk membuat grid di "lantai"
	double i;
	const float Z_MIN = -50, Z_MAX = 50;
	const float X_MIN = -50, X_MAX = 50;
	const float gap = 1.5;
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
		for(i=Z_MIN;i<Z_MAX;i+=gap){
			glVertex3f(i, 0, Z_MIN);
			glVertex3f(i, 0, Z_MAX);
		}
		for(i=X_MIN;i<X_MAX;i+=gap){
			glVertex3f(X_MIN, 0, i);
			glVertex3f(X_MAX, 0, i);
		}
	glEnd();
}

void truk(){

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

void display() {
	// Kalau move dan angle tidak nol, gerakkan kamera...
	if (deltaMove)
		moveMeFlat(deltaMove);
	if (deltaAngle) {
		angle += deltaAngle;
		orientMe(angle);
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Gambar grid
	Grid();

	// Gambar objek di sini...
	truk();
	glutSwapBuffers();
	glFlush();
}

void pressKey(int key, int x, int y) {
	// Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas
	// Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak
	switch (key) {
		case GLUT_KEY_LEFT : deltaAngle = -0.01f;break;
		case GLUT_KEY_RIGHT : deltaAngle = 0.01f;break;
		case GLUT_KEY_UP : deltaMove = 1;break;
		case GLUT_KEY_DOWN : deltaMove = -1;break;
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
		case GLUT_KEY_RIGHT : if (deltaAngle > 0.0f)
			deltaAngle = 0.0f;
			break;
		case GLUT_KEY_UP : if (deltaMove > 0)
			deltaMove = 0;
			break;
		case GLUT_KEY_DOWN : if (deltaMove < 0)
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

void lighting(){
	// Fungsi mengaktifkan pencahayaan
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

void init(void){
	glEnable (GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("Truk");
	glutIgnoreKeyRepeat(1); // Mengabaikan key repeat (saat tombol keyboard dipencet terus)
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	glutDisplayFunc(display);
	glutIdleFunc(display); // Fungsi display-nya dipanggil terus-menerus
	glutReshapeFunc(Reshape);
	lighting();
	init();
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glutMainLoop();
	return(0);
}
