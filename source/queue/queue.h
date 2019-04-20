#ifndef queue_H_
#define queue_H_

#include <stdlib.h>
#include "../support_functions/support_functions.h"

typedef struct      s_node
{
    char            *data;
    struct s_node   *next;
    struct s_node   *prev;
}                   t_node;

typedef struct      s_queue
{
    t_node          *head;
    t_node          *tail;
    size_t          size;
}                   t_queue;

typedef struct      s_iterator
{
	t_node          *node;
}                   t_iterator;

/* t_iterators */
t_iterator          first(t_queue *q);
t_iterator          last(t_queue *q);
t_iterator	        next(t_iterator *i);
t_iterator	        prev(t_iterator *i);
char			    *fetch(const t_iterator *i);
void		        store(const t_iterator *i, const char *elem);

/* t_queue main */
void		        queue_create(t_queue *q);
void                queue_push(t_queue *q, char *value);
char                *queue_pop(t_queue *q);
int                 queue_is_empty(t_queue *q);
size_t		        queue_len(t_queue *q);
void		        queue_destroy(t_queue *q);

/*queue support */
void	            queue_insert(t_queue *q, t_iterator *i, char *num);
void                queue_push_back(t_queue *q, char *value);
void	            queue_del(t_queue *q, t_iterator *i);
void		        queue_print(t_queue *q);

#endif
