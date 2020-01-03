// Purpose: Calculate the Max number using macros.
// Author: Tianyu Zhang
// 04/22/18

#ifndef MAX2
#define MAX2(x,y) ((x > y)? x : y)
#endif

#ifndef MAX3
#define MAX3(x,y,z) MAX2(MAX2(x,y),z)
#endif

