#include "py/runtime.h"

STATIC mp_obj_t myaudios(mp_obj_t index_obj) 
{
    mp_int_t index = mp_obj_get_int(index_obj);

    // Your code here!

    // signature: mp_obj_t mp_obj_new_list(size_t n, const mp_obj_t *items);
    mp_obj_t audio[] = {
        mp_obj_new_int(123),
        mp_obj_new_float(456.789),
        mp_obj_new_str("hello", 5),
    };
    return mp_obj_new_list(3, audio);
}

MP_DEFINE_CONST_FUN_OBJ_1(myaudios_obj, myaudios);

STATIC const mp_rom_map_elem_t myaudios_globals_table[] = 
{
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_builtins) },
    { MP_ROM_QSTR(MP_QSTR_myaudios), MP_ROM_PTR(&myaudios_obj) },
};