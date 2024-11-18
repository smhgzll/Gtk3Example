#include <gtk/gtk.h>

// Callback function for the button click
static void on_button_clicked(GtkWidget *button, gpointer user_data) {
    GtkEntry *entry = GTK_ENTRY(user_data);  // Get the textbox widget from user_data
    if (GTK_IS_ENTRY(entry)) {  // Check if the passed user_data is a valid GtkEntry
        gtk_entry_set_text(entry, "Hello, World!");  // Set the textbox text
    }
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *entry;
    GtkWidget *box;

    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a new window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK3 Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 150);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a box to hold the button and textbox
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Create a button
    button = gtk_button_new_with_label("Click me");

    // Create a textbox (GtkEntry)
    entry = gtk_entry_new();

    // Connect the button's "clicked" signal to the callback, passing the entry widget as user data
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), entry);

    // Add the button and textbox to the box
    gtk_box_pack_start(GTK_BOX(box), entry, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);

    // Show all widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}
