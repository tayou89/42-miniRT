#include "parsing.h"

void	print_element_count(t_count count);
void	print_sphere_data(t_sp *sphere);
void	print_plane_data(t_pl *plane);
void	print_cylinder_data(t_cy *cylinder);
void	print_ambient_data(t_ambient ambient, int ambient_count);
void	print_camera_data(t_camera camera, int camera_count);
void	print_light_data(t_light light, int light_count);
void	print_coordinate(char *title, t_point coordinate);
void	print_vector(t_vec3 normal);
void	print_color(t_color color);
void	print_double(char *title, double data);

void	print_data(t_data *data)
{
	print_element_count(data->count);
	print_sphere_data(data->sphere);
	print_plane_data(data->plane);
	print_cylinder_data(data->cylinder);
	print_ambient_data(data->ambient, data->count.ambient);
	print_camera_data(data->camera, data->count.camera);
	print_light_data(data->light, data->count.light);
}

void	print_element_count(t_count count)
{
	printf("======================element count=========================\n\n");
	printf("Ambient: %d\n", count.ambient);
	printf("Camera: %d\n", count.camera);
	printf("Light: %d\n", count.light);
	printf("Sphere: %d\n", count.sphere);
	printf("Plane: %d\n", count.plane);
	printf("Cylinder: %d\n", count.cylinder);
	printf("\n");
}

void	print_sphere_data(t_sp *sphere)
{
	t_sp	*head;
	int		number;

	printf("======================sphere data=========================\n\n");
	if (sphere == (void *) 0)
	{
		printf("Sphere data does not exist.\n\n");
		return ;
	}
	number = 1;
	head = sphere;
	while (sphere != (void *) 0)
	{
		printf("Sphere number: %d\n", number);
		print_coordinate("Center", sphere->center);
		print_color(sphere->color);
		print_double("Diameter", sphere->diameter);
		print_double("Radius", sphere->radius);
		printf("\n");
		number++;
		sphere = sphere->next;
	}
	sphere = head;
}

void	print_plane_data(t_pl *plane)
{
	t_pl	*head;
	int		number;

	printf("======================plane data=========================\n\n");
	if (plane == (void *) 0)
	{
		printf("plane data does not exist.\n\n");
		return ;
	}
	number = 1;
	head = plane;
	while (plane != (void *) 0)
	{
		printf("plane number: %d\n", number);
		print_coordinate("Center", plane->center);
		print_vector(plane->normal);
		print_color(plane->color);
		printf("\n");
		number++;
		plane = plane->next;
	}
	plane = head;
}

void	print_cylinder_data(t_cy *cylinder)
{
	t_cy	*head;
	int		number;

	printf("======================cylinder data=========================\n\n");
	if (cylinder == (void *) 0)
	{
		printf("cylinder data does not exist.\n\n");
		return ;
	}
	number = 1;
	head = cylinder;
	while (cylinder != (void *) 0)
	{
		printf("cylinder number: %d\n", number);
		print_coordinate("Center", cylinder->center);
		print_vector(cylinder->normal);
		print_double("Diameter", cylinder->diameter);
		print_double("Radius", cylinder->radius);
		print_double("Height", cylinder->height);
		print_color(cylinder->color);
		printf("\n");
		number++;
		cylinder = cylinder->next;
	}
	cylinder = head;
}

void	print_ambient_data(t_ambient ambient, int ambient_count)
{
	printf("======================ambient data=========================\n\n");
	if (ambient_count == 0)
	{
		printf("ambient data does not exist.\n\n");
		return ;
	}
	print_double("Ratio", ambient.ratio);
	print_color(ambient.color);
	printf("\n");
}

void	print_camera_data(t_camera camera, int camera_count)
{
	printf("======================camera data=========================\n\n");
	if (camera_count == 0)
	{
		printf("camera data does not exist.\n\n");
		return ;
	}
	print_coordinate("View_point", camera.view_point);
	print_vector(camera.normal);
	printf("FOV: %d\n", camera.fov);
	printf("\n");
}

void	print_light_data(t_light light, int light_count)
{
	printf("======================light data=========================\n\n");
	if (light_count == 0)
	{
		printf("light data does not exist.\n\n");
		return ;
	}
	print_coordinate("point", light.point);
	print_double("Ratio", light.ratio);
	print_color(light.color);
	printf("\n");
}


void	print_coordinate(char *title, t_point coordinate)
{
	printf("%s.x: %.5f\n", title, coordinate.x);
	printf("%s.y: %.5f\n", title, coordinate.y);
	printf("%s.z: %.5f\n", title, coordinate.z);
}

void	print_vector(t_vec3 normal)
{
	printf("Normal vector.x: %.5f\n", normal.x);
	printf("Normal vector.y: %.5f\n", normal.y);
	printf("Normal vector.z: %.5f\n", normal.z);
}

void	print_color(t_color color)
{
	printf("Color.r: %f\n", color.x);
	printf("Color.g: %f\n", color.y);
	printf("Color.b: %f\n", color.z);
}

void	print_double(char *title, double data)
{
	printf("%s: %.5f\n", title, data);
}
