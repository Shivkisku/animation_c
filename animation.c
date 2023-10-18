#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 24
#define MOON_RADIUS 10

int main() {
    float a = 0, b = 0;
    float z[HEIGHT][WIDTH] = {0};
    char output[HEIGHT][WIDTH+1] = {' '};

    while (1) {
        memset(output, ' ', HEIGHT*(WIDTH+1));
        memset(z, 0, HEIGHT*WIDTH*sizeof(float));

        for (int j = 0; j < 628; j++) {
            for (int i = 0; i < 628; i++) {
                float c = sin(i/100.0);
                float d = sin(j/100.0);
                float e = cos(a);
                float f = sin(a);
                float g = cos(b);
                float h = sin(b);
                float D = 1 / (c*e + 2);
                float l = cos(i/100.0);
                float m = cos(j/100.0);
                float n = sin(i/100.0);
                float t = d*e;
                float u = f*t;
                float v = c*g;
                float w = c*h;
                float x = d*f*g;
                float y = d*f*h;
                float z1 = l + MOON_RADIUS;
                float O = t*f*h - u*g;

                int screenX = 40 + 30 * D * (m*e*v - x*h - u*w);
                int screenY = 12 + 15 * D * (m*e*w + x*g + u*v);
                int screenZ = 8 + 15 * D * (n*f - t*d*g - u*d*h);

                if (screenX >= 0 && screenX < WIDTH && screenY >= 0 && screenY < HEIGHT && D > z[screenY][screenX]) {
                    z[screenY][screenX] = D;
                    output[screenY][screenX] = ".,-~:;=!*#$@"[(int)(O > 0 ? O : 0)];
                }
            }
        }

        printf("\x1b[H");
        for (int k = 0; k < HEIGHT; k++) {
            for (int l = 0; l < WIDTH; l++) {
                putchar(output[k][l]);
            }
            putchar('\n');
        }

        a += 0.04;
        b += 0.02;
        usleep(30000);
    }

    return 0;
}
