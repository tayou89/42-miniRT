#include "viewport.h"

static void	get_viewport_initial_data(t_viewport *viewport, t_camera camera);
static void	get_viewport_vector(t_viewport *viewport, t_camera camera);
static void	get_viewport_point(t_viewport *viewport);
void	print_viewport_data(t_viewport *viewport);

void	get_viewport_data(t_viewport *viewport, t_camera camera)
{
	get_viewport_initial_data(viewport, camera);
	get_viewport_vector(viewport, camera);
	get_viewport_point(viewport);
	print_viewport_data(viewport);

}

static void	get_viewport_initial_data(t_viewport *viewport, t_camera camera)
{
	viewport->center = get_viewport_center(camera, FOCAL_LENGTH);
	viewport->width = get_viewport_width(camera.fov, FOCAL_LENGTH);
	viewport->height = get_viewport_height(viewport->width);
}

static void	get_viewport_vector(t_viewport *viewport, t_camera camera)
{
	viewport->axis_vector = get_viewport_axis_vector(camera.normal);
	viewport->right_vector = get_viewport_right_vector(viewport, camera);
	viewport->down_vector = get_viewport_down_vector(viewport, camera);
	viewport->right_unit = \
		get_viewport_unit_vector(viewport->right_vector, DIR_RIGHT);
	viewport->down_unit = \
		get_viewport_unit_vector(viewport->down_vector, DIR_DOWN);
}

static void	get_viewport_point(t_viewport *viewport)
{
	viewport->left_top = get_viewport_corner(viewport, DIR_LEFT, DIR_UP);
	viewport->starting = get_viewport_starting(viewport);
}

void	print_viewport_data(t_viewport *viewport)
{
	printf("viewport->width: %f\n", viewport->width);
	printf("viewport->height: %f\n", viewport->height);
	printf("\n");
	printf("viewport->center.x: %f\n", viewport->center.x);
	printf("viewport->center.y: %f\n", viewport->center.y);
	printf("viewport->center.z: %f\n", viewport->center.z);
	printf("\n");
	printf("viewport->left_top.x: %f\n", viewport->left_top.x);
	printf("viewport->left_top.y: %f\n", viewport->left_top.y);
	printf("viewport->left_top.z: %f\n", viewport->left_top.z);
	printf("\n");
	printf("viewport->starting.x: %f\n", viewport->starting.x);
	printf("viewport->starting.y: %f\n", viewport->starting.y);
	printf("viewport->starting.z: %f\n", viewport->starting.z);
	printf("\n");
	printf("viewport->right_vector.x: %.15f\n", viewport->right_vector.x);
	printf("viewport->right_vector.y: %.15f\n", viewport->right_vector.y);
	printf("viewport->right_vector.z: %.15f\n", viewport->right_vector.z);
	printf("\n");
	printf("viewport->down_vector.x: %.15f\n", viewport->down_vector.x);
	printf("viewport->down_vector.y: %.15f\n", viewport->down_vector.y);
	printf("viewport->down_vector.z: %.15f\n", viewport->down_vector.z);
	printf("\n");
	printf("viewport->right_unit.x: %.15f\n", viewport->right_unit.x);
	printf("viewport->right_unit.y: %.15f\n", viewport->right_unit.y);
	printf("viewport->right_unit.z: %.15f\n", viewport->right_unit.z);
	printf("\n");
	printf("viewport->down_unit.x: %.15f\n", viewport->down_unit.x);
	printf("viewport->down_unit.y: %.15f\n", viewport->down_unit.y);
	printf("viewport->down_unit.z: %.15f\n", viewport->down_unit.z);
	printf("\n");
	printf("viewport->axis_vector.x: %f\n", viewport->axis_vector.x);
	printf("viewport->axis_vector.y: %f\n", viewport->axis_vector.y);
	printf("viewport->axis_vector.z: %f\n", viewport->axis_vector.z);
}
