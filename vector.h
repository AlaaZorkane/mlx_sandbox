#if !defined(VECTOR_H)
#define VECTOR_H

typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_vector
{
	t_point a;
	t_point b;
} t_vector;

#endif // VECTOR_H
