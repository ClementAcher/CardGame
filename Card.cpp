
#include "Card.h"

ostream & operator << (ostream & out, Card& c) {
		c.print(out);
	return(out);
}