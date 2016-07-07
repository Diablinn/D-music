#include <stdlib.h>
#include <gtk/gtk.h>

#include "interface.h"

int main(int argc,char **argv)
{
    GtkWidget* p_Window;

    gtk_init(&argc,&argv);

    //Creation of the main window
    p_Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(p_Window), "D-music");
    gtk_window_set_default_size(GTK_WINDOW(p_Window), 400, 100);
	gtk_window_set_position (GTK_WINDOW (p_Window), GTK_WIN_POS_CENTER);

	//Binding of the main window and its destrcution
	g_signal_connect(G_OBJECT(p_Window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //Creation of the interface :
    create_interface(p_Window);

    //Show the window
    gtk_widget_show_all(p_Window);

    //GTK's Main loop
    gtk_main();

    return EXIT_SUCCESS;
}
