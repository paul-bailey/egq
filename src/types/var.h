#ifndef EGQ_VAR_H
#define EGQ_VAR_H

#include <egq.h>
#include <uarg.h>

/*
 * can't just be a-b, because if they're floats, a non-zero result
 * might cast to 0
 */
#define OP_CMP(a_, b_) (a_ == b_ ? 0 : (a_ < b_ ? -1 : 1))

#define V_INITTBL(n, cb, m, M) \
        { .magic = QPTRXI_MAGIC, .name = n, \
                .h = { .fn = cb, .minargs = m, .maxargs = M }}

#define TBLEND { .name = NULL }

struct type_inittbl_t {
        int magic;
        const char *name;
        struct func_intl_t h;
};

struct var_wrapper_t {
        struct list_t siblings;
        struct var_t *v;
};

/* array.c */
extern void typedefinit_array(void);

/* empty.c */
extern void typedefinit_empty(void);

/* float.c */
extern void typedefinit_float(void);

/* function.c */
extern void typedefinit_function(void);

/* integer.c */
extern void typedefinit_integer(void);

/* object.c */
extern void typedefinit_object(void);

/* string.c */
extern void typedefinit_string(void);

/* ../var.c */
extern void var_config_type(int magic, const char *name,
                            const struct operator_methods_t *opm,
                            const struct type_inittbl_t *tbl);

#endif /* EGQ_VAR_H */
