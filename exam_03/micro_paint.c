#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_zone
{
	int		width;
	int		height;
	char	back;
}	t_zone;

typedef struct	s_shape
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	color;
}	t_shape;

int	ft_strlen(char *str)
{
	int	i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	clear_all(FILE *file, char *str)
{
	fclose(file);
	if (str)
		free(str);
	return (1);
}

int	print_err(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

char	*get_zone(FILE *file, t_zone *zone)
{
	char	*drawing;
	int		scan_ret;
	int		i = 0;

	if ((scan_ret = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->back)) != 3)
		return (NULL);
	if (zone->width <= 0 || zone->height <= 0 || zone->width > 300 || zone->height > 300)
		return (NULL);
	drawing = malloc(sizeof(char) * zone->width * zone->height);
	if (!drawing)
		return (NULL);
	while (i < zone->width * zone->height)
		drawing[i++] = zone->back;
	return (drawing);
}

int	in_rectangle(float x, float y, t_shape shape)
{
	if (x < shape.x || y < shape.y || x > shape.x + shape.width || y > shape.y + shape.height)
		return (0);
	if (x - shape.x < 1 || y - shape.y < 1 \
		|| shape.y + shape.height - y < 1 || shape.x + shape.width - x < 1)
		return (2);
	return (1);
}

void	draw_shape(char *drawing, t_shape shape, t_zone zone)
{
	int	i = 0;
	int	j = 0;
	int	ret;

	while (i < zone.height)
	{
		j = 0;
		while (j < zone.width)
		{
			ret = in_rectangle(j, i, shape);
			if ((shape.type == 'r' && ret == 2) ||
				(shape.type == 'R' && ret))
				drawing[i * zone.width + j] = shape.color;
			j++;
		}
		i++;
	}
}

int	draw_shapes(FILE *file, char *drawing, t_zone zone)
{
	t_shape	tmp;
	int		scan_ret;

	while ((scan_ret = fscanf(file, "%c %f %f %f %f %c\n", \
			&tmp.type, &tmp.x, &tmp.y, &tmp.width, &tmp.height, &tmp.color)) == 6)
	{
		if ((tmp.type != 'r' && tmp.type != 'R') || tmp.width <= 0 || tmp.height <= 0)
		{
			return (0);
		}
		draw_shape(drawing, tmp, zone);
	}
	if (scan_ret != -1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_zone	zone;
	char	*drawing;
	FILE	*file;
	int		i = 0;

	if (ac != 2)
		return (print_err("Error: argument\n"));
	if (!(file = fopen(av[1], "r")))
		return (print_err("Error: Operation file corrupted\n"));
	if (!(drawing = get_zone(file, &zone)))
		return (clear_all(file, NULL) && print_err("Error: Operation file corrupted\n"));
	if (!draw_shapes(file, drawing, zone))
		return (clear_all(file, drawing) && print_err("Error: Operation file corrupted\n"));
	while (i < zone.height)
	{
		write(1, &drawing[i * zone.width], zone.width);
		write(1, "\n", 1);
		i++;
	}
	clear_all(file, drawing);
	return (0);
}
