#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


int minscanf (char *fmt, ...);

int main (void) {
	char c[10]; 
	int o1 = 2, o2 = 3, s = 4;
//	o1 = o2 = s = 2;
	printf("%d\n\n", minscanf ("b%d%db%d\n", &o1, &o2, &s));
	printf ("-- %d %d %d\n", o1, o2, s);
}

/* minscanf: minimal scanf with variable argument list */
int minscanf (char *fmt, ...) {
	va_list ap;	/* points to each unnamed arg in turn */
	char *p, *sval, *cval = malloc (sizeof (char));
	int *ival, i;

	unsigned *uval;
	double *dval;

	va_start (ap, fmt); /* make ap point to 1st unnamed arg */

	for (p = fmt, i = 0; *p && *p != EOF; ++p, ++i) {
//		*cval = 0;
		for (;*p != '%' && *cval != EOF; ++p, ++i) { // gets all characters until it hits % sign
			*cval = getchar ();
//			scanf("%c", cval);
			if (*p != '%' && *p != *cval)
				return i;
		}

		switch (*++p) {
			case 'd':
			case 'i':
				ival = va_arg (ap, int *);
				scanf ("%d", ival);
				break;
			case 'f':
				dval = va_arg (ap, double *);
				scanf ("%f", dval); break;
			case 'o':
				uval = va_arg (ap, unsigned *);
				scanf ("%o", uval);
				break;
			case 'O':
				uval = va_arg (ap, unsigned *);
				scanf ("%O", uval);
				break;
			case 'u':
				uval = va_arg (ap, unsigned *);
				scanf ("%u", uval);
				break;	
			case 'x':
				uval = va_arg (ap, unsigned *);
				scanf ("%x", uval);
				break;	
			case 'X':
				uval = va_arg (ap, unsigned *);
				scanf ("%X", uval);
				break;
			case 'e':
				dval = va_arg (ap, double *);
				scanf ("%e", dval);
				break;
			case 'E':
				dval = va_arg (ap, double *);
				scanf ("%e", dval);
				break;
			case 'g':
				dval = va_arg (ap, double *); 
				scanf ("%g", dval);
				break;
			case 'G':
				dval = va_arg (ap, double *);
				scanf ("%G", dval);
				break;
			case 'c':
				cval = va_arg (ap, char *);
				scanf ("%c", cval); 
				break;
			case 's':
				sval = v_arg (ap, char *);
				scanf ("%s\n", sval);
				break;
			default :
				scanf("%c", cval);
				break;
		}
	}

	va_end (ap);	/* clean up when done */

	return i;
}
