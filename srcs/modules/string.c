// Add header

#include "printf.h"

void	string_handler(t_printf *data)
{
	char	*str;

	if (!(str = va_arg(*data->args, char *)))
		str = "(null)";
	buffer_add_str(data, str, (size_t)ft_strlen(str));
}
