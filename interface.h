#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdbool.h>

/*Creation of the interface : button play, stop, next/previous track...*/
void create_interface(GtkWidget* p_Window);

void callback_play(GtkWidget *widget, gpointer data);
void callback_prev(GtkWidget *widget, gpointer data);
void callback_next(GtkWidget *widget, gpointer data);

#endif // INTERFACE_H_INCLUDED
