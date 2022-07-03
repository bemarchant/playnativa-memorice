// Include MicroPython API.
#include "py/runtime.h"

// This is the function which will be called from Python as cexample.add_ints(a, b).
STATIC mp_obj_t getAudio(mp_obj_t a_obj) {
    // Extract the ints from the micropython input objects.
    int a = mp_obj_get_int(a_obj);
    int b = 20;
    if(a == 0)
    {
        b = 100;
    }
    // Calculate the addition and convert to MicroPython object.
    return mp_obj_new_int(b);
}

// Define a Python reference to the function above.
STATIC MP_DEFINE_CONST_FUN_OBJ_2(getAudio_obj, getAudio);

// Define all properties of the module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimized to word-sized integers by the build system (interned strings).
STATIC const mp_rom_map_elem_t example_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_data-audio) },
    { MP_ROM_QSTR(MP_QSTR_getAudio), MP_ROM_PTR(&getAudio_obj) },
};
STATIC MP_DEFINE_CONST_DICT(example_module_globals, example_module_globals_table);

// Define module object.
const mp_obj_module_t example_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&example_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_data-audio, example_user_cmodule);