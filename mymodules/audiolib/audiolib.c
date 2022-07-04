// Include MicroPython API.
#include "py/runtime.h"

// This is the function which will be called from Python as audiolib.getAudio(a, b).
STATIC mp_obj_t mymodule_getAudio(mp_obj_t a, mp_obj_t b) 
{
    int a = mp_obj_get_int(a);
    int b = mp_obj_get_int(b);
    mp_obj_t tuple[1];

    tuple[0] = a;
    
    return mp_obj_new_tuple(1, tuple);
}

// Define a Python reference to the function above.
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mymodule_getAudio_obj, mymodule_getAudio);

// Define all properties of the module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimized to word-sized integers by the build system (interned strings).
STATIC const mp_rom_map_elem_t mymodule_module_globals_table[] = 
{
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_audiolib) },
    { MP_ROM_QSTR(MP_QSTR_getAudio), MP_ROM_PTR(&mymodule_getAudio_obj) },
};
STATIC MP_DEFINE_CONST_DICT(mymodule_module_globals, mymodule_module_globals_table);

// Define module object.
const mp_obj_module_t mymodule_user_cmodule = 
{
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&mymodule_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_audiolib, mymodule_user_cmodule);
