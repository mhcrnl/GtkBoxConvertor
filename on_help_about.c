
#include "on_help_about.h"

void on_help_about(void)
{
	GtkWidget * about_dialog = gtk_about_dialog_new();
	gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(about_dialog), "authors");
	gtk_about_dialog_set_license(GTK_ABOUT_DIALOG(about_dialog), "license");
	gtk_dialog_run(GTK_DIALOG(about_dialog));
	gtk_widget_destroy(about_dialog);
}
