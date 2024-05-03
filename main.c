
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

void gameplay(ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *fifo, ALLEGRO_EVENT event, ALLEGRO_SAMPLE *sample);

int main() {

    // Declarations
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *fifo = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT event = {0};
    ALLEGRO_SAMPLE *sample = NULL;

    // Initialisation
    assert(al_init());
    al_init_primitives_addon();
    assert(al_install_keyboard());
    assert(al_init_image_addon());
    assert(al_install_joystick());
    al_init_font_addon();
    assert(al_init_ttf_addon());
    al_init_acodec_addon();
    al_install_audio();

    al_reserve_samples(1);// numéro correspond aux nombres de sons

    // Creation des elements
    const int WIDSPLAY = 800;
    const int HIDSPLAY = 600;
    display = al_create_display(WIDSPLAY, HIDSPLAY);
    al_set_window_position(display, 170, 50);
    timer = al_create_timer(1.0 / 60);
    fifo = al_create_event_queue();
    sample = al_load_sample("../musique/La_Cucaracha.wav");


    // Sources d'evenements
    al_register_event_source(fifo, al_get_display_event_source(display));
    al_register_event_source(fifo, al_get_timer_event_source(timer));
    al_register_event_source(fifo, al_get_keyboard_event_source());

    // Boucle d'evenements
    al_start_timer(timer);

    gameplay(timer, fifo, event, sample);

    //dessinerCuisine(Niveau1);

    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(fifo);
    al_destroy_sample(sample);
}


void gameplay(ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *fifo, ALLEGRO_EVENT event, ALLEGRO_SAMPLE *sample) {
    ALLEGRO_FONT *font = al_load_ttf_font("..\\assets\\Play-Regular.ttf", 14, 0);
    int frame = 0;
    int temps = 0;  //temps = frames/60 pour pouvoir travailler en secondes depuis le lancement du lvl


    int attaque_cooldown = 3;


    bool fini = false;

    int frame_counter_cafard = 0; // Déclarer en dehors de la boucle
    int frame_actuelle_cafard = 0; // Déclarer en dehors de la boucle

    while (!fini) {
        al_play_sample(sample, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
        al_wait_for_event(fifo, &event);

        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE: {
                fini = true;
                break;
            }
            case ALLEGRO_EVENT_TIMER:
                frame = frame + 1;
                if (frame % 60 == 0) { //convertisseur frames --> secondes
                    temps = temps + 1;
                }


                //les affichages textuels dans l'ordre

                break;

        }
    }
}


















