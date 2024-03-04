#ifndef GLUTIL_H
#define GLUTIL_H



#include <vector>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<Mmsystem.h>
#include <string>
using namespace std;


class TextureInfo {
public:
    int imageWidth;
    int imageHeight;
    GLubyte* imageData;
    GLuint textureID;

    TextureInfo(const char* filename) {
        FILE* file = fopen(filename, "rb");
        if (!file) {
            std::cerr << "Error opening file: " << filename << std::endl;
            exit(1);
        }

        fseek(file, 18, SEEK_SET);
        fread(&imageWidth, sizeof(int), 1, file);
        fread(&imageHeight, sizeof(int), 1, file);

        int imageSize = imageWidth * imageHeight * 3;

        imageData = new GLubyte[imageSize];

        fseek(file, 54, SEEK_SET); // Skip the header
        fread(imageData, sizeof(GLubyte), imageSize, file);

        for (int i = 0; i < imageSize; i += 3) {
            GLubyte temp = imageData[i];
            imageData[i] = imageData[i + 2];
            imageData[i + 2] = temp;
        }

        fclose(file);

        glEnable(GL_TEXTURE_2D);
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
    }
};
std::vector<TextureInfo> textures;
void loadImageAndStore(const char* filename) {
 textures.push_back(TextureInfo(filename));
 }
void ApplyTexture(float x1, float y1,float x2, float y2,float x3, float y3,float x4, float y4, GLuint texture )
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex2f(x1,y1);

    glTexCoord2f(1.0, 0.0);
    glVertex2f(x2,y2);

    glTexCoord2f(1.0, 1.0);
    glVertex2f(x3,y3);

    glTexCoord2f(0.0, 1.0);
    glVertex2f(x4,y4);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

#endif
