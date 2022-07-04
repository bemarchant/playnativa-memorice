#include "py/runtime.h"

const mp_rom_obj_array_t myfirstaudio{
    {&mp_type_array},
    9,
    {
        1,2,4,5,6,7,8,9,10
    },
} mp_obj_array_t;

STATIC const mp_rom_map_elem_t myaudios_module_globals_table[] = {

    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_audios) },
    { MP_ROM_QSTR(MP_QSTR_myfirstaudio), MP_ROM_PTR(&myfirstaudio_obj) },
};

STATIC MP_DEFINE_CONST_DICT(myaudios_module_globals, myaudios_module_globals_table);

const mp_obj_module_t myaudios_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&audios_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_audios, myaudios_user_cmodule, MODULE_AUDIOS_ENABLED);