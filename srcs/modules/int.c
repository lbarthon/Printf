// Add header

#include "printf.h"

static size_t	get_pow(long long nbr)
{
	size_t	pow;

	pow = 10;
	while (pow < (size_t)nbr)
		pow *= 10;
	return (pow / 10);
}

void			int_handler(t_printf *data)
{
	long long	nbr;
	size_t		pow;

	nbr = va_arg(*data->args, int);
	if (nbr < 0)
	{
		buffer_add_char(data, '-');
		nbr = -nbr;
	}
	pow = get_pow(nbr);
	while (pow >= 1)
	{
		buffer_add_char(data, ((int)(nbr / pow) % 10) + 48);
		pow = pow == 1 ? 0 : pow / 10;
	}
}
