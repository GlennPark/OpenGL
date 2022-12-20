#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    GLfloat rectPosX;
    GLfloat rectPosY;
    GLfloat rectSize;

    GLfloat xStep;
    GLfloat yStep;

    GLfloat windowWidth;
    GLfloat windowHeight;

    double radius;
    double delta_theta, cord_length;
    double xcenter, ycenter;
    double x, y, theta;
    double current_angle, atime;

public slots:
    void timerFunction();
};
#endif // WIDGET_H
