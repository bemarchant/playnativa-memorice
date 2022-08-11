#include "py/runtime.h"
#include "audiolib.h"
#include <stdio.h>
#include "pico/stdlib.h"   // stdlib 
#include "hardware/irq.h"  // interrupts
#include "hardware/pwm.h"  // pwm 
#include "hardware/sync.h" // wait for interrupt

const mp_rom_obj_tuple_t sound1_obj = sound1;
const mp_rom_obj_tuple_t sound2_obj = sound2;
const mp_rom_obj_tuple_t sound3_obj = sound3;
const mp_rom_obj_tuple_t sound4_obj = sound4;
const mp_rom_obj_tuple_t sound5_obj = sound5;
const mp_rom_obj_tuple_t sound6_obj = sound6;

STATIC const mp_rom_map_elem_t audiodata_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_audiodata_) },
    { MP_ROM_QSTR(MP_QSTR_sound1), MP_ROM_PTR(&sound1_obj) },
    { MP_ROM_QSTR(MP_QSTR_sound2), MP_ROM_PTR(&sound2_obj) },
    { MP_ROM_QSTR(MP_QSTR_sound3), MP_ROM_PTR(&sound3_obj) },
    { MP_ROM_QSTR(MP_QSTR_sound4), MP_ROM_PTR(&sound4_obj) },
    { MP_ROM_QSTR(MP_QSTR_sound5), MP_ROM_PTR(&sound5_obj) },
    { MP_ROM_QSTR(MP_QSTR_sound6), MP_ROM_PTR(&sound6_obj) },
};

STATIC MP_DEFINE_CONST_DICT(audiodata_module_globals, audiodata_module_globals_table);
const mp_obj_module_t audiodata_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&audiodata_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_myaudios, audiodata_user_cmodule);

