void quhuanhang(char *s)
{
	while (*s != '\n')
	{
		s++;
	}
	*s = '\0';
}