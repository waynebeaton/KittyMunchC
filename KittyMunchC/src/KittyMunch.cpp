// Copyright (c) 1984, 2014 Wayne Beaton
// All rights reserved, distributed under the terms of the Eclipse Public License 1.0.

#include <stdlib.h>
#include <math.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo/cairo.h>

#include "Game.h"

#define WIDTH        1000
#define HEIGHT       550

static short FPS = 15;

static GtkWidget *drawing;

static Game * game;

static gboolean on_tick(gpointer user_data) {
	game->tick();

	gtk_widget_queue_draw(drawing);

	return game->isRunning();
}

static void on_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
	game->draw(cr);
}

static gboolean on_mouse_moved(GtkWidget *widget, GdkEventMotion *event,
		gpointer data) {
	game->mouseMoved(event->x, event->y);

	return TRUE;
}

static gboolean on_button_press(GtkWidget *widget, GdkEventButton  *event) {
	if (event->button == 1) game->buttonClicked();
	return TRUE;
}

int main(int argc, char *argv[]) {
	game = new Game(WIDTH, HEIGHT);

	GtkWidget *window;
	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGHT);
	gtk_window_set_title(GTK_WINDOW(window), "Scrolling drawingArea");
	g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	drawing = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), drawing);
	g_signal_connect(drawing, "draw", G_CALLBACK (on_draw), NULL);
	g_signal_connect(drawing, "motion-notify-event", G_CALLBACK (on_mouse_moved), NULL);
	g_signal_connect(drawing, "button-press-event", G_CALLBACK(on_button_press), NULL);

	gtk_widget_set_events(drawing, gtk_widget_get_events(drawing)|GDK_POINTER_MOTION_MASK|GDK_BUTTON_PRESS_MASK);

	gtk_widget_show_all(window);
	g_timeout_add(1000 / FPS, (GSourceFunc) on_tick, NULL);
	gtk_main();

	delete game;

	return 0;
}
