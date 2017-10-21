#include <stdarg.h>
#include <stdio.h>

void minprintf (char *fmt, ...);

int main (void) {
	minprintf ("b%d%db%d\n", 0, 0, 5);
	minprintf ("%f\n", 2.0);
}

/* minprintf: minimal printf with variable argument list */
void minprintf (char *fmt, ...) {
	va_list ap;	/* points to each unnamed arg in turn */
	char *p, *sval, cval;
	int ival;
	unsigned uval;
	double dval;

	va_start (ap, fmt); /* make ap point to 1st unnamed arg */

	for (p = fmt; *p; ++p) {
		if (*p != '%') {
			putchar (*p);
			continue;
		}

		switch (*++p) {
			case 'd':
			case 'i':
				ival = va_arg (ap, int);
				printf ("%d", ival);
				break;
			case 'f':
				dval = va_arg (ap, double);
				printf ("%f", dval);
				break;
			case 'o':
				uval = va_arg (ap, unsigned);
				printf ("%o", ival);
				break;
			case 'O':
				uval = va_arg (ap, unsigned);
				printf ("%O", ival);
				break;
			case 'u':
				uval = va_arg (ap, unsigned);
				printf ("%u", ival);
				break;	
			case 'x':
				uval = va_arg (ap, unsigned);
				printf ("%x", ival);
				break;	
			case 'X':
				uval = va_arg (ap, unsigned);
				printf ("%X", ival);
				break;
			case 'e':
				dval = va_arg (ap, double);
				printf ("%e", dval);
				break;
			case 'E':
				dval = va_arg (ap, double);
				printf ("%e", dval);
				break;
			case 'g':
				dval = va_arg (ap, double);
				printf ("%g", dval);
				break;
			case 'G':
				dval = va_arg (ap, double);
				printf ("%G", dval);
				break;
			case 'c':
				cval = va_arg (ap, int);
				printf ("%c", cval); 
				break;
			case 's':
				for (sval = va_arg (ap, char *); *sval; ++sval)
					putchar (*sval);
				break;
			default :
				putchar (*p);
				break;
		}
	}

	va_end (ap);	/* clean up when done */
}
