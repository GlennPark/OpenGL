#include "widget.h"
#include <GLUT/glut.h>
//#include <cmath>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    lx = 0, ly = 0, lz = -1.0;
    xAngle = 0, yAngle = 0, zAngle = 0;
    red = 0.2, green = 0.2, blue = 0.2;
    bAmbient = false;
    bAttach = false;
    setWindowTitle("OpenGL Lighting");
    resize(300, 300);
}

Widget::~Widget()
{
}

void Widget::initializeGL( )
{
    initializeOpenGLFunctions( );
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0,0,(GLint)w,(GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void Widget::paintGL( )
{
    glClear(GL_COLOR_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    GLfloat arLight[]={red, green, blue, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, arLight);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

//    if(bAttach){
//        glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
//        glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
//        glRotatef(zAngle, 0.0f, 0.0f, 1.0f);
//    }

//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    GLfloat lightpos[] = {lx, ly, lz, 1};
//    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

//    if(bAmbient){
//        GLfloat ambient[4]={0,1,0,1};
//        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
//    } else {
//        GLfloat ambient[4]={0,0,0,1};
//        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
//    }

//    if(bAttach == false){
//        glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
//        glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
//        glRotatef(zAngle, 0.0f, 0.0f, 1.0f);
//    }

    glutSolidTeapot(0.5);
    glPopMatrix();
    glFlush();

}

void Widget::keyPressEvent(QKeyEvent* event)
{
    switch(event->key( )) {
    case Qt::Key_1:         // 전체 창
        yAngle += 2;
        break;
    case Qt::Key_2:         // 좌하단
        yAngle -= 2;
        break;
    case Qt::Key_3:         // 우하단
        xAngle += 2;
        break;
    case Qt::Key_4:         // 절대 크기
        xAngle -= 2;
        break;
    case Qt::Key_5:         // 절대 크기
        zAngle += 2;
        break;
    case Qt::Key_6:         // 절대 크기
        zAngle -= 2;
        break;
    case Qt::Key_0:         // 절대 크기
        xAngle = yAngle = zAngle = 0.0;
        break;

    case Qt::Key_A:
        red += 0.1;
        break;
    case Qt::Key_S:
        red -= 0.1;
        break;
    case Qt::Key_D:
        green += 0.1;
        break;
    case Qt::Key_F:
        green -= 0.1;
        break;
    case Qt::Key_G:
        blue += 0.1;
        break;
    case Qt::Key_H:
        blue -= 0.1;
        break;
    case Qt::Key_J:
        red = 0.5, green = 0.5, blue = 0.5;
        break;


//    switch(event->key( )) {
//    case Qt::Key_1:         // 전체 창
//        bAmbient = GL_TRUE;
//        break;
//    case Qt::Key_2:         // 좌하단
//        bAmbient = GL_FALSE;
//        break;
//    case Qt::Key_3:         // 우하단
//        bAttach = GL_TRUE;
//        break;
//    case Qt::Key_4:         // 절대 크기
//        bAttach = GL_FALSE;
//        break;

//    case Qt::Key_A:
//        xAngle += 2;
//        break;
//    case Qt::Key_S:
//        xAngle -= 2;
//        break;
//    case Qt::Key_D:
//        yAngle += 2;
//        break;
//    case Qt::Key_F:
//        yAngle -= 2;
//        break;
//    case Qt::Key_G:
//        zAngle += 2;
//        break;
//    case Qt::Key_H:
//        zAngle -= 2;
//        break;
//    case Qt::Key_J:
//        xAngle = yAngle = zAngle = 0.0;
//        break;

//    case Qt::Key_Z:
//        lx -= 0.1;
//        break;

//    case Qt::Key_X:
//        lx += 0.1;
//        break;

//    case Qt::Key_C:
//        ly += 0.1;
//        break;

//    case Qt::Key_V:
//        ly -= 0.1;
//        break;

//    case Qt::Key_B:
//        lz += 0.1;
//        break;

//    case Qt::Key_N:
//        lz -= 0.1;
//        break;

//    case Qt::Key_M:
//        lx = 0, ly = 0, lz = -1.0;
//        break;

    };

//    QString str;
//    str
//    resizeGL(width( ), height( ));
    update( );
}
