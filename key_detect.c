int	key_detect(int keycode)
{
	if (keycode == 13)
		key_up(data);
	if (keycode == 1)
		key_down(data);
	if (keycode == 2)
		key_right(data);
	if (keycode == 0)
		key_left(data);
	return (0);
}