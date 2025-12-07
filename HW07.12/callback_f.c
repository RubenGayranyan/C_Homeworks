#include <stdio.h>

void register_event_handler(void (*callback)());
void on_button_click();
void on_mouse_click();
void on_window_resize();


int main() {
    register_event_handler(on_button_click);
    register_event_handler(on_mouse_click);
    register_event_handler(on_window_resize);

    return 0 ;
}

void register_event_handler(void (*callback)()) {
    if(callback)
        callback();
}
void on_button_click() {
    printf("Button click\n");
}

void on_mouse_click() {
    printf("Mouse click\n");
}
void on_window_resize() {
    printf("Window resize\n");
}

