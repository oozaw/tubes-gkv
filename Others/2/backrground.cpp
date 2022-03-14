///*
// * FreeGLUT Shapes Demo
// *
// * Written by Nigel Stewart November 2003
// *
// * This program is test harness for the sphere, cone 
// * and torus shapes in FreeGLUT.
// *
// * Spinning wireframe and smooth shaded shapes are
// * displayed until the ESC or q key is pressed.  The
// * number of geometry stacks and slices can be adjusted
// * using the + and - keys.
// */
//
//#include <GL/glut.h>
//#include <math.h>
//
//double rotAngle = 0; // rotation angle (BEWARE: Global)
//double rotAngle1 = 0; // rotation angle (BEWARE: Global)
//float angle=0.0, deltaAngle = 0.0, ratio;
//float x=0.0f,y=1.75f,z=50.0f; // posisi awal kamera
//float lx=0.0f,ly=0.0f,lz=-1.0f;
//int deltaMove = 0,h,w;
//int bitmapHeight=12;
//
//void orientMe(float ang) {
//	// Fungsi ini untuk memutar arah kamera (tengok kiri/kanan)
//	lx = sin(ang);
//	lz = -cos(ang);
//	glLoadIdentity();
//	gluLookAt(x, y, z,
//	x + lx,y + ly,z + lz,
//	0.0f,1.0f,0.0f);
//}
//
//void moveMeFlat(int i) {
//	// Fungsi ini untuk maju mundur kamera
//	x = x + i*(lx)*0.1;
//	z = z + i*(lz)*0.1;
//	glLoadIdentity();
//	gluLookAt(x, y, z,
//	x + lx,y + ly,z + lz,
//	0.0f,1.0f,0.0f);
//}
//
///* run this program using the console pauser or add your own getch, system("pause") or input loop */
//	
//const double PI = 3.142857143;
//int i, radius, jumlah_titik, x_tengah, y_tengah;
//
//int a = 0; // int
//int b = 0;
//bool right = true;
//bool left = true;
//	
//void city(){
//	//sky
//	glBegin(GL_QUADS);
//	glColor3ub(135,206,250);
//	glVertex2f(-10.0,10.0);
//	glVertex2f(10.0,10.0);
//	glColor3ub(255,69,0);
//	glVertex2f(10.0,-6.2);
//	glVertex2f(-10.0,-6.2);
//	glEnd();
//	
//	//moon
//	glColor3f(1,1,0.7);
//	glBegin(GL_POLYGON);
//	
//	radius = 50;
//	jumlah_titik = 100;	
//	x_tengah = -0;
//	y_tengah = 1;
//	
//	for (i=0;i<=360;i++){
//		float sudut = i * (2*PI/jumlah_titik);
//		float x = x_tengah + radius *cos(sudut);
//		float y = y_tengah + radius *cos(sudut);
//		glVertex2f(x/10,y/10);
//	}	
//	glEnd();
//	
//	//shadow
//	glBegin(GL_POLYGON);
//	glColor3ub(105,105,105);
//	glVertex2f(-9.8,-6.0);
//	glVertex2f(-9.8,1.0);
//	glVertex2f(-4.0,1.0);
//	glVertex2f(-4.0,-2.0);
//	glVertex2f(3.0,-2.0);
//	glVertex2f(2.0,2.0);
//	glVertex2f(8.2,-6.0);
//	glEnd();
//	
//	//building
//	glBegin(GL_POLYGON);
//	glColor3f(0.0,0.0,0.0);
//	glVertex2f(-9.8,-6);
//	glVertex2f(-9.8,0);
//	glVertex2f(-9.6,0);
//	glVertex2f(-9.6,1);
//	glVertex2f(-9.2,1);
//	glVertex2f(-9.2,1.5);
//	glVertex2f(-6.6,1.5);
//	glVertex2f(-6.6,1);
//	glVertex2f(-6.6,1);
//	glVertex2f(-6.2,1);
//	glVertex2f(-6.2,0);
//	glVertex2f(-6,0);
//	glVertex2f(-6,-6);
//	glEnd();
//	
//	//window
//	glBegin(GL_QUADS);
//	glColor3ub(255,255,0);
//	glVertex2f(-9.4,0.8);
//	glVertex2f(-6.4,0.8);
//	glVertex2f(-6.4,0.2);
//	glVertex2f(-9.4,0.2);
//	
//	glVertex2f(-9.6,-0.2);
//	glVertex2f(-6.2,-0.2);
//	glVertex2f(-6.2,-5.8);
//	glVertex2f(-9.6,-5.8);
//	glEnd();
//	
//	glLineWidth(10);
//	glBegin(GL_LINES);
//	glColor3f(0,0,0);
//	glVertex2f(-7.9,-5.8);
//	glVertex2f(-7.9,-0.2);
//	
//	glVertex2f(-6.2,-3.2);
//	glVertex2f(-9.6,-3.2);
//	
//	glVertex2f(-6.2,-1.7);
//	glVertex2f(-9.6,-1.7);
//	
//	glVertex2f(-6.2,-4.7);
//	glVertex2f(-9.6,-4.7);
//	
//	glVertex2f(-7,-5.8);
//	glVertex2f(-7,-0.2);
//	
//	glVertex2f(-8.8,-5.8);
//	glVertex2f(-8.8,-0.2);
//	glEnd();
//	
//	//building2
//	glBegin(GL_POLYGON);
//	glColor3f(0.0,0.0,0.0);
//	glVertex2f(-5.5,-6);
//	glVertex2f(-5.5,2);
//	glVertex2f(-5.3,2);
//	glVertex2f(-5.3,2.2);
//	glVertex2f(-5.1,2.2);
//	glVertex2f(-5.1,2.7);
//	glVertex2f(-3.5,2.7);
//	glVertex2f(-3.5,2.2);
//	glVertex2f(-3.3,2.2);
//	glVertex2f(-3.3,2);
//	glVertex2f(-3.1,2);
//	glVertex2f(-3.1,-6);
//	glEnd();
//	
//	//window2
//	glBegin(GL_QUADS);
//	glColor3ub(255,255,0);
//	glVertex2f(-4.4,-5.8);
//	glVertex2f(-4.4,2.3);
//	glVertex2f(-4.1,2.3);
//	glVertex2f(-4.1,-5.8);
//	
//	glVertex2f(-4.7,-5.5);
//	glVertex2f(-4.7,1.8);
//	glVertex2f(-5.2,1.8);
//	glVertex2f(-5.2,-5.5);
//	
//	glVertex2f(-3.8,-5.5);
//	glVertex2f(-3.8,1.8);
//	glVertex2f(-3.3,1.8);
//	glVertex2f(-3.3,-5.5);
//	glEnd();
//	
//	//building3
//	glBegin(GL_QUADS);
//	glColor3f(0,0,0);
//	glVertex2f(-3,-6);
//	glVertex2f(-3,-2);
//	glVertex2f(-1.1,-2);
//	glVertex2f(-1.1,-6);
//	glEnd();
//	
//	//building4
//	glBegin(GL_POLYGON);
//	glColor3f(0.0,0.0,0.0);
//	glVertex2f(-1,-6);
//	glVertex2f(-1,2);
//	glVertex2f(0,2);
//	glVertex2f(0,3);
//	glVertex2f(1,3);
//	glVertex2f(1,4.5);
//	glVertex2f(2,4.5);
//	glVertex2f(3,3);
//	glVertex2f(3,2);
//	glVertex2f(4,2);
//	glVertex2f(4,-6);
//	glEnd();
//	
//	//window4
//	glBegin(GL_QUADS);
//	glColor3ub(255,255,0);
//	glVertex2f(-0.8,1.8);
//	glVertex2f(3.8,1.8);
//	glVertex2f(3.8,0.8);
//	glVertex2f(-0.8,0.8);
//	
//	glVertex2f(-0.8,-5.2);
//	glVertex2f(-0.8,-4.2);
//	glVertex2f(3.8,-4.2);
//	glVertex2f(3.8,-5.2);
//	
//	glVertex2f(-0,-2.2);
//	glVertex2f(-0,-1.2);
//	glVertex2f(3.8,-1.2);
//	glVertex2f(3.8,-2.2);
//	
//	glVertex2f(2.9,0.5);
//	glVertex2f(3.8,0.5);
//	glVertex2f(3.8,-0.9);
//	glVertex2f(2.9,-0.9);
//	
//	glVertex2f(-0.8,0.5);
//	glVertex2f(0.1,0.5);
//	glVertex2f(0.1,-0.9);
//	glVertex2f(-0.8,-0.9);
//	
//	glVertex2f(-0.8,-2.5);
//	glVertex2f(0.1,-2.5);
//	glVertex2f(0.1,-3.8);
//	glVertex2f(-0.8,-3.8);
//	
//	glVertex2f(1.1,0.5);
//	glVertex2f(2,0.5);
//	glVertex2f(2,-0.9);
//	glVertex2f(1.1,-0.9);
//	
//	glVertex2f(0.0,-5.8);
//	glVertex2f(0.0,-5.4);
//	glVertex2f(3.8,-5.4);
//	glVertex2f(3.8,-5.8);
//	glEnd();
//	
//	//building5
//	glBegin(GL_QUADS);
//	glColor3f(0,0,0);
//	glVertex2f(4.1,-6);
//	glVertex2f(4.1,3);
//	glVertex2f(7,3);
//	glVertex2f(7,-6);
//	
//	//window5
//	glBegin(GL_QUADS);
//	glColor3ub(255,255,0);
//	glVertex2f(5.2,-5.9);
//	glVertex2f(5.2,-1.7);
//	glVertex2f(5.8,-1.7);
//	glVertex2f(5.8,-5.9);
//	
//	glVertex2f(4.4,-1.4);
//	glVertex2f(4.4,2.7);
//	glVertex2f(5,2.7);
//	glVertex2f(5,-1.4);
//	
//	glVertex2f(6,-1.4);
//	glVertex2f(6,2.7);
//	glVertex2f(6.7,2.7);
//	glVertex2f(6.7,-1.4);
//	
//	glVertex2f(5.2,-1.4);
//	glVertex2f(5.2,2.7);
//	glVertex2f(5.8,2.7);
//	glVertex2f(5.8,-1.4);
//	
//	glVertex2f(4.4,-5.9);
//	glVertex2f(4.4,-1.7);
//	glVertex2f(5,-1.7);
//	glVertex2f(5,-5.9);
//	
//	glVertex2f(6,-5.9);
//	glVertex2f(6,-1.7);
//	glVertex2f(6.7,-1.7);
//	glVertex2f(6.7,-5.9);
//	glEnd();
//	
//	//building6
//	glBegin(GL_POLYGON);
//	glColor3f(0.0,0.0,0.0);
//	glVertex2f(7.5,-6);
//	glVertex2f(7.5,0);
//	glVertex2f(9,0);
//	glVertex2f(9,-2);
//	glVertex2f(9.8,-2);
//	glVertex2f(9.8,-6);
//	glEnd();
//	
//	//window6
//	glBegin(GL_QUADS);
//	glColor3ub(255,255,0);
//	glVertex2f(7.7,-5.8);
//	glVertex2f(7.7,-0.2);
//	glVertex2f(8.8,-0.2);
//	glVertex2f(8.8,-5.8);
//	glEnd();
//	glFlush();
//}
//	
//void leftcloud(){
//	//cloud
//	glColor3ub(255,255,255);
//	glBegin(GL_POLYGON);
//	radius = 12;
//	jumlah_titik = 100;
//	x_tengah = -50;
//	y_tengah = 50;
//	for (i=0;i<=360;i++){
//			
//		float sudut=i* (2*PI/jumlah_titik);
//		float x = x_tengah + radius *cos(sudut);
//		float y = y_tengah + radius *sin(sudut);
//		glVertex2f(x/10,y/10);				
//	}
//	radius = 10;
//	jumlah_titik = 100;
//	x_tengah = -60;
//	y_tengah = 50;
//	for (i=0;i<=360;i++){
//			
//		float sudut=i* (2*PI/jumlah_titik);
//		float x = x_tengah + radius *cos(sudut);
//		float y = y_tengah + radius *sin(sudut);
//		glVertex2f(x/10,y/10);
//	}
//	radius = 10;
//	jumlah_titik = 100;
//	x_tengah = -40;
//	y_tengah = 50;
//	for (i=0;i<=360;i++){
//			
//		float sudut=i*(2*PI/jumlah_titik);
//		float x = x_tengah + radius *cos(sudut);
//		float y = y_tengah + radius *sin(sudut);
//		glVertex2f(x/10,y/10);
//	}
//	glEnd();
//
//	//cloud2
//	glBegin(GL_POLYGON);
//	radius = 12;
//	jumlah_titik = 100;
//	x_tengah = -70;
//	y_tengah = 80;
//	for (i=0;i<=360;i++){
//			
//		float sudut=i* (2*PI/jumlah_titik);
//		float x = x_tengah + radius *cos(sudut);
//		float y = y_tengah + radius *sin(sudut);
//		glVertex2f(x/10,y/10);				
//	}
//	radius = 10;
//	jumlah_titik = 100;
//	x_tengah = -80;
//	y_tengah = 80;
//	for (i=0;i<=360;i++){
//			
//		float sudut=i* (2*PI/jumlah_titik);
//		float x = x_tengah + radius *cos(sudut);
//		float y = y_tengah + radius *sin(sudut);
//		glVertex2f(x/10,y/10);
//	}
//	radius = 10;
//	jumlah_titik = 100;
//	x_tengah = -60;
//	y_tengah = 80;
//	for (i=0;i<=360;i++){
//		
//		float sudut=i*(2*PI/jumlah_titik);
//		float x = x_tengah + radius *cos(sudut);
//		float y = y_tengah + radius *sin(sudut);
//		glVertex2f(x/10,y/10);
//	}
//	glEnd();
//}
//
//void rightcloud(){
//	//cloud
//	glColor3ub(255,255,255);
//	glBegin(GL_POLYGON);
//	radius = 12;
//	jumlah_titik = 100;
//	x_tengah = 70;
//	y_tengah = 80;
//	for (i=0;i<=360;i++){
//		
//		float sudut=i* (2*PI/jumlah_titik);
//		float x = x_tengah + radius *cos(sudut);
//		float y = y_tengah + radius *sin(sudut);
//		glVertex2f(x/10,y/10);				
//	}
//	radius = 10;
//	jumlah_titik = 100;
//	x_tengah = 80;
//	y_tengah = 80;
//	for (i=0;i<=360;i++){
//		
//		float sudut=i* (2*PI/jumlah_titik);
//		float x = x_tengah + radius *cos(sudut);
//		float y = y_tengah + radius *sin(sudut);
//		glVertex2f(x/10,y/10);
//	}
//	radius = 10;
//	jumlah_titik = 100;
//	x_tengah = 60;
//	y_tengah = 80;
//	for (i=0;i<=360;i++){
//		
//		float sudut=i*(2*PI/jumlah_titik);
//		float x = x_tengah + radius *cos(sudut);
//		float y = y_tengah + radius *sin(sudut);
//		glVertex2f(x/10,y/10);
//	}
//	glEnd();
//
//	//cloud2
//	glBegin(GL_POLYGON);
//	radius = 12;
//	jumlah_titik = 100;
//	x_tengah = 50;
//	y_tengah = 50;
//	for (i=0;i<=360;i++){
//			
//		float sudut=i* (2*PI/jumlah_titik);
//		float x = x_tengah + radius *cos(sudut);
//		float y = y_tengah + radius *sin(sudut);
//		glVertex2f(x/10,y/10);				
//	}
//	radius = 10;
//	jumlah_titik = 100;
//	x_tengah = 60;
//	y_tengah = 50;
//	for (i=0;i<=360;i++){
//			
//		float sudut=i* (2*PI/jumlah_titik);
//		float x = x_tengah + radius *cos(sudut);
//		float y = y_tengah + radius *sin(sudut);
//		glVertex2f(x/10,y/10);
//	}
//	radius = 10;
//	jumlah_titik = 100;
//	x_tengah = 40;
//	y_tengah = 50;
//	for (i=0;i<=360;i++){
//			
//		float sudut=i*(2*PI/jumlah_titik);
//		float x = x_tengah + radius *cos(sudut);
//		float y = y_tengah + radius *sin(sudut);
//		glVertex2f(x/10,y/10);
//	}
//	glEnd();
//	glFlush();
//}
//
//void keyboard(unsigned char k, int x, int y)
//{
//	// Fungsi ini untuk rotasi kamera
//	switch (k)
//	{
//		case 'q':
//			rotAngle += 10; // increase rotation by 10 degrees
//			break;
//		case 'w':
//			rotAngle1 += 10; // increase rotation by 10 degrees
//			break;
//		case 'e':
//			rotAngle1 -= 10; // increase rotation by 10 degrees
//			break;
//		case 'r':
//			rotAngle -= 10; // decrease rotation by 10 degrees
//			break;
//		case (27):
//			exit(0); // exit
//	}
//	glutPostRedisplay();
//}
//
//void pressKey(int key, int x, int y) {
//	// Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas
//	// Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak
//	switch (key) {
//		case GLUT_KEY_LEFT : 
//			deltaAngle = -0.12f;
//			break;
//		case GLUT_KEY_RIGHT : 
//			deltaAngle = 0.12f;
//			break;
//		case GLUT_KEY_UP : 
//			deltaMove = 4;
//			break;
//		case GLUT_KEY_DOWN : 
//			deltaMove = -4;
//			break;
//	}
//}
//
//void releaseKey(int key, int x, int y) {
//	// Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas
//	// Saat tombol dilepas, variabel angle dan move diset nol => kamera berhenti
//	switch (key) {
//		case GLUT_KEY_LEFT :
//			if (deltaAngle < 0.0f)
//				deltaAngle = 0.0f;
//				break;
//		case GLUT_KEY_RIGHT : 
//			if (deltaAngle > 0.0f)
//				deltaAngle = 0.0f;
//				break;
//		case GLUT_KEY_UP : 
//			if (deltaMove > 0)
//				deltaMove = 0;
//				break;
//		case GLUT_KEY_DOWN : 
//			if (deltaMove < 0)
//				deltaMove = 0;
//				break;
//	}
//}
//
//void Reshape(int w1, int h1) {
//	// Fungsi reshape
//	if(h1 == 0) h1 = 1;
//	w = w1;
//	h = h1;
//	ratio = 1.0f * w / h;
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glViewport(0, 0, w, h);
//	gluPerspective(45,ratio,0.1,1000);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(
//	x, y, z,
//	x + lx,y + ly,z + lz,
//	0.0f,1.0f,0.0f);
//}
//			
//void renderScene(void){
//	if (deltaMove)
//		moveMeFlat(deltaMove);
//	if (deltaAngle) {
//		angle += deltaAngle;
//		orientMe(angle);
//	}
//	glClear(GL_COLOR_BUFFER_BIT);
//	glPushMatrix();
//	city();
//	glRotated(rotAngle, 0, 1, 0); // rotate by rotAngle about y-axis
//	glRotated(rotAngle1, 1, 0, 0); // rotate by rotAngle about yaxis
//	glPopMatrix();	
//		
//	glPushMatrix();
//	glTranslatef(a,0,0);
//	leftcloud();
//	glPopMatrix();
//	
//	glPushMatrix();
//	glTranslatef(b,0,0);
//	rightcloud();
//	glPopMatrix();
//	
//	glPopMatrix();
//	glutSwapBuffers();
//	glFlush();
//}
//	
//void time(int t){
//	
//	if (left){
//		a +=2;
//	}else {
//		a-=2;
//	}
//	if (a > 20){
//		left = false;
//	}else if (a < -20){
//		left = true;
//	}
//	
//	if (right){
//		b -=1;
//	} else {
//		b +=1;
//	}
//	if ( b < -20){
//		right = false;
//	} else if (b > 20){
//		right = true;
//	}
//	glutPostRedisplay();
//	glutTimerFunc(350,time,0);
//}
//
//void init(void) {
//	glEnable (GL_DEPTH_TEST);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//}
//	
//int main(int argc, char **argv){
//	glutInit(&argc, argv);
////	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(650, 600);
//	glutCreateWindow("Background");
//	glutSpecialFunc(pressKey);
//	glutSpecialUpFunc(releaseKey);
//	glutKeyboardFunc(keyboard);
//	glutDisplayFunc(renderScene);
//	glutIdleFunc(renderScene);
//	glutReshapeFunc(Reshape);
//	glutTimerFunc(1,time,0);
////	init();
//	glutMainLoop();
//	return 0;
//}

