# GTK3 Example

This is a simple GTK3 application written in C that creates a window with a button and a textbox. When the button is clicked, the textbox will display the text "Hello, World!".

## Requirements

To compile and run this program, you will need to have the GTK3 library installed on your system. You can install GTK3 using the following package manager commands depending on your operating system:

### For Fedora:
```bash
sudo dnf install gtk3-devel
```

### For macOS (using Homebrew):
```bash
brew install gtk+3
```

### For Windows:
Install GTK3 from MSYS2 or follow the instructions on the [GTK website](https://www.gtk.org/).

## Code Explanation

### Header File

The code begins by including the GTK header:
```c
#include <gtk/gtk.h>
```
This allows us to access GTK3 functions and structures.

### Callback Function

A callback function `on_button_clicked` is defined to handle the button click event. When the button is clicked, this function sets the text of the textbox (`GtkEntry`) to "Hello, World!":
```c
static void on_button_clicked(GtkWidget *button, gpointer user_data) {
    GtkEntry *entry = GTK_ENTRY(user_data);  // Get the textbox widget from user_data
    if (GTK_IS_ENTRY(entry)) {  // Check if the passed user_data is a valid GtkEntry
        gtk_entry_set_text(entry, "Hello, World!");  // Set the textbox text
    }
}
```

### Main Function

In the `main` function, GTK is initialized, and a window is created. A vertical box (`GtkBox`) is used to hold the button and textbox:
```c
window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window), "GTK3 Example");
gtk_window_set_default_size(GTK_WINDOW(window), 300, 150);
g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
```

A button and a textbox are created:
```c
button = gtk_button_new_with_label("Click me");
entry = gtk_entry_new();
```

The `g_signal_connect` function connects the button's "clicked" signal to the `on_button_clicked` callback, passing the textbox widget (`entry`) as user data:
```c
g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), entry);
```

Finally, the button and textbox are added to the window, and the GTK main loop is started:
```c
gtk_box_pack_start(GTK_BOX(box), entry, TRUE, TRUE, 0);
gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);
gtk_widget_show_all(window);
gtk_main();
```

### How It Works

1. When you run the program, a window is displayed with a textbox and a button.
2. When the button is clicked, the text "Hello, World!" will appear in the textbox.

## Compilation

To compile this program, you can use the following command in the terminal:
```bash
gcc `pkg-config --cflags gtk+-3.0` gtk_example.c -o gtk_example `pkg-config --libs gtk+-3.0`
```

This command uses `pkg-config` to retrieve the necessary flags and libraries for GTK3.

## Running the Program

After compilation, you can run the program using:
```bash
./gtk_example
```
