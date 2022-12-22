#include "widget.h"
#include "ui_widget.h"
#include <GLUT/glut.h>
//#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    xAngle = 0, yAngle = 0, zAngle = 0;
    setWindowTitle("OpenGL GLUT3D");
    resize(600, 600);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    GLUquadricObj *pQuad;
    pQuad = gluNewQuadric();
    gluQuadricDrawStyle(pQuad, GLU_LINE);

    gluSphere(pQuad, 0.3, 20, 20);

    glPushMatrix();
    glTranslatef(-0.6, 0.6, 0.0);
    gluCylinder(pQuad, 0.2, 0.2, 0.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.6, -0.6, 0.0);
    gluCylinder(pQuad, 0.2, 0.2, 0.0, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, 0.6, 0.0);
    gluDisk(pQuad, 0.1, 0.3, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, -0.6, 0.0);
    gluDisk(pQuad, 0.1, 0.3, 10, 10);
    glPopMatrix();

    gluDeleteQuadric(pQuad);
    glPopMatrix();

//    glutWireTeapot(0.3);
//    glPushMatrix();
//    glTranslatef(-0.6, 0.6, 0.0);
//    glutWireCube(0.4);
//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(-0.6, -0.6, 0.0);
//    glutWireSphere(0.3, 20, 20);
//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(0.6, 0.6, 0.0);
//    glutWireCone(0.3, 0.6, 20, 10);
//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(0.6, -0.6, 0.0);
//    glutWireTorus(0.1, 0.2, 20, 20);
//    glPopMatrix();



    glFlush();

}
