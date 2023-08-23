#ifndef UTILS_VEC_H
# define UTILS_VEC_H
# include <math.h>

# include "datasheet.h"

t_vec3	vinit(void);
t_vec3	vset(double x, double y, double z);
t_point	pset(double x, double y, double z);
t_color	cset(double x, double y, double z);
double	vlen2(t_vec3 vec);
double	vlen(t_vec3 vec);
t_vec3	vunit(t_vec3 vec);
t_vec3	vadd_v(t_vec3 vec1, t_vec3 vec2);
t_vec3	vsub_v(t_vec3 vec1, t_vec3 vec2);
t_vec3	vmul_v(t_vec3 vec1, t_vec3 vec2);
t_vec3	vadd_s(t_vec3 vec, double s);
t_vec3	vsub_s(t_vec3 vec, double s);
t_vec3	vmul_s(t_vec3 vec, double s);
double	vdot(t_vec3 vec1, t_vec3 vec2);
t_vec3	vcross(t_vec3 vec1, t_vec3 vec2);
t_point	padd_v(t_point point, t_vec3 vec);
#endif
