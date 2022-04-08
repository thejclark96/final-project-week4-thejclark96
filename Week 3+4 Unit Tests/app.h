// #ifndef APP_H
// #define APP_H

#include "physics.h"
#include <stdbool.h>
#include <stdlib.h>
#include "ctest.h"
#include <time.h>




struct hm_attributes {
  unsigned int    num_of_enemies;
  unsigned int    display_diameter;       // cm
  unsigned int    init_conds;
  float           x_vel;                  // cm/s
  float           y_vel;                  // cm/s
  int             init_x_pos;             // pixels 0-128
  unsigned int    user_defined_mode;
  float           x_pos;                  // pixels 0-128
  float           y_pos;                  // pixels 0-128
};

struct platform_attributes {
  unsigned int    max_force;              // N
  unsigned int    mass;                   // kg
  unsigned int    length;                 // cm
  bool            wall_bounce_en;         // t/f
  unsigned int    max_bounce_speed;       // cm/s
  bool            auto_control_en;        // t/f
  unsigned int    energy_reduction;       // % of kinetic energy reduced after passive bounce
  float           x_pos;                  // pixels 0-128
  float           y_pos;                  // pixels 0-128
  float           x_vel;                  // cm/s

};