#include <gtk/gtk.h>
#include <iostream>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

static GtkWidget* label;

static void fontSet(GtkFontChooser* fontButton, gpointer data){

    PangoFontDescription* fontd = pango_font_description_from_string(gtk_font_chooser_get_font(fontButton));

    gtk_widget_override_font(label, fontd);
    std::cout << gtk_font_chooser_get_font(fontButton) << std::endl;
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget* window;

  GtkWidget* fontButton;
  GtkWidget* vbox;
  GtkWidget* scrolledWindow;

  const char* css =  "label#font-label{font-family: Comic Sans MS}";

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Font Sel");
  gtk_widget_set_name(window, "Font-Sel-Window");
  gtk_window_set_default_size (GTK_WINDOW (window), WINDOW_WIDTH, WINDOW_HEIGHT);


  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  gtk_box_set_homogeneous(GTK_BOX(vbox), false);

  fontButton = gtk_font_button_new();
  gtk_container_add(GTK_CONTAINER(vbox), fontButton);

  scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
  gtk_scrolled_window_set_min_content_height(GTK_SCROLLED_WINDOW(scrolledWindow), WINDOW_HEIGHT);
  gtk_container_add(GTK_CONTAINER(vbox), scrolledWindow);

  label = gtk_label_new("the quick brown fox jumped over the lazy dog\nTHE QUICK BROWN FOX JUMPED OVER THE LAZY DOG\n😀❤\n:) :( :-) :-(\n1234567890\n!@#$%^&*()-=_+/\\,.;':\"\n[] {} ()");
  gtk_widget_set_name(label, "font-label");
  gtk_container_add(GTK_CONTAINER(scrolledWindow), label);

  gtk_container_add(GTK_CONTAINER(window), vbox);

  PangoFontDescription* fontd = pango_font_description_from_string("Comic Sans MS");

  gtk_widget_override_font(label, fontd);

  g_signal_connect(fontButton, "font-set", G_CALLBACK(fontSet), NULL);

  gtk_widget_show_all (window);
}

int main (int argc, char **argv){
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
