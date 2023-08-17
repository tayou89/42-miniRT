int	color_get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	color_get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	color_get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	color_get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	color_get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
