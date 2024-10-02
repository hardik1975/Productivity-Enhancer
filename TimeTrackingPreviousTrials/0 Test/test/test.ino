#include "MainApp.h"

MainApp app("yo", "hardikhardik", "pool.ntp.org");

void setup() {
    app.setup();
}

void loop() {
    app.loop();
}
