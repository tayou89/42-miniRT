#ifndef UTILS_VEC_BONUS_H
# define UTILS_VEC_BONUS_H
# include <math.h>
# include "datasheet_bonus.h"

t_vec3	vinit(void);
t_vec3	vset(double x, double y, double z);
t_vec3	vinverse(t_vec3 vec);
int		vsame(t_vec3 vec1, t_vec3 vec2);
t_vec3	vmin(t_vec3 vec1, t_vec3 vec2);
double	vlen2(t_vec3 vec);
double	vlen(t_vec3 vec);
t_vec3	vunit(t_vec3 vec);
t_vec3	vadd_v(t_vec3 vec1, t_vec3 vec2);
t_vec3	vsub_v(t_vec3 vec1, t_vec3 vec2);
t_vec3	vmul_v(t_vec3 vec1, t_vec3 vec2);
t_vec3	vadd_s(t_vec3 vec, double s);
t_vec3	vsub_s(t_vec3 vec, double s);
t_vec3	vmul_s(t_vec3 vec, double s);
t_vec3	vdiv_s(t_vec3 vec, double s);
double	vdot(t_vec3 vec1, t_vec3 vec2);
t_vec3	vcross(t_vec3 vec1, t_vec3 vec2);
#endif
