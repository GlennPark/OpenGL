#include "widget.h"
#include <GLUT/glut.h>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{

    Action = 0;
    setWindowTitle("OpejGL Modeling");
    resize(600, 600);
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
//    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 0.0);
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
    glTranslatef(0.0, 0.6, 0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutWireTeapot(0.2);
    glFlush();
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    switch(event->key()){
    case Qt::Key_Z:
        break;
    case Qt::Key_1:
        break;
    case Qt::Key_2:
        break;
    case Qt::Key_3:
        break;
    case Qt::Key_4:
        break;
    case Qt::Key_5:
        break;
    case Qt::Key_6:
        break;
    case Qt::Key_7:
        break;
    case Qt::Key_8:
        break;
    case Qt::Key_9:
        break;
    case Qt::Key_0:
        break;
    };
    update();

}
