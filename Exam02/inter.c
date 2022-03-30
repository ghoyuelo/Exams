Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------
Escriba un programa que reciba como parámetros dos cadenas de caracteres y que
muestre, sin duplicados, los caracteres comunes a las dos cadenas.
Se mostrarán en el orden de aparición dentro de la primera cadena.
La visualización se debe terminar con un salto de línea.
Si el número de parámetros transmitidos es distinto de 2, el programa mostrará
'\n'.
Ejemplos:
$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "algo" "no crea que esta frase esconde algo" | cat -e
algo$
$>./inter | cat -e
$

int	main(int argc, char **argv)
{
	int	used[255];
	int	i, j;

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && !used[(unsigned char)argv[i][j]])
					used[(unsigned char)argv[i][j]] = 1;
				else if (i == 1 && used[(unsigned char)argv[i][j]] == 1)
				{
					write(1,&argv[i][j], 1);
					used[(unsigned char)argv[i][j]] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
