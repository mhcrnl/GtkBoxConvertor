#include <stdlib.h>
#include <gtk/gtk.h>

#define max 30
/*
*   GLOBAL VARIABLES
*/
const gchar *title = "GtkBox Convertor Cels To Fahr";
const gchar *author = "Mihai Cornel mhcrnl@gmail.com";
const gchar *date  = "24 noe 2018";
const gchar *version = "0.01";

GtkWidget *en_fahr = NULL;
/*
*   FUNCTIONS
*/
static void calculate(GtkWidget *wid, GtkWidget *entry);

static void calculate(GtkWidget *wid, GtkWidget *entry)
{
    float celsius = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
    float fahrenheit = (celsius * 9/5) + 32;

    gchar s_fahr[max];
    g_sprintf(s_fahr, "%.2f", fahrenheit);

    gtk_entry_set_text(GTK_ENTRY(en_fahr), s_fahr);
}

static void helloWorld (GtkWidget *wid, GtkWidget *win)
{
  GtkWidget *dialog = NULL;

  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Hello World!");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}

int main (int argc, char *argv[])
{
  GtkWidget *button = NULL;
  GtkWidget *win = NULL;
  GtkWidget *vbox = NULL;

  GtkWidget *hbox = NULL;
  GtkWidget *lb_cels = NULL;
  GtkWidget *en_cels = NULL;

  GtkWidget *hbox1 = NULL;
  GtkWidget *lb_fahr = NULL;
  //GtkWidget *en_fahr = NULL;
  GtkWidget *bt_calc = NULL;

  GtkWidget *hbox2 = NULL;

  /* Initialize GTK+ */
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init (&argc, &argv);
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

  /* Create the main window */
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (win), 8);
  gtk_window_set_title (GTK_WINDOW (win), title);
  gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
  gtk_widget_realize (win);
  g_signal_connect (win, "destroy", gtk_main_quit, NULL);

  /* Create a vertical box with buttons */
  vbox = gtk_vbox_new (TRUE, 6);
  gtk_container_add (GTK_CONTAINER (win), vbox);
  /*
  * Gtk_HBox
  */
  hbox = gtk_hbox_new(TRUE,6);
  gtk_container_add(GTK_CONTAINER(vbox), hbox);

  lb_cels = gtk_label_new("Celsius");
  gtk_container_add(GTK_CONTAINER(hbox), lb_cels);

  en_cels = gtk_entry_new();
  gtk_container_add(GTK_CONTAINER(hbox), en_cels);

  button = gtk_button_new_from_stock (GTK_STOCK_DIALOG_INFO);
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (helloWorld), (gpointer) win);
  gtk_box_pack_start (GTK_BOX (hbox), button, TRUE, TRUE, 0);

  hbox1 = gtk_hbox_new(TRUE,6);
  gtk_container_add(GTK_CONTAINER(vbox), hbox1);

  lb_fahr = gtk_label_new("Fahrenheit");
  gtk_container_add(GTK_CONTAINER(hbox1), lb_fahr);

  en_fahr = gtk_entry_new();
  gtk_container_add(GTK_CONTAINER(hbox1), en_fahr);

  bt_calc = gtk_button_new_with_label("Calculate");
  gtk_container_add(GTK_CONTAINER(hbox1), bt_calc);
  g_signal_connect(G_OBJECT(bt_calc), "clicked", G_CALLBACK(calculate), en_cels);

  hbox2 = gtk_hbox_new(TRUE,6);
  gtk_container_add(GTK_CONTAINER(vbox), hbox2);

  button = gtk_button_new_from_stock (GTK_STOCK_CLOSE);
  g_signal_connect (button, "clicked", gtk_main_quit, NULL);
  gtk_box_pack_start (GTK_BOX (hbox2), button, TRUE, TRUE, 0);

  /* Enter the main loop */
  gtk_widget_show_all (win);
  gtk_main ();
  return 0;
}
