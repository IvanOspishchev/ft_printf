/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:29:05 by nparker           #+#    #+#             */
/*   Updated: 2019/04/20 16:29:07 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/* Functions for t_iterators */
t_iterator first(t_queue *q)
{
    t_iterator res;

    res.node = q->head;
    return (res);
}

t_iterator last(t_queue *q)
{
    t_iterator res;

    res.node = q->tail;
    return (res);
}

t_iterator prev(t_iterator *i)
{
    i->node = i->node->prev;
    return (*i);
}

t_iterator next(t_iterator *i)
{
    i->node = i->node->next;
    return (*i);
}

char *fetch(const t_iterator *i)
{
    return (i->node->data);
}

void store(const t_iterator *i, const char *elem)
{
    i->node->data = ft_strdup(elem);
}


/* Fuctions for queue */
void queue_create(t_queue *q)
{
    q->head = NULL;
    q->tail = NULL;
	q->size = 0;
}

void queue_push_back(t_queue *q, char *value)
{
    t_iterator res;

    res.node = (t_node *)malloc(sizeof(t_node));
    if (res.node == NULL)
        exit(1);
    res.node->next = NULL;
    res.node->prev = NULL;
    store(&res, value);
    if (q->size == 0) {
        q->head = res.node;
        q->tail = res.node;
    } else {
        q->tail->next = res.node;
        res.node->prev = q->tail;
        res.node->next = NULL;
        q->tail =  res.node;
    }
    q->size++;
}

void queue_insert(t_queue *q, t_iterator *i, char * value)
{
    t_iterator res;

    if (q->head == i->node && i->node == NULL) {
        queue_push_back(q, value);
        return ;
    }
    if (i->node == NULL)
        exit(1);
	res.node = (t_node *)malloc(sizeof(t_node));
    if (res.node == NULL)
        exit(1);
    res.node->next = NULL;
    res.node->prev = NULL;
    store(&res, value);
    res.node->prev = i->node->prev;
    res.node->next = i->node;
    if (res.node->prev != NULL)
        res.node->prev->next = res.node;
    i->node->prev = res.node;
    if (i->node == q->head)
        q->head = res.node;
    q->size++;
}

void queue_del(t_queue *q, t_iterator *i)
{
    if (q->head == i->node)
        q->head = q->head->next;
    else if (q->tail == i->node)
        q->tail = q->tail->prev;
    if (i->node->next != NULL)
        i->node->next->prev = i->node->prev;
    if (i->node->prev != NULL)
        i->node->prev->next = i->node->next;
    ft_strdel(&i->node->data);
    free(i->node);
    i->node = NULL;
    q->size--;
}

char *queue_pop(t_queue *q)
{
    char *res;
    t_iterator i;

    i = last(q);
    res = ft_strdup(fetch(&i));
    queue_del(q, &i);
    return (res);
}

void queue_push(t_queue *q, char *value)
{
    t_iterator begin;

    begin = first(q);
    queue_insert(q, &begin, value);
}

size_t queue_len(t_queue *q)
{
    return (q->size);
}

int queue_is_empty(t_queue *q)
{
    return (queue_len(q) == 0);
}

void queue_destroy(t_queue *q)
{
    t_iterator i = first(q);
    t_iterator i_del;

    while (i.node) {
        i_del = i;
        next(&i);
        queue_del(q, &i_del);
    }
}
