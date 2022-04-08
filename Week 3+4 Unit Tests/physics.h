#include "app.h"
#include "physics.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ctest.h"
#include <time.h>


struct hm_attributes;
struct platform_attributes;
void gravity_force    (float ggravity, struct hm_attributes *enemy);

void bounce           (struct hm_attributes       * enemy, struct platform_attributes * platform );

void booster          (struct hm_attributes       * enemy);

void platform_physics (struct platform_attributes * platform);