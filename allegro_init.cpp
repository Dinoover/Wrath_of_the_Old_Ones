#include "allegro_init.hpp"


void allegro_initialisation()
{
    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    //show_mouse(screen);
}

void bitmap_load(BITMAP* files[29])
{
    files[0]=load_bitmap("images/back.bmp",NULL);
    if(!files[0])
    error();

    files[1]=load_bitmap("images/001.bmp",NULL);
    if(!files[1])
    error();

    files[2]=load_bitmap("images/002.bmp",NULL);
    if(!files[2])
    error();

    files[3]=load_bitmap("images/003.bmp",NULL);
    if(!files[3])
    error();

    files[4]=load_bitmap("images/004.bmp",NULL);
    if(!files[4])
    error();

    files[5]=load_bitmap("images/005.bmp",NULL);
    if(!files[5])
    error();

    files[6]=load_bitmap("images/006.bmp",NULL);
    if(!files[6])
    error();

    files[7]=load_bitmap("images/007.bmp",NULL);
    if(!files[7])
    error();

    files[8]=load_bitmap("images/008.bmp",NULL);
    if(!files[8])
    error();

    files[9]=load_bitmap("images/009.bmp",NULL);
    if(!files[9])
    error();

    files[10]=load_bitmap("images/010.bmp",NULL);
    if(!files[10])
    error();

    files[11]=load_bitmap("images/011.bmp",NULL);
    if(!files[11])
    error();

    files[12]=load_bitmap("images/012.bmp",NULL);
    if(!files[12])
    error();

    files[13]=load_bitmap("images/013.bmp",NULL);
    if(!files[13])
    error();

    files[14]=load_bitmap("images/014.bmp",NULL);
    if(!files[14])
    error();

    files[15]=load_bitmap("images/015.bmp",NULL);
    if(!files[15])
    error();

    files[16]=load_bitmap("images/016.bmp",NULL);
    if(!files[16])
    error();

    files[17]=load_bitmap("images/017.bmp",NULL);
    if(!files[17])
    error();

    files[18]=load_bitmap("images/018.bmp",NULL);
    if(!files[18])
    error();

    files[19]=load_bitmap("images/019.bmp",NULL);
    if(!files[19])
    error();

    files[20]=load_bitmap("images/020.bmp",NULL);
    if(!files[20])
    error();

    files[21]=load_bitmap("images/021.bmp",NULL);
    if(!files[21])
    error();

    files[22]=load_bitmap("images/022.bmp",NULL);
    if(!files[22])
    error();

    files[23]=load_bitmap("images/023.bmp",NULL);
    if(!files[23])
    error();

    files[24]=load_bitmap("images/cursor.bmp",NULL);
    if(!files[24])
    error();

    files[25]=load_bitmap("images/menu.bmp",NULL);
    if(!files[25])
    error();

    files[26]=load_bitmap("images/title.bmp",NULL);
    if(!files[26])
    error();

    files[27]=load_bitmap("images/plateau.bmp",NULL);
    if(!files[27])
    error();

    files[28]=load_bitmap("images/selection.bmp",NULL);
    if(!files[28])
    error();
}

void bitmap_destroy(BITMAP* files[29])
{
    for(int i=0; i<29; i++)
    {
        destroy_bitmap(files[i]);
    }
}

void error()
{
    allegro_message("probleme : chargement images");
    allegro_exit();
    exit(EXIT_FAILURE);
}

void keyboard()
{

}

