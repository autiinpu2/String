# Code exemple
```c
int	main(void)
{
	t_string	s;
	char		*rev;

	string_init(&s);
	s.vptr->create(&s, "12345");
	s.vptr->print(&s);
	rev = s.vptr->reverse(&s);
	if (rev)
	{
		printf("%s\n", rev);
		free(rev);
	}
	printf("%d\n", s.vptr->to_int(&s));
	s.vptr->join(&s, 4, " est ", "un ", "nom", "bre!");
	s.vptr->print(&s);
	s.vptr->destroy(&s);
	return (0);
}
```
