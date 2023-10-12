#include <assert.h>
#include <bare.h>
#include <js.h>
#include <stdlib.h>

static js_value_t *
bare_abort (js_env_t *env, js_callback_info_t *info) {
  abort();

  return NULL;
}

static js_value_t *
init (js_env_t *env, js_value_t *exports) {
  int err;

#define V(name, fn) \
  { \
    js_value_t *val; \
    err = js_create_function(env, name, -1, fn, NULL, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, exports, name, val); \
    assert(err == 0); \
  }

  V("abort", bare_abort)
#undef V

  return exports;
}

BARE_MODULE(bare_abort, init)
