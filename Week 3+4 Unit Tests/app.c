#include "app.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


unsigned int  data_struct_vers = 1;       // Default is 1?
float         gravity;                    // mm/s^2
unsigned int  canyon_size;                // cm convert to pixels

struct hm_attributes            h_mass;
struct platform_attributes      platform;
struct shield_boost_attributes  boost_shield;

float y_prev_pos;
float x_prev_pos;


static void blink_task(void *arg){
    PP_UNUSED_PARAM(arg);

    /* Enemy starting values */
    y_prev_pos = 1;
    h_mass.display_diameter   = 5;
    h_mass.init_conds         = 1;
    h_mass.init_x_pos         = 60;
    h_mass.num_of_enemies     = 1;
    h_mass.user_defined_mode  = 1;
    h_mass.x_pos              = h_mass.init_x_pos;
    h_mass.x_vel              = 2;
    h_mass.y_pos              = 2;
    h_mass.y_vel              = 0;

    /* Platform starting values */
    platform.auto_control_en  = 0;
    platform.energy_reduction = 0;
    platform.length           = 30;
    platform.mass             = 1;
    platform.max_bounce_speed = 0;
    platform.max_force        = 10;
    platform.wall_bounce_en   = 0;
    platform.x_pos            = 64;
    platform.x_vel            = 0;
    platform.y_pos            = 120;

    /* Other game features you need to control */
    int canyon_pixel_width  = (canyon_size * 10) / 0.18;   // Converted to pixels
    int canyon_left_bound   = (128 - canyon_pixel_width) / 2;
    int canyon_right_bound  = 128 - canyon_left_bound;

    float tau_phys  = 10 * 10^(-3);

    // convert mm/s^2 to pixels/tau_phys
    gravity = 0.05444;




    while (1){


        /* Call all the physics functions */
        platform_physics( &platform);
        gravity_force   ( gravity, (&h_mass));
        bounce          ( (&h_mass), (&platform));

        /* TESTING PURPOSES: Boost the ball's speed when velocity gets too low */
        if(abs((&h_mass)->y_pos) >  100){
            booster     ( &h_mass);
        }


        /* UPDATE THE POSTITIONS OF THE ENEMY AND PLATFORM SHIELD; PUT THIS IN PHYSICS AS A FUNCTION!  */
        (&h_mass)->y_pos = (&h_mass)->y_pos + (&h_mass)->y_vel;
        y_prev_pos = (&h_mass)->y_pos;                                 // Store previous position

        (&h_mass)->x_pos = (&h_mass)->x_pos + (&h_mass)->x_vel;
        x_prev_pos = (&h_mass)->x_pos;                                 // Store previous position

    }
}