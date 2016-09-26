/*
** mrb_libssh.c - LibSSH class
**
** Copyright (c) Uchio Kondo 2016
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_libssh.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  int len;
} mrb_libssh_data;

static const struct mrb_data_type mrb_libssh_data_type = {
  "mrb_libssh_data", mrb_free,
};

static mrb_value mrb_libssh_init(mrb_state *mrb, mrb_value self)
{
  mrb_libssh_data *data;
  char *str;
  int len;

  data = (mrb_libssh_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_libssh_data_type;
  DATA_PTR(self) = NULL;

  mrb_get_args(mrb, "s", &str, &len);
  data = (mrb_libssh_data *)mrb_malloc(mrb, sizeof(mrb_libssh_data));
  data->str = str;
  data->len = len;
  DATA_PTR(self) = data;

  return self;
}

static mrb_value mrb_libssh_hello(mrb_state *mrb, mrb_value self)
{
  mrb_libssh_data *data = DATA_PTR(self);

  return mrb_str_new(mrb, data->str, data->len);
}

static mrb_value mrb_libssh_hi(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, "hi!!");
}

void mrb_mruby_libssh_gem_init(mrb_state *mrb)
{
    struct RClass *libssh;
    libssh = mrb_define_class(mrb, "LibSSH", mrb->object_class);
    mrb_define_method(mrb, libssh, "initialize", mrb_libssh_init, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, libssh, "hello", mrb_libssh_hello, MRB_ARGS_NONE());
    mrb_define_class_method(mrb, libssh, "hi", mrb_libssh_hi, MRB_ARGS_NONE());
    DONE;
}

void mrb_mruby_libssh_gem_final(mrb_state *mrb)
{
}

