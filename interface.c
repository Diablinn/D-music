#include "interface.h"

bool IS_PLAYED = FALSE;

GtkWidget* create_interface(GtkWidget* p_Window)
{
    GtkWidget *p_playBtn;
    GtkWidget *p_label[2]; //0 : nameSong; 1 : play/stop
    GtkWidget *p_button[2];
    GtkWidget *p_frameSong;
    GtkWidget *p_boxV_main;
    GtkWidget *p_boxH;

    gchar* sUtf8;

    //Main box vertical :
    p_boxV_main = gtk_vbox_new(FALSE, 5);
    //We add it in the main window
    gtk_container_add(GTK_CONTAINER(p_Window), p_boxV_main);

    //NameSong :
    sUtf8 = g_locale_to_utf8("Chanson jouée", -1, NULL, NULL, NULL);
    p_frameSong = gtk_frame_new(sUtf8);
    p_label[0]=gtk_label_new(NULL);
    sUtf8 = g_locale_to_utf8("<span foreground=\"#000000\">Ma chanson trop cool</span>", -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(p_label[0]), sUtf8);
    gtk_container_add(GTK_CONTAINER(p_frameSong), p_label[0]);
    //We add it in the main box (vertical) :
    gtk_box_pack_start(GTK_BOX(p_boxV_main), p_frameSong, TRUE, FALSE, 0);

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
    p_label[1] = gtk_label_new("Play");
    gtk_container_add(GTK_CONTAINER(p_playBtn), p_label[1]);
    //Bind of the play button : pointer to its label in argument : allow the callback
    //to change "play" with "stop"
    g_signal_connect(G_OBJECT(p_playBtn), "clicked", G_CALLBACK(callback_play), p_label[1]);
    //We add the play button to the horizontal box :
    gtk_box_pack_start(GTK_BOX(p_boxH), p_playBtn, FALSE, FALSE, 0);

    //Next track button :
    p_button[1] = gtk_button_new_with_label("Next");
    gtk_box_pack_start(GTK_BOX(p_boxH), p_button[1], FALSE, FALSE, 0);
    g_signal_connect(G_OBJECT(p_button[1]), "clicked", G_CALLBACK(callback_next), NULL);

    return p_frameSong;
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
