#include "interface.h"

bool IS_PLAYED = FALSE;

void create_interface(GtkWidget* p_Window)
{
    GtkWidget *p_playBtn;
    GtkWidget *p_labelPlay;
    GtkWidget *p_button[2];
    GtkWidget *p_nameSong;
    GtkWidget *p_boxV_main;
    GtkWidget *p_boxH;

    //Main box vertical :
    p_boxV_main = gtk_vbox_new(FALSE, 5);
    //We add it in the main window
    gtk_container_add(GTK_CONTAINER(p_Window), p_boxV_main);

    //NameSong :
    p_nameSong = gtk_button_new_with_label("Chanson de la mort");
    //We add it in the main box (vertical) :
    gtk_box_pack_start(GTK_BOX(p_boxV_main), p_nameSong, TRUE, FALSE, 0);

    //Box horizontal :
    p_boxH = gtk_hbox_new(TRUE, 5);
    //We add it in the main box (vertical) :
    gtk_box_pack_start(GTK_BOX(p_boxV_main), p_boxH, TRUE, TRUE, 0);

    //Previous track button :
    p_button[0] = gtk_button_new_with_label("Prev");
    gtk_box_pack_start(GTK_BOX(p_boxH), p_button[0], FALSE, FALSE, 0);
    g_signal_connect(G_OBJECT(p_button[0]), "clicked", G_CALLBACK(callback_prev), NULL);

    //Creation of the play button
    p_playBtn = gtk_button_new();
    p_labelPlay = gtk_label_new("Play");
    gtk_container_add(GTK_CONTAINER(p_playBtn), p_labelPlay);
    //Bind of the play button : pointer to its label in argument : allow the callback
    //to change "play" with "stop"
    g_signal_connect(G_OBJECT(p_playBtn), "clicked", G_CALLBACK(callback_play), p_labelPlay);
    //We add the play button to the horizontal box :
    gtk_box_pack_start(GTK_BOX(p_boxH), p_playBtn, FALSE, FALSE, 0);

    //Next track button :
    p_button[1] = gtk_button_new_with_label("Next");
    gtk_box_pack_start(GTK_BOX(p_boxH), p_button[1], FALSE, FALSE, 0);
    g_signal_connect(G_OBJECT(p_button[1]), "clicked", G_CALLBACK(callback_next), NULL);
}


void callback_play(GtkWidget *widget, gpointer data)
{
    if (! IS_PLAYED){
        printf("Play");
        IS_PLAYED = TRUE;
        gtk_label_set(GTK_LABEL(data), "Stop");
    } else{
        printf("Stop");
        IS_PLAYED = FALSE;
        gtk_label_set(GTK_LABEL(data), "Play");
    }
}


void callback_prev(GtkWidget *widget, gpointer data)
{
    printf("Prev");
}


void callback_next(GtkWidget *widget, gpointer data)
{
    printf("Next");
}
