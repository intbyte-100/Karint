#include "karint.h"
#include "karint/util/logger.h"
#include <gtk/gtk.h>


void karint::terminate() {
    glfwTerminate();
}

void karint::update() {
    glfwPollEvents();
}

void karint::init() {
#ifdef KARINT_DEBUG
    karint::logger::debugMode = true;
#endif
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CENTER_CURSOR, 1);
    glfwWindowHint(GLFW_ALPHA_BITS, 0);
    glfwSwapInterval(1);
}


#ifdef __linux__

struct SystemDialog {
    char* title;
    char* text;
};

void activate(GtkApplication *app, gpointer data) {
    SystemDialog dialogData = *(SystemDialog*) data;

    auto dialog = gtk_message_dialog_new(NULL, static_cast<GtkDialogFlags>(0), GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", dialogData.text );
    gtk_window_set_title(GTK_WINDOW(dialog), dialogData.title);
    gint result = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy( GTK_WIDGET(dialog));
}

void karint::systemDialog(const char *title, const char *text) {

    SystemDialog dialog {
        .title = const_cast<char *>(title),
        .text = const_cast<char *>(text)
    };

    GtkApplication *app;
    app = gtk_application_new("com.karint.sys_dialog",G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), (gpointer) &dialog);
    g_application_run(G_APPLICATION(app), 0, nullptr);
    g_object_unref(app);
}

#endif