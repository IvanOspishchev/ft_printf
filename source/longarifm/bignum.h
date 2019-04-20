#ifndef BIGNUM_H_
#define BIGNUM_H_


typedef struct  s_bignum
{
    char        sign;
    t_string    int_part;
    t_string    frac_part;
}               t_bignum;

t_bignum        big_num_create_by_str(char sign, char *int_part, char *frac_part);
t_bignum        big_num_create_by_size(char sign, int i_part, int f_part);
t_bignum        bin_sum(t_bignum *l, t_bignum *r);
t_bignum        bin_minus(t_bignum *l, t_bignum *r);
t_bignum        bin_mult(t_bignum *l);
t_bignum        bin_divide(t_bignum *l);
void       	 	big_num_destroy(t_bignum *num);
t_bignum        dec_mult(t_bignum *n);
t_bignum        dec_div(t_bignum *n);
t_bignum        dec_sum(t_bignum *l, t_bignum *r);
void			swap_comp_str(t_string *s1, t_string *s2);

#endif
