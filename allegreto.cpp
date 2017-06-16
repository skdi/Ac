#include <allegro.h>
#define ancho 320
#define alto 240
 
int main() 
{ 
 allegro_init();
 install_keyboard();
  
 int pausa;
  
 // incializa el audio en allegro
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }
 
    // ajustamos el volumen
 set_volume(230, 200);
  
 // definimos el audio del programa
 MIDI *musica1  = load_midi("flourish.mid");
 MIDI *musica2  = load_midi("seal.mid");
  
 SAMPLE *sonido1 = load_wav("ding.wav");
 SAMPLE *sonido2 = load_wav("notify.wav");
  
 set_color_depth(32);
 set_gfx_mode(GFX_AUTODETECT_WINDOWED, ancho, alto, 0, 0);
  
 BITMAP *buffer = create_bitmap(ancho, alto);
 pausa = 0;
    while ( !key[KEY_ESC] )
    {
       clear_to_color(buffer, 0x333333);
       if ( key[KEY_SPACE] )
       {
            if ( pausa == 0)
            {
               midi_pause();
               pausa = 1;
            }else{
               midi_resume();
               pausa = 0;   
            }
       }        
        
       if ( key[KEY_1] )
       {
            play_midi(musica1,1);
       }
        
       if ( key[KEY_2] )
       {
            play_midi(musica2,1);
       } 
                     
       if ( key[KEY_3] )
       {
            play_sample(sonido1,200,150,1000,0);
       }
       if ( key[KEY_4] )
       {
            play_sample(sonido2,200,150,1000,0);
       }
  
    rectfill(buffer, 2, 2, ancho-4, alto-4, 0xDF1680);
    rectfill(buffer, 30, 30, ancho-30, alto-30, 0x000000);
 
       textout_centre_ex(buffer, font, "ESC para Salir", ancho/2, 10, 0xFFFFFF, 0xDF1680); 
       textout_centre_ex(buffer, font, "1.- Inicia Musica 1", ancho/2, 70, 0xFFFFFF, 0x333333);  
       textout_centre_ex(buffer, font, "2.- Inicia Musica 2", ancho/2, 90, 0xFFFFFF, 0x333333);
       textout_centre_ex(buffer, font, "3.- Reproduce Sonido 1", ancho/2, 110, 0xFFFFFF, 0x333333);
       textout_centre_ex(buffer, font, "4.- Reproduce Sonido 2", ancho/2, 130, 0xFFFFFF, 0x333333);
       textout_centre_ex(buffer, font, "Barra espaciadora detiene musica", ancho/2, 200, 0xFFFFFF, 0x333333);                     
    textout_centre_ex(buffer, font, "http://devcpp-allegro.blogspot.com/", ancho/2, alto-20, 0xFFFFFF, 0xDF1680); 
  
    blit(buffer, screen, 0, 0, 0, 0, ancho, alto);
    }
 
     
    // liberamos memoria
    destroy_midi(musica1);
    destroy_midi(musica2);
    destroy_sample(sonido1);
    destroy_sample(sonido2);
 destroy_bitmap(buffer);
  
 return 0;
}
END_OF_MAIN();
