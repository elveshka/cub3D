#include "libft/libft.h"

int main(void)
{
	char *s1 = "Rfdfdf";
	char *s2 = "R";

	ft_putnbr_fd(ft_strncmp(s1, s2, 1), 1);
	return(0);
}