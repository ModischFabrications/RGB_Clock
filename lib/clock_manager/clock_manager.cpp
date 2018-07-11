#include "clock_manager.h"

// initialise static
unsigned long clock_manager::last_call = millis();

void clock_manager::tick()
{
    // define last value to get difference
    unsigned long now = millis();
    unsigned long delta_t = now - last_call;

    if (debug) print_looptime(delta_t);

    // update hardware manager
    HW_manager::check_change();

    last_call = now;
}

// ------ private -------------

void clock_manager::register_buttons()
{
    HW_manager::add_listener(0, &inc_hour);
    HW_manager::add_listener(1, &inc_minute);
    HW_manager::add_listener(2, &dim_light);
}

void clock_manager::inc_hour()
{
    if (debug) Serial.println(F("inc_hour"));
    // don't forget wraparound
    
}

void clock_manager::inc_minute()
{
    if (debug) Serial.println(F("inc_minute"));
    // add leds.get_n_leds()/60 minutes

}

void clock_manager::dim_light()
{
    if (debug) Serial.println(F("dim_light"));

}

void clock_manager::print_looptime(unsigned long delta_t)
{
    Serial.print(F("cycle time: "));
    Serial.print(delta_t);
    Serial.println(F(" ms"));
}
