#include "glcard.h"

glcard::glcard(QImage m) :
    QGLWidget()
{
    xAr = 0;
    m1 = m;
    t = new QTimer;
    QObject::connect(t, SIGNAL(timeout()), this, SLOT(rot()));
}

void glcard::rot()
{
    xAr+=5;
    if(xAr > 360) xAr =0;
    if(xAr==180||xAr == 360) t->stop();
    else
    {
        t->start(25);
    }
    updateGL();
}


void glcard::genTex()
{
    glGenTextures(2, tex);

    QImage texture1;
    texture1.load("f1.png");
    texture1 = QGLWidget::convertToGLFormat(texture1);
    glBindTexture(GL_TEXTURE_2D, tex[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture1.width(), (GLsizei)texture1.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture1.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    texture1 = m1;
    texture1 = QGLWidget::convertToGLFormat(texture1);
    glBindTexture(GL_TEXTURE_2D, tex[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture1.width(), (GLsizei)texture1.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture1.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void glcard::initializeGL()
{
    glClearColor(0.9, 0.9, 0.9, 1.0);
    glEnable(GL_DEPTH_TEST);
    //glShadeModel(GL_SMOOTH);
    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    genTex();
}

void glcard::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -10.0, 10.0);
    glViewport(0, 0, (GLint)w, (GLint)h);
}

void glcard::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}


void glcard::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glRotatef(xAr, 1.0, 0.0, 0.0);


    GLfloat cVertexArray[8][3];
    GLubyte cIndexArray[1][4];

    cVertexArray[0][0] = -1.0;
    cVertexArray[0][1] = -1.0;
    cVertexArray[0][2] = 0.05;

    cVertexArray[1][0] = -1.0;
    cVertexArray[1][1] = 1.0;
    cVertexArray[1][2] = 0.05;

    cVertexArray[2][0] = 1.0;
    cVertexArray[2][1] = 1.0;
    cVertexArray[2][2] = 0.05;

    cVertexArray[3][0] = 1.0;
    cVertexArray[3][1] = -1.0;
    cVertexArray[3][2] = 0.05;

    cVertexArray[4][0] = -1.0;
    cVertexArray[4][1] = -1.0;
    cVertexArray[4][2] = -0.05;

    cVertexArray[5][0] = -1.0;
    cVertexArray[5][1] = 1.0;
    cVertexArray[5][2] = -0.05;

    cVertexArray[6][0] = 1.0;
    cVertexArray[6][1] = 1.0;
    cVertexArray[6][2] = -0.05;

    cVertexArray[7][0] = 1.0;
    cVertexArray[7][1] = -1.0;
    cVertexArray[7][2] = -0.05;

    glBindTexture(GL_TEXTURE_2D, tex[0]);

    GLfloat cTextureArray [8][2];

    cTextureArray[3][0] = 1.0;
    cTextureArray[3][1] = 0.0;

    cTextureArray[2][0] = 1.0;
    cTextureArray[2][1] = 1.0;

    cTextureArray[1][0] = 0.0;
    cTextureArray[1][1] = 1.0;

    cTextureArray[0][0] = 0.0;
    cTextureArray[0][1] = 0.0;

    cIndexArray[0][0] = 0;
    cIndexArray[0][1] = 3;
    cIndexArray[0][2] = 2;
    cIndexArray[0][3] = 1;

    glVertexPointer(3, GL_FLOAT, 0, cVertexArray);
    glTexCoordPointer(2, GL_FLOAT, 0, cTextureArray);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, cIndexArray);

    glBindTexture(GL_TEXTURE_2D, tex[0]);

    cTextureArray[0][0] = 0.0;
    cTextureArray[0][1] = 0.0;

    cTextureArray[1][0] = 1.0;
    cTextureArray[1][1] = 0.0;

    cTextureArray[5][0] = 1.0;
    cTextureArray[5][1] = 1.0;

    cTextureArray[4][0] = 0.0;
    cTextureArray[4][1] = 1.0;

    cIndexArray[0][0] = 0;
    cIndexArray[0][1] = 1;
    cIndexArray[0][2] = 5;
    cIndexArray[0][3] = 4;

    glVertexPointer(3, GL_FLOAT, 0, cVertexArray);
    glTexCoordPointer(2, GL_FLOAT, 0, cTextureArray);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, cIndexArray);

    glBindTexture(GL_TEXTURE_2D, tex[1]);

    cTextureArray[7][0] = 1.0;
    cTextureArray[7][1] = 1.0;

    cTextureArray[4][0] = 0.0;
    cTextureArray[4][1] = 1.0;

    cTextureArray[5][0] = 0.0;
    cTextureArray[5][1] = 0.0;

    cTextureArray[6][0] = 1.0;
    cTextureArray[6][1] = 0.0;

    cIndexArray[0][0] = 7;
    cIndexArray[0][1] = 4;
    cIndexArray[0][2] = 5;
    cIndexArray[0][3] = 6;

    glVertexPointer(3, GL_FLOAT, 0, cVertexArray);
    glTexCoordPointer(2, GL_FLOAT, 0, cTextureArray);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, cIndexArray);

    glBindTexture(GL_TEXTURE_2D, tex[0]);

    cTextureArray[3][0] = 0.0;
    cTextureArray[3][1] = 0.0;

    cTextureArray[7][0] = 1.0;
    cTextureArray[7][1] = 0.0;

    cTextureArray[6][0] = 1.0;
    cTextureArray[6][1] = 1.0;

    cTextureArray[2][0] = 0.0;
    cTextureArray[2][1] = 1.0;

    cIndexArray[0][0] = 3;
    cIndexArray[0][1] = 7;
    cIndexArray[0][2] = 6;
    cIndexArray[0][3] = 2;

    glVertexPointer(3, GL_FLOAT, 0, cVertexArray);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, cIndexArray);

    glBindTexture(GL_TEXTURE_2D, tex[0]);

    cTextureArray[1][0] = 0.0;
    cTextureArray[1][1] = 0.0;

    cTextureArray[2][0] = 1.0;
    cTextureArray[2][1] = 0.0;

    cTextureArray[6][0] = 1.0;
    cTextureArray[6][1] = 1.0;

    cTextureArray[5][0] = 0.0;
    cTextureArray[5][1] = 1.0;

    cIndexArray[0][0] = 1;
    cIndexArray[0][1] = 2;
    cIndexArray[0][2] = 6;
    cIndexArray[0][3] = 5;

    glVertexPointer(3, GL_FLOAT, 0, cVertexArray);
    glTexCoordPointer(2, GL_FLOAT, 0, cTextureArray);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, cIndexArray);

    glBindTexture(GL_TEXTURE_2D, tex[0]);

    cTextureArray[0][0] = 0.0;
    cTextureArray[0][1] = 0.0;

    cTextureArray[4][0] = 1.0;
    cTextureArray[4][1] = 0.0;

    cTextureArray[7][0] = 1.0;
    cTextureArray[7][1] = 1.0;

    cTextureArray[3][0] = 0.0;
    cTextureArray[3][1] = 1.0;

    cIndexArray[0][0] = 0;
    cIndexArray[0][1] = 4;
    cIndexArray[0][2] = 7;
    cIndexArray[0][3] = 3;

    glVertexPointer(3, GL_FLOAT, 0, cVertexArray);
    glTexCoordPointer(2, GL_FLOAT, 0, cTextureArray);
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, cIndexArray);


}
