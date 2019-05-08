#include <stdlib.h>
#include <vga.h>
#include <math.h>
#include "letras.h"
#include "screen.h"

// int maxx = 1024, maxy = 768;
// int midx = maxx/2, midy = maxy/2;

// void letra(int col, int fil, const unsigned char *punA)
// {
//     char aux;
//     int x,y;
//     aux = *punA;
//     for(y=0; y<12; y++)
//     {
//         for(x=0; x<8; x++)
//         {
//             if((aux & 0x80) == 0x80)
//                 vga_setcolor(14);        // Letra
//             else
//                 vga_setcolor(0);        // Fondo
//             vga_drawpixel(col+x,fil+y);
//             aux <<= 1;
//         }
//         punA++; aux = *punA;
//     }
// }

// void linea(int x1, int y1, int x2, int y2, int color)
// {
//    vga_setcolor(color);
//    vga_drawline(x1,-y1 + maxy,x2,-y2 + maxy);
// }

// void cuadro(int x1, int y1, int x2, int y2, int color)
// {
//     linea(x1,y1,x2,y1,color);
//     linea(x2,y1,x2,y2,color);
//     linea(x2,y2,x1,y2,color);
//     linea(x1,y2,x1,y1,color);
// }

// float seno(float x)
// {
//     float y;
//     y = floor(200*sin(M_PI*x/180));
//     return y;
// }

// float coseno(float x)
// {
//     float y;
//     y = floor(200*cos(M_PI*x/180));
//     return y;
// }

int main(void)
{
    vga::Screen screen;

    // int i;
    // float x,y;
    // float x1,y1,x2,y2;

    // vga_init();
    // vga_setmode(G1024x768x256);
    int maxx = screen.getMaxX();
    int maxy = screen.getMaxY();
    
    int midx = screen.getMidX();
    int midy = screen.getMidY();
    
    // cuadro(1,1,maxx-1,maxy-40,2);
    screen.letra(midx-3,45,flechaU);
    screen.letra(maxx-12,midy-3,flechaR);
    screen.linea(vga::Punto(midx,5),vga::Punto(midx,maxy-45),14);    // eje y
    screen.linea(vga::Punto(5,midy),vga::Punto(maxx-5,midy),14);     // eje x
    screen.letra(midx+5,45,Y);
    screen.letra(maxx-12,midy+5,X);

    // x1 = 0; y1 = seno(x1);
    // for(i=0; i<=72; i++)
    // {
    //     x2 = x1 + 5; y2 = seno(x2);
    //     linea(x1 + midx, y1 + midy, x2 + midx, y2 + midy, 12);
    //     x1 = x2; y1 = y2;
    // }

    // x1 = 0; y1 = coseno(x1);
    // for(i=0; i<=72; i++)
    // {
    //     x2 = x1 + 5; y2 = coseno(x2);
    //     linea(x1 + midx, y1 + midy, x2 + midx, y2 + midy, 33);
    //     x1 = x2; y1 = y2;
    // }

    vga_getch();
    vga_setmode(TEXT);

    return EXIT_SUCCESS;
}
